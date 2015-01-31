#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<alloc.h>
#include<stdlib.h>
#define FILE_SIZE 1009
#define RECORD_SIZE 49
#define INBUFF_SIZE 50
#define KEY_SIZE 5
#define PRO_NAME_SIZE 15
#define COM_NAME_SIZE 15
#define TOTAL_BYTES (RECORD_SIZE * FILE_SIZE)
#define NULL_TER `\0'
#define FULL `f'
#define EMPTY `e'
#define DELETED `d'
#include <graphics.h>
#include <iostream.h>



	 void gra1();
	 void gra2();
	 void box(int,int);


       const int DIVISOR = 1009;
       const int FOUND =1;
       const int NOT_FOUND=0;
       const char file[]="record.dbf";

       char *main_menu[]={
				"^Record Manager",
				"^Stock Manager",
				 "Cash ^Memo",
				"^Quit"
			  };

	    char *record_menu[]={
				 "^Insert New Item Record",
				 "^De1ete Item Record",
				 "^Find Item Record",
				 "^Modify Item Record",
				 "^List All Record",
				  "E^xit"
				  };
	    char *stock_menu[]={
				    "^Low Stock",
				    "^Increment In Stock",
				    "E^xit"
				  };
	    char *find_menu[] ={
				   "^CodeNo.",
				   "^Product Name",
				   "Co^Mpany Name",
				   "E^xit"
				};
	   typedef struct item_record{
				    char flag;
				    char code[KEY_SIZE+1];
				    char pro_name[PRO_NAME_SIZE+ 1];
				    char com_name[COM_NAME_SIZE+1];
				    int wet;
				    float rate;
				    int stock;
				    int min_stock;
				      }ITEM_RECORD;

	   void rserver(void),
		sserver(void),
		insert_item(void),
		increase(void),
		del_record(void),
		find_record(void),
		find_by_code(void),
		find_by_product(void),
		find_by_company(void),
		scan_record(void),
		initialize(void),
		set_count_record(void),
		modi_record(void),
		list(void),
		print_memo(void),
		print_screen(void),
		setmode(int),
		write_string(char *,int,int,int),
		write_char(char,int,int,int),
		mainscreen(void),
		drawbox(int,int,int,int,int),
		drawline(int,int,int,int),
		menubox(int,int,int,int,char),
		savevideo(int,int,int,int,char *),
		restorevideo(int,int,int,int,char *),
		displaymenu(char **,int,int,int),
		getkey(void),
		cur_size(int,int),
		massagebox(char*,int,int,int),
		swep(char *, char *,int),
		sort( char *,char *);

	    int locate(const char *),
		popupmenu(char **,int,int,int,int, int,char* ,char),
		get_string(char *,int,int,int,int),
		get_digits(char *,int,int,int,int),
		get_integer(int *,int,int,int),
		get_float(float *,int,int,int),
		getresponse(char **,char *,int,int,int);

	   long get_address(const char *);

	   FILE* file_ptr;

	    char inbuff[INBUFF_SIZE+ 1];
	     char far *mem;

	    int ascii,scan;
	    int count_record=0;

	     void main(void)
	       {
		   int gdriver = DETECT, gmode, errorcode;
		   initgraph(&gdriver, &gmode, "c:\\turboc2\\bin");


		      gra1();
		      gra2();



		  int sr=5,sc=5,er=14,ec=5+14+3+2;
		  int mm_choice;

		   if((file_ptr=fopen(file,"r+")) != NULL)
		   set_count_record();
		   else
		   {
		     file_ptr=fopen(file,"w+");
		     initialize();
		    }
		    mem=(char far *)0xb8000000L;
		    setmode(3);
		    cur_size(32,0);
		    mainscreen();

		   while(1)
		     {
		      mm_choice=popupmenu(main_menu,4,sr,sc,er,ec,"RSMQ",'m');

		      switch(mm_choice)
		       {

			  case 1:
			       rserver();
			       break;
			  case 2:
			       sserver();
			       break;
			  case 3:
			       print_memo();
			       break;
		      case 4:
		      case 27:
			     clrscr();
			     cur_size(6,7);
			     fclose(file_ptr);
			     exit(1);
		     }
	       }

	   }
	   void rserver(void)
	   {
	     int rm_choice,areareqd;
	     int sr=6,sc= 10,er=7+6+2+3,ec=10+22+3+2;
	     char *p;

	     areareqd=(er-sr+1 )*(ec-sc+1)*2;
	     p=(char *)malloc(areareqd);
	     savevideo(sr,sc,er,ec,p);

	     while(1)

	      {
		   rm_choice=popupmenu(record_menu,6,sr,sc,er,ec,"IDFMLX", 'r');

		   switch(rm_choice)
		    {
		       case 1:
			    insert_item();
			    break;
		       case 2:
			    del_record();
			    break;
		       case 3:
			    find_record();
			    break;
		       case 4:
			    modi_record();
			   break;
		       case 5:
			    list();
			    break;
		       case 6:
		       case 27:

			    restorevideo(sr,sc,er,ec,p);
			    free(p);
			    break;
		     }
	      if(rm_choice==6|rm_choice==27)
		      break;
	    }
	    }


	 void sserver(void)
	    {
	      int sm_choice,areareqd;
	      int sr=6,sc=10,er=7+3+5,ec=10+18+3+2;
	      char*p;
	      areareqd=(er-sr+ 1 )*(ec-sc+ 1 )*2;
	      p=(char *)malloc(areareqd);
	      savevideo(sr,sc,er,ec,p);
	      while(1)
	      {
		  sm_choice=popupmenu(stock_menu,3,sr,sc,er,ec,"LIX", 's');
		  switch( sm_choice)
		    {
		       case 1:
			    scan_record();
			    break;
		       case 2:
			    increase();
			    break;
		      case 3:
		      case 27:
			    restorevideo(sr,sc,er,ec,p);
			    free(p);
			    break;
		     }

		 if(sm_choice==3|sm_choice==27)
		       break;
}
}
	 void insert_item(void)
	    {
	     char *p,ch;
	     int temp,i,areareqd,is_esc=1;
	     int sr=8,sc=5,er=20,ec=75;
	     ITEM_RECORD record;
	     areareqd=(er-sr+1)*(ec-sc+1)*2;
	     p=(char *)malloc(areareqd);
	     savevideo(sr,sc,er,ec,p);
	     while(1)
		 {
		 menubox(sr,sc,er,ec,0x17);
		 drawbox(sr,sc+1,er,ec-1,0x17);
		 drawline(sr+2,sc+1,ec-1,0x17);
		 write_string("Record EntryBox",sr+1,sc+26,0x17);
		 write_string("New item code no. (INT ,NOT NULL)    :",sr+4,sc+3,0x17);
		 write_string("Product name    (STRING ,NOT NULL)    :",sr+5,sc+3,0x17);
		 write_string("COmpany name  (STRING ,NOT NULL)     :",sr+6,sc+3,0x17);
		 write_string("Wet of product   (INT ,NULL)       :",sr+7,sc+3,0x17);
		 write_string("Rate of product (FLOAT ,NOT NULL)      :",sr+8,sc+3,0x17);
		 write_string("Crrent stock   (INT ,NULL)       :",sr+9,sc+3,0x17);
		 write_string("Min stock limit (INT ,NULL)      :",sr+10,sc+3,0x17);
		 if(count_record>=FILE_SIZE)
		 {
			massagebox("There isno space in the file",10,25,0x30);
			}
		   else
		   {
			do {
			    cur_size(6,7);
			   if((is_esc=get_digits(record.code,KEY_SIZE+1,sr+4,sc+50,0))==0)
				break;
			    if(strlen(record.code)!=KEY_SIZE)
			    {
			       cur_size(30,0);
			       massagebox("Item code must be 5 digit long", 13,25 ,0x30);
			    }
			 else
			     {	 if(locate(record.code)==FOUND)
				  {
					    cur_size(30,0);
					    massagebox("There is already a item with this code", 13, 17,0x30);
				    }
			       }
			    } while((strlen(record.code)!=KEY_SIZE)|(locate(record.code)==FOUND));
			 if(is_esc==0)
			    break;
			 else

			    if(get_string(record.pro_name,PRO_NAME_SIZE+1,sr+5 ,sc+50,0)==0)
			     break;
			    else

			    if(get_string(record.com_name,COM_NAME_SIZE+ 1,sr+6,sc+50,1 )==0)
				break;
			     else

				if(get_integer(&record.wet,sr+7,sc+50,1)==0)
				    break;
				else

				    if(get_float(&record.rate,sr+8,sc+50,0)==0)
				       break;
				    else
					if(get_integer(&record.stock,sr+9,sc+50,1)==0)
					   break;
				       else

					   if(get_integer(&record.min_stock,sr+10,sc+50, 1 )==0)
					      break;
					   else
					   {
					       record.flag='f';
					       fwrite(&record,sizeof(ITEM_RECORD),1 ,file_ptr);
					       ++count_record;
					    }
			  }

	       } /*endofwhile*/
	     cur_size(32,0);
	     restorevideo(sr,sc,er,ec,p);
	     free(p);
   }
 void increase(void)
{
   char *p,temp_code[KEY_SIZE+1];
   int areareqd,is_esc=1,temp_quan;
   int sr=8,sc=0,er=18,ec=79;
   ITEM_RECORD record;

   areareqd=(er-sr+ 1 )*(ec-sc+ 1 )*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);

   menubox(sr,sc,er,ec,0x17);
   drawbox(sr,sc+1,er,ec-1,0x17);
   drawline(sr+2,sc+1,ec-1,0x17);
   drawline(er-2,sc+1,ec-1,0x17);
   write_string("Increment in Stock",sr+1,sc+30,0x17);
   write_string("Item Code No. of the Product you want to increase",sr+4,sc+3,0x17);
   if(count_record==0)
	 massagebox("There is no record in the file", 15,25,0x30);
   else
    {
	 do {
	      cur_size(6,7);

	      if((is_esc=get_digits(temp_code,KEY_SIZE+1,sr+4,sc+55,0))==0)
		  break;

	      if(strlen(temp_code)!=KEY_SIZE)
	      {
		  cur_size(30,0);
		  massagebox("Key field must be 5 digit long", 10,25,0x30);
	      }
	      else
	      {

		  if(locate(temp_code)==NOT_FOUND)
		  {
		      cur_size(30,0);
		      massagebox("There is no record with this code", 13,17,0x30);
		  }

	      }
	  } while((strlen(temp_code)!=KEY_SIZE)|(locate(temp_code)==NOT_FOUND));


		 if(is_esc!=0)
	 {
	      gotoxy(sc+4,er);
	      fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);
	      printf("%s     %s       %s       %d      %8.2f     %d    %6d\n",record.code,record.pro_name,record.com_name,record.wet,record.rate,record.stock,record.min_stock);
	      write_string("Quantity",sr+6,sc+13,0x17);

	      if(get_integer(&temp_quan,sr+6,sc+29,1)==1)
	      {
		   record.stock=record.stock+temp_quan;
		   locate(temp_code);
		   fwrite(&record,sizeof(ITEM_RECORD), 1,file_ptr);
	      }

	 }

     }
  cur_size(32,0);
  restorevideo(sr,sc,er,ec,p);
  free(p);

  }

