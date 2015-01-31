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

public partial class Default2 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Request.QueryString["username"] == "harshit" && Request.QueryString["password"] == "spider")
        {
            Response.Write("<br>Username : " + Request.QueryString["username"]);
            Response.Write("<br>Password : " + Request.QueryString["password"]);
        }
        else
        {
            Response.Redirect("Default.aspx?authentication=Invalid Username/Password");
        }
    }
    protected void LinkButton1_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default.aspx?action=logout");
    }
}
