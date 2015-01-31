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
   
    protected void myTest(object sender, EventArgs e)
    {
        if (sender is Button)
        {
            Response.Redirect("test.html");
            literal.Text = "Button clicked";
        }
        else if (sender is LinkButton)
        {
            Response.Redirect("test.html");
            literal.Text = "LinkButton clicked";
        }
        else if (sender is ImageButton)
        {
            Response.Redirect("test.html");
            literal.Text = "ImageButton clicked";
        }
    }

    protected void changeColor(object sender, EventArgs e)
    {
        /*if (dropDownList.SelectedIndex == 0)
            textbox.BackColor = System.Drawing.Color.Red;
        else if (dropDownList.SelectedIndex == 1)
            textbox.BackColor = System.Drawing.Color.Blue;
        else if (dropDownList.SelectedIndex == 2)
            textbox.BackColor = System.Drawing.Color.Green;
        else if (dropDownList.SelectedIndex == 3)
            textbox.BackColor = System.Drawing.Color.Yellow;*/
       // textbox.BackColor = System.Drawing.Color.FromName(dropDownList.SelectedValue);
    }
    protected void dropDownList_SelectedIndexChanged(object sender, EventArgs e)
    {
        textbox.BackColor = System.Drawing.Color.FromName(dropDownList.SelectedValue);
    }
}
