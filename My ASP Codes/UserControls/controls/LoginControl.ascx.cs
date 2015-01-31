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

public partial class controls_LoginControl : System.Web.UI.UserControl
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Visible=false;
        
        if (TextBox1.Text == "harshit" && TextBox2.Text == "spider")
        {
            Label1.Visible = true;
            Label1.Text = "Perfect";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "Invalid Username/Password";
        }
    }
}
