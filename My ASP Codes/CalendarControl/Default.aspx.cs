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


    protected void ShowDate(object sender, EventArgs e)
    {
        literal1.Visible = true;
        Button btn = (Button)sender;
        if (btn.ID == "currentDate")
        {
            literal1.Text = calendar1.TodaysDate+"";
        }
        else if (btn.ID == "selectedDate")
        {
            literal1.Text = calendar1.SelectedDate+"";
        }
    }
}