void scan_record(void)
{
    int i,tt=1,count=0;
    int sr=1,sc=0,er=23,ec=79,areareqd;
    ITEM_RECORD record;
    char *p,*temp_code,*temp_pro_name;

    areareqd=(er-sr+1)*(ec-sc+1)*2;
    p=(char *)malloc(areareqd);
    savevideo(sr,sc,er,ec,p);

    menubox( sr,sc,er,ec,0x17);
    drawbox(sr,sc,er,ec,0x17);
    drawline(sr+2, sc,ec,0x17);
    drawline(sr+4,sc,ec,0x17);
    write_string("List of Low Stock Record",sr+1,sc+27,0x17);
    write_string("Sr.no   Code   Product    Company    Wet     Rate    Stock   Min Limit",sr+3,sc+1,0x17);


    if(count_record==0)
	 massagebox("File is Empty",10,35,0x30);
    else
     {
	  fseek(file_ptr,0,SEEK_SET);
	  temp_code=(char *)malloc(count_record*(KEY_SIZE+1));
	  temp_pro_name=(char *)malloc(count_record*(PRO_NAME_SIZE+1));

	  for(i=0;i< FILE_SIZE;++i)
	     {
	       write_string( "WAIT" ,er-1,sc+39,0x87);
	       fseek(file_ptr, i*sizeof(ITEM_RECORD), SEEK_SET);

	       fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);

	       if((record.flag=='f') && (record.stock<record.min_stock))
	       {
		   strncpy(temp_code+(count*(KEY_SIZE+ 1 )),record.code,KEY_SIZE+1);
		   strncpy(temp_pro_name+(count*(PRO_NAME_SIZE+ 1)) ,record.pro_name,PRO_NAME_SIZE+1);
		   count++;
	       }

	  }
	  if(count==0)
	       massagebox("No stock shortage", 10,28,0x30);
	  else
	  {
		sort(temp_code,temp_pro_name);
		for(i=0;i<count;i++)
		{
		   if(tt%16==0)
		   {
		       tt=1;
		       write_string("MORE",er-1,sc+38,0x87);
		       getch();
		       menubox(sr+6,sc+1,er-1,ec-1,0x17);
		     }

		   gotoxy(2,6+tt%16);
		   if(locate(temp_code+(i*(KEY_SIZE+1)))==FOUND)
		   {
		       fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);
		       printf(" %d     %s     %s       %s       %d    %8.2f      %d     %d\n",i+1,record.code,record.pro_name,record.com_name,record.wet,record.rate,record.stock,record.min_stock);

		       tt++;
		       }
			    else
			      printf("error");
	      }
	      write_string(" ",er-1,sc+38,0x17);
	      getch();

	 }
	 free(temp_code);
	 free(temp_pro_name);
    }
  restorevideo(sr,sc,er,ec,p);
  free(p);

}

void del_record(void)
{
   char *p,temp_code[KEY_SIZE+1];
   int areareqd;
   int sr=8,sc=0,er=18,ec=79,is_esc=1;
   ITEM_RECORD record;
   areareqd=(er-sr+1)*(ec-sc+1)*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);

   menubox(sr,sc,er,ec,0x17);
   drawbox(sr,sc+1,er,ec-1,0x17);
   drawline(sr+2,sc+1,ec-1,0x17);
   drawline(er-2,sc+1,ec-1,0x17);
   write_string("Delete Record",sr+1 ,sc+32,0x17);
   write_string("Item Code No. of the Product you want to Delete",sr+4,sc+3,0x17);

   if(count_record==0)
	 massagebox("There is no record in the file", 15,25,0x30);
   else
    {
	 do {
	      cur_size(6,7);

	      if((is_esc=get_digits(temp_code,KEY_SIZE+1,sr+4,sc+55,0))==0)
		  break;

			      if(strlen(temp_code)!=KEY_SIZE)
	      {
		   cur_size(30,0);
		   massagebox("Key field must be 5 digit long", 10,25,0x30);
	      }
	      else
	      {

		   if(locate(temp_code)==NOT_FOUND)
		   {
		       cur_size(30,0);
		       massagebox("There is no record with this code", 13,17,0x30);
		   }
		}
	  } while((strlen(temp_code)!=KEY_SIZE)|(locate(temp_code)==NOT_FOUND));

	 if(is_esc!=0)
	 {
	      gotoxy(sc+4,er);
	      fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);
	    printf("%s   %s   %s   %d   %8.2f   %d   %d\n",record.code,record.pro_name,record.com_name,record.wet,record.rate,record.stock,record.min_stock);
	     do
	      {
		   cur_size(32,0);
		   massagebox("Do you want to delete record (`Y' or `N')", 13,17,0x30);

		   if(ascii==89|ascii==121)
		   {
		       if(locate(temp_code)==FOUND)
		       {
			     --count_record;
			     record.flag='d';//DELETED;

			     fwrite(&record,sizeof(ITEM_RECORD),1,file_ptr);
		       }

		   }
	      }while(ascii!=89 && ascii!=121 && ascii!=78 && ascii!=110 && ascii!=27);

	   }
	 }


  cur_size(32,0);
  restorevideo(sr,sc,er,ec,p);
	     free(p);

	   }

	   void find_record(void)
	     {
	      char *p,*m,temp_code[KEY_SIZE+1];
	      int areareqd,fm_choice;
	      int sr=7,sc=20,er=19,ec=40;
	      ITEM_RECORD record;

	      areareqd=(er-sr+1)*(ec-sc+1)*2;
	      m=(char *)malloc(areareqd);
	      savevideo(sr,sc,er,ec,m);
	      while(1)

	       {
		    fm_choice=popupmenu(find_menu,4,sr,sc,er,ec,"CPMX", 'f');

		    switch(fm_choice)
		    {
			case 1:
			    find_by_code();
			    break;
			case 2:
			    find_by_product();
			    break;
			case 3:
			    find_by_company();
			     break;
			case 4:
			case 27:
			    restorevideo(sr,sc,er,ec,m);
			   free(m);
			   break;
			  }

		   if(fm_choice==4|fm_choice==27)
			break;
	       }
	       }
	       void find_by_code(void)
	       {

		 char *p,temp_code[KEY_SIZE+1];
		 int areareqd;
		 int sr=6,sc=0,er=18,ec=79,is_esc=1;
		 ITEM_RECORD record;
		 areareqd=(er-sr+1)*(ec-sc+1)*2;
		 p=(char *)malloc(areareqd);
		 savevideo(sr,sc,er,ec,p);

		  menubox(sr,sc,er,ec,0x17);
		  drawbox(sr,sc,er,ec,0x17);
		  drawline(sr+2,sc,ec,0x17);
		  drawline(sr+6,sc,ec,0x17);
		  drawline(sr+8,sc,ec,0x17);
		  write_string("Find by Code",sr+1,sc+32,0x17);
		  write_string("Item Code No. of the Product you want to find",sr+4,sc+3,0x17);
		  write_string(" Code    Product     Company     Wet      Rate       Stock      Min Limit",sr+7,sc+1,0x17);

   do {
	cur_size(6,7);

	if((is_esc=get_digits(temp_code,KEY_SIZE+1,sr+4,sc+55,0))==0)
	    break;

	if(strlen(temp_code)!=KEY_SIZE)
	{
	    cur_size(30,0);
	    massagebox("Key field must be 5 digit long", 10,25,0x30);
	}
	else
	{

	    if(locate(temp_code)==NOT_FOUND)
	    {
		cur_size(30,0);
		massagebox("There is no record with this code", 13,17,0x30);
	    }
	}
     } while((strlen(temp_code)!=KEY_SIZE)|(locate(temp_code)==NOT_FOUND));

 cur_size(30,0);

 if(is_esc!=0)
 {
	gotoxy(sc+1,er-1);
	fread(&record, sizeof(ITEM_RECORD), 1,file_ptr);
		  printf(" %s    %s         %s         %d     %8.2f      %d        %d\n",record.code,record.pro_name,record.com_name,record.wet, record.rate, record.stock, record.min_stock);
	  getch();
     }
   restorevideo(sr,sc,er,ec,p);
      free(p);

}
void find_by_product(void)

