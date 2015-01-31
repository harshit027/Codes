import java.net.*;
class Test
{
	public static void main(String[] args)
	{
       try
       {
	    	InetAddress address = InetAddress.getLocalHost();
           System.out.println("Address "+address);
           /*
           * Get NetworkInterface for the current host and then read the
           * hardware address.
           */
           NetworkInterface ni = NetworkInterface.getByInetAddress(address);
           System.out.println("NI = "+ni);
           byte[] mac = ni.getHardwareAddress();


          /*
         * Extract each array of mac address and convert it to hexa with the
         * following format 08-00-27-DC-4A-9E.
         */

          System.out.print("MAC Address : ");
          for (int i = 0; i < mac.length; i++)
          {
              System.out.printf("%02X%s", mac[i], (i < mac.length - 1) ? "-" : "");
          }
          System.out.println("\n");
          String osname=System.getProperty("os");
          System.out.println("OS : "+osname);
       }
       catch (Exception e)
       {
         System.out.println(e);
       }
   }
}

