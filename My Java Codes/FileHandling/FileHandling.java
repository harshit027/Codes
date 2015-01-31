import java.io.*;
import java.util.*;

class FileHandling
{
	public static void main(String args[])
	{
		File f=new File("F:\\My java appl\\Mybook\\MyBook.java ");
		String str;
		str=f.getName();
		str+="\nPath : "+f.getPath();
		str+="\nAbsolute Path :"+f.getAbsolutePath();
		str+="\nParent : "+f.getParent();
		str+="\nLast Modified : "+f.lastModified();
		System.out.println(str);

	}
}
