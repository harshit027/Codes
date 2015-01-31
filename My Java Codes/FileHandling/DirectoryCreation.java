import java.io.*;
import java.util.*;


 class DirectoryCreation
 {
      public static void main(String[] args)
      {
		  File f=new File("MyDirectory");
		  f.mkdirs();
		  System.out.println("A directory named "+f.getName()+" is created in current folder");
		  System.out.println("Absolute path: " + f.getAbsolutePath() +
                                        "\nCan read: " + f.canRead() +
                                        "\nCan write: " + f.canWrite() +
                                        "\ngetName: " + f.getName() +
                                        "\ngetParent: " + f.getParent() +
                                        "\ngetPath: " + f.getPath() +
                                        "\nlength: " + f.length() );

	  }
}