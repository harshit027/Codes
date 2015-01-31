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

public partial class NewAccount : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void resetBTN_Click(object sender, EventArgs e)
    {
        idTB.Text = "";
        currentbalTB.Text = "";
        Label1.Visible = false;
    }
    protected void submitBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        DateTime todayDate = DateTime.Today;
        int dd = todayDate.Day;
        int mm = todayDate.Month;
        int yy = todayDate.Year;
        string openingDate = "" + mm + "/" + dd + "/" + yy;
        Database db = new Database();
        string query = "insert into account (cid,acctype,date,balance) values (" + idTB.Text + ",'" + acctypeDDL.SelectedValue + "','" + openingDate + "'," + currentbalTB.Text+")";
        if (db.setdata(query) > 0)
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue;'>Account Created</h4>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue;'>Error in creating account</h4>";
        }
    }
}
