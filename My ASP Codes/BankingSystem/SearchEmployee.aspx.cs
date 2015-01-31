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

public partial class SearchEmployee : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void cancelBTN_Click(object sender, EventArgs e)
    {
        Response.Redirect("StaffHome.aspx");
    }

    protected void searchBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        nameTB.Text = "";
        
        phoneTB.Text = "";
        addressTB.Text = "";
        emailTB.Text = "";
        Database db = new Database();
        string query = "select * from employee where empid="+idTB.Text;
        SqlDataReader dr = db.getdata(query);

        if (dr.Read())
        {
            idTB.Text = dr[0] + "";
            nameTB.Text = dr[1] + "";
            phoneTB.Text = dr[3] + "";
            emailTB.Text = dr[4] + "";
            addressTB.Text = dr[5] + "";
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue;'>Record Found</h4>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red;'>No Record Found</h4>";
        }

    }
}
