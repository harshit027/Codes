#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"

static int Comparator(const void *i, const void *j)
{
	if ((*(int *)i) > (*(int *)j))
		return (1);
	if ((*(int *)i) < (*(int *)j))
		return (-1);
	return (0);
}
main (int argc, char ** argv)
{

	int NoOfProcesses,MyRank, Root = 0;
	int i,j,k, NoofElements, NoOfElementsPerProcess,
	NoElementsToSort;
	int count, temp;
	long *Input, *InputData;
	long *Splitter, *AllSplitter;
	long *Buckets, *BucketBuffer, *LocalBucket;
	long *OutputBuffer, *Output;
	FILE *InputFile, *fp;
	MPI_Status status;
	MPI_File filePointer;
        
	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &NoOfProcesses);
	MPI_Comm_rank(MPI_COMM_WORLD, &MyRank);

        if (MyRank == Root){
                NoofElements=1000;	
		Input = (long *) malloc (NoofElements*sizeof(long));
		if(Input == NULL) {
			printf("Error : Can not allocate memory \n");
		}
		/* Initialise random number generator */
		/*printf ( "Input Array for Sorting \n\n ");
		srand48((unsigned int)NoofElements);
		for(i=0; i< NoofElements; i++) {
			Input[i] = rand()%100;
			printf ("%d ",Input[i]);
		}*/
	}
	printf ( "\n\n ");
	/**** Sending Data ****/
	MPI_Bcast (&NoofElements, 1, MPI_LONG, 0, MPI_COMM_WORLD);
	/*if(( NoofElements % NoOfProcesses) != 0){
		if(MyRank == Root)
			printf("Number of Elements are not divisible by NoOfProcesses \n");
		MPI_Finalize();
		exit(0);
	}*/
	NoOfElementsPerProcess = NoofElements / NoOfProcesses;
	InputData = (long *) malloc (NoOfElementsPerProcess * sizeof(long));

	/*Reading parallely */
	 int readBufferSize=0;
	 readBufferSize = NoOfElementsPerProcess * sizeof(long);
	 MPI_File_open(MPI_COMM_WORLD,"/uufs/chpc.utah.edu/common/home/ci-water4-0/CS6965/data/sort_data.dat",MPI_MODE_RDONLY,MPI_INFO_NULL,&filePointer);
	 MPI_File_read_at(filePointer, MyRank*readBufferSize, InputData, NoOfElementsPerProcess, MPI_LONG, &status);
	 
         printf("\n%d received: ", MyRank);
         for(i=0; i< NoOfElementsPerProcess; i++)
         {
          printf("%f,",InputData[i]);
         }
         printf("\n");  
         MPI_File_close(&filePointer);

	/*Scattering over processes*/
	/*MPI_Scatter(Input, NoOfElementsPerProcess, MPI_INT, InputData, NoOfElementsPerProcess, MPI_INT, Root, MPI_COMM_WORLD);*/
	/**** Sorting Locally ****/
	qsort ((char *) InputData, NoOfElementsPerProcess, sizeof(long), Comparator);
	/**** Choosing Local Splitters ****/
	Splitter = (long *) malloc (sizeof (long) * (NoOfProcesses-1));
	for (i=0; i< (NoOfProcesses-1); i++){
		Splitter[i] = InputData[NoofElements/(NoOfProcesses*NoOfProcesses) * (i+1)];
	}
	/**** Gathering Local Splitters at Root ****/
	AllSplitter = (long *) malloc (sizeof (long) * NoOfProcesses * (NoOfProcesses-1));
	MPI_Gather (Splitter, NoOfProcesses-1, MPI_LONG, AllSplitter, NoOfProcesses-1,
			MPI_LONG, Root, MPI_COMM_WORLD);
	/**** Choosing Global Splitters ****/
	if (MyRank == Root){
		qsort ((char *) AllSplitter, NoOfProcesses*(NoOfProcesses-1), sizeof(long), Comparator);
		for (i=0; i<NoOfProcesses-1; i++)
			Splitter[i] = AllSplitter[(NoOfProcesses-1)*(i+1)];
	}
	/**** Broadcasting Global Splitters ****/
	MPI_Bcast (Splitter, NoOfProcesses-1, MPI_LONG, 0, MPI_COMM_WORLD);
	/**** Creating NoOfProcesses Buckets locally ****/
	Buckets = (long *) malloc (sizeof (long) * (NoofElements + NoOfProcesses));
	j = 0;
	k = 1;
	for (i=0; i<NoOfElementsPerProcess; i++){
		if(j < (NoOfProcesses-1)){
			if (InputData[i] < Splitter[j])
				Buckets[((NoOfElementsPerProcess + 1) * j) + k++] = InputData[i];
			else{
				Buckets[(NoOfElementsPerProcess + 1) * j] = k-1;
				k=1;
				j++;
				i--;
			}
		}
		else
			Buckets[((NoOfElementsPerProcess + 1) * j) + k++] = InputData[i];
	}
	Buckets[(NoOfElementsPerProcess + 1) * j] = k - 1;
	/**** Sending buckets to respective processors ****/
	BucketBuffer = (long *) malloc (sizeof (long) * (NoofElements + NoOfProcesses));
	MPI_Alltoall (Buckets, NoOfElementsPerProcess + 1, MPI_LONG, BucketBuffer,
			NoOfElementsPerProcess + 1, MPI_LONG, MPI_COMM_WORLD);
	/**** Rearranging BucketBuffer ****/
	LocalBucket = (long *) malloc (sizeof (long) * 2 * NoofElements / NoOfProcesses);
	count = 1;
	for (j=0; j<NoOfProcesses; j++) {
		k = 1;
		for (i=0; i<BucketBuffer[(NoofElements/NoOfProcesses + 1) * j]; i++)
			LocalBucket[count++] = BucketBuffer[(NoofElements/NoOfProcesses + 1) * j + k++];
	}
	LocalBucket[0] = count-1;

	NoElementsToSort = LocalBucket[0];
	qsort ((char *) &LocalBucket[1], NoElementsToSort, sizeof(long), Comparator);

	if(MyRank == Root) {
		OutputBuffer = (long *) malloc (sizeof(long) * 2 * NoofElements);
		Output = (long *) malloc (sizeof (long) * NoofElements);
	}

        long *WriteBuffer=(long *) malloc(sizeof(long) * 2 * (NoOfElementsPerProcess-1));
        for(i=0;i<(2*NoOfElementsPerProcess);i++)
        WriteBuffer[i]=LocalBucket[i+1];

	/*Writing output  parallely*/
	int offset;
	offset = MyRank*(NoofElements/NoOfProcesses)*sizeof(long);
	MPI_File_open(MPI_COMM_WORLD, "OutputFile.out", MPI_MODE_CREATE|MPI_MODE_WRONLY, MPI_INFO_NULL, &filePointer);
	printf("\nRank: %d, Offset: %d\n", MyRank, offset);
	MPI_File_set_view(filePointer, offset, MPI_LONG, MPI_LONG, "native", MPI_INFO_NULL);
	MPI_File_write(filePointer, WriteBuffer, (NoofElements/NoOfProcesses), MPI_LONG, &status);
	MPI_File_close(&filePointer);

	/*Gathering sub blocks at the root*/
	MPI_Gather (LocalBucket, 2*NoOfElementsPerProcess, MPI_LONG, OutputBuffer,2*NoOfElementsPerProcess, MPI_LONG, Root, MPI_COMM_WORLD);
	/**** Rearranging output buffer ****/
	if (MyRank == Root){
		count = 0;
		for(j=0; j<NoOfProcesses; j++){
			k = 1;
			for(i=0; i<OutputBuffer[(2 * NoofElements/NoOfProcesses) * j]; i++)
				Output[count++] = OutputBuffer[(2*NoofElements/NoOfProcesses) * j + k++];
		}
		/**** Printng the output ****/
		if ((fp = fopen("sort.out", "w")) == NULL){
			printf("Can't Open Output File \n");
			exit(0);
		}
		fprintf (fp, "Number of Elements to be sorted : %d \n", NoofElements);
		printf ( "Number of Elements to be sorted : %d \n", NoofElements);
		fprintf (fp, "The sorted sequence is : \n");
		printf( "Sorted output sequence is\n\n");
		for (i=0; i<NoofElements; i++){
			fprintf(fp, "%d\n", Output[i]);
			printf( "%d ", Output[i]);
		}
		printf ( " \n " );
		fclose(fp);
		free(Input);
		free(OutputBuffer);
		free(Output);
	}
	free(InputData);
	free(Splitter);
	free(AllSplitter);
	free(Buckets);
	free(BucketBuffer);
	free(LocalBucket);

	MPI_Finalize();
}

