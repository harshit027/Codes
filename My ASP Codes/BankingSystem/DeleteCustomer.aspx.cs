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

public partial class DeleteCustomer : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void showBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        dataLB.Visible = false;
        dataLB.Text = "";
        Database db = new Database();
        string query = "select * from customer where cid=" + idTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            dataLB.Visible = true;
            dataLB.Text="Name : "+reader[1] + ""+"<br/>";
            dataLB.Text += "Phone : " + reader[2] + "" + "<br/>";
            dataLB.Text += "EmailId : " + reader[3] + "" + "<br/>";
            dataLB.Text += "Address : " + reader[4] + "" + "<br/>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red;'>No such record</h4>";
        }
    }
    protected void deleteBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible=false;
        Database db = new Database();
        string query = "delete from customer where cid=" + idTB.Text;
        if (db.setdata(query) > 0)
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue'>Record Deleted</h4>";
        }
        else 
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue'>Error in deleting</h4>";
        }

    }
}
