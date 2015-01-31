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
    protected void rb1_SelectedIndexChanged(object sender, EventArgs e)
    {
        hdn1.Value = rb1.SelectedValue;
    }
    protected void ChangeTheme(object sender, EventArgs e)
    {
        if (hdn1.Value == "")
        {
            Response.Write("First Select Theme");
        }
        else
        {
            Response.Redirect("Default.aspx?th=" + hdn1.Value);
        }
    }
}