{
   char *p,temp_pro_name[PRO_NAME_SIZE+ 1];
   int areareqd,i,temp= 1 ,count=0;
   int sr=3,sc=0,er=24,ec=79;
   ITEM_RECORD record;

   areareqd=(er-sr+ 1 )*(ec-sc+ 1 )*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);
   menubox(sr,sc,er,ec,0x17);
   drawbox(sr,sc,er,ec,0x17);
   drawline(sr+2,sc,ec,0x17);
   write_string("Find by Product name",sr+1,sc+32,0x17);
   drawline(sr+6,sc,ec,0x17);
   write_string("Sr.no    Code    Product    Company    Wet    Rate    Stock    MinLimit",sr+7,sc+1,0x17);
   drawline(sr+8,sc,ec,0x17);
   write_string("Product name you want to flnd",sr+4,sc+3,0x17);

   cur_size(6,7);

   if(get_string(temp_pro_name,PRO_NAME_SIZE+1,sr+4,sc+55,0)==1)
   {
	i=0;
	cur_size(32,0);
	fseek(file_ptr, 0,SEEK_SET);
	while(i<FILE_SIZE)
	{
	     write_string("WAIT",er-1,sc+39,0x87);
	     fseek(file_ptr,i*sizeof(ITEM_RECORD),SEEK_SET);
	     fread(&record,sizeof(ITEM_RECORD),1,file_ptr);

	     if(strcmp(temp_pro_name,record.pro_name)==0)
	     {
	       if(temp%11==0)
		   {
		       temp=1;
		       write_string("MORE",er-1,sc+38 ,0x87);
		       getch();
		       menubox(sr+9,sc+ 1,er- 1,ec- 1,0x17);
		   }
		   gotoxy(2, 12+temp%11);
		   count++;
		   printf("%d       %s       %s       %s       %d  %8.2f    %d      %d\n",count,record.code,record.pro_name,record.com_name,record.wet,record.rate,record.stock,record.min_stock);
		   temp++;
	      }
	      i++;
	      }
	      write_string(" ",er-1,sc+38,0x17);

	 if(temp==1)
	      massagebox("There is no such Record",13,25,0x30);
	 else
	      getch();

     }
  cur_size(32,0);
  restorevideo(sr,sc,er,ec,p);
  free(p);

}
void find_by_company(void)
{

   char *p, temp_com_name[COM_NAME_SIZE+ 1];
   int areareqd,i,temp= 1 ,count=0;
   int sr=3,sc=0,er=24,ec=79;
   ITEM_RECORD record;

   areareqd=( er-sr+ 1 )*(ec-sc+ 1 )*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);

   menubox( sr,sc,er,ec,0x17);
   drawbox(sr,sc,er,ec,0x17);
   drawline(sr+2,sc,ec,0x17);
   drawline(sr+6,sc,ec,0x17);
   write_string("Sr.no      Code     Product     Company     Wet     Rate     Stock   Min_Limit",sr+7,sc+1,0x17);
   drawline(sr+8,sc,ec,0x17);
   write_string("Find by Company name",sr+1,sc+32,0x17);
   write_string("Comp any name you want to find", sr+4, sc+3,0x17);

   cur_size(6,7);

   if(get_string(temp_com_name,COM_NAME_SIZE+1,sr+4,sc+55,0)==1)
       {
	 i=0;
	 cur_size(32,0);
	 fseek(file_ptr,0,SEEK_SET);

	 while(i<FILE_SIZE)
	 {
	      write_string("WAIT",er- 1 ,sc+39,0x87);
	      fseek(file_ptr,i*sizeof(ITEM_RECORD),SEEK_SET);
	      fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);

	      if(strcmp(temp_com_name,record.com_name)==0)
	      {
		   if(temp%11==0)
		   {
		       temp=1;
		       write_string("MORE",er-1,sc+38,0x87);
		       getch();
		       menubox(sr+9,sc+1,er-1,ec-1,0x17);
		   }
		   gotoxy(2,12+temp%11);
		   count++;
		   printf(" %d         %s      %s        %s        %d   %8.2f     %d      %d\n",count,record.code,record.pro_name,record.com_name,record.wet,record.rate,record. stock,record.min_stock);
		   temp++;
	      }
	      i++;
	      }
		write_string(" ",er-1,sc+38,0x17);

	 if(temp== 1)
	      massagebox("There is no such Record", 13,25,0x30);
	 else
	      getch();

  }
  cur_size(32,0);
  restorevideo(sr,sc,er,ec,p);
  free(p);

}

