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

public partial class SearchCustomer : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void searchBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        
        
        Database db = new Database();
        string query = "select * from customer where cid=" + idTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            Label1.Visible = true;
            Label1.Text = "Name : " + reader[1] + "" + "<br/>";
            Label1.Text += "Phone : " + reader[2] + "" + "<br/>";
            Label1.Text += "EmailId : " + reader[3] + "" + "<br/>";
            Label1.Text += "Address : " + reader[4] + "" + "<br/>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red; text-align:center'>No such record</h4>";
        }
    }
}
