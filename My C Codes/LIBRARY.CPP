		 /**********************************/
		 /******* LIBRARY MANAGEMENT *******/
		 /**********************************/

#include"iostream.h"
#include"conio.h"
#include"stdio.h"
#include"dos.h"
#include"fstream.h"
#include"graphics.h"
#include"string.h"
#include"time.h"
#include"process.h"


/**********************************************/
/*****************BOOK RECORD******************/
/**********************************************/

class Book
{
protected:
unsigned int book_isbn;
char book_status;

private:
char book_name[20];
char book_author[20];
float book_price;

public:
void getNewBook();
void showBook();
void addNewBook();
void showBookFile();
void delBook(unsigned int);
void searchBook();
void modifyBook();
}buk;


void Book::getNewBook()
{
cout<<"\nENTER THE NAME OF BOOK-------:";
gets(book_name);
cout<<"\nENTER THE AUTHOR NAME--------:";
gets(book_author);
cout<<"\nENTER THE BOOK PRICE---------:";
cin>>book_price;
cout<<"\nENTER THE BOOK ISBN----------:";
cin>>book_isbn;
book_status='R';
}

void Book::showBook()
{
cout<<"\n-------------BOOK DETAILS--------------";
cout<<"\n---------------------------------------";
cout<<"\nBOOK NAME--------->"<<book_name;
cout<<"\nBOOK AUTHOR------->"<<book_author;
cout<<"\nBOOK PRICE-------->"<<book_price;
cout<<"\nBOOK ISBN--------->"<<book_isbn;
cout<<"\nBOOK STATUS------->"<<book_status;
cout<<"\n---------------------------------------";
}

