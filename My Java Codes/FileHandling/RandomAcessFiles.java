import java.io.*;

class RandomAcessFiles
{
	public static void main(String args[])
	{
		try
		{
			RandomAccessFile raf=new RandomAccessFile("MyDirectory\\MyTestFile2.dat","rw");
		    for(int i=0;i<10;i++)
		    {
		    	raf.writeDouble(i*2.5);
		    }
		    raf.close();

		    raf=new RandomAccessFile("MyDirectory\\MyTestfile2.dat","r");
		    for(int i=0;i<10;i++)
		    {
		    	System.out.println(i+" : "+raf.readDouble());
		    }
		    raf.close();

		    raf=new RandomAccessFile("MyDirectory\\MyTestFile2.dat","rw");
		    raf.seek(2*8);
		    raf.writeDouble(3.33);
		    raf.close();

		    raf=new RandomAccessFile("MyDirectory\\MyTestFile2.dat","r");
		    System.out.println("Updated Data is .....");
		    for(int i=0;i<10;i++)
		    {
				System.out.println(i+" : "+raf.readDouble());
			}
			raf.close();
		}
		catch(Exception e)
		{
		}

	}
}
