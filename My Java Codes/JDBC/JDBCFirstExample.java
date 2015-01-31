import java.sql.*;

class JDBCFirstExample {
	public static void main(String args[]) {
		try {
			String dsn = "student_database";
			String qry = "SELECT * FROM student  ";
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:"+dsn);
			Statement st = con.createStatement();
			ResultSet rs =st.executeQuery(qry);
			while(rs.next()) {
				System.out.print(rs.getString(1)+" ");
				System.out.print(rs.getString(2)+" ");
				System.out.print(rs.getString(3)+" ");
				System.out.println(rs.getString(4));

			}
			rs.close();
			con.close();
		}
		catch(Exception e) {
			System.out.println("Error :"+e);
		}
	}
}