void Book::showBookFile()
{
clrscr();
fstream infile;
unsigned int counter=0;
infile.open("bookfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&buk,sizeof(buk));
while(!infile.eof())
{
counter++;
buk.showBook();
infile.read((char*)&buk,sizeof(buk));
}
cout<<"\nNUMBER OF BOOKS------->"<<counter;
infile.close();
}

void Book::addNewBook()
{
clrscr();
char ch;
fstream outfile;
outfile.open("bookfile.dat",ios::app);
buk.getNewBook();
outfile.write((char*)&buk,sizeof(buk));

outfile.close();
cout<<"\nANY MORE BOOKS YOU WANT TO ADD <Y / N> :";
cin>>ch;
if(ch=='y'||ch=='Y')
buk.addNewBook();
else
return;
}

void Book::delBook(unsigned int isbn)
{
clrscr();
fstream outfile,infile;
outfile.open("temp.dat",ios::app);
infile.open("bookfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&buk,sizeof(buk));
cout<<"\nENTER THE ISBN NUMBER OF BOOK TO BE DELETED :";
cin>>isbn;
while(!infile.eof())
{
if(book_isbn!=isbn)
outfile.write((char*)&buk,sizeof(buk));
infile.read((char*)&buk,sizeof(buk));
}
infile.close();
outfile.close();
remove("bookfile.dat");
rename("temp.dat","bookfile.dat");
cout<<"\nTHE BOOK ENTRY IS DELETED !";
delay(2000);
}

void Book::searchBook()
{
clrscr();
int counter=0;
unsigned int isbn;
char name[20];
unsigned short choice;
fstream infile;
cout<<"\nSEARCH BY AUTHOR NAME-----------|--1--|";
cout<<"\nSEARCH BY BOOK ISBN-------------|--2--|";
cout<<"\nRETURN TO PREVIOUS MENU---------|--3--|";
cout<<"\n---------------------------------------";
cout<<"\n\nENTER YOUR CHOICE------------:";
cin>>choice;
switch(choice)
{
case 1:
clrscr();
cout<<"\nENTER THE AUTHOR NAME TO BE SEARCHED :";
gets(name);
infile.open("bookfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&buk,sizeof(buk));
while(!infile.eof())
{
if(strcmpi(book_author,name)==0)
{
counter++;
buk.showBook();
}
infile.read((char*)&buk,sizeof(buk));
}
infile.close();

cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 2:
clrscr();
cout<<"\nENTER THE BOOK ISBN TO BE SEARCHED----:";
cin>>isbn;
infile.open("bookfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&buk,sizeof(buk));
while(!infile.eof())
{
if(book_isbn==isbn)
{
buk.showBook();
counter++;
}
infile.read((char*)&buk,sizeof(buk));
}
cout<<"\n\nRECORDS FOUND = "<<counter;
break;

case 3:
return;
}
}

void Book::modifyBook()
 {
fstream file;
int mod_choice;
unsigned long isbn;
do
{
clrscr();
cout<<"\n----------------MODIFY BOOK----------------";
cout<<"\n-------------------------------------------";
cout<<"\nCHANGE BOOK NAME-----------|...1...|";
cout<<"\nCHANGE AUTHOR NAME---------|...2...|";
cout<<"\nCHANGE BOOK PRICE----------|...3...|";
cout<<"\nCHANGE BOOK STATUS---------|...4...|";
cout<<"\nEXIT MODIFY MENU-----------|...5...|";
cout<<"\n--------------------------------------------";
cout<<"\n\nENTER YOUR CHOICE NO.-----------:";
cin>>mod_choice;
if(mod_choice!=5)
{
cout<<"\nENTER THE BOOK ISBN--------:";
cin>>isbn;
file.open("bookfile.dat",ios::in|ios::out);
file.seekg(0,ios::beg);
file.read((char*)&buk,sizeof(buk));
int n=file.tellg();
while(!file.eof())
{
if(isbn==book_isbn)
{
switch(mod_choice)
{
    case 1:
	     clrscr();
	     cout<<"\nENTER THE NEW BOOK NAME--------:";
	     gets(book_name);
	     file.seekg(n-sizeof(buk));
	     file.write((char*)&buk,sizeof(buk));
	     file.flush();
	     break;
    case 2:
	     cout<<"\nENTER THE NEW AUTHOR NAME------:";
	     gets(book_author);
	     file.seekg(n-sizeof(buk));
	     file.write((char*)&buk,sizeof(buk));
	     file.flush();
	     break;
     case 3:
	     clrscr();
	     cout<<"\nENTER THE NEW PRICE---------:";
	     cout<<book_price;
	     file.seekg(n-sizeof(buk));
	     file.write((char*)&buk,sizeof(buk));
	     file.flush();
	     break;

     case 4:
	     clrscr();
	     if(book_status=='I'||book_status=='i')
	     book_status='R';
	     else
	     book_status='I';
	     file.seekg(n-sizeof(buk));
	     file.write((char*)&buk,sizeof(buk));
	     file.flush();
	     cout<<"\nBOOK STATUS CHANGED !";
	     delay(2000);
	     break;
	  }
	}
file.read((char*)&buk,sizeof(buk));
n=file.tellg();
}
file.close();
}
}
while(mod_choice!=5);
cout<<"\n\nMODIFICATION DONE !";
delay(2000);
}


/************************************************************/
/*************************FEES RECORD************************/
/************************************************************/

class Fees
{
private:
float caution_fee;
float monthly_fee;
float due_date_fee;
public:
void getFeeStruct();
void createFeeFile();
void showFeeStruct();
void viewFeeFile();
}fee;

void Fees::getFeeStruct()
{
caution_fee=400;
monthly_fee=150;
due_date_fee=5;
}

void Fees::showFeeStruct()
{
cout<<"\n----------FEE STRUCTURE-------------";
cout<<"\n------------------------------------";
cout<<"\nCAUTION FEE------->"<<caution_fee<<" Rs ";
cout<<"\nMONTHLY FEE------->"<<monthly_fee<<" Rs ";
cout<<"\nDUE DATE FEE------>"<<due_date_fee<<" Rs per day";
cout<<"\n------------------------------------";
}

void Fees::createFeeFile()
{
fstream outfile;
outfile.open("feefile.dat",ios::app);
fee.getFeeStruct();
outfile.write((char*)&fee,sizeof(fee));
outfile.close();
}

void Fees::viewFeeFile()
{
clrscr();
fstream infile;
infile.open("feefile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&fee,sizeof(fee));
fee.showFeeStruct();
infile.close();
}

/**********************************************************/
/***********************MEMBER RECORD**********************/
/**********************************************************/

class Member
{
protected:
unsigned int mem_id;
char fee_status;
char issued_book;

private:
char mem_name[20];
char mem_add[50];
unsigned int day,mon,year;
char phone_no[15];


public:
void getNewMem();
void showMem();
void addNewMem();
void showMemFile();
void delMem(unsigned int);
void searchMem();
void modifyMem();
void showFeeRec();
void checkMemFee(unsigned int);
}mem;



void Member::getNewMem()
{
time_t currenttime;
time(&currenttime);
tm *ptm=localtime(&currenttime);
day=ptm->tm_mday;
mon=ptm->tm_mon+1;
year=ptm->tm_year+1900;

cout<<"\nENTER THE NAME OF MEMBER------:";
gets(mem_name);
cout<<"\nENTER THE PHONE NUMBER--------:";
gets(phone_no);
cout<<"\nENTER THE MEMBER ID-----------:";
cin>>mem_id;
cout<<"\nENTER THE ADDRESS-------------:";
gets(mem_add);
fee_status='P';
issued_book='N';
}

void Member::showMem()
{
cout<<"\n------------MEMBER DETAILS------------";
cout<<"\n--------------------------------------";
cout<<"\nMEMBER NAME--------->"<<mem_name;
cout<<"\nCONTACT NUMBER------>"<<phone_no;
cout<<"\nMEMBER ADDRESS------>"<<mem_add;
cout<<"\nMEMBER ID----------->"<<mem_id;
cout<<"\nDATE OF ENTRY------->"<<day<<"-"<<mon<<"-"<<year;
cout<<"\nIS BOOK ISSUED------>"<<issued_book;
cout<<"\n--------------------------------------";
}

void Member::showMemFile()
{
clrscr();
fstream infile;
unsigned int counter=0;

infile.open("memfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&mem,sizeof(mem));
while(!infile.eof())
{
counter++;
mem.showMem();
infile.read((char*)&mem,sizeof(mem));
}
cout<<"\nNUMBER OF MEMBERS------------>"<<counter;
infile.close();
}

void Member::addNewMem()
{
clrscr();
char ch;
fstream outfile;
outfile.open("memfile.dat",ios::app);
mem.getNewMem();
outfile.write((char*)&mem,sizeof(mem));
outfile.close();
cout<<"\nANY MORE MEMBERS YOU WANT TO ADD <Y / N> :";
cin>>ch;
if(ch=='y'||ch=='Y')
mem.addNewMem();
else
return;
}

void Member::delMem(unsigned int id)
{
fstream outfile,infile;
outfile.open("temp.dat",ios::app);
infile.open("memfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&mem,sizeof(mem));
cout<<"\nENTER THE ID OF THE MEMBER TO BE DELETED :";
cin>>id;
while(!infile.eof())
{
if(mem_id!=id)
outfile.write((char*)&mem,sizeof(mem));
infile.read((char*)&mem,sizeof(mem));
}
infile.close();
outfile.close();
remove("memfile.dat");
rename("temp.dat","memfile.dat");
cout<<"\nTHE MEMBER ENTRY IS DELETED !";
delay(2000);
}

void Member::searchMem()
{
clrscr();
int counter=0;
unsigned int id;
char name[20];
unsigned short choice;
fstream infile;
cout<<"\nSEARCH BY MEMBER NAME-----------|--1--|";
cout<<"\nSEARCH BY MEMBER ID-------------|--2--|";
cout<<"\nRETURN TO PREVIOUS MENU---------|--3--|";
cout<<"\n---------------------------------------";
cout<<"\n\nENTER YOUR CHOICE------------:";
cin>>choice;
switch(choice)
{
case 1:
clrscr();
cout<<"\nENTER THE MEMBER NAME TO BE SEARCHED-------:";
gets(name);
infile.open("memfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&mem,sizeof(mem));
while(!infile.eof())
{
if(strcmpi(mem_name,name)==0)
{
counter++;
mem.showMem();
}
infile.read((char*)&mem,sizeof(mem));
}
infile.close();

cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 2:
clrscr();
cout<<"\nENTER THE MEMBER ID TO BE SEARCHED----:";
cin>>id;
infile.open("memfile.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&mem,sizeof(mem));
while(!infile.eof())
{
if(mem_id==id)
{
mem.showMem();
counter++;
}
infile.read((char*)&mem,sizeof(mem));
}
cout<<"\n\nRECORDS FOUND = "<<counter;
break;

case 3:
return;
}
}
void Member::showFeeRec()
{
cout<<"\n-------------MEMBER FEE RECORD--------------";
cout<<"\n--------------------------------------------";
cout<<"\nMEMBER ID----------->"<<mem_id;
cout<<"\nFEE STATUS---------->"<<fee_status;
cout<<"\n--------------------------------------------";
}

void Member::checkMemFee(unsigned int id)
{
clrscr();
fstream infile;
infile.open("memfile.dat",ios::in);
infile.seekg(0,ios::beg);
cout<<"\nENTER THE MEMBER ID------->";
cin>>id;
infile.read((char*)&mem,sizeof(mem));
while(!infile.eof())
{
if(mem_id==id)
mem.showFeeRec();
infile.read((char*)&mem,sizeof(mem));
}
}

void Member::modifyMem()
 {
fstream file;
int mod_choice;
unsigned long id;
do
{
clrscr();
cout<<"\n----------------MODIFY MEMBER--------------";
cout<<"\n-------------------------------------------";
cout<<"\nCHANGE MEMBER NAME------|...1...|";
cout<<"\nCHANGE PHONE NUMBER-----|...2...|";
cout<<"\nCHANGE ADDRESS----------|...3...|";
cout<<"\nCHANGE BOOK POSSESION---|...4...|";
cout<<"\nEXIT MODIFY MENU--------|...5...|";
cout<<"\n--------------------------------------------";
cout<<"\n\nENTER YOUR CHOICE NO.-----------:";
cin>>mod_choice;
if(mod_choice!=5)
{
cout<<"\nENTER THE MEMBER ID TO BE MODIFIED--------:";
cin>>id;
file.open("memfile.dat",ios::in|ios::out);
file.seekg(0,ios::beg);
file.read((char*)&mem,sizeof(mem));
int n=file.tellg();
while(!file.eof())
{
if(id==mem_id)
{
switch(mod_choice)
{
     case 1:
	     clrscr();
	     cout<<"\nENTER THE NEW MEMBER NAME--------:";
	     gets(mem_name);
	     file.seekg(n-sizeof(mem));
	     file.write((char*)&mem,sizeof(mem));
	     file.flush();
	     break;
    case 2:
	     cout<<"\nENTER THE NEW PHONE NUMBER------:";
	     gets(phone_no);
	     file.seekg(n-sizeof(mem));
	     file.write((char*)&mem,sizeof(mem));
	     file.flush();
	     break;
     case 3:
	     clrscr();
	     cout<<"\nENTER THE NEW ADDRRESS---------:";
	     gets(mem_add);
	     file.seekg(n-sizeof(mem));
	     file.write((char*)&mem,sizeof(mem));
	     file.flush();
	     break;

     case 4:
	     clrscr();
	     if(issued_book=='y'||issued_book=='Y')
	     issued_book='N';
	     else
	     issued_book='Y';

	     file.seekg(n-sizeof(mem));
	     file.write((char*)&mem,sizeof(mem));
	     file.flush();
	     cout<<"\nMEMBER POSSESION STATUS CHANGED !";
	     delay(2000);
	     break;

}
}
file.read((char*)&mem,sizeof(mem));
n=file.tellg();
}
file.close();
}
}
while(mod_choice!=5);
cout<<"\n\nMODIFICATION DONE !";
delay(2000);
}

/*************************************************************/
/*********************TRANSACTION RECORD**********************/
/*************************************************************/

class Transaction:public Member,Book
{
private:
unsigned int d,m,y;
unsigned int isbn,id;
unsigned int trans_id;
char *trans_type;

public:
void transType();
void issueBook();
void returnBook();
void viewTrans();
void changeBstatus(unsigned int);
void changeMstatus(unsigned int);
void viewTransFile();
void searchTransRecord();
void changeBookStatus();
}trans;

void Transaction::transType()
{
unsigned int choice;
do
{
clrscr();
cout<<"\n--------------------TRANSACTION-------------------";
cout<<"\n--------------------------------------------------";
cout<<"\nISSUE BOOK----------------|--1--|";
cout<<"\nRETURN BOOK---------------|--2--|";
cout<<"\nRETURN TO PREVIOU MENU----|--3--|";
cout<<"\n--------------------------------------------------";
cout<<"\nENTER CHOICE-------:";
cin>>choice;
switch(choice)
{
case 1:
trans.issueBook();
break;
case 2:
trans.returnBook();
break;
case 3:
return;
}
}while(choice!=3);
}

void Transaction::issueBook()
{
clrscr();

time_t currenttime;
time(&currenttime);
tm *ptm=localtime(&currenttime);
Transaction t;
trans_type="ISSUE";
cout<<"\n----------ISSUE BOOK------------";
cout<<"\n--------------------------------";
cout<<"\nENTER BOOK ISBN---------:";
cin>>isbn;
cout<<"\nENTER MEMBER ID---------:";
cin>>id;
cout<<"\nENTER TRANSACTION ID----:";
cin>>trans_id;
cout<<"\n\n";
delay(2000);
cout<<"\nCHANGE THE BOOK STATUS AND MEMBER STATUS !";
delay(2000);
buk.modifyBook();
mem.modifyMem();

d=ptm->tm_mday;
m=ptm->tm_mon+1;
y=ptm->tm_year+1900;

fstream outfile;
outfile.open("trans.dat",ios::app);
outfile.write((char*)&trans,sizeof(trans));
outfile.close();
cout<<"\nBOOK ISSUED !";
delay(2000);
}

void Transaction::returnBook()
{
clrscr();
time_t currenttime;
time(&currenttime);
tm *ptm=localtime(&currenttime);
Transaction t;
trans_type="RETURN";
cout<<"\n----------RETURN BOOK------------";
cout<<"\n---------------------------------";
cout<<"\nENTER BOOK ISBN--------------:";
cin>>isbn;
cout<<"\nENTER MEMBER ID--------------:";
cin>>id;
cout<<"\nENTER THE TRANSACTION ID-----:";
cin>>trans_id;
cout<<"\n\n";
delay(3000);
cout<<"\nCHANGE THE BOOK STATUS AND MEMBER STATUS !";
delay(2000);
buk.modifyBook();
mem.modifyMem();

d=ptm->tm_mday;
m=ptm->tm_mon+1;
y=ptm->tm_year+1900;

fstream outfile;
outfile.open("trans.dat",ios::app);
outfile.write((char*)&trans,sizeof(trans));
outfile.close();

cout<<"\nBOOK RACKED !";
delay(2000);
}

void Transaction::viewTrans()
{
cout<<"\n-----------TRANSACTION TYPE-------------";
cout<<"\n----------------------------------------";
cout<<"\nTRANSACTION ID------->"<<trans_id;
cout<<"\nTRANSACTION TYPE----->"<<trans_type;
cout<<"\nBOOK ISBN "<<trans_type<<"D----->"<<isbn;
cout<<"\nMEMBER ID------------>"<<id;
cout<<"\nDATE OF "<<trans_type<<"-------->"<<d<<"-"<<m<<"-"<<y;
cout<<"\n----------------------------------------";
}

void Transaction::changeBstatus(unsigned int b)
{
cout<<"\nBOOK STATUS CHANGED !";
fstream file;
file.open("bookfile.dat",ios::in|ios::out);
file.seekg(0,ios::beg);
file.read((char*)&buk,sizeof(buk));
int n=file.tellg();
while(!file.eof())
{
if(b==book_isbn)
{
book_status='I';
file.seekg(n-sizeof(buk));
file.write((char*)&buk,sizeof(buk));

}
}
file.close();
}

void Transaction::changeMstatus(unsigned int m)
{
cout<<"\nMEMBER STATUS CHANGED !";
fstream file;
file.open("memfile.dat",ios::in|ios::out);
file.seekg(0,ios::beg);
file.read((char*)&mem,sizeof(mem));
int n=file.tellg();
while(!file.eof())
{
if(m==mem_id)
{
issued_book='Y';
file.seekg(n-sizeof(mem));
file.write((char*)&mem,sizeof(mem));
}
}
file.close();
}

void Transaction::viewTransFile()
{
clrscr();
fstream infile;
infile.open("trans.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&trans,sizeof(trans));
while(!infile.eof())
{
trans.viewTrans();
infile.read((char*)&trans,sizeof(trans));
}
infile.close();
}

void Transaction ::searchTransRecord()
{
clrscr();
int counter=0;
unsigned int tid,mid,b_isbn;
unsigned int dd,mm;
unsigned short choice;
fstream infile;

cout<<"\n---------SEARCH TRANSACTION MENU------------";
cout<<"\n--------------------------------------------";
cout<<"\nSEARCH BY TRANSACTION ID---------|--1--|";
cout<<"\nSEARCH BY DATE OF TRANSACTION----|--2--|";
cout<<"\nSEARCH BY MEMBER ID--------------|--3--|";
cout<<"\nSEARCH BY BOOK ISBN--------------|--4--|";
cout<<"\nRETURN TO PREVIOUS MENU----------|--5--|";
cout<<"\n--------------------------------------------";
cout<<"\n\nENTER YOUR CHOICE------------:";
cin>>choice;
switch(choice)
{
case 1:
clrscr();
cout<<"\nENTER THE TRANSACTION ID TO BE SEARCHED-------:";
cin>>tid;
infile.open("trans.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&trans,sizeof(trans));
while(!infile.eof())
{
if(tid==trans_id)
{
counter++;
trans.viewTrans();
}
infile.read((char*)&trans,sizeof(trans));
}
infile.close();

cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 2:
clrscr();
cout<<"\nENTER THE DATE OF TRANSACTION TO BE SEARCHED----:";
cout<<"\nDAY <1-31>-----:";
cin>>dd;
cout<<"\nMONTH <1-12>---:";
cin>>mm;
infile.open("trans.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&trans,sizeof(trans));
while(!infile.eof())
{
if(dd==d&&mm==m)
{
trans.viewTrans();
counter++;
}
infile.read((char*)&trans,sizeof(trans));
}
cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 3:
clrscr();
cout<<"\nENTER THE MEMBER ID FOR TRANSACTION TO BE SEARCHED-------:";
cin>>mid;
infile.open("trans.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&trans,sizeof(trans));
while(!infile.eof())
{
if(mid==id)
{
counter++;
trans.viewTrans();
}
infile.read((char*)&trans,sizeof(trans));
}
infile.close();

cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 4:
clrscr();
cout<<"\nENTER THE BOOK ISBN FOR TRANSACTION TO BE SEARCHED-------:";
cin>>tid;
infile.open("trans.dat",ios::in);
infile.seekg(0,ios::beg);
infile.read((char*)&trans,sizeof(trans));
while(!infile.eof())
{
if(isbn==b_isbn)
{
counter++;
trans.viewTrans();
}
infile.read((char*)&trans,sizeof(trans));
}
infile.close();

cout<<"\n\nRECORDS FOUND = "<<counter;
getch();
break;

case 5:
return;
}


}

/*********************************************************/
/*********************GRAPHICS PACKAGE********************/
/*********************************************************/

class Graphics:public Transaction
{
private:
unsigned int select;
char ch;

public:
void switchGraph();
void mainMenu();
void books();
void members();
void transactions();
void fees();
}gra;

void Graphics::switchGraph()
{
int driver=0,mode;
initgraph(&driver,&mode,"");
}
void rear();
void Graphics::mainMenu()
{
clrscr();
gra.switchGraph();
setbkcolor(1);
select=0;

cout<<"\n-----------------MAIN MENU----------------------";
cout<<"\n------------------------------------------------";
cout<<"\nBOOK MENU-------------------|---1---|";
cout<<"\nMEMBER MENU-----------------|---2---|";
cout<<"\nTRANSACION MENU-------------|---3---|";
cout<<"\nFEES FILE-------------------|---4---|";
cout<<"\nEXIT LIBRARY----------------|---5---|";
cout<<"\n------------------------------------------------";
cout<<"\nENTER YOUR CHOICE--------:";
cin>>select;

switch(select)
{
case 1:
gra.books();
break;
case 2:
gra.members();
break;
case 3:
gra.transactions();
break;
case 4:
gra.fees();
break;
case 5:
cout<<"\nTHANK YOU !";
rear();
delay(2000);
return;
}
getch();
closegraph();
}

void Graphics::books()
{
unsigned int n;
clrscr();
gra.switchGraph();
setbkcolor(4);
select=0;
cout<<"\n-----------------BOOK MENU----------------------";
cout<<"\n------------------------------------------------";
cout<<"\nADD NEW BOOK ENTRY----------------|---1---|";
cout<<"\nDELETE A BOOK ENTRY---------------|---2---|";
cout<<"\nMODIFY BOOK RECORD----------------|---3---|";
cout<<"\nSEARCH BOOK ENTRY-----------------|---4---|";
cout<<"\nSHOW BOOK STORE-------------------|---5---|";
cout<<"\nEXIT BOOK MENU--------------------|---6---|";
cout<<"\n------------------------------------------------";
cout<<"\nENTER YOUR CHOICE--------:";
cin>>select;

switch(select)
{
case 1:
buk.addNewBook();
break;
case 2:
buk.delBook(n);
break;
case 3:
buk.modifyBook();
break;
case 4:
buk.searchBook();
break;
case 5:
buk.showBookFile();
break;
case 6:
cout<<"\nYOU EXIT BOOK MENU !";
delay(2000);
gra.mainMenu();
}

cout<<"\n\nDO YOU WANT TO CONTINUE !";
cin>>ch;
if(ch=='y'||ch=='Y')
gra.books();

else
{
cout<<"\nYOU EXIT BOOK MENU !";
delay(2000);
gra.mainMenu();
}

getch();
closegraph();
}

void Graphics::members()
{
unsigned int n;
clrscr();
gra.switchGraph();
setbkcolor(5);
select=0;

cout<<"\n-----------------MEMBER MENU----------------------";
cout<<"\n------------------------------------------------";
cout<<"\nADD NEW MEMER ENTRY----------------|---1---|";
cout<<"\nDELETE A MEMBER ENTRY--------------|---2---|";
cout<<"\nMODIFY MEMBER RECORD---------------|---3---|";
cout<<"\nSEARCH MEMBER ENTRY----------------|---4---|";
cout<<"\nSHOW MEMBER FILE-------------------|---5---|";
cout<<"\nCHECK MEMBER FEE DETAILS-----------|---6---|";
cout<<"\nEXIT MEMBER MENU-------------------|---7---|";
cout<<"\n------------------------------------------------";
cout<<"\nENTER YOUR CHOICE--------:";
cin>>select;

switch(select)
{
case 1:
mem.addNewMem();
break;
case 2:
mem.delMem(n);
break;
case 3:
mem.modifyMem();
break;
case 4:
mem.searchMem();
break;
case 5:
mem.showMemFile();
break;
case 6:
mem.checkMemFee(n);
case 7:
cout<<"\nYOU EXIT MEMBER MENU !";
delay(2000);
gra.mainMenu();

}
cout<<"\n\nDO YOU WANT TO CONTINUE !";
cin>>ch;
if(ch=='y'||ch=='Y')
gra.members();

else
{
cout<<"\nYOU EXIT MEMBER MENU !";
delay(2000);
gra.mainMenu();
}
getch();
closegraph();
}

void Graphics::transactions()
{

unsigned int n;
clrscr();
gra.switchGraph();
setbkcolor(6);
select=0;

cout<<"\n---------------TRANSACTION MENU-----------------";
cout<<"\n------------------------------------------------";
cout<<"\nTRANSACTION TYPE----------------|---1---|";
cout<<"\nSHOW TRANSACTION FILE-----------|---2---|";
cout<<"\nSHOW LAST TRANSACTION-----------|---3---|";
cout<<"\nSEARCH TRANSACTION RECORD-------|---4---|";
cout<<"\nEXIT TRANSACTION MENU-----------|---5---|";
cout<<"\n------------------------------------------------";
cout<<"\nENTER YOUR CHOICE--------:";
cin>>select;

switch(select)
{
case 1:
trans.transType();
break;
case 2:
trans.viewTransFile();
break;
case 3:
trans.viewTrans();
break;
case 4:
trans.searchTransRecord();
break;
case 5:
cout<<"\nYOU EXIT TRANSACTION MENU !";
delay(2000);
gra.mainMenu();

}
cout<<"\n\nDO YOU WANT TO CONTINUE !";
cin>>ch;
if(ch=='y'||ch=='Y')
gra.transactions();

else
{
cout<<"\nYOU EXIT TRANSACTION MENU !";
delay(2000);
gra.mainMenu();
}

getch();
closegraph();
}

void Graphics::fees()
{
clrscr();
select=0;
gra.switchGraph();
setbkcolor(8);
cout<<"\n--------------------FEES MENU-------------------";
cout<<"\n------------------------------------------------";
cout<<"\nCREATE FEES STRUCTURE---------|---1---|";
cout<<"\nSHOW FEES STRUCTURE-----------|---2---|";
cout<<"\nEXIT FEES MENU----------------|---3---|";
cout<<"\n------------------------------------------------";
cout<<"\nENTER YOUR CHOICE--------:";
cin>>select;

switch(select)
{
case 1:
fee.createFeeFile();
break;
case 2:
fee.viewFeeFile();
break;
case 3:
cout<<"\nYOU EXIT FEES MENU !";
delay(2000);
gra.mainMenu();
}
cout<<"\n\nDO YOU WANT TO CONTINUE !";
cin>>ch;
if(ch=='y'||ch=='Y')
gra.fees();

else
{
cout<<"\nYOU EXIT FEES MENU ";
delay(2000);
gra.mainMenu();
}
getch();
closegraph();
}

/***********************************************/
/******************FRONT PAGES******************/
/***********************************************/


void bfill1(int x,int y,int fillcolor,int bcolor)
{
int n=fillcolor;
int present=getpixel(x,y);
if(present!=bcolor && present!=fillcolor)
{
putpixel(x,y,fillcolor);

bfill1(x-1,y,n,15);
bfill1(x,y+1,n,15);
bfill1(x,y-1,n,15);
bfill1(x+1,y,n,15);
}
}

void gra1()
{
clrscr();
char msg[33];
int gdriver=DETECT,gmode,errorcode,c1x,c2x,c3x,c4x,c5x,c6x;
int c1y,c2y,c3y,c4y,c5y,c6y;
c1x=c2x=270;
c3x=c4x=370;
c5x=220;c6x=420;
c1y=c3y=20;
c2y=c4y=120;
c5y=c6y=70;
initgraph (&gdriver, &gmode," c:\\tc\bgi");
setfillstyle(8,8);
setcolor(7);
line(0,300,640,300);
floodfill(320,240,7);
setcolor(4);
line(c1x,c1y,c2x,c2y);
line(c1x,c1y,c3x,c3y);
line(c1x,c1y,c4x,c4y);
line(c2x,c2y,c3x,c3y);
line(c2x,c2y,c4x,c4y);
line(c3x,c3y,c4x,c4y);
line(c1x,c1y,c5x,c5y);
line(c5x,c5y,c2x,c2y);
line(c3x,c3y,c6x,c6y);
line(c4x,c4y,c6x,c6y);
setfillstyle(1,15);
floodfill(320,72,4);
floodfill(320,68,4);
floodfill(240,70,4);
floodfill(400,70,4);
setfillstyle(1,4);
floodfill(300,70,4);
floodfill(340,70,4);

settextstyle(10,0,4);
setcolor(15);
outtextxy(100,150,"CENTRAL LIBRARY");

setcolor(15);
line (320-150,320-13,320+150,320-13);
line (320-150,320+12,320+150,320+12);
line (320-150,320-13,320-150,320+12);
line (320+150,320+12,320+150,320-13);
int s=30,w;
gotoxy(20,23);
cout<<"LOADING . . .";
for (int x1=171,x2=171,y1=308,y2=331,y=1,S=0;x1<470;x1++,x2++,y++,S++)
{
setcolor(4);
line (x1,y1,x2,y2);
w=(x1-169)/3;
for (int i=34; i<=78; i++)
{
gotoxy(i,23) ;
cout <<" " ;
}
gotoxy(34,23); cout<<w<<"%";
if (x2>270) s=0;
if (x2>370) s=0;
if (x2==320)
delay(0);
else
delay(s);
}
delay(0);
for (int i=27; i<=78; i++)
{
gotoxy(i,23) ;
cout <<" " ;
}

gotoxy(28,23);
cout<<"COMPLETE";
gotoxy(20,25);
cout<<"PRESS ANY KEY TO CONTINUE ";
getch();
closegraph();

}
void gra2()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd, &gm, "c:\\turboc2\\bin");

setfillstyle(10,9);
floodfill(410,250,15);
floodfill(225,215,15);
floodfill(275,210,15);
floodfill(350,215,15);
floodfill(390,210,15);
floodfill(423,205,15);
floodfill(423,230,15);
floodfill(270,244,15);
floodfill(300,200,15);

setcolor(4);
ellipse(320,240,0,360,300,150);
settextstyle(8,0,4);
settextjustify(1,1);
setcolor(4);
outtextxy(320,170,"PRESENTED BY");
delay(1000);
settextstyle(8,0,4);
setcolor(4);
outtextxy(320,220,"");
delay(1000);
settextstyle(7,0,5);
setcolor(15);
outtextxy(320,265,"HARSHIT TIWARI");
delay(1000);

for (int stangle=0;!kbhit();stangle++)
{
setcolor(4);
ellipse(320,240,stangle,
stangle+20,300,150);
ellipse(320,240,stangle+180,stangle+200,300,150);
delay(9);
setcolor(14);
ellipse(320,240,stangle-1,stangle+19,300,150);
ellipse(320,240,stangle-1+180,stangle+199,300,150);

}
getche();

}


void gra3()
{
int d=0,m;
initgraph(&d,&m,"");
setbkcolor(15);
delay(3000);
settextstyle(3,0,6);
setcolor(1);
outtextxy(150,70,"HARSHIT");
setcolor(15);
circle(50,100,20);
bfill1(50,100,1,15);
delay(3000);

setcolor(4);
outtextxy(250,170,"KUMAR");
setcolor(15);
circle(50,200,20);
bfill1(50,200,4,15);
delay(3000);

setcolor(2);
outtextxy(350,270,"TIWARI");
setcolor(15);
circle(50,300,20);
bfill1(50,300,2,15);


getch();
closegraph();
}
void rear()
{
int driver=0,mode;
initgraph(&driver,&mode,"");
setbkcolor(15);
setcolor(4);
settextstyle(10,0,6);
outtextxy(80,150,"THANK YOU");
getch();
closegraph();
}
void graphicScreen()
{
gra1();
gra2();
gra3();
}
/***************************************************/

void main()
{
graphicScreen();
gra.mainMenu();
}

