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
    protected void ShowView(object sender, EventArgs e)
    {
        Button btn = (Button)sender;
        if (btn.ID == "Button1")
            MultiView1.ActiveViewIndex = 0;
        else if (btn.ID == "Button2")
            MultiView1.ActiveViewIndex = 1;
        else if (btn.ID == "Button3")
            MultiView1.ActiveViewIndex = 2;
        else if (btn.ID == "Button4")
            MultiView1.ActiveViewIndex = 3;
    }
}
