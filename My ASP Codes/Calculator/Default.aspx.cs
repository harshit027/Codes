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
    protected void Calculate(object sender, EventArgs e)
    {
        Button btn = (Button)sender;
        if (btn.Text == "=")
        {
            float f1 = float.Parse(Literal3.Text);
            float f2 = float.Parse(Literal1.Text);
            if (Literal2.Text == "+")
            {
                Literal1.Text = (f1 + f2).ToString();
            }
            if (Literal2.Text == "-")
            {
                Literal1.Text = (f1 - f2).ToString();
            }
            if (Literal2.Text == "*")
            {
                Literal1.Text = (f1 * f2).ToString();
            }
            if (Literal2.Text == "/")
            {
                Literal1.Text = (f1 / f2).ToString();
            }
        }
        else
        {
            if (btn.Text == "/" || btn.Text == "*" || btn.Text == "-" || btn.Text == "+")
            {
                Literal2.Text = btn.Text;
                Literal3.Text = Literal1.Text;
                Literal1.Text = "0";
            }
            else
            {
                if (Literal1.Text == "0")
                {
                    Literal1.Text = btn.Text;
                }
                else
                {
                    Literal1.Text = Literal1.Text + btn.Text;
                }
            }
        }
    }
}