void modi_record(void)
   {

   char *p,temp_code[KEY_SIZE+1];
   int areareqd,is_esc= 1;
   int sr=6,sc=0,er=21,ec=79;
   ITEM_RECORD record;

   areareqd=(er-sr+ 1 )*(ec-sc+ 1 )*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);

   menubox(sr,sc,er,ec,0x17);
   drawbox(sr,sc+1,er,ec- 1,0x17);
   drawline(sr+2,sc+1,ec- 1,0x17);
   drawline(er-2,sc+1,ec-1,0x17);
   write_string("Modify Record",sr+ 1 ,sc+30,0x17);
   write_string("Item Code No. ofthe Product you want to Moclify :",sr+4,sc+3,0x17);
   write_string("Product name     (STRING ,NOT NULL)  :",sr+6,sc+7,0x17);
   write_string("Company name      (STRING ,NOT NULL)  : ",sr+7,sc+7,0x17);
   write_string("Wet of product   (INT ,NULL)    :",sr+8,sc+7,0x17);
   write_string("Rate ofproduct   (FLOAT ,NOT NULL)   : ",sr+9,sc+7,0x17);
   write_string("Current stock    (INT ,NULL)    :",sr+10,sc+7,0x17);
   write_string("Min stock limit  (INT ,NULL)    :",sr+11,sc+7,0x17);

   if(count_record==0)
	 massagebox("There is no record in the file", 15,25,0x30);
   else
     {
	do {
	     cur_size(6,7);
	       if((is_esc=get_digits(temp_code,KEY_SIZE+1,sr+4,sc+55,0))==0)
		  break;

	     if(strlen(temp_code)!=KEY_SIZE)
	     {
		  cur_size(30,0);
		  massagebox("Key field must be 5 digit long", 10,25,0x30);
	     }
	     else
		   {
		    if(locate(temp_code)==NOT_FOUND)
		    {
			cur_size(30,0);
			massagebox("There is no record with this code",13,20,0x30);
		    }
		}

	   } while(( strlen(temp_code)!=KEY_SIZE)||(locate(temp_code)==NOT_FOUND));

	   if(is_esc!=0)
	   {
	       gotoxy(sc+4,er);
	       fread(&record,sizeof(ITEM_RECORD),1,file_ptr);
	       printf("%s   %s   %s   %d  %8.2f   %d   %d\n",record.code,record.pro_name,record.com_name,record.wet,record.rate, record.stock,record.min_stock);
	       if(get_string(record.pro_name,PRO_NAME_SIZE+1,sr+6,sc+54,0) !=0)

		if(get_string(record.com_name,COM_NAME_SIZE+1,sr+7,sc+54,1)!=0)

		    if(get_integer(&record.wet,sr+8,sc+54,1)!=0)

		    if(get_float(&record.rate,sr+9,sc+54,0) !=0)

		       if(get_integer(&record.stock,sr+10,sc+54,1)!=0)

			 if(get_integer(&record.min_stock,sr+11,sc+54,1)!=0)
			  {
			    do {
				cur_size(32,0);
				massagebox("Do you want to store this record (`Y' or `N')", 13, 17,0x30);
				if(ascii==89||ascii==121)
				   {
				   if(locate(temp_code)==FOUND)
				   {
				    record.flag='f';
				   fwrite(&record, sizeof(ITEM_RECORD),1 ,file_ptr);
				   }
				}
			     }while(ascii!=89&&ascii!=121 &&ascii!=78&&ascii!=110&& ascii!=27);
}
}
}
   cur_size(32,0);
   restorevideo(sr,sc,er,ec,p);
   free(p);

}
void list(void)
{
   int i,temp=1,count=0;
   int sr=1,sc=0,er=23,ec=79,areareqd;
   char *p,*temp_code,*temp_pro_name;
   ITEM_RECORD record;

   areareqd=(er-sr+ 1 )*(ec-sc+ 1 )*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);

   menubox(sr,sc,er,ec,0x17);
   drawbox(sr,sc,er,ec,0x17);
   drawline(sr+3,sc,ec,0x17);
   drawline(sr+5, sc,ec,0x17);
   write_string("List of Total Record",sr+1,sc+27,0x17);
   write_string("Total Record = ",sr+2,ec-23,0x17);
   gotoxy(72,sr+3);
   printf("%-4d",count_record);
   write_string("Sr.no    Code    Product    Company     Wet     Rate        Stock   Min_Limit",sr+4,sc+ 1,0x17);
   if(count_record==0)
	massagebox("There isno record in the file", 10,25,0x30);
   else
    {
	fseek(file_ptr,0,SEEK_SET);
	temp_code=(char * )malloc(count_record*(KEY_SIZE+ 1));
	temp_pro_name=(char * )malloc(count_record*(PRO_NAME_SIZE+ 1));

	for(i=0;i<FILE_SIZE;++i)
	    {
	    // write_string(" ",er-1,sc+38,0x87);
	     fseek(file_ptr,i*sizeof(ITEM_RECORD),SEEK_SET);
	     fread(&record,sizeof(ITEM_RECORD),1,file_ptr);

		     if(record.flag=='f')
	     {
		  strncpy(temp_code+( count *(KEY_SIZE+ 1 )),record.code,KEY_SIZE+1);
		  strncpy(temp_pro_name+(count*(PRO_NAME_SIZE+1)),record.pro_name,PRO_NAME_SIZE+ 1);

		  count++;
	     }

	 }
	 sort(temp_code,temp_pro_name);

	 for(i=0;i<count_record;i++)
	 {
	     if(temp%16==0)
	     {
		  temp=1;
		  write_string("MORE",er-1,sc+38,0x87);
		  getch();
		  menubox(sr+6,sc+1,er-1,ec-1,0x17);
	     }
	     gotoxy(2,7+temp%16);
	     locate(temp_code+(i*(KEY_SIZE+ 1)));
	     fread(&record, sizeof( ITEM_RECORD),1,file_ptr);
	     printf(" %d      %s       %s      %s        %d   %8.2f     %d      %d\n",i+1,record.code,record.pro_name,record.com_name,record.wet,record.rate,record.stock,record.min_stock);
	     temp++;
	}

	 write_string(" ",er-1,sc+38,0x17);
	 getch();
	 free(temp_code);
	 free(temp_pro_name);
     }
   restorevideo(sr,sc,er,ec,p);
   free(p);
 }

	  void print_memo(void)
	   {
	     char *p_1,*p_2;
	     char data_code[10][6],temp_code[KEY_SIZE+ 1];
	     int areareqd_1,areareqd_2,is_esc= 1;
	     int sr=5,sc=0,er=22,ec=79;
	     int data_qty[10],data_discount[10],temp_qty,temp_discount;
	     int choice=0,check,i,data_count=0;
	     float total=0,gross_amt,net_amt;
	     ITEM_RECORD record;
	     areareqd_1 =(er- sr+ 1 )*(ec-sc+ 1 )*2;
	     p_1=(char *)malloc(areareqd_1);
	     savevideo(sr, sc,er,ec,p_1);

	     menubox(sr,sc,er,ec,0x17);
	     drawbox(sr,sc+1,er,ec-1,0x17);
	     drawline(sr+2,sc+1,ec-1,0x17);
	     drawline(er-2,sc+1,ec-1,0x17);
	     drawline(sr+4,sc+1,ec-1,0x17);
write_string("Entry Form For Cash Memo",sr+1,sc+30,0x17);  write_string("Sr no.    Code no.             Quantity                        Discount",sr+3,sc+7,0x17);

      for(i=0;i<10;i++)
	{
		    do{
			cur_size(6,7);
			gotoxy(10,11+i);
			printf("%d",data_count+1);

if((is_esc=get_digits(temp_code,KEY_SIZE+1,sr+5+i,sc+  18,0))==0)
				 break;

			if( strlen(temp_code)!= KEY_SIZE)
			{
			   cur_size(30,0);
massagebox("Item code must be 5 digit long",     13,25,0x30);
			 }
			else
				 if(locate(temp_code)!=FOUND)
				 {
				      cur_size(30,0);
				            massagebox("There is no item with this   code", 13,17,0x30);
				 }
		     } while((strlen(temp_code)!=KEY_SIZE)||(locate(temp_code)!=FOUND));


		    if(locate(temp_code)==FOUND)
		    {
			 gotoxy(3,22);
			 fread(&record,sizeof(ITEM_RECORD),1,file_ptr);
			 printf("%s %s %s %d %f %d %d\n",record.code,record.pro_name,record.com_name, record.wet, record.rate,record.stock,record.min_stock);

		    }
		    if(is_esc==0)
			 break;
		    else

			 if(get_integer(&temp_qty,sr+5+i,sc+39,0)==0)
			     break;
			 else

			     if(temp_qty>record.stock)
			     {
				  massagebox("Out of stock.",13,33,0x30);
				  write_string(" ",sr+5+i,sc+39,0x17);
				  i=i-1;
				  continue;
			      }
			     else

				  if(get_integer(&temp_discount,sr+5+i,sc+63,0)==0)
				      break;
				  else
				  {
				      strncpy(data_code[data_count],temp_code,KEY_SIZE+1);
				      data_qty[data_count]=temp_qty;
				      data_discount[data_count]=temp_discount;
				      data_count++;
				  }

		       }

		if(data_count!=0)
		{
		    cur_size(32,0);
		    areareqd_2=25*80*2;
		    p_2=(char *)malloc(areareqd_2);
		    savevideo(0,0,24,79,p_2);
		    menubox(0,0,24,79,0x07);
		    write_string("PACK GENERAL STORE",0,25,0x07);
		    write_string("Shastribridge,Jabalpur",1,25,0x07);
		    write_string("DATE -",3,3,0x07);
		    write_string("CASH MEMO",3,68,0x07);

		    drawbox(4,0,21,79,0x07);
		    write_string("S.  Ptcls   comp   Data qty    Qty Rate    Gross Amt     Dis.    Net Amt", 5,1 ,0x07);
		    write_string("no.                              (Rs.)       (Ks.)        %       (Rs.)",6,1,0x07);
		    drawline(7,0,79,0x07);
		    drawline( 18,0,79,0x07);
	 for(i=0;i<data_count;i++)
	 {
	     locate(data_code[i]);
	     fread(&record,sizeof(ITEM_RECORD),1,file_ptr);
	     gross_amt=record.rate*data_qty[i];
	     net_amt=record.rate * data_qty[i] * (1-(data_discount[i]/100.00));
	     gotoxy(2,9+i);
	     printf("%d   %s     %s",i+1,record.pro_name,record.com_name);

	     printf("      %d        %8.2f     %8.2f       %d    %8.2f",data_qty[i],record.rate,gross_amt,data_discount[i],net_amt);

	     total=total+net_amt;
	 }
	 write_string("Prepared by -", 19,4,0x07);
	 write_string("Total", 19,58,0x07) ;
	 write_string("Amount",20,61,0x07);
	 gotoxy(70,21);
	 printf("%9.2f",total);

	 do {
	     write_string("    Do You want to print cash meno (Y orN) ",er,sc+2,0x70);
	     getkey();
	     if(ascii==121||ascii==89|| ascii==13)
		{
		  choice=1;
		  for(i=0;i<data_count;i++)
		  {
			    locate(data_code[i]);
			    fread(&record,sizeof(ITEM_RECORD), 1,file_ptr);
			    record.stock=record.stock-data_qty[i];
			    locate(data_code[i]);
			    fwrite(&record,sizeof(ITEM_RECORD), 1 ,file_ptr);
		  }

	      }
	    }while(ascii!=12l && ascii!=89 && ascii!=13 && ascii!=110 && ascii!=78 && ascii!=27);

			    if(choice==1)
		    {
			 write_string("                                  ",er,sc+2,0x07);
			 massagebox("Attach Printer",10,30,0x30);
			 print_screen();
			 getch();
		    }
		   restorevideo(0,0,24,79,p_2);
		   free(p_2);
	       }
	       cur_size(32,0);
	       restorevideo(sr,sc,er,ec,p_1);
	       free(p_1);

	   }

	   long get_address(const char* key)
	   {
	       long int_key,address;

	       int_key=atol(key);
	       address=(int_key%DIVISOR)*sizeof(ITEM_RECORD);
	       return address;
	    }
	   int locate(const char* key)
	    {
	       long address,start_add,unocc_add;
	       int delete_flag=0;
	       char ch,stored_key[KEY_SIZE+1];
	       ITEM_RECORD record;
	       address = get_address(key);
	       unocc_add=start_add=address;
	      do{
		   fseek(file_ptr, address, SEEK_SET);

		   switch(fgetc(file_ptr))
		  {
			 case 'd':
				       if(!delete_flag)
				       {
					     unocc_add=address;
					     delete_flag=1;
				       }
				       break;
			 case 'e':
				       if(delete_flag)
					     fseek(file_ptr,unocc_add,SEEK_SET);
				       else
					     fseek(file_ptr,address,SEEK_SET);

				       return NOT_FOUND;
			 case 'f':
				       fseek(file_ptr,address,SEEK_SET);
				       fread(&record,sizeof(ITEM_RECORD),1,file_ptr);

				       if(strncmp(key,record.code,KEY_SIZE)==0)
					   {
					     fseek(file_ptr,address,SEEK_SET);
					     return FOUND;
					   }

				       break;
		     }
		     address=(address+sizeof(ITEM_RECORD))%TOTAL_BYTES;
		  } while(address!=start_add);

		 fseek(file_ptr,unocc_add,SEEK_SET);
		 return NOT_FOUND;

	    }

	    void initialize(void)
	    {
		 int i;
		 ITEM_RECORD record={'e',"   ","      ","      ",0,0,0,0};

		 for(i=0;i<FILE_SIZE;++i)
		 {
		     fseek(file_ptr,i*sizeof(ITEM_RECORD),SEEK_SET);
		     fwrite(&record,sizeof(ITEM_RECORD),1,file_ptr);
		 }

		 count_record=0;

	   }

 void set_count_record(void)

 {
    int i;

    fseek(file_ptr,0,SEEK_SET);

    for(i=0;i<FILE_SIZE;++i)
    {
	 fseek(file_ptr,i*sizeof(ITEM_RECORD),SEEK_SET);

	 if(fgetc(file_ptr)=='f')
	       ++count_record;
    }
}


