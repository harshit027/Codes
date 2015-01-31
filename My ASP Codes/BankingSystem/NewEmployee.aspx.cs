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

public partial class NewEmployee : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    
    protected void resetBTN_Click(object sender, EventArgs e)
    {
        nameTB.Text = "";
        passwordTB.Text = "";
        phoneTB.Text = "";
        addressTB.Text = "";
        emailTB.Text = "";
        Label1.Visible = false;
    }

    protected void submitBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible=false;
        
            Database db = new Database();
            string query = "insert into employee (empname,emppwd,empphone,empemail,empaddress) values('" + nameTB.Text + "','" + passwordTB.Text + "','" + phoneTB.Text + "','" + emailTB.Text + "','" + addressTB.Text + "')";
            int n;
            n = db.setdata(query);
            if (n > 0)
            {
                Label1.Visible = true;
                Label1.Text = "<h4 style='background-color:white; color:blue;'>Saved Successfully</h4>";
            }
            else
            {
                Label1.Visible = true;
                Label1.Text = "<h4 style='background-color:white; color:red;'>Error in saving</h4>";
            }
        
        
    }
}
