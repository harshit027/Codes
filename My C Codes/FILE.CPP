/*handling the file system using functions : HARSHIT*/

#include"stdlib.h"
#include"conio.h"
#include"stdio.h"
#include"iostream.h"

#define size 10
#define buffer 100

void FOPEN()
{
FILE *fp;
char filename[40],mode[10];
char choice;

printf("\nenter a file name :");
gets(filename);
fflush(stdin);
printf("\nenter the mode (max 3 characters) :");
gets(mode);
fflush(stdin);

if((fp=fopen(filename,mode)) !=NULL)
{
printf("\nthe file %s is successfully opened in %s mode :",filename,mode);
fclose(fp);
}
else
{
fprintf(stderr,"\nerror occured in opening the file %s in mode %s :",filename,mode);
return;
}
}
void FPRINTF()
{
FILE *fp;
char filename[50],mode[10];
float array[10];
int i;
puts("\nenter any five numbers ");
for(i=0;i<5;i++)
cin>>array[i];
fflush(stdin);
puts("\nenter the name of the file :");
gets(filename);
puts("\nenter the mode  (max 3 characters) :");
gets(mode);
fp=fopen(filename,mode);
if(fp==NULL)
{
fprintf(stderr,"\nerror in opening the file %s",filename);
exit(1);
}
else
{
puts("\nthe following data is written if the file u opened :");
for(i=0;i<5;i++)
{
fprintf(fp,"\ndata[%d] = %f",i,array[i]);
fprintf(stdout,"\ndata[%d] = %f",i,array[i]);
}}
fclose(fp);
}

void FSCANF()
{
FILE *fp;
float f1,f2,f3;
char filename[50],mode[10];
puts("\nenter the filename :");
gets(filename);
puts("\nenter the mode (max 3 characters):");
gets(mode);
fp=fopen(filename,mode);
if(fp==NULL)
{
fprintf(stderr,"\nerror in opening the file %s in %s mode",filename,mode);
exit(1);
}
fscanf(fp,"%f%f%f",&f1,&f2,&f3);
printf("\n%f\n%f\n%f",f1,f2,f3);
fclose(fp);
}


void DIRECT()
{
int a1[size],a2[size];
FILE *fp;
char filename[50],mode[5];
puts("\nenter  the elements of array a1 :");
for(int i=0;i<size;i++)
scanf("%d",&a1[i]);
fflush(stdin);
puts("\nwriting into the file :");
puts("\nenter the file name :");
gets(filename);
puts("\nenter the mode (max 3 characters ) :");
gets(mode);
fp=fopen(filename,mode);
if(fp==NULL)
{
fprintf(stderr,"\nerror in opening the file %s:",filename);
exit(1);
}
/*saving the array a1 in the file */

if(fwrite(a1,sizeof(int),size,fp)!=size)
{
fprintf(stderr,"\nerror writing in the file :");
exit(1);
}
fclose(fp);
puts("\nreading from the file :");
puts("\nenter the file name :");
gets(filename);
puts("\nenter the mode (max 3 characters ):");
gets(mode);
fp=fopen(filename,mode);
 if (fp==NULL)
 {
 fprintf(stderr,"\nerror in opening the file %s in %s mode",filename,mode);
 exit(1);
 }

/*reading from the file */
if(fread(a2,sizeof(int),size,fp)!=size)
{
fprintf(stderr,"\nerror reading from the file :");
exit(1);
}
fclose(fp);

for(i=0;i<size;i++)
printf("\n%d\t%d",a1[i],a2[i]);
}

void RANDOM_ACCESS()
{
char msg[]="abcdefghijklmnopqrstuvwxyz";
FILE *fp;
char buf[buffer];
char filename[20], mode[10];

/*opening and writing to file */

puts("\nwriting in the file :");
puts("\nenter the file name :");
gets(filename);
fflush(fp);
puts("\nenter the mode (max 3 characters):");
gets(mode);
fflush(fp);
fp=fopen(filename,mode);
if(fp==NULL)
{
fprintf(stderr,"\nerror in opening the file %s",filename);
exit(1);
}

if(fputs(msg,fp)==EOF)
{
fprintf(stderr,"\nerror in writing in file %s",filename);
exit(1);
}
fclose(fp);
/*reading the file*/
puts("\nreading the file :");
puts("\nenter the filename :");
gets(filename);
fflush(fp);
puts("\nenter the mode(max 3 characters) :");
gets(mode);
fflush(fp);
fp=fopen(filename,mode);

if(fp==NULL);
{
fprintf(stderr,"\nerror in opening the file %s",filename);
exit(1);
}
printf("\nbefore reading the file ,the position is at %ld :",ftell(fp));

fgets(buf,buffer,fp);
printf("\nafter reading the first 5 characters %s the position is at %ld",buf,ftell(fp));
fgets(buf,buffer,fp);
printf("\nafter reading the next 5 characters %s the position is at %ld",buf,ftell(fp));
rewind(fp);
printf("\nafter rewinding the position indicator is at %ld",ftell(fp));
printf("\nreading starts from start again %s :",buf);
fclose(fp);
}

void F_EOF()
{

char buf[buffer];
char filename[50],mode[10];
FILE *fp;
puts("\nenter the file name :");
gets(filename);
puts("\nenter the mode (max 3 characters) :");
gets(mode);
fp=fopen(filename,mode);

if(fp==NULL)
{
fprintf(stderr,"\nerror opening the file %s:",filename);
exit(1);
}
while(!feof(fp))
{
fgets(buf,buffer,fp);
printf("\n%s",buf);
}
fclose(fp);
}

void main()
{
clrscr();
FPRINTF();
getch();
}