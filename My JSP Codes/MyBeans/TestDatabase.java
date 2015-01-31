import java.sql.*;
import java.util.*;

class TestDatabase
{
public static void main(String args[])
	{

        String dsn="student_dsn";
		String query="delete from students where sid=4";
        Database db1=new Database();
			if(db1.setData(query,dsn)>0)
		   {
			  System.out.println("Query Processed Successfully !");
		   }
		   else
		   {
		    	System.out.println("Processing Failed!");
		    }
		   try
		   {
		    	db1.closeConnection();
		   }
		   catch(Exception ex)
		   {
		    	System.out.println("Error : "+ex);
		   }


		Database db=new Database();
		query="select * from students";

		try
		{
			ResultSet rs=db.getData(query,dsn);
			while (rs.next())
			{
				System.out.print(rs.getString(1)+"---");
				System.out.print(rs.getString(2)+"---");
				System.out.print(rs.getString(3)+"---");
				System.out.println(rs.getString(4)+"---");
			}
            rs.close();
            db.closeConnection();
		}
		catch(Exception ex)
		{
			System.out.println("Error : "+ex);
		}
	}
}