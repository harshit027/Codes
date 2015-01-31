import java.io.*;
import java.net.*;

 class ExampleServer
  {
	  // Choose a port outside of the range 1-1024:
      public static final int PORT = 8080;
      public static void main(String[] args)throws IOException
      {
         ServerSocket s = new ServerSocket(PORT);
         System.out.println("Started: " + s);
         try
         {
			 // Blocks until a connection occurs:
             Socket socket = s.accept();
             try
		     {
				 String message="Hello Client, Your are connected : "+socket;
                 System.out.println( "Connection accepted: "+ socket);
                 BufferedReader in =
                   new BufferedReader(
                     new InputStreamReader(
                        socket.getInputStream()));
                 // Output is automatically flushed
                 // by PrintWriter:
                 PrintWriter out =
                       new PrintWriter(
						   new BufferedWriter(
							   new OutputStreamWriter(
								   socket.getOutputStream())),true);
                 BufferedReader inkb=
                   new BufferedReader(
		             	new InputStreamReader(System.in));
                  while (true)
		    	  {
					  out.println(message);
                      message=in.readLine();
                       if(message.equalsIgnoreCase("exit"))
                       break;
                       System.out.println("Client : "+message);
                       message=inkb.readLine();
				   }
                   // Always close the two sockets..
			   }
              catch(Exception e)
              {
				  e.toString();
			  }
			  System.out.println("closing connections...");
              socket.close();
		  }
          catch(Exception e)
          {
			  e.toString();
		  }
          s.close();
	  }
}