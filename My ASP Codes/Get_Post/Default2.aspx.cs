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
    protected void Button1_Click(object sender, EventArgs e)
    {
        string s = "Number of Values :" + Request.QueryString.Count;
        s += "<br>Values are :";
        for (int i = 0; i <= Request.QueryString.Count - 1; i++)
        {
            s += "<br>" + Request.QueryString[i];
        }
        Response.Write(s);
    }
}
