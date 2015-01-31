		    //SPORT CLUB MANAGMENT SYSTEM//

							      //CHECK,2,3,4

#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<fstream.h>

struct date_rec
{
short int dd;
short int mm;
int yyyy;
}due_date,current_date;
int check=0;

  class facility
{
private:
char fac_type[10];
short int fac_code;
public:
void get_facility();
void show_fac();
void show_facility();
void add_facility();
void reports();
}fac;
void facility::get_facility()
{
cout<<"\nENTER THE FACILITY TO BE ADDED-------:";
gets(fac_type);
cout<<"\nENTER THE CODE FOR THIS FACILITY------:";
cin>>fac_code;
}
void facility::show_fac()
{
cout<<"\n";
cout<<setiosflags(ios::left)<<setw(10)<<" "<<setw(25)<<fac_code<<setw(30)<<fac_type;
}
void facility::add_facility()
{
 fstream outfile;
char choice='y';
outfile.open("facility.dat",ios::app);
while(choice=='y'||choice=='Y')
{
fac.get_facility();
outfile.write((char*)&fac,sizeof(fac));
cout<<"\nANY MORE FACILITY TO BE ADDED--<<Y/N>>?----:";
cin>>choice;
}
}
void facility::show_facility()
{
clrscr();
fstream infile;
infile.open("facility.dat",ios::in);
infile.seekg(0,ios::beg);
cout<<"\n    FACILITY CODE--------->FACILITY TYPE---:";
cout<<"\n--------------------------------------------:";
infile.read((char*)&fac,sizeof(fac));
while(!infile.eof())
{
fac.show_fac();
infile.read((char*)&fac,sizeof(fac));
}
}
class fees_file
{
private:
unsigned long mem_code;
date_rec date_of_deposit;
float amount;
short int payment_code;
public:
void add_fees_object(unsigned long code,date_rec date,int paycode);
void del_fees_object(unsigned long code);
void check_due_date(int& check);
void get_fees();
void show_fees_file();
void show_fees();
void update_fees_file();
void fees_collection();
void fees_due();
}fees,temp;
 void fees_file::add_fees_object(unsigned long code,date_rec date,int paycode)
{
fstream outfile;
fees.mem_code=code;
fees.date_of_deposit=date;
fees.payment_code=paycode;
if(fees.payment_code==1)
 fees.amount=7000.00;
 else
 fees.amount=3500.00;
 outfile.open("feesfile.dat",ios::app);
 outfile.write((char*)&fees,sizeof(fees));
 outfile.flush();
 outfile.close();
 }
 void fees_file::del_fees_object(unsigned long code)
 {
 fstream outfile,infile;
 outfile.open("tempfile.dat",ios::app);
 infile.open("feesfile.dat",ios::in);
  infile.seekg(0,ios::beg);
  infile.read((char*)&fees,sizeof(fees));
  while(!infile.eof())
  {
  if(fees.mem_code!=code)
  outfile.write((char*)&fees,sizeof(fees));
  infile.read((char*)&fees,sizeof(fees));
  }
  infile.close();
  outfile.close();
   remove("feesfile.dat");
   rename("tempfile.dat","feesfile.dat");
  }
  void fees_file::get_fees()
  {
  cout<<"ENTER THE DATE OF SUBMISSION OF FEES----:";
  cin>>date_of_deposit.dd;
  getch();
  cin>>date_of_deposit.mm;
  getch();
  cin>>date_of_deposit.yyyy;
  cout<<"ENTER THE AMOUNT FEES------:";
  cin>>amount;
  }
  void fees_file::show_fees()
  {
  cout<<"\nDATE OF SUBMISSION OF FEES-----:"<<date_of_deposit.dd<<"-"<<date_of_deposit.mm<<"-"<<date_of_deposit.yyyy;
  cout<<"\nAMOUNT OF FEES---------:"<<amount;
  }
  void fees_file::check_due_date(int& check)
  {
  if(due_date.yyyy<=current_date.yyyy)
  {
  if(due_date.mm<=current_date.mm)
    {
    if(due_date.dd<=current_date.dd)
    check=1;
   }
   }
   else
   check=0;
   }
   void fees_file::update_fees_file()
   {
    fstream infile,outfile;
    char ch;
    clrscr();
    cout<<"\nENTER CURRENT DATE---:<<dd/mm/yyyy>>-----:";
    cin>>current_date.dd>>ch>>current_date.mm>>ch>>current_date.yyyy;
     outfile.open("tempfile.dat",ios::app);
     infile.open("feesfile.dat",ios::in);
      infile.seekg(0,ios::beg);
  infile.read((char*)&fees,sizeof(fees));
  while(!infile.eof())
  {
   switch(fees.payment_code)
   {
   case 1:
	   due_date.yyyy=fees.date_of_deposit.yyyy+1;
	     due_date.mm=fees.date_of_deposit.mm;
	   due_date.dd=fees.date_of_deposit.dd;
	   fees.check_due_date(check);
	   switch(check)
	   {
	   case 0:
		  outfile.write((char*)&fees,sizeof(fees));
		  break;
	   case 1:
		   cout<<"\nMEMBER CODE------:"<<fees.mem_code;
		   cout<<"FEES WAS DUE ON----:"<<due_date.dd<<"-"<<due_date.mm<<"-"<<due_date.yyyy;
		   cout<<"HAS THE FEES BEEN DEPOSITE--[Y\N]---";
		   cin>>ch;
	  if(ch=='y'||ch=='Y')
	   {
	   temp.mem_code=fees.mem_code;
	   cout<<"\nENTER THE DATE ON WHICH THE FEES WAS DEPOSITE---:";
	   cin>>temp.date_of_deposit.dd>>ch>>temp.date_of_deposit.mm>>ch>>temp.date_of_deposit.yyyy;
	   cout<<"\nENTER THE AMMOUNT DEPOSITE---:";
	   cin>>temp.amount;
	   temp.payment_code=fees.payment_code;
	   outfile.write((char*)&temp,sizeof(temp));
	   }
	   else
	   outfile.write((char*)&fees,sizeof(fees));
	   break;
	}
	 break;
    case 0 :
	    due_date.mm=fees.date_of_deposit.mm+6;
	    due_date.yyyy=fees.date_of_deposit.yyyy;
	    switch(due_date.mm)
	    {
	    case 13:
		     due_date.mm=1;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 14:
		     due_date.mm=2;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 15:
		     due_date.mm=3;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 16:
		     due_date.mm=4;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 17:
		     due_date.mm=5;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 18:
		     due_date.mm=6;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
		  }
	      fees.check_due_date(check);
	      switch(check)
	      {
		case 0 :
		       outfile.write((char*)&fees,sizeof(fees));
			 break;
		case 1 :
			cout<<"\nMEMBER CODE-----:"<<fees.mem_code;
			cout<<"\nFEES WAS DUE ON"<<due_date.dd<<"-"<<due_date.mm<<"-"<<due_date.yyyy;
			cout<<"HAS FEES BEEN DEPOSITED---[Y\N]---:";
			cin>>ch;

	      if(ch=='y'||ch=='Y')
	   {
	   temp.mem_code=fees.mem_code;
	   cout<<"\nENTER THE DATE ON WHICH THE FEES WAS DEPOSITE---:";
	   cin>>temp.date_of_deposit.dd>>ch>>temp.date_of_deposit.mm>>ch>>temp.date_of_deposit.yyyy;
	   cout<<"\nENTER THE AMMOUNT DEPOSITE---:";
	   cin>>temp.amount;
	   temp.payment_code=fees.payment_code;
	   outfile.write((char*)&temp,sizeof(temp));
	   }
	   else
	   outfile.write((char*)&fees,sizeof(fees));
	   break;
	  }
	   break;
	 }
      infile.read((char*)&fees,sizeof(fees));
  }
  infile.close();
  outfile.close();
   remove("feesfile.dat");
   rename("tempfile.dat","feesfile.dat");
  }
    void fees_file::show_fees_file()
    {
    fstream infile;
     infile.open("feesfile.dat",ios::in);
    infile.seekg(0,ios::beg);
  infile.read((char*)&fees,sizeof(fees));
  while(!infile.eof())
    {
      fees.show_fees();
      infile.read((char*)&fees,sizeof(fees));
      }
      infile.close();
      }
      void fees_file::fees_collection()
      {
      fstream infile;
      cout<<"\nCHOOSE THE MONTH IN WHICH YOU WANT TO SEE DATAWISE FEES COLLECTION-----:";
     int month;
     cout<<"\n\nENTER THE MONTH----:";
     cin>>month;
     cout<<"\n    DATE-------:MEMBERSHIP CODE----:";
     cout<<"\n--------------------------:";
     for(int i=1;i<=31;i++)
     {
     infile.open("feesfile.dat",ios::in);
     infile.seekg(0,ios::beg);
  infile.read((char*)&fees,sizeof(fees));
  while(!infile.eof())
      {
      if(fees.date_of_deposit.dd==i&&fees.date_of_deposit.mm==month)
      {
      cout<<"\n";
cout<<fees.date_of_deposit.dd<<"-"<<fees.date_of_deposit.mm<<"-"<<fees.date_of_deposit.yyyy<<"-----::"<<fees.mem_code;
      }
      infile.read((char*)&fees,sizeof(fees));
      }
      infile.close();
      }
      gotoxy(22,25);
      cout<<"PRESS ANY KEY TO CONTINUE------:";
      getch();
      }
  void fees_file::fees_due()
      {
	fstream infile;
	char ch;
	cout<<"\nENTER THE CURRENT DATE---:<<dd/mm/yyyy>>:---:";
	cin>>current_date.dd>>ch>>current_date.mm>>ch>>current_date.yyyy;
      clrscr();
       cout<<"\nMEMBER CODE-------:>DUE DATE------:";
       infile.open("feesfile.dat",ios::in);
      infile.seekg(0,ios::beg);
  infile.read((char*)&fees,sizeof(fees));
    while(!infile.eof())
  {
   switch(fees.payment_code)
   {
   case 1:
	   due_date.yyyy=fees.date_of_deposit.yyyy+1;
	     due_date.mm=fees.date_of_deposit.mm;
	   due_date.dd=fees.date_of_deposit.dd;
       if( due_date.yyyy==current_date.yyyy)
	{
	if( due_date.mm<=current_date.mm)
	cout<<"\n"<<fees.mem_code<<"-----------:>"<<due_date.dd<<"-"<<due_date.mm<<"-"<<due_date.yyyy;
	}
	break;
       case 0:
		 due_date.mm=fees.date_of_deposit.mm+6;
		 due_date.yyyy=fees.date_of_deposit.yyyy;
       switch(due_date.mm)
	{
	   case 13:
		     due_date.mm=1;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 14:
		     due_date.mm=2;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 15:
		     due_date.mm=3;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 16:
		     due_date.mm=4;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 17:
		     due_date.mm=5;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
	    case 18:
		     due_date.mm=6;
		    due_date.yyyy=fees.date_of_deposit.yyyy+1;
		     break;
		  }
       if(due_date.yyyy==current_date.yyyy)
	{
	  if(due_date.mm<=current_date.mm)
	      cout<<"\n"<<fees.mem_code<<"-------------:>"<<due_date.dd<<"-"<<due_date.mm<<"-"<<due_date.yyyy;
	      }
	      break;
	      }
		 infile.read((char*)&fees,sizeof(fees));
      }
      infile.close();

      gotoxy(20,24);
      cout<<"PRESS ANY KEY TO CONTINUE------:";
      getch();
      }

     class club_mem:public fees_file,public facility
     {
     private:
     unsigned long mem_code;
     char mem_name[20];
     date_rec date_of_joining;
     char address[30];
     long int phone_no;
     short int fac_code1;
     short int fac_code2;
     short int fac_code3;
     short int no_of_child;
     short int payment_code;
     public:
     char ch;
     unsigned long get_rec_no();
     void get_data();
     void show_data();
     void add_object();
     void show_object();
     void del_object();
     void modify_object();
     void facility_availed();
     void search_object();
     void membership_card();
}member;
unsigned long club_mem::get_rec_no()
     {
      int found=0;
      unsigned long recno,temp_recno;

  struct node
      {
      unsigned long rec_no;
      node*link;
      };
      node*start,*ptr,*ptr1,*ptr2;
      fstream infile;
      infile.open("clubfile.dat",ios::in);
      infile.seekg(0,ios::end);
      int n=infile.tellg();
      infile.close();
      if(n==0)
      recno=1;
      else
      {
      infile.open("clubfile.dat",ios::in);
       start=ptr=new node;
      infile.seekg(0,ios::beg);
       infile.read((char*)&member,sizeof(member));
    while(!infile.eof())
     {
       ptr->rec_no=member.mem_code;
       ptr->link=new node;
       ptr=ptr->link;
       infile.read((char*)&member,sizeof(member));
      }
	ptr->link=NULL;
	ptr1=start;
	while(ptr1->link!=NULL)
	{
	 ptr2=ptr1->link;
	   while(ptr2!=NULL)
	    {
	     if(ptr2->rec_no<ptr1->rec_no)
	       {
		 temp_recno=ptr2->rec_no;
		 ptr2->rec_no=ptr1->rec_no;
		 ptr1->rec_no=temp_recno;
	       }
		 ptr2=ptr2->link;
	       }
		ptr2=ptr1->link;
		ptr1=ptr2;
	       }
	ptr1=start;
	while(ptr1!=NULL && found!=1)
	{
	 ptr2=ptr1;
	 ptr1=ptr1->link;
	 if((ptr2->rec_no)+1!=ptr1->rec_no)
	 {
	  recno=(ptr2->rec_no)+1;
	  found=1;
	  }
	 }
    if(found!=1)recno=(ptr2->rec_no)+1;
    ptr=start;
      while(start!=NULL)
      {
      start=start->link;
      delete ptr;
      }
     }
    return recno;
    }
     void club_mem::get_data()
     {
     clrscr();
     mem_code=get_rec_no();
     cout<<"\nENTER THE NAME-----------------------:";
     gets(mem_name);
     cout<<"\nENTER THE DATE OF JOINING----<<DD/MM/YYYY>>---------:";
     cin>>date_of_joining.dd>>ch>>date_of_joining.mm>>ch>>date_of_joining.yyyy;
     cout<<"\nENTER THE ADDRESS-------------------------:";
     gets(address);
     cout<<"\nENTER THE PHONE NO>------------------:";
     cin>>phone_no;
     clrscr();
     cout<<"<<<<<<<IMPORTANT>>>>>>>";
     cout<<"\nNOW YOU WILL ENTER THE FACILITY CODES WHICH YOU WANT TO AVAIL-------------:";
     cout<<"\nIF YOU DID NOT SEE THE AVAILABLE FACILITY WITH THEIR RESPECTIVE-------------------:";
     cout<<"\nCODES AT THE BEGINING,YOU CAN SEE NOW----------------:";
     cout<<"\n\nENETR[Y or N]-------------:";
     char ch;
     cin>>ch;
     if(ch=='Y'||ch=='y')
     {
     fac.show_facility();
     gotoxy(20,24);
     cout<<"PRESS ANY KEY TO CONTINUE--------------------:";
     getch();
     }
     clrscr();
     cout<<"\nENTER THE FACILITY CODE NO.1-----------------:";
     cin>>fac_code1;
     cout<<"\nENTER THE FACILITY CODE NO.2-----------------:";
     cin>>fac_code2;
     cout<<"\nENTER THE FACILITY CODE NO.3-----------------:";
     cin>>fac_code3;
     cout<<"\nENTER THE NO. OF CHILDREN<<ABOVE 12>>-----------------:";
     cin>>no_of_child;
     cout<<"\nENTER CODE FOR MODE OF PAYMENT----------:";
     cout<<"\n1---FOR YEAERLY PAYMENT--------:";
     cout<<"\n0---FOR HALFYEARLY PAYMENT---------:";
     cin>>payment_code;
   }
    void club_mem::show_data()
     {
       clrscr();
       cout<<"\nMEMBERSHIP NO.------:"<<mem_code;
       cout<<"\nNAME------------------:"<<mem_name;
       cout<<"\nDATE OF JOINING---------:"<<date_of_joining.dd<<"-"<<date_of_joining.mm<<"-"<<date_of_joining.yyyy;
       cout<<"\nADDRESS----------:"<<address;
       cout<<"\nPHONE NO.--------:"<<phone_no;
       cout<<"\nFACILITY CODE NO. 1-----------:"<<fac_code1;
       cout<<"\nFACILITY CODE NO. 2-----------:"<<fac_code2;
       cout<<"\nFACILITY CODE NO. 3-----------:"<<fac_code3;
       cout<<"\nNO. OF CHILDREN--------:"<<no_of_child;
       cout<<"\n\nPRESS ANY KEY TO CONTINUE-------:";
	 getch();
	 }
	 void club_mem::add_object()
	 {
	   fstream outfile;
	   char choice='y';
	   while(choice=='y')
	   {
	    clrscr();
	    cout<<"\nDO YOU WANT TO SEE THE LIST OF FACILITIES AVAILABLE IN THE CLUB---------:";
	    cout<<"\nYOU ARE ADVISED TO ENTER 'Y' BEFORE FILLING THE FORM--------:";
	    cout<<"\n\nENTER<<Y or N>>----:";
	    char ch;
	    cin>>ch;
	    if(ch=='y'||ch=='Y')
	    {
	      fac.show_facility();
	      gotoxy(20,24);
	      cout<<"PRESS ANY KEY TO CONTINUE-------:";
	      getch();
	   }
	  outfile.open("clubfile.dat",ios::app);
	  member.get_data();
	  outfile.write((char*)&member,sizeof(member));
	  outfile.flush();
	  outfile.close();
    add_fees_object(member.mem_code,member.date_of_joining,member.payment_code);
    cout<<"\nANY MORE RECORDS TO BE ENTERED---[Y or N]--------:";
    cin>>choice;
  }
}
  void club_mem::show_object()
{
  fstream infile;
      infile.open("clubfile.dat",ios::in);
      infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
      {
	member.show_data();
	infile.read((char*)&member,sizeof(member));
       }
     }
  void club_mem::del_object()
  {
   unsigned long code;
   fstream infile,outfile;
   cout<<"\nENTER THE MEMBERSHIP NO. TO BE DELETED-----:";
   cin>>code;
       outfile.open("tempclub.dat",ios::app);
       infile.open("clubfile.dat",ios::in);
       infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
      {
       if(member.mem_code!=code)
       outfile.write((char*)&member,sizeof(member));
       infile.read((char*)&member,sizeof(member));
     }
 infile.close();
 outfile.close();
 remove("clubfile.dat");
 rename("tempclub.dat","clubfile.dat");
 del_fees_object(code);
 remove("feesfile.dat");
 rename("tempfile.dat","feesfile.dat");
 }
 void club_mem::modify_object()
 {
  fstream file;
  int mod_choice;
  unsigned long code;
  do
  {
  clrscr();
  cout<<"\n     MODIFY MENU     ";
  cout<<"\n-----------------------------";
  cout<<"\n CHANGE ADDRESS           |...1...|";
  cout<<"\n CHANGE PHONE NO.         |...2...|";
  cout<<"\n CHANGE FACILITY CODE     |...3...|";
  cout<<"\n CHANGE NO. OF CHILDREN   |...4...|";
  cout<<"\n EXIT MODIFY MENU         |...5...|";
  cout<<"\n\nENTER YOUR CHOICE NO.-----------:";
  cin>>mod_choice;
  if(mod_choice!=5)
  {
  cout<<"\nENTER THE MEMBERSHIP CODE--------:";
  cin>>code;
     file.open("clubfile.dat",ios::in|ios::out);
     file.seekg(0,ios::beg);
     file.read((char*)&member,sizeof(member));
     int n=file.tellg();
  while(!file.eof())
 {
   if(code==member.mem_code)
   {
   switch(mod_choice)
   {
     case 1:
	     clrscr();
	     cout<<"\nENTER THE NEW ADDRESS--------:";
	     gets(member.address);
	     file.seekg(n-sizeof(member));
	     file.write((char*)&member,sizeof(member));
	     file.flush();
	     break;
    case 2:
	     cout<<"\nENTER THE NEW PHONE NO.------:";
	     cin>>member.phone_no;
	     file.seekg(n-sizeof(member));
	     file.write((char*)&member,sizeof(member));
	     file.flush();
	     break;
     case 3:
	     clrscr();
	      cout<<"\nFACILITY CODE NO. 1-----------:";
	      cin>>member.fac_code1;
	      cout<<"\nFACILITY CODE NO. 2-----------:";
	       cin>>member.fac_code2;
	      cout<<"\nFACILITY CODE NO. 3-----------:";
	       cin>>member.fac_code3;
	       file.seekg(n-sizeof(member));
	     file.write((char*)&member,sizeof(member));
	     file.flush();
	     break;

       case 4:
	      clrscr();
	      cout<<"\nENTER NO. OF CHILDREN ABOVE 12---------:";
	      cin>>member.no_of_child;
		  file.seekg(n-sizeof(member));
	     file.write((char*)&member,sizeof(member));
	     file.flush();
	     break;
	  }
	}
      file.read((char*)&member,sizeof(member));
      n=file.tellg();
    }
    file.close();
    }
  }
   while(mod_choice!=5);
   clrscr();
   cout<<"\nYOU ENDED THE MODIFY SESSION-------:";
   cout<<"\n@-THANK YOU-@";
   delay(700);
   }
   void club_mem::search_object()
   {
     fstream infile;
     int search_choice;
     long int phno;
     unsigned long code;
     char name[20];
     do
     {
      int counter=0;
      clrscr();
      cout<<"\nMEMBER CODE    |..1..|";
      cout<<"\nMEMBER NAME    |..2..|";
      cout<<"\nPHONE NUMBER   |..3..|";
      cout<<"\nEXIT           |..4..|";
      cout<<"\nENTER YOUR CHOICE NUMBER-------:";
      cin>>search_choice;
      switch(search_choice)
  {
     case 1:
	     clrscr();
	     cout<<"\nENTER THE MEMBER CODE TO BE SEARCHED-------:";
	     cin>>code;
	     infile.open("clubfile.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
    {
     if(member.mem_code==code)
     {
       counter++;
       member.show_data();
     }
     infile.read((char*)&member,sizeof(member));
     }
     infile.close();
     gotoxy(22,24);
     cout<<"RECORDS FOUND="<<counter;
     getch();
     break;

 case 2:
	     clrscr();
	     cout<<"\nENTER THE MEMBER NAME TO BE SEARCHED-------:";
	     cin>>name;
	     infile.open("clubfile.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
    {
     if(strcmpi(member.mem_name,name)==0)
     {
       counter++;
       member.show_data();
     }
     infile.read((char*)&member,sizeof(member));
     }
     infile.close();
     gotoxy(22,24);
     cout<<"RECORDS FOUND="<<counter;
     getch();
     break;

  case 3:
	     clrscr();
	     cout<<"\nENTER THE PHONE NUMBER TO BE SEARCHED-------:";
	     cin>>phno;
	     infile.open("clubfile.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
    {
     if(member.phone_no==phno)
     {
       counter++;
       member.show_data();
     }
     infile.read((char*)&member,sizeof(member));
     }
     infile.close();
     gotoxy(22,24);
     cout<<"RECORDS FOUND="<<counter;
     getch();
     break;

 case 4:
	clrscr();
	gotoxy(22,15);
	cout<<"#@--YOU ENDED THE SEARCH SESSION--@#";
	gotoxy(27,18);
	cout<<"@@---THANK YOU---@@";
	delay(700);
	break;
    }
  }
    while(search_choice!=4);
    }
      void club_mem::facility_availed()
      {
       fstream infile;
       cout<<"\nENTER THE FACILITY CODE FOR SEARCHING-------:";
       int code;
       cin>>code;
       cout<<"FOLLOWING MEMBERS ARE REGISTERED WITH FACILITY CODE NUMBER-----:"<<code;
       cout<<"\n:---------------------------------:";
       cout<<"MENMBER CODE           NAME        ";
       cout<<"\n:----------------------------------:";
	     infile.open("clubfile.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
    {
      if(code==member.fac_code1||code==member.fac_code2||code==member.fac_code3)
      {
      cout<<"\n"<<setiosflags(ios::left)<<setw(25)<<member.mem_code<<setw(25)<<member.mem_name;
      }
  infile.read((char*)&member,sizeof(member));
  }
   infile.close();
   cout<<"\n:------------------------------------:";
   gotoxy(20,24);
   cout<<"PRESS ANY TO CONTNUE--------:";
   getch();
 }
  void club_mem::membership_card()
  {
	     fstream infile;
	     infile.open("clubfile.dat",ios::in);
	     infile.seekg(0,ios::beg);
      infile.read((char*)&member,sizeof(member));
  while(!infile.eof())
    {
   clrscr();
cout<<"\n:-----------------------------------------------------:";
cout<<"\n:-----------------------------------------------------:";
textcolor(RED);
gotoxy(20,2);
cprintf("\nY.M.C.A.SPORTS CLUB ");
cout<<"\n:-----------------------------------------------------:";
cout<<"\n\n               MEMBERSHIP CARDS                      ";
textcolor(GREEN);
cout<<"\n:-----------------------------------------------------:";
cout<<"\n\n  NAME    :"<<setiosflags(ios::left)<<setw(20)<<member.mem_name<<"CODE :"<<setw(15)<<member.mem_code;
cout<<"\n   ADDRESS  :"<<setiosflags(ios::left)<<setw(20)<<member.address;
cout<<"PHONE NUMBER   :"<<member.phone_no;
cout<<"\n:-------------------------------------------------------:";
cout<<"\n\n FACILITY CODE 1   FACILITY CODE 2   FACILITY CODE 3 ";
cout<<"\n       "<<setiosflags(ios::left)<<setw(18)<<member.fac_code1<<setw(18)<<member.fac_code2<<setw(15)<<member.fac_code3;
cout<<"\n:--------------------------------------------------------------:";
cout<<"\n\n"<<setiosflags(ios::right)<<setw(60)<<"MANAGER";
cout<<"\n:--------------------------------------------------------:";
cout<<"\n:--------------------------------------------------------:";
   gotoxy(20,24);
   cout<<"PRESS ANY KEY TO CONTINUE-----------:";
   getch();
   infile.read((char*)&member,sizeof(member));
   }
     infile.close();
  }
   void facility::reports()
   {
   fstream infile;
   int report_choice;
   do
   {
   clrscr();
   textcolor(RED);
   cprintf("\nREPORT MENU");
   cprintf("\n:-------------------:");
   textcolor(GREEN);
   cout<<"\nLIST OF ALL MEMBERS WITH ALL FIELDS                           |..1..|";
   cout<<"\nLIST OF ALL FACILITY AVAILABLE IN THE CLUB                    |..2..|";
   cout<<"\nACTIVITY WISE MEMBER CODE AND MEMBER'S NAME                   |..3..|";
   cout<<"\nDATAWISE FEES COLLECTED FROM MEMBERS IN A PARTICULAR MONTH    |..4..|";
   cout<<"\nLIST OF MEMBERS WHOSE FEES IS DUE IN THE CURRENT MONTH        |..5..|";
   cout<<"\nMEMBERSHIP CARD FOR EACH MEMBER                               |..6..|";
   textcolor(RED);
   gotoxy(20,24);
   cprintf("\nEXIT REPORT SESSION                     |...7...|");
   cout<<"\n\nREPORT ON WHAT?:---:ENTER YOUR CHOICE:---:";
   cin>>report_choice;
   switch(report_choice)
   {
   case 1:
	  clrscr();
	  member.show_object();
	  break;
   case 2:
	  fac.show_facility();
	  getch();
	  break;
   case 3:
	  clrscr();
	  member.facility_availed();
	  break;
   case 4:
	  clrscr();
	  fees.fees_collection();
	  break;
   case 5:
	  clrscr();
	  fees.fees_due();
	  break;
   case 6:
	  clrscr();
	  member.membership_card();
	  break;
   case 7:
	  clrscr();
	  gotoxy(22,15);
	  cout<<"TOU ENDED THE REPORT SESSION-----:";
	  gotoxy(27,18);
	  cout<<"@@--THANK YOU--@@";
	  delay(700);
	  break;
	}
   }
       while(report_choice!=7);
       }


     void graphic_screen()
      {
      int driver,mode;
      driver=DETECT;
      initgraph(&driver,&mode,"");
      setbkcolor(15);
      setcolor(1);
      settextstyle(8,0,6);
      outtextxy(150,50,"@INDIAN@");
      outtextxy(20,250,"SPORTS CLUB");
      delay(5000);
      cleardevice();


      setbkcolor(15);
      setcolor(1);
      settextstyle(8,0,6);
      outtextxy(100,100,"CREATED");
      settextstyle(8,0,6);
      outtextxy(250,250,"BY");
      delay(5000);
      cleardevice();


      setbkcolor(15);
      setcolor(1);
      settextstyle(8,0,6);
      outtextxy(60,100,"|*HARSHIT*|");
      delay(5000);
      closegraph();

    }
      void main()
      {
      int main_choice;
      graphic_screen();
      do
      {
      clrscr();
      textcolor(RED);
      gotoxy(22,7);
      cprintf("      MAIN MENU     ");
      textcolor(GREEN);
      gotoxy(22,8);
      cprintf(":--------------------:");
      textcolor(RED);
      gotoxy(22,10);
      cprintf("REGISTER A NEW MEMBER                       |....[1]....|");
      textcolor(GREEN);
      gotoxy(22,11);
      cprintf("REMOVE A MEMBER                             |....[2]....|");
      textcolor(GREEN);
      gotoxy(22,12);
      cprintf("MODIFY INFORMATION ABOUT A MEMBER           |....[3]....|");
      textcolor(GREEN);
      gotoxy(22,13);
      cprintf("SEARCH FOR INFORMATION ABOUT A MEMBER       |....[4]....|");
      textcolor(GREEN);
      gotoxy(22,14);
      cprintf("ENTRY OF FEES IN FACILITY FILE              |....[5]....|");
      textcolor(GREEN);
      gotoxy(22,15);
      cprintf("AAD NEW FACILITY IN FACILITY FILE           |....[6]....|");
      textcolor(GREEN);
      gotoxy(22,16);
      cprintf("REPORTS                                     |....[7]....|");
      textcolor(RED);
      gotoxy(22,17);
      cprintf("EXIT                                        |....[8]....|");
      textcolor(GREEN);
      gotoxy(22,20);
      cprintf("ENTER YOUR CHOICE NUMBER-------------:");
      cin>>main_choice;
      switch(main_choice)
      {

    case 1:
	    clrscr();
	    member.add_object();
	    break;

    case 2:
	    clrscr();
	    member.del_object();
	    break;

    case 3:
	    clrscr();
	    member.modify_object();
	    break;

    case 4:
	    clrscr();
	    member.search_object();
	    break;


    case 5:
	    clrscr();
	    fees.update_fees_file();
	    break;


    case 6:
	    clrscr();
	    fac.add_facility();
	    break;

    case 7:
	    clrscr();
	    member.reports();
	    break;

   case 8:
	  clrscr();
	  gotoxy(25,10);
	  cout<<"YOU ENDED THE SESSION----:	";
	  gotoxy(27,12);
	  cout<<"@@--THANK YOU--@@";
	  delay(3000);
	  break;
	  }
	 }
       while(main_choice!=8);
}