void print_screen(void)

{
  union REGS i;

  int86(5,&i,&i);

}

void setmode(int mode)

{
  union REGS i,o;

  i.h.ah=0;
  i.h.al=mode;
  int86(16,&i,&o);

}
void write_string(char *s,int r,int c,int att)

{
    while(*s!='\0')
    {
	 if(*s=='^')

	 {
	      s++;
	      write_char(*s,r,c,0x50);
	 }

		      else
			 write_char(*s,r,c,att);
		    s++;
		    c++;
		    }
}

 void write_char( char ch,int r,int c,int att)
      {
	char far *v;
	v= mem+r*160+c*2;
	*v=ch;
	v++;
	*v=att;
       }


 void mainscreen(void)
  {
       int i,j;
	    menubox(0,0,24,79,0x30);
	    drawbox(3,0,21,79,0x30);
	    drawbox( 1,0,23,79,0x30);
	    write_char(204,3 ,0,0x30);
	    write_char(185,3,79,0x30);
	    write_char(204,21,0,0x30);
	    write_char(185,21,79,0x30);
	    for(i=4;i<=20;i++)
	     {
	     for(j=1;j<=78;j++)
	     write_char(3,i,j,0x0);
	    }
      write_string("Esc - To exit",2,65,0x30);

  }


void drawbox(int sr,int sc,int er,int ec,int att)
{
	     int i;
	     for(i=sc+1;i<ec;i++)
	     {

		 write_char(205,sr,i,att);
		 write_char(205,er,i,att);
	     }
	     for(i=sr+1; i<er;i++)
	       {
		  write_char(186,i,sc,att);
		  write_char(186,i,ec,att);
	       }
      write_char(201,sr,sc,att);
      write_char(187,sr,ec,att);
      write_char(200,er,sc,att);
      write_char( 188,er,ec,att);
 }

