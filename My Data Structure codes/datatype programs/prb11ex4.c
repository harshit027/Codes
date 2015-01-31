#include<stdio.h>
#include<conio.h>
void main()
{
auto int i=100;
printf("i=%d\n",i);
{
int i=1;
printf("i=%d\n",i);
{
i+=1;
printf("i=%d\n",i);
}
printf("i=%d\n",i);
}
printf("i=%d\n",i);
}
