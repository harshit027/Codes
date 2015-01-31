import java.io.*;
import java.util.*;

class WriteFile
{
	public static void main(String args[])
	{
		try
		{
			PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("MyDirectory\\MyTestFile1.txt")));
			System.out.println("Write some text : ");
			Scanner sobj=new Scanner(System.in);
			String a=sobj.nextLine();
			out.println(a);
			out.close();
		}
		catch(Exception e)
		{
		}
	}
}