void drawline(int sr,int sc,int ec,int att)
{
	      int i;
	      for(i=sc+1;i<ec;i++)
	      write_char(205,sr,i,att);
	      write_char(204,sr,sc,att);
	      write_char(185,sr,ec,att);
}
void menubox(int sr,int sc,int er,int ec,char fill)
{
	     int i,j;
	      for(i=sr;i<=er;i++)
	       {
		  for(j=sc;j<=ec;j++)
		    write_char(' ',i,j,fill);
	       }
}
int popupmenu(char **menu,int count,int sr,int sc,int er,int ec,char *hotkeys, char menu_head)
{
	int i,choice;

   menubox(sr,sc,er,ec,112);
   drawbox(sr,sc,er,ec,112);
   drawline(sr+2,sc,ec,112);

   switch(menu_head)
     {
	  case 'm':
	      write_string("Main Menu",sr+1,sc+5, 112);
	      break;
	  case 'r':
	      write_string("Record Menu", sr+1 ,sc+8, 112);
	      break;
	  case 's':
	      write_string("StockMenu",sr+1,sc+7,112);
	      break;
	  case 'f':
	      write_string("Find menu",sr+ 1,sc+5, 112);
	      break;
     }
  displaymenu(menu,count,sr+3,sc+2);
  choice=getresponse(menu,hotkeys,sr+2,sc+1,count);

  return(choice);

}

void savevideo(int sr,int sc,int er,int ec,char *buffer)
{
   char far *v;
   int i,j;

   for(i=sr;i<=er;i++)
     {
       for(j=sc;j<=ec;j++)
	{
	      v=mem+i*160+j*2;
	      *buffer=*v;
	      v++;
	      buffer++;
	      *buffer=*v;

	      buffer++;

	  }

      }
}

void restorevideo(int sr,int sc,int er,int ec,char *buffer)
{
    char far *v;
    int i,j;

    for(i=sr;i<=er;i++)
      {
	 for(j=sc;j<=ec;j++)
	  {
	      v=mem+i*160+j*2;
	      *v=*buffer;
	      v++;
	      buffer++;
	      *v=*buffer;
	      buffer++;
	  }
   }
}

void displaymenu(char **menu,int count,int sr,int sc)

{
    int i;

    for(i=0;i<count;i++)
      {
	  write_string(menu[i],sr,sc, 112);
	  sr++;
      }
}
int getresponse( char **menu,char *hotkeys,int sr,int sc,int count)
{
   int choice=1,len,hotkeychoice;
   len=strlen(hotkeys);
   write_string(menu[choice-1],sr+choice,sc+1,111);
   while(1)
   {
	getkey();
	if(ascii==0)
	 {
	     switch(scan)
	     {
		  case 80:
		      write_string(menu[choice-1],sr+choice,sc+1,112);
		      choice++;
		      break;
		  case 72:
		      write_string(menu[choice-1],sr+choice,sc+1, 112);
		      choice--;
		      break;
	     }

	     if(choice==0)
		  choice=count;
	     if(choice>count)
		  choice=1;

	     write_string(menu[choice-1],sr+choice,sc+1,111);
	 }
	 else
	 {
	     if(ascii==13)
		  return(choice);

	     if(ascii==27)
		  return(27);

	     ascii=toupper(ascii);
	     hotkeychoice=1;

	     while(*hotkeys !='\0')
	     {


			   if(*hotkeys==ascii)
				 return(hotkeychoice);
			   else
			      {
				hotkeys++;
				hotkeychoice++;
			      }
		      }

		       hotkeys=hotkeys-len;
		}
	}
}

 void getkey(void)
{
	      union REGS ii,oo;

	     while(!kbhit())
		;
	     ii.h.ah=0;
	     int86(22,&ii,&oo);
	     scan=oo.h.ah;
	     ascii=oo.h.al;

}
void cur_size(int ssl,int esl)
{
    union REGS i,o;
	     i.h.ah=1;
	     i.h.ch=ssl;
	     i.h.cl=esl;
	     i.h.bh=0;

	     int86(16,&i,&o);
}
void massagebox(char *mass,int sr,int sc,int att)
{
   char *p;
   int areareqd,er,len,ec;

   er=sr+2;
   len=strlen(mass);
   ec=sc+len+4;
   areareqd=(er-sr+1)*(ec-sc+1)*2;
   p=(char *)malloc(areareqd);
   savevideo(sr,sc,er,ec,p);
   menubox(sr,sc,er,ec,att);
   drawbox(sr, sc,er,ec,att);
   write_string(mass,sr+1,sc+2,att);
   getkey();
   restorevideo(sr,sc,er,ec,p);
   free(p);
}

