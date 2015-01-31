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
        Response.Write("ApplicationPath : "+Request.ApplicationPath+"<br>");
        Response.Write("BrowserVersion : " + Request.Browser.Version + "<br>");
        Response.Write("PhysicalApplicationPath : " + Request.PhysicalApplicationPath + "<br>");
        Response.Write("URL : " + Request.Url.ToString() + "<br>");
        Response.Write("Host Address : " + Request.UserHostAddress.ToString() + "<br>");
        Response.Write("Host Name : " + Request.UserHostName+ "<br>");
        Response.Write("RequestType : " + Request.RequestType+ "<br>");
    }

}
