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

public partial class UpdateCustomer : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void resetBTN_Click(object sender, EventArgs e)
    {
        idTB.Text = "";
        nameTB.Text = "";
        phoneTB.Text = "";
        emailTB.Text = "";
        addressTB.Text = "";
        Label1.Visible=false;
    }
    protected void submitBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible=false;
        Database db = new Database();
        string query = "update customer set cname='" + nameTB.Text + "', cphone='" + phoneTB.Text + "', cemail='" + emailTB.Text + "', caddress='" + addressTB.Text + "' where cid=" + idTB.Text;
        if(db.setdata(query)>0)
        {
            Label1.Visible=true;
            Label1.Text = "<h4 style='background-color:white; color:blue;'>Update Successfully</h4>";
        }
        if(db.setdata(query)>0)
        {
            Label1.Visible=true;
            Label1.Text="<h4 style='background-color:white; color:red;'>Error in updating</h4>";
        }
    }


   
    protected void showDataBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible=false;
        nameTB.Text = "";
        phoneTB.Text = "";
        emailTB.Text = "";
        addressTB.Text = "";
        Database db = new Database();
        string query = "select * from customer where cid=" + idTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            nameTB.Text = reader[1] + "";
            phoneTB.Text = reader[2] + "";
            emailTB.Text = reader[3] + "";
            addressTB.Text = reader[4] + "";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red;'>No such record</h4>";
        }

    }
    
}
