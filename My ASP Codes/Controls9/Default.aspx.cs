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
    protected void Page_PreInit(object sender, EventArgs e)
    {
        string th_name = "btnMagenta";
        if (Request.QueryString["th"] == "yellow")
        {
            th_name = "btnYellow";
        }
        Button1.SkinID = th_name;
        Button2.SkinID = th_name;
        Button3.SkinID = th_name;
        Button4.SkinID = th_name;
        Button5.SkinID = th_name;
        Button6.SkinID = th_name;
        Button7.SkinID = th_name;
        Button8.SkinID = th_name;
        Button9.SkinID = th_name;
        Button10.SkinID = th_name;
        Button11.SkinID = th_name;
        Button12.SkinID = th_name;
    }
}
