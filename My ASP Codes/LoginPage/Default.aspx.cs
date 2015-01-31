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

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void loginCheck(object sender, EventArgs e)
    {
        messageLit.Visible=false;
       
        if (usernameTB.Text.Equals("pace") && passwordTB.Text.Equals("bureau"))
        {
            Response.Redirect("game.aspx");

        }
        else
        {
           messageLit.Visible = true;
           messageLit.Text = "Invalid Username/Password";
        }
    }
}
