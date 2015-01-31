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

    }
    protected void RetrieveCookie(object sender, EventArgs e)
    {
        try
        {
            HttpCookieCollection hcc = Request.Cookies;
            HttpCookie cookie1 = hcc[0];
            if (cookie1.Name == "cookie1")
            {
                TextBox1.BackColor = System.Drawing.Color.FromName(cookie1.Value);
            }
            HttpCookie cookie2 = hcc[1];
            if (cookie2.Name == "cookie2")
            {
                TextBox2.BackColor = System.Drawing.Color.FromName(cookie2.Value);
            }
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.ToString());
        }
    }
}
