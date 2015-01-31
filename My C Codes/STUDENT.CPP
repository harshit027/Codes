#include"iostream.h"
#include"conio.h"
#include"stdio.h"
#include"graphics.h"
#include"fstream.h"
#include"iomanip.h"
#include"dos.h"
#include"string.h"

typedef struct date_type
{
unsigned int dd;
unsigned int mm;
unsigned int yyyy;
}dates;

class student_file
{

private:
dates date_of_birth;
dates date_of_entry;
char name[20];
unsigned int code_no;

public:
void get_new_data();
void add_new_student();
void del_student(unsigned int);
void show_data();
void show_student();
void search_student();
}stu;

void student_file::get_new_data()
{
char ch;
cout<<"\nENTER THE NAME OF STUDENT------";
gets(name);
fflush(stdin);
cout<<"\nENTER THE DATE OF BIRTH--------:";
cin>>date_of_birth.dd>>ch>>date_of_birth.mm>>ch>>date_of_birth.yyyy;
cout<<"\nENTER THE DATE OF ENTRY--------:";
cin>>date_of_entry.dd>>ch>>date_of_entry.mm>>ch>>date_of_entry.yyyy;
cout<<"\nENTER THE CODE NUMBER----------:";
cin>>code_no;
}

void student_file::add_new_student()
{
fstream outfile;
char choice='y';
outfile.open("student.dat",ios::app);
while(choice=='y'||choice=='Y')
{
stu.get_new_data();
outfile.write((char*)&stu,sizeof(stu));
cout<<"\nANY MORE STUDENT TO BE ADDED--<<Y/N>>?----:";
cin>>choice;
}
}

void student_file::show_data()
{
cout<<"\nNAME          : "<<name;
cout<<"\nCODE NUMBER   : "<<code_no;
cout<<"\nDATE OF ENTRY : "<<date_of_entry.dd<<"-"<<date_of_entry.mm<<"-"<<date_of_entry.yyyy;
cout<<"\nDATE OF ENTRY : "<<date_of_birth.dd<<"-"<<date_of_birth.mm<<"-"<<date_of_birth.yyyy;
}


void student_file::show_student()
{
clrscr();
fstream infile;
infile.open("student.dat",ios::in);
infile.seekg(0,ios::beg);
cout<<"\n------------STUDENT DETAILS---------------";
cout<<"\n------------------------------------------";
infile.read((char*)&stu,sizeof(stu));
while(!infile.eof())
{
stu.show_data();
infile.read((char*)&stu,sizeof(stu));
cout<<"\n------------------------------------------";
}
}

void student_file::del_student(unsigned int code)
 {
 fstream outfile,infile;
 outfile.open("tempfile.dat",ios::app);
 infile.open("student.dat",ios::in);
  infile.seekg(0,ios::beg);
  infile.read((char*)&stu,sizeof(stu));
  cout<<"\nENTER THE CODE NUMBER OF STUDENT TO BE DELETED :";
  cin>>code;
  while(!infile.eof())
  {
  if(code_no!=code)
  outfile.write((char*)&stu,sizeof(stu));
  infile.read((char*)&stu,sizeof(stu));
  }
  infile.close();
  outfile.close();
   remove("student.dat");
   rename("tempfile.dat","student.dat");
  }


  void student_file::search_student()
   {
     fstream infile;
     int search_choice;
     unsigned long code;
     char nm[20];
     do
     {
      int counter=0;
      clrscr();
      cout<<"\nSTUDENT CODE    |..1..|";
      cout<<"\nSTUDENT NAME    |..2..|";
      cout<<"\nEXIT            |..3..|";
      cout<<"\nENTER YOUR CHOICE NUMBER :";
      cin>>search_choice;
      switch(search_choice)
  {
     case 1:
	     clrscr();
	     cout<<"\nENTER THE STUDENT CODE TO BE SEARCHED :";
	     cin>>code;
	     infile.open("student.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&stu,sizeof(stu));
  while(!infile.eof())
    {
     if(stu.code_no==code)
     {
       counter++;
       stu.show_data();
     }
     infile.read((char*)&stu,sizeof(stu));
     }
     infile.close();
     gotoxy(22,24);
     cout<<"RECORDS FOUND="<<counter;
     getch();
     break;

 case 2:
	     clrscr();
	     cout<<"\nENTER THE STUDENT NAME TO BE SEARCHED :";
	     gets(nm);
	     infile.open("student.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&stu,sizeof(stu));
  while(!infile.eof())
    {
     if(strcmpi(stu.name,nm)==0)
     {
       counter++;
       stu.show_data();
     }
     infile.read((char*)&stu,sizeof(stu));
     }
     infile.close();
     gotoxy(22,24);
     cout<<"RECORDS FOUND="<<counter;
     getch();
     break;

 case 3:
	delay(100);
	break;
    }
  }
    while(search_choice!=3);
    }

    void boundryfill(int x,int y,int fillcolor,int bcolor)
     {
		delay(2);

		int present=getpixel(x,y);
		if(present!=bcolor && present!=fillcolor)
	       {
			putpixel(x,y,fillcolor);

			boundryfill(x-1,y,4,15);
			boundryfill(x,y+1,4,15);
			boundryfill(x,y-1,4,15);
				boundryfill(x+1,y,4,15);
	       }

     }


void graphics_screen()
{
int driver =DETECT,mode;
initgraph(&driver,&mode,"");
setbkcolor(1);

settextstyle(2,0,8);
outtextxy(50,100,"---STUDENT DATA ENTRY---");
line(50,130,410,130);
delay(3000);

settextstyle(2,0,5);
outtextxy(250,200,"LOADING...");
setcolor(15);
rectangle(250,250,350,260);
boundryfill(251,259,4,15);
setcolor(4);
outtextxy(20,400,"Press enter to continue :");
getch();
closegraph();
}


void menu()
{
int driver=0,mode;
initgraph(&driver,&mode,"");
clrscr();
unsigned int code;
int i;char choice;
setbkcolor(1);
puts("============================MENU=========================");
puts("\nADD NEW STUDENT--------------|--1--|");
puts("\nSHOW STUDENT FILE------------|--2--|");
puts("\nDELETE STUDENT---------------|--3--|");
puts("\nSEARCH STUDENT---------------|--4--|");
puts("\nEXIT-------------------------|--5--|");
puts("\n=========================================================\n");
puts("\n\nENTER A CHOICE FROM THE MENU (1-5) : ");
scanf("%d",&i);
fflush(stdin);
switch(i)
{
case 1: stu.add_new_student();
break;
case 2: stu.show_student();
break;
case 3: stu.del_student(code);
break;
case 4: stu.search_student();
break;

case 5:puts("\n! ! THANK YOU ! !");
return;
}
puts("\nRETURN TO PREVIOUS MENU (Y/N) :");
cin>>choice;
if(choice=='y'||choice=='Y')
menu();
if(choice=='n'||choice=='N')
{
puts("\n! !THANK YOU ! !");
return;
}
getch();
closegraph();
}

void main()
{
clrscr();
graphics_screen();
menu();
getch();

}