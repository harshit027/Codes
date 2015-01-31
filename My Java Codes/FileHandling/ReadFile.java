import java.io.*;
import java.util.*;

class ReadFile
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader in=new BufferedReader(new FileReader("MyDirectory\\MyTestFile1.txt"));
			//System.out.println("The contents of file are :\n"+in.readLine());
			String s1=new String();
			String s2=new String();
			while((s1=in.readLine())!=null)
			{
				s2=s2+s1+"\n";
			}
			System.out.println(s2);
			in.close();
		}
		catch(Exception e)
		{
		}
	}
}
