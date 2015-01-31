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
    protected void SendData(object sender, EventArgs e)
    {
        Response.Redirect("Default2.aspx?data1=" + TextBox1.Text + "&data2=" + TextBox2.Text + "&data3=" + TextBox3.Text);
    }
}
