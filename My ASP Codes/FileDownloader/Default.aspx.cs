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
using System.IO;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void moreFiles(object sender, EventArgs e)
    {
        string[] f = Directory.GetFiles(Request.PhysicalApplicationPath+"/morefiles");
        foreach (string s in f)
        {
            string[] arr = s.Split("/\\".ToCharArray());
            string filename = arr[arr.Length - 1];
            Literal1.Text += "<a href='morefiles/" + filename + "'>" + filename + "</a><br>";
        }
    }
}
