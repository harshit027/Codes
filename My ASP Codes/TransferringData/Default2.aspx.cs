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
    protected void ShowData(object sender, EventArgs e)
    {
        Response.Write("<br> Items Recieved : " + Request.QueryString.Count);
        Response.Write("<br> Name : " + Request.QueryString["data1"]);
        Response.Write("<br> Branch : " + Request.QueryString["data2"]);
        Response.Write("<br> College : " + Request.QueryString["data3"]);
    }
}
