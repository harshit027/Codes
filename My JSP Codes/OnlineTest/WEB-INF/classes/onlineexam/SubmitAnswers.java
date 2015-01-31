package onlineexam;

import javax.servlet.*;
import java.io.*;
import java.sql.*;
import javax.servlet.http.*;

public class SubmitAnswers extends HttpServlet {

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {

        HttpSession session=request.getSession(true);
	    String answers[]=null;
	    String correctAnswers[]=null;
        int counter=0;
	    if(answers==null)
	    {
			int arrayIndex=0;
			try
			{
				Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				Connection con=DriverManager.getConnection("jdbc:odbc:onlineexam");
				Statement st=con.createStatement();
				ResultSet rs=st.executeQuery("select * from mainpaper");

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
            answers=new String[arrayIndex];
            correctAnswers=new String[arrayIndex];

              try
			   {
				  Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
				  Connection con=DriverManager.getConnection("jdbc:odbc:onlineexam");
				  Statement st=con.createStatement();
				  ResultSet rs=st.executeQuery("select * from mainpaper");
				  int i=0;
				  while(rs.next())
				  {
					  correctAnswers[i]=rs.getString(7);
					  i++;
				  }
				  rs.close();
				  con.close();
			   }
			    catch(Exception e)
			    {
			    }
		}

       if(session.getAttribute("counterInSubmit")==null && (session.getAttribute("counter")+"").equals(""))
        {
			session.setAttribute("counterInSubmit",0+"");
		}



			  String temp=session.getAttribute("counterInSubmit")+"";
		      int i=Integer.parseInt(temp);
		      answers[i]=request.getParameter("option")+"";
		      i++;

		    if(i>counter-1)
		    {
				int marksObtained=0;
				for(int j=0;j<counter;j++)
				{
					if(answers[j]==correctAnswers[j])
					{
						marksObtained++;
					}
				}
			  session.setAttribute("result",marksObtained+"$"+counter+"");
			  response.sendRedirect("endTest.jsp");
			  return;
		  }

		session.setAttribute("counterInSubmit",i+"");

        response.sendRedirect("mainTest.jsp");

	}
}