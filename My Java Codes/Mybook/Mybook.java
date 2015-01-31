import java.util.Scanner;

class Book
{
	int book_isbn;
	String b_author,b_title;
	void getBook()
	{
		Scanner s=new Scanner(System.in);


		System.out.println("\nEnter the author name :");
		b_author=s.nextLine();

		System.out.println("\nEnter the book title :");
		b_title=s.nextLine();


		System.out.println("\nEnter the book_isbn :");
		book_isbn=s.nextInt();



	}
	void showBook()
	{
		System.out.println("--------BOOK DETAILS-------");
		System.out.println("\nBook ISBN : "+book_isbn);
		System.out.println("\nBook Author : "+b_author);
		System.out.println("\nBook Title : "+b_title);
		System.out.println("---------------------------");
	}
}

class Mybook
{
	public static void main(String args[])
	{
		int i;
		Book b[]=new Book[5];
		for(i=0;i<5;i++)
		b[i]=new Book();
		for(i=0;i<2;i++)
		{

		     b[i].getBook();
		     b[i].showBook();
		 }

	}
}
