import java.io.*;
import java.util.*;

class FileCreation
{
	public static void main(String args[])
	{
		//File Myfile=new File("F:\\My java appl\\FileHandling\\Myfile.txt");
		OutputStream out=new FileOutputStream("Myfile.txt");
		out.println("This text is written in myfile");
	}
}
