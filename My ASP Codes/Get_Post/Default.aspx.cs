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
    protected void btn1_Click(object sender, EventArgs e)
    {
        if (tb1.Text == "")
        {
            Response.Write("Error");
        }
        else
        {
            Response.Redirect("Default2.aspx?tb1=" + tb1.Text+"&tb2="+TextBox1.Text+"&tb3="+TextBox2.Text);
        }
    }
}
