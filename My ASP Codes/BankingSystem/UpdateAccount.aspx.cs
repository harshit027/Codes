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

public partial class UpdateAccount : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void showBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;


        Database db = new Database();
        string query = "select * from account where accno=" + accountNoTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            Label1.Visible = true;
            Label1.Text = "Account No : " + reader[0] + "" + "<br/>";
            Label1.Text += "Customer Id : " + reader[1] + "" + "<br/>";
            Label1.Text += "Account Type : " + reader[2] + "" + "<br/>";
            Label1.Text += "Opening Date : " + reader[3] + "" + "<br/>";
            Label1.Text += "Current Balance : " + reader[4] + "" + "<br/>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red; text-align:center'>No such record</h4>";
        }
    }
    protected void submitBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        Database db = new Database();
        string query = "update account set acctype= '" + acctypeDDL.SelectedValue + "' where accno=" + accountNoTB.Text;
        if (db.setdata(query) > 0)
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue; text-align:center'>Updated Successfully</h4>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red; text-align:center'>Error in updating</h4>";
        }
    }
}
