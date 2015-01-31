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

public partial class Default3 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btn1_Click(object sender, EventArgs e)
    {
        string s = "Number of Values Posted :" + Request.Form.Count;
        //foreach (string s1 in Request.Form)
        //{
        //    s += "<br>" + Request.Form[s1];
        //}
        string[] v1 = { "tb1", "TextBox1", "TextBox2" };
        for (int i = 0; i <= 2; i++)
        {
            s += "<br>" + Request.Form[v1[i]];
        }
        Response.Write(s);
        //Response.Redirect("Default4.aspx");
    }
}
