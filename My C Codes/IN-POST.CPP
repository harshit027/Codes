#include"stdio.h"
#include"conio.h"
#include"string.h"

char stack[25];
int top=-1;

void push(char symbol)
{
if(top>=24)
{
puts("\nstack is full now :");
return ;
}
else
{
top++;
stack[top]=symbol;
}}

char pop()
{
char item;
if(top==-1)
{
puts("\nstack is empty now :");
return 0;
}
else
{
item=stack[top];
top--;
}
return (item);
}


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

void intopost(char infix[])
{
int length;
int index=0,pos=0;
char symbol,temp;
char postfix[40];
length=strlen(infix) ;
push('1');
while(index<length)
{
symbol=infix[index];
switch(symbol)
{
case '(' : push(symbol);
break;
case ')' : temp=pop();
while(temp!='(')
{
postfix[pos]=temp;
pos++;
temp=pop();
}
break;
case'+':
case'-':
case'*':
case'/':
case'^':
while(precedence(stack[top])>=precedence(symbol))
{
temp=pop();
postfix[pos]=temp;
pos++;
}
push(symbol);
break;
default : postfix[pos++]=symbol;
break;
}
index++;
}
while(top>0)
{
temp=pop();
postfix[pos++]=temp;
}
postfix[pos++]='\0';
puts("\nthe postfix expression is =\n");
puts(postfix);
return;
}
void main()
{
clrscr();
char infix[40];
puts("\nenter the infix expression :");
gets(infix);
intopost(infix);
getch();
}