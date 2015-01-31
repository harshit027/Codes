//reads the data from the file :HARSHIT

#include"stdlib.h"
#include"conio.h"
#include"stdio.h"

void main()
{
clrscr();
FILE *fp;
char filename[20];
char *msg;
puts("Enter the filename to be read :");
gets(filename);
fflush(stdin);
fp=fopen(filename,"r");
if(fp==NULL)
fprintf(stderr,"Error in opening the file");
else
{
fgets(msg,100,fp);
fprintf(stdout,"%s",msg);
}
fclose(fp);
getch();
}
