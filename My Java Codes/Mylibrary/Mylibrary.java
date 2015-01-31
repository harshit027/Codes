import java.util.Scanner;
import java.util.Date;

class Books
{
	int bno;
	String bname;
	String bauthor;
	float bprice;
	Books()
	{
		bno=101;
		bname="JURASSIC PARK";
		bauthor ="ROWLING";
		bprice=100;
	}

     Books(int n,String bn,String ba,float p)
	{
		bno=n;
		bname=bn;
		bauthor=ba;
		bprice=p;
	}

	void getBook()
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("ENTER BOOK ISBN : ");
	    bno=obj.nextInt();
		System.out.println("ENTER BOOK NAME : ");
		bname=obj.nextLine();
		bname=obj.nextLine();
		System.out.println("ENTER BOOK AUTHOR : ");
		bauthor=obj.nextLine();
		System.out.println("ENTER BOOK PRICE : ");
		bprice=obj.nextFloat();
	}

	void showBook()
	{
		System.out.println("BOOK NO :"+bno+"\nBOOK NAME :"+bname+"\nBOOK AUTHOR :"+bauthor+"\nBOOK PRICE : "+bprice);
	}
}

class Members
{
	private int memid;
	private String memname;

	Members()
	{
		memid=1;
		memname="HARSHIT";
	}

    Members(int id,String name)
    {
		memid=id;
		memname=name;
	}

	void getMember()
	{
		Scanner obj=new Scanner(System.in);
		System.out.println("ENTER MEMBER ID");
		memid=obj.nextInt();
		System.out.println("ENTER MEMBER NAME");
		memname=obj.nextLine();
		memname=obj.nextLine();
	}

	void showMember()
	{
		System.out.println("MEMBER ID : "+memid+"\nMEMBER NAME : "+memname);
	}
}

class Transaction
{
	Books b;
	Members m;
	Date d;
	String type;

	Transaction(Books bref,Members mref,Date d,String type)
	{
		System.out.println("---------------------------------------------------");
		bref.showBook();
		System.out.println("\nTRANSACTION : "+type);
		mref.showMember();
		System.out.println("\nON "+d);
	}
}


class Mylibrary
		{
			public static void main(String args[])
			{
				Books b[]=new Books[5];
				Members m[]=new Members[5];
				b[0]=new Books();
				b[0].getBook();
				b[0].showBook();

				m[0]=new Members();
				m[0].getMember();
				m[0].showMember();

				Date d=new Date();
				Transaction t=new Transaction(b[0],m[0],d,"issue");
			}
		}
