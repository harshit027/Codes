import java.io.*;
import java.util.*;


 class CheckingEOF
 {
      public static void main(String[] args)
      {
		 //FileInputStream in=new FileInputStream("1.txt");
		 try
		 {
			 DataInputStream in =new DataInputStream(
			                                  new BufferedInputStream(
			                                  new FileInputStream("MyDirectory\\MyTestFile1.txt")));
			 while(in.available() != 0)
		     System.out.print((char)in.readByte());

		 }
		 catch(Exception e)
		 {
			 System.out.println(e);
		 }

	  }
}