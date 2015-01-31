//writes the data in the file:HARSHIT

#include"stdlib.h"
#include"stdio.h"
#include"iostream.h"
#include"conio.h"

void main()
{
clrscr();
FILE *fp;
char filename[10];
char *msg;
puts("Enter the filename :");
gets(filename);
fflush(stdin);
fp=fopen(filename,"w");
if(fp==NULL)
fprintf(stderr,"Error in opening the file");
else
{
puts("Enter the data to be written to the file :\n");
gets(msg);
fprintf(fp,"%s",msg);
fprintf(stdout,"\nFollowing data is written to the file ----\n%s",msg);
}
fclose(fp);
getch();
}