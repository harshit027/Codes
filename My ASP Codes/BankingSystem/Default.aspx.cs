using System;
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

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Request.QueryString["action"] == "logout")
        {
            Session.RemoveAll();
            Response.Redirect("Default.aspx");
        }
        if (Session["authentication"]+"" == "invalid")
        {
            Label1.Visible = true;
            Label1.Text = "Invalid Username Password";
        }
        

    }
    protected void loginBTN_Click(object sender, EventArgs e)
    {
        Database db = new Database();
        string query = "select * from employee where empname='" + usernameTB.Text + "' and emppwd='" + passwordTB.Text + "'";
        SqlDataReader dr = db.getdata(query);

        if (dr.Read())
        {
            Session.Add("authentication", "valid");
            Session.Add("username", usernameTB.Text+"");
            Response.Redirect("StaffHome.aspx");
            
        }
        else
        {

            Session.Add("authentication", "invalid");
            Session.Add("username",  "");
            Response.Redirect("StaffHome.aspx");
            
        }

    }
}
