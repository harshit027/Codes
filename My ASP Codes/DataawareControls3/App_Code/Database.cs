using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;

/// <summary>
/// This class is used to manage database connectivity functions and variables
/// </summary>
public class Database
{
    private string constr = null;
    private SqlConnection con=null;
    private SqlCommand com = null;
    private SqlDataAdapter da = null;
    private DataSet ds = null;
    private SqlDataReader dr = null;

	public Database()
	{
        constr = ConfigurationManager.AppSettings["constr"];
    }
    public SqlDataReader getdata(string qry)
    {
        try
        {
            con = new SqlConnection(constr);
            con.Open();
            com = new SqlCommand(qry, con);
            dr = com.ExecuteReader();
        }
        catch (Exception ex)
        {
        }
        return dr;
    }
    public int setdata(string qry)
    {
        int n = 0;
        try
        {
            con = new SqlConnection(constr);
            con.Open();
            com = new SqlCommand(qry, con);
            n = com.ExecuteNonQuery();
        }
        catch (Exception ex)
        {

        }
        finally
        {
            if (con != null && con.State == ConnectionState.Open)
            {
                con.Close();
            }
        }
        return n;
    }
    public DataSet GetDataSet(string qry)
    {
        try
        {
            da = new SqlDataAdapter(qry, constr);
            ds = new DataSet();
            da.Fill(ds, "t1");
        }
        catch (Exception ex)
        {
        }
        finally
        {
            da.Dispose();
        }
        return ds;
    }
    public DataTable GetDataTable(string qry)
    {
        try
        {
            da = new SqlDataAdapter(qry, constr);
            ds = new DataSet();
            da.Fill(ds, "t1");
        }
        catch (Exception ex)
        {
        }
        finally
        {
            da.Dispose();
        }
        if (ds.Tables.Count > 0)
        {
            return ds.Tables[0];
        }
        else
        {
            return null;
        }
    }
}
