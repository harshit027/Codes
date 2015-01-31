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
        if (Request.QueryString.Count > 0)
        {
            if (Request.QueryString["authentication"] != null)
            {
                Literal1.Text = Request.QueryString["authentication"];
                Literal1.Visible = true;
            }

            else if (Request.QueryString["action"] != null)
            {
                Response.Write(Request.QueryString["action"]);
            }
        }
    }
    protected void Login_Click(object sender, EventArgs e)
    {
        Response.Redirect("Default2.aspx?username=" + TextBox1.Text + "&password=" + TextBox2.Text);
    }
}