int get_string(char *name,int len,int sr,int sc,int is_null)
{
   int i=0;
   char *temp;
   *name='\0';
   temp=(char *)malloc(len*1);
   menubox(sr,sc,sr,sc+len-2,0x20);
   gotoxy(sc+1,sr+1);

   while(i<len-1)
    {
       getkey();

       if(ascii==27)
	     return(0);

       if(scan==15 && (is_null==1 || i!=0))
	     break;

       if((ascii>=48 && ascii <=57)||(ascii>=65 && ascii<=90)||(ascii>=97 && ascii <=122)||ascii==32)
	{
	     *(temp+i)=ascii;
	     write_char(ascii,sr,sc+i,0x20);
	     gotoxy(sc+i+2,sr+1);

			i++;
			}
		       else
			{
			    if((i!=0|| is_null==1) && ascii==13)
				break;
			    gotoxy(sc+i+1,sr+1);

			    if(i!=0 && ascii==8)
			    {
				write_char(' ',sr,sc+i-1,0x20);
				gotoxy(sc+i,sr+1);
				i--;
			    }

		       }
		  } /* End while */

		*(temp+i)='\0';
		 strcpy(name,temp);
		 return(1);
}
int get_digits(char *name,int len,int sr,int sc,int is_null)
{
		 int i=0;
		 char *temp;
		 *name='0';
		 temp =(char *)malloc(len*1);
		 menubox(sr,sc,sr,sc+len-2,0x20);
		 gotoxy(sc+1,sr+1);

		 while(i<len-1)
		   {
		      getkey();

		      if(ascii==27)
			  return(0);

		      if(scan==15 && (is_null==1||i!=0))
			 break;

		      if(ascii>=48 && ascii <=57)
			{
			 *(temp+i)=ascii;


			write_char(ascii,sr,sc+i,0x20);
			gotoxy(sc+i+2,sr+1);
			i++;
		   }
		   else
		    {

		       if((i!=0||is_null==1)&&ascii==13)
			    break;

		       gotoxy(sc+i+1,sr+1);

		       if(i!=0 && ascii==8)
			 {
			   write_char(' ',sr,sc+i-1,0x20);
			   gotoxy(sc+i,sr+1);
			   i-- ;
			  }
		  }
	}
	     *(temp+i)='\0';
	     strcpy(name,temp);
	     return(1);
}
int get_integer(int *name,int sr,int sc,int is_null)
{
	      int i=0,len=6;
	      char *temp;
	      *name=0;
	      temp=(char *)malloc(len*1);
	      menubox(sr,sc,sr,sc+len-2,0x20);
	      write_char('0',sr,sc,0x20);

	      gotoxy(sc+1,sr+1);

	     while(i<len-1)
	       {
		   getkey();
		   if(ascii==27)
			return(0);

		    if(scan==15 && (is_null==1||i!=0))
			break;

		    if(ascii>=48 && ascii <=57)
		      {
			*(temp+i)=ascii;
			write_char(ascii,sr,sc+i,0x20);
			gotoxy(sc+i+2,sr+1);
			i++;
		    }
		    else
		    {
			if((i!=0||is_null==1) && ascii==13)
			     break;

			gotoxy(sc+i+1,sr+1);

			if(i!=0 && ascii==8)
			   {
			     write_char(' ',sr,sc+i-1,0x20);
			     gotoxy(sc+i,sr+1);
			     i--;
			    }
		 }
		}
	      *(temp+i)='\0';
	      *name=atoi(temp);
	      return(1);
}
int get_float(float *name,int sr,int sc,int is_null)
{
	     int i=0,len=8;
	     char *temp;
	     *name=0;
	     temp=(char *)malloc(len* 1);
	     menubox(sr, sc,sr,sc+len-2,0x20);
	     write_char('0',sr,sc,0x20);
	     gotoxy(sc+1,sr+1);
   while(i<len-1)
     {
	 getkey();

	 if(ascii==27)   // Esc key
	     return(0);

	 if(scan==15&&(is_null==1||i!=0))// Tab key
	     break;

	 if((ascii>=48 && ascii<=57)|| ascii==46)
	 {
	     *(temp+i)=ascii;
	     write_char(ascii,sr,sc+i,0x20);
	     gotoxy(sc+i+2,sr+1);
	     i++;
	 }
       else
	 {
	     if((i!=0||is_null==1) && ascii==13)//Enter key
		  break;

	     gotoxy(sc+i+1,sr+1);

	     if(i!=0 && ascii==8) //Backspace key
	     {
		  write_char(' ',sr,sc+i-1,0x20);
		  gotoxy(sc+i,sr+1);
		  i--;
	     }

	 }
     }
   *(temp+i)='\0';
   *name = atof(temp);
   return(1);

}
void sort(char *temp_code,char *temp_pro_name)
{

  int i,j;

  for(i=0;i<count_record-1; i++)
  {
    for(j=i+1;j<count_record;j++)
    {
	 if(strcmp(temp_pro_name+(i*(PRO_NAME_SIZE+1)),temp_pro_name+(j*(PRO_NAME_SIZE+1)))>0)
	 {
	     swep(temp_pro_name+(i*(PRO_NAME_SIZE+1)),temp_pro_name+(j*(PRO_NAME_SIZE+1)),PRO_NAME_SIZE+1);

	     swep(temp_code+(i*(KEY_SIZE+ 1)),temp_code+(j*(KEY_SIZE+ 1)),KEY_SIZE+1);

	 }
     }
}
}
void swep(char *b,char *c,int n)
{
  char temp[15];
  strncpy(temp,b,n);
  strncpy(b,c,n);
  strncpy(c,temp,n);

}


    //*************************************************************
   //	   INDIVIDUAL FUNCTION DEFINITIONS FOR FIRST TWO SCREEN
   //*************************************************************
	void gra1()				//Function definition #1
	{
	clrscr();
	char msg[33];
	int gdriver=DETECT,gmode,errorcode,c1x,c2x,c3x,c4x,c5x,c6x;
	int c1y,c2y,c3y,c4y,c5y,c6y;
	c1x=c2x=270;                    //       c1   c3
	c3x=c4x=370;                    //   c5           c6
	c5x=220;c6x=420;                //       c2   c4
	c1y=c3y=20;
	c2y=c4y=120;
	c5y=c6y=70;
	initgraph (&gdriver, &gmode," c:\\tc");
	setfillstyle(1,8);
	setcolor(8);
	line(0,300,640,300);
	floodfill(320,240,8);
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
	line(c4x,c4y,c6x,c6y);       		//DRAW THE LOGO OF PACK
	setfillstyle(1,15);
	floodfill(320,72,4);
	floodfill(320,68,4);
	floodfill(240,70,4);
	floodfill(400,70,4);
	setfillstyle(1,4);
	floodfill(300,70,4);
	floodfill(340,70,4);
	settextjustify(1,1);
	settextstyle(10,0,7);
	setcolor(15);
	outtextxy(230,200,"P");
	outtextxy(290,200,"A");			//TO WRITE PACK
	outtextxy(350,200,"C");
	outtextxy(410,200,"K");

	setfillstyle(9,1);                    //backcolor of first screen
	floodfill(410,250,15);
	floodfill(225,215,15);
	floodfill(275,210,15);
	floodfill(350,215,15);            	//TO FILL THE LETTERS PACK
	floodfill(390,210,15);
	floodfill(423,205,15);
	floodfill(423,230,15);
	floodfill(270,244,15);
	floodfill(300,200,15);

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
	      if (x2>270) s=0; if (x2>370) s=0;
						       //for delay
		if (x2==320) delay(0); else
		delay(s);
		}
		delay(0);
		for (int i=27; i<=78; i++)
		{
			gotoxy(i,23) ;
			cout <<" " ;
		}

	gotoxy(28,23);
	cout<<"COMPLETE";  gotoxy(20,25);
	cout<<"PRESS ANY KEY TO CONTINUE ";
	getch();
	cleardevice();

	}
	void gra2()                             //Function definition *2
	{
	clrscr();                               //To make a designer ellipse
	int gd=DETECT,gm;
	initgraph(&gd, &gm, "c:\\turboc2\\bin");

	setfillstyle(9,1);                      //to fill the second screen
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
	settextstyle(10,0,4);
	settextjustify(1,1);
	setcolor(2);
	outtextxy(320,170,"SHOP MANAGEMENT");
	delay(1000);
	settextstyle(4,0,4);
	setcolor(20);
	outtextxy(320,220,"PRESENTED BY:");
	delay(1000);
	settextstyle(10,0,4);
	setcolor(6);
	outtextxy(320,265,"Harshit Tiwari");
	delay(1000);
	outtextxy(315,280," ");
	delay(100);
	outtextxy(320,295," ");




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


































