import java.sql.*;

class Database
{

    private Connection connection=null;
    private ResultSet resultSet=null;
    private Statement statement=null;

	private int count=0;
	public ResultSet getData(String query,String dsn)
	{

		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			this.connection=DriverManager.getConnection("jdbc:odbc:"+dsn,"","");
			this.statement=this.connection.createStatement();
			this.resultSet =this.statement.executeQuery(query);


		}
		catch(Exception ex)
		{
			System.out.println("Error : "+ex);
		}

		return resultSet;
	}

	public int  setData(String query,String dsn)
	{

		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			this.connection=DriverManager.getConnection("jdbc:odbc:"+dsn,"","");
			this.statement=this.connection.createStatement();
			this.count=this.statement.executeUpdate(query);

        }
		catch(Exception ex)
		{
			System.out.println("Error : "+ex);
		}

		return this.count;
	}

     public void closeConnection()
     {
		 try
		 {
			 this.connection.close();
		 }
		 catch(Exception ex)
		 {
			 System.out.println("Error : "+ex);
		 }
	 }


}
