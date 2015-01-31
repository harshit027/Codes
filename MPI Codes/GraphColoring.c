#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>


typedef int bool;
#define true 1
#define false 0
/*file reading routine*/
void readlines(MPI_File *in, const int rank, const int size, const int overlap,
               char ***lines, int *nlines)
{
    MPI_Offset filesize;
    MPI_Offset localsize;
    MPI_Offset start;
    MPI_Offset end;
    char *chunk;

    /* figure out who reads what */

    MPI_File_get_size(*in, &filesize);
    localsize = filesize/size;
    start = rank * localsize;
    end   = start + localsize - 1;

    /* add overlap to the end of everyone's chunk... */
    end += overlap;

    /* except the last processor*/
    if (rank == size-1) end = filesize;

    localsize =  end - start + 1;


    chunk = malloc( (localsize + 1)*sizeof(char));


    MPI_File_read_at_all(*in, start, chunk, localsize, MPI_CHAR, MPI_STATUS_IGNORE);
    chunk[localsize] = '\0';

    int locstart=0, locend=localsize;
    if (rank != 0) {
        while(chunk[locstart] != '\n') locstart++;
        locstart++;
    }
    if (rank != size-1) {
        locend-=overlap;
        while(chunk[locend] != '\n') locend++;
    }
    localsize = locend-locstart+1;

    /* Now let's copy our actual data over into a new array, with no overlaps */
    char *data = (char *)malloc((localsize+1)*sizeof(char));
    memcpy(data, &(chunk[locstart]), localsize);
    data[localsize] = '\0';
    free(chunk);

    /* Now we'll count the number of lines */
    *nlines = 0;
    int i=0;
    for (i=0; i<localsize; i++)
        if (data[i] == '\n') (*nlines)++;

    /* Now the array lines will point into the data array at the start of each line */
    /* assuming nlines > 1 */
    *lines = (char **)malloc((*nlines)*sizeof(char *));
    (*lines)[0] = strtok(data,"\n");
    i=0;
    for (i=1; i<(*nlines); i++)
        (*lines)[i] = strtok(NULL, "\n");

    return;
}

void printlines(char **lines, const int nlines, const int rank) {
    int i=0;
    for (i=0; i<nlines; i++) {

        printf("%d: <%s>\n", rank, lines[i]);
    }
}
/**file reading routine end*/

/*node structure linked list*/

struct node
{
           int id;
           int randomValue;
           char color;
           struct node* next;
           bool isColored;
           
};


/*unique visited nodes*/
struct tree
{
           int id;
           struct tree *left;
           struct tree *right;
};
typedef struct tree VISITED_NODE_TREE;
typedef struct node NODE;

void addNeighbor(NODE *parentNode, int nodeId);
void addToVisited(int nodeId);
void createParentNodes(int numberOfNodes, NODE** parentNodes);
NODE * getHead(int id, NODE** parentNodes, int noOfNodes);
int getListSize(NODE* head);
void deleteNode(NODE* head, int id);
void flagNode(NODE * head, int id);

int main( int argc, char *argv[] )
{

     MPI_File in;
    int rank, size;
    int ierr;
    unsigned int numberOfNodes;
    numberOfNodes = 450;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_File_open(MPI_COMM_WORLD, "GInput448.txt", MPI_MODE_RDONLY, MPI_INFO_NULL, &in);
    
    NODE *parentNodes[numberOfNodes];
    createParentNodes(numberOfNodes,parentNodes);
    const int overlap=100;
    char **lines;
    int nlines;
    readlines(&in, rank, size, overlap, &lines, &nlines);

    /*printf("Rank %d has %d lines\n", rank, nlines);
 *
 *     printlines(lines, nlines, rank);*/
     int i=0;
     const char delimiter[1]=" ";
     char* token;
     char * currentEdge[3];
      int j=0;
     // printf("\nno of lines %d",nlines);
        printf("\nPrrocess %d\n",rank);
	  for (i=0; i<nlines; i++)
	  {
              if(lines[i]!=NULL)
              {
		j=0;
	       // printf("\n%d: <%s>\n", rank, lines[i]);
	        token = strtok(lines[i],delimiter);
               // printf("\ntoken %s ", token);
	        for(j=0;j<3;j++)
	        {
			currentEdge[j]=token;
			token = strtok(NULL,delimiter);
		}

	       //	printf("\n%s --> %s",currentEdge[0],currentEdge[1]);
                int headId=0;
                int digit=0;
                if(currentEdge[1]!=NULL)
                headId=atoi(currentEdge[1]);
                if(currentEdge[2]!=NULL)
                digit=atoi(currentEdge[2]);

               // printf("\n Head : %d",headId); 
                NODE * head= getHead(headId,parentNodes,numberOfNodes);
               // printf("\nHead->id : %d",head->id);
               
               // printf("\n%d",digit);
               // printf("digit %d",digit);
                addNeighbor(head,digit);
              }
          }
    /*printing the graph*/ 
    for(i=0;i<numberOfNodes;i++)
    {
      NODE* temp= parentNodes[i];
      printf("\n");
      while(temp!=NULL)
      {
        printf("%d->",temp->id);
        temp=temp->next;
      }
     // printf("Size = %d", getListSize(temp));
    }
    if(rank==0)
    {
      int nodeCounter=0;
    }
    /*finding Maximum Independent Set*/
    int minimum=0;
    bool isMinimum=true;
    int maximumIndependentSet[numberOfNodes];
    int colorCounter=0;
    int colorArray[numberOfNodes];
    int sendNodeBuffer[numberOfNodes];
    int receiveNodeBuffer[numberOfNodes*size];
    int sendColorBuffer [numberOfNodes];
    int receiveColorBuffer[numberOfNodes*size];
    for(i=0;i<numberOfNodes;i++)
    {
     sendNodeBuffer[i]=0;
     sendColorBuffer [i]=0;
    }
    for(i=0;i<numberOfNodes*size;i++)
    {
     receiveNodeBuffer[i]=0;
     receiveColorBuffer [i]=0;
    }
    bool isNodeLeft=true;
   while(isNodeLeft)

  {
    /*initializing mis*/
    for(i=0;i<numberOfNodes;i++)
    {
       maximumIndependentSet[i]=0;
    }
    int misCounter=0;
    for(i=0;i<numberOfNodes;i++)
    {
      minimum=0;
      isMinimum=true;
      NODE* temp=parentNodes[i];
      if(getListSize(temp)>0)
     {
      minimum=parentNodes[i]->id;
      temp=temp->next;
      while(temp!=NULL)
      {
        if(((temp->id)<minimum) && !(temp->isColored))
        {
	   isMinimum=false;
           break;
	}
        temp=temp->next;
      }
      if(isMinimum && (getListSize(parentNodes[i])>0))
      {
        maximumIndependentSet[misCounter]=minimum;
        flagNode(parentNodes[i],minimum);
        misCounter++;	
      }
     }	
    }
   // printf("\n");
    /*printing local mis*/
    colorCounter++;
   // if(rank==0)
   // printf("Color Counter = %d",colorCounter);
    for(i=0;i<numberOfNodes;i++)
    {
      if(maximumIndependentSet[i]!=0)
      { 
      // printf("\n{%d, }",maximumIndependentSet[i]);
       sendNodeBuffer[maximumIndependentSet[i]-1]=1;
       /*getting the neighbors*/
      /* NODE * head=getHead(maximumIndependentSet[i],parentNodes,numberOfNodes);
       int neighbors[numberOfNodes-1];
       int k=0;
       for(k=0;k<numberOfNodes-1;k++)
       neighbors[k]=0;
       
       NODE *temp=head;
       temp=temp->next;
       while(temp!=NULL)
       {
         neighbors[k]=temp->id;
         k++;
         temp=temp->next;
        // printf("\nNeighbor %d",neighbors[k]);
       }
       for(k=0;k<numberOfNodes-1;k++)
       printf("Neighbors %d\n",neighbors[k]);*/
      /* bool tempFlag=true;
       int color=0;
       for(k=0;k<numberOfNodes;k++)
       {
         for(j=0;j<numberOfNodes-1;j++)
         {
            if((sendColorBuffer[neighbors[j]-1]) !=0)
            {
              if(sendColorBuffer[neighbors[j]]-1)
              continue;
              else
              {
                color=sendColorBuffer[j];
                tempFlag=false;
                break;
              }
            }
         }
         if(tempFlag) 
          break;
       }*/
        
       sendColorBuffer[maximumIndependentSet[i]-1]=colorCounter; 
      }    
     
    }
      /* for(i=0;i<numberOfNodes;i++)
       {
      printf("\na[%d] = %d ",i,sendNodeBuffer[i]);
       }*/
  
    /*Gathering and Broadcasting*/
   
    MPI_Gather(&sendNodeBuffer,numberOfNodes, MPI_INT,&receiveNodeBuffer, numberOfNodes, MPI_INT,0, MPI_COMM_WORLD);
    MPI_Gather(&sendColorBuffer,numberOfNodes, MPI_INT,&receiveColorBuffer, numberOfNodes, MPI_INT,0, MPI_COMM_WORLD);


    
 
    if(rank==0)
    {
       /*  for(i=0;i<numberOfNodes*size;i++)
       {
      printf("\na[%d] = %d ",i%9,receiveNodeBuffer[i]);
       }*/

       j=0;
       for(i=0;i<(numberOfNodes*size);i++)
       {
         if(receiveNodeBuffer[i]==1)
         {
            j=(i%numberOfNodes);
            sendNodeBuffer[j]=receiveNodeBuffer[i];
         }
       }  
       j==0;
       for(i=0;i<(numberOfNodes*size);i++)
       {
         if(receiveNodeBuffer[i]==1)
         {
           j=(i%numberOfNodes);
           sendColorBuffer[j]=receiveColorBuffer[i];
         }
       }
     }



    MPI_Bcast(sendNodeBuffer,numberOfNodes, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(sendColorBuffer,numberOfNodes, MPI_INT, 0, MPI_COMM_WORLD);
    
   /* if(rank==1)
    {printf("\nNode Buffer\n");
    for(i=0;i<numberOfNodes;i++)
    {
       printf("a[%d]=%d\n",i,sendNodeBuffer[i]);
    }*/
   /*Finding to flag nodes*/
    int globalMIS[numberOfNodes];
    for(i=0;i<numberOfNodes;i++)
    {
      globalMIS[i]=0;
    } 
    for(i=0;i<numberOfNodes;i++)
    {
      if(sendNodeBuffer[i]==1)
      globalMIS[i]=i+1;
    }

    for(i=0;i<numberOfNodes;i++)
    {
      for(j=0;j<numberOfNodes;j++)
      {
         if(globalMIS[j]!=0)
         flagNode(parentNodes[i],globalMIS[j]);
      }
    }
   /* printf("\nColor Buffer\n");
    for(i=0;i<numberOfNodes;i++)
    {
       printf("a[%d]=%d\n",i,sendColorBuffer[i]);
    }
   */
    isNodeLeft=false;
    for(i=0;i<numberOfNodes;i++)
    {
      
      if(sendNodeBuffer[i]==0)
      {
        isNodeLeft=true;
        break;
      }      
    }
}
    colorCounter=max_array(sendColorBuffer,numberOfNodes);
    if(rank==0)
    printf("\nNo of colors used = %d", colorCounter);
    free(lines[0]);
    free(lines);

    MPI_File_close(&in);

    MPI_Finalize();
    return 0;
}


void addNeighbor(NODE* head, int nodeId)
{
NODE *ptr,*loc;
ptr=(NODE *)malloc(sizeof(NODE));
ptr->id=nodeId;
ptr->next=(NODE *)NULL;
ptr->isColored=false;
loc=head;
while(loc->next!=(NODE *)NULL)
loc=loc->next;
loc->next=ptr;

}


VISITED_NODE_TREE *insert(VISITED_NODE_TREE *tree,int nodeId)
{
  if(tree==NULL)
    {
       tree=(VISITED_NODE_TREE *)malloc(sizeof(VISITED_NODE_TREE));
       tree->left=tree->right=NULL;
       tree->id=nodeId;
     }
else
{
	if(nodeId<tree->id)
	      tree->left=insert(tree->left,nodeId);

	if(nodeId>tree->id)
          tree->right=insert(tree->right,nodeId);
}

return(tree);
}

void createParentNodes(int numberOfNodes, NODE ** parentNodes)
{
	int i=0;
   
	for(i=0; i<numberOfNodes; i++)
	{
                
		NODE *parent= (NODE*) malloc(sizeof(NODE));
		parent->id=i+1;
	       	parent->next=(NODE*) NULL;
                parent->isColored=false;
		parentNodes[i]=parent;
               // printf("\nid -> %d",parentNodes[i]->id);
	}

}

NODE * getHead(int id, NODE ** parentNodes, int noOfNodes)
{
  int i=0;
  NODE *temp;
  for(i=0;i<noOfNodes;i++)
  {
    
    temp=parentNodes[i];
    if(temp->id==id)
    break;
  }
  return temp;
}

int getListSize(NODE* head)
{
 int size=0;
 NODE* temp= (NODE*)malloc(sizeof(NODE));
 temp=head;
 while(temp->next !=NULL)
 {
  size++;
  temp=temp->next;
 }
 return size;
}

void deleteNode(NODE * head, int id)
{
NODE* temp= (NODE *)malloc (sizeof(NODE));
temp=head;
while(temp != NULL)
{
  if(temp->id==id)
  {
    temp=NULL;
    break;
  }
  else
  {
    temp=temp->next;
  }
}
}

void flagNode(NODE * head, int id)
{
NODE* temp= (NODE *)malloc (sizeof(NODE));
temp=head;
while(temp != NULL)
{
  if(temp->id==id)
  {
    temp->isColored=true;
    break;
  }
  else
  {
    temp=temp->next;
  }
}
}
int max_array(int a[], int n)
{
int i,j,r=0;

for(i =0; i< n; i++)
   {
       for(j = 0; j<i; j++)
       {
           if((i != j) && (a[j] == a[i]))
           {
               r++;
               break;
           }
       }
   }
  return(n-r);
} 
