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
    protected void ChangeColor(object sender, EventArgs e)
    {
        int counter = int.Parse(HiddenField1.Value);
        string[] colors = { "red", "blue", "lime", "yellow", "pink", "white", "purple" };
        Table1.BackColor = System.Drawing.Color.FromName(colors[counter]);
        counter++;
        if (counter == 6)
            counter = 0;
        HiddenField1.Value = "" + counter;
    
    }
}
