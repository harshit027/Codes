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

public partial class NewMember : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        SqlConnection con = null;

        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "insert into members (mname, maddress, mphone, mmobile, memail) values ('" + nameTB.Text + "','" + addressTB.Text + "','" + phoneTB.Text + "','" + mobileTB.Text + "','" + emailTB.Text + "')";
            com.CommandText = qry;

            int n = com.ExecuteNonQuery();
            if (n >= 0)
            {
                Label1.Text = "<span style='color:green'>Member Added Successfully</span>";
            }
            else
            {
                Label1.Text = "<span style='color:red'>Unable to add member, Please check the data entered</span>";
            }
            Label1.Visible = true;


        }
        catch (Exception ex)
        {
            Label1.Text = "<span style='color:red'>Error :" + ex.ToString() + "</span>";
            Label1.Visible = true;

        }
        finally
        {
            if (con.State == ConnectionState.Open) 
            con.Close();
        }

    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        nameTB.Text = "";
        addressTB.Text = "";
        phoneTB.Text = "";
        emailTB.Text = "";
        mobileTB.Text = "";
    }
}
