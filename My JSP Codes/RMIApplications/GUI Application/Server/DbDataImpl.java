import java.rmi.*;
import java.rmi.server.*;
import java.sql.*;


class DbDataImpl extends UnicastRemoteObject implements DbData{
	public DbDataImpl() throws RemoteException {
	}
	public String getEmpData(int deptno)  {
		String data="";
		try {
			String dsn = "rmi_ex";
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con = DriverManager.getConnection("jdbc:odbc:"+dsn, "scott", "tiger");
			String qry = "Select * from emp";
			if(deptno!=0) {
				qry += " where deptno="+deptno;
			}
			Statement st = con.createStatement();

			ResultSet rs = st.executeQuery(qry);
			while(rs.next()) {
				data +=rs.getString(1) +","+rs.getString(2)+","+rs.getString(3)+"," +rs.getString(4) +","+rs.getString(5) +","+rs.getString(6) +","+rs.getString(7) +","+rs.getString(8)+"#";
			}
			rs.close();
			con.close();
		}
		catch(Exception ex) {
		}
		return data;
	}
}