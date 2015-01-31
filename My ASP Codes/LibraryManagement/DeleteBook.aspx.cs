using System;
using System.Collections;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;
using System.Data.SqlClient;

public partial class DeleteBook : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection con = null;
        Label1.Visible = false;
        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "delete from books where bookid=" + TextBox1.Text;
            com.CommandText = qry;
            if (com.ExecuteNonQuery() > 0)
            {
                Label1.Text = "<span style='color:green'>Book Deleted</span>";
            }
            else
            {
                Label1.Text = "<span style='color:green'>Book Cannot be Deleted</span>";
            }
            Label1.Visible = true;
        }
        catch (Exception ex)
        {
            Label1.Visible = true;
            Label1.Text = "<span style='color:red'>" + ex.Message + "</span>";
        }
        finally
        {
            if (con.State == ConnectionState.Open)
                con.Close();
        }
    }
}
