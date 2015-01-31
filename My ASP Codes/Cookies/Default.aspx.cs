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
    protected void StoreCookie(object sender, EventArgs e)
    {
        try
        {
            HttpCookie cookie1 = new HttpCookie("cookie1", TextBox1.Text);
            cookie1.Expires = new DateTime(2010, 12, 10);
            Response.SetCookie(cookie1);
            HttpCookie cookie2 = new HttpCookie("cookie2", TextBox2.Text);
            cookie2.Expires = new DateTime(2010, 12, 10);
            Response.SetCookie(cookie2);
            Response.Redirect("Default2.aspx");
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.ToString());
        }
        
    }
}
