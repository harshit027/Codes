#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"ctype.h"

#define size 50

typedef struct stack
{
char list[size];
int top;
}s;

int first;
/*----------------------------------------------------------- */
/*checks the precedence of the oprerator*/
int precedence(char a)
{
if(a=='^')
return 3;
else
{
if(a=='*'||a=='/')
return 2;
else
{
if(a=='+'||a=='-')
return 1;
else return 0;
}}
}
/*-------------------------------------------------------------*/
/*sets top of the stack*/
void settop(s *p)
{
p->top=-1;
}
/*--------------------------------------------------------------*/
/*checks if the stack is empty or not */
int empty(s *p)
{
if(p->top==-1)
return 1;
else
return 0;
}
/*---------------------------------------------------------*/
/*pushes a value in the stack */
void push(s *p,char t[])
{
int j=0;
while(t[j]!='\0')
{
p->top++;
p->list[p->top]=t[0];
first=p->top;
j++;
}}
/*-------------------------------------------------------------------*/
/*pops a value from the stack*/
char pop(s *p)
{
char x;
if(empty(p)==1)
{
puts("\nstack is empty now :");
return 0;
}
x=p->list[p->top];
p->top--;
first=p->top;
return x;
}
/*-----------------------------------------------------------*/
/*gives the topmost value of the stack*/
char gettop(s *p)
{
return(p->list[first]);
}
/*----------------------------------------------------------*/
void intopre(char in[])
{
int i;
char c[1];
char str1[20],str2[20],str3[20],temp[1];
stack s1,s2;
settop(&s1);
settop(&s2);
for(i=0;i<strlen(in);i++)
{
if(isalpha(in[i])!=0 || isdigit (in[i])!=0)
{
temp[0]=in[i];
push(&s1,temp);
}
else if(in[i]==')')
{
temp[0]='(';
while(1)
{
c[0]=pop(&s2);
strcpy(str1,c);
if(strcmp(str1,temp)==0)
break;
else
c[0]=pop(&s1);
strcpy(str2,c);
c[0]=pop(&s1);
strcpy(str3,c);
strcat(str3,str2);
strcat(str1,str3);
push(&s1,str1);
}}
else
{
while(!empty(&s2) && in[i]!='(' && gettop(&s2)!='(' && precedence(in[i])<=precedence(gettop(&s2)))
{
c[0]=pop(&s2);
strcpy(str1,c);
c[0]=pop(&s1);
strcpy(str2,c);
c[0]=pop(&s1);
strcpy(str3,c);
strcat(str3,str2);
strcat(str1,str3);
push(&s1,str1);
}
temp[0]=in[i];
push(&s2,temp);
}
while(!empty(&s2))
{
c[0]=pop(&s2);
strcpy(str1,c);
c[0]=pop(&s1);
strcpy(str2,c);
c[0]=pop(&s1);
strcpy(str3,c);
strcat(str3,str2);
strcat(str1,str3);
push(&s1,str1);
}
printf("\nthe prefix expression is = %s",str1);
}}
void main()
{
char infix[25];
clrscr();
puts("\nenter the infix exp :");
scanf("%s",infix);
intopre(infix);
getch();
}