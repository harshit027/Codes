import java.net.*;
import java.io.*;

class ExampleClient
{
    public static void main(String[] args) throws IOException
    {
       // Passing null to getByName() produces the
       // special "Local Loopback" IP address, for
       // testing on one machine w/o a network:
       InetAddress addr =
       InetAddress.getByName(null);
       // Alternatively, you can use
       // the address or name:
       // InetAddress addr =
       //    InetAddress.getByName("127.0.0.1");
       // InetAddress addr =
       //    InetAddress.getByName("localhost");
       System.out.println("addr = " + addr);
       Socket socket =
       new Socket(addr, ExampleServer.PORT);
       // Guard everything in a try-finally to make
       // sure that the socket is closed:

      try
	  {
		  String message="";
          //System.out.println("Hello client ,you are connected : " + socket);
          BufferedReader in =
             new BufferedReader(
                 new InputStreamReader(
          socket.getInputStream()));
          // Output is automatically flushed
          // by PrintWriter:
          PrintWriter out =
                 new PrintWriter(
					 new BufferedWriter(
						 new OutputStreamWriter(socket.getOutputStream())),true);
          BufferedReader inkb=
          new BufferedReader(
			  new InputStreamReader(System.in));
           while(true)
           {
	          message=in.readLine();
	          if(message.equalsIgnoreCase("exit"))
	          break;
	          System.out.println("Server : "+message);
		      message=inkb.readLine();
		      out.println(message);
	       }
	   }
       catch(Exception e)
       {
	    	e.toString();
	   }
	    System.out.println("closing connections...");
        socket.close();
	}
}