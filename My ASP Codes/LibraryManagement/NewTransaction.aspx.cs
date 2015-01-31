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

public partial class NewTransaction : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void cancelBTN_Click(object sender, EventArgs e)
    {
        memberidTB.Text = "";
        bookidTB.Text = "";
        dateTB.Text = "";
        Response.Redirect("Default.aspx");
    }
    protected void okBTN_Click(object sender, EventArgs e)
    {
        SqlConnection con = null;
        Label1.Visible=false;
        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";

            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "insert into transactions (bookID, memberID, dateOfTrans, typeOfTrans) values (" + bookidTB.Text + "," + memberidTB.Text + ",'" + dateTB.Text + "','" + type_of_transLT.SelectedValue.ToString()+ "')" ;

            com.CommandText = qry;
            if (com.ExecuteNonQuery() > 0)
            {
                Label1.Visible = true;
                Label1.Text = "<span style='color:green'>Transaction Succeeded</span>";
            }
            else
            {
                Label1.Visible = true;
                Label1.Text = "<span style='color:green'>Transaction Failed</span>";
            }
        }
        catch (Exception ex)
        {
            Label1.Visible = true;
            Label1.Text = "<span style='color:green'>"+ex.Message+"</span>";
        }

    }
}
