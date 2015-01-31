package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class SampleTest extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        HttpSession session=request.getSession(true);
	    String test[][]=null;
        int counter=0;
	    if(test==null)
	    {
			int arrayIndex=0;
			try
			{
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection con=DriverManager.getConnection("jdbc:odbc:onlineexam");
				Statement st=con.createStatement();
				ResultSet rs=st.executeQuery("select * from samplepaper");

				while(rs.next())
				{
					arrayIndex+=1;
				}
				rs.close();
				con.close();
			}
			catch(Exception e)
			{
				e.toString();
		    }
            counter=arrayIndex;
		    test=new String[arrayIndex][6];
		    try
			{
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection con=DriverManager.getConnection("jdbc:odbc:onlineexam");
				Statement st=con.createStatement();
				ResultSet rs=st.executeQuery("select * from samplepaper");
				int i=0;
				while(rs.next())
				{
					test[i][0]=rs.getString(1);
					test[i][1]=rs.getString(2);
					test[i][2]=rs.getString(3);
					test[i][3]=rs.getString(4);
					test[i][4]=rs.getString(5);
					test[i][5]=rs.getString(6);
					i++;
				}
				rs.close();
				con.close();
			}
			catch(Exception e)
			{
				e.toString();
		    }
		}

        if(session.getAttribute("questionParameters")==null || (session.getAttribute("questionParameters")+"").equals(""))
        {
			//session.setAttribute("questionParameters","hello");
			session.setAttribute("questionParameters",""+test[0][0]+"%"+test[0][1]+"%"+test[0][2]+"%"+test[0][3]+"%"+test[0][4]+"%"+test[0][5]);
		    session.setAttribute("counter",0+"");
		}
		else
		{
			//String temp[]=(session.getAttribute("questionParameters")+"").split("%");
			//int qNo=Integer.parseInt(temp[0]);
			//qNo--;
			String temp=session.getAttribute("counter")+"";
			int i=Integer.parseInt(temp);
			i++;
			if(i>counter-1)
			{
				response.sendRedirect("test.jsp");
				session.removeAttribute("counter");
				session.removeAttribute("questionParameters");
				return;
			}
			session.setAttribute("questionParameters",""+test[i][0]+"%"+test[i][1]+"%"+test[i][2]+"%"+test[i][3]+"%"+test[i][4]+"%"+test[i][5]);
		    session.setAttribute("counter",i+"");
		}
		response.sendRedirect("sampleTest.jsp");
        /*
		response.setContentType("text/html");
		PrintWriter pw  = response.getWriter();
		String temp1[]=(session.getAttribute("questionParameters")+"").split("%");
        pw.println(temp1[0]);
        pw.println(temp1[1]);
        pw.println(temp1[2]);
        pw.println(temp1[3]);
        pw.println(temp1[4]);
        pw.println(temp1[5]);
        */
	}
}