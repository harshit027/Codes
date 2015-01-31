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
        ErrorMsgLiteral.Visible = false;
        try
        {
        double d1 = double.Parse(firstNumberTB.Text);
        double d2 = double.Parse(secondNumberTB.Text);
        double d3 = 0;
        Button btn=(Button) sender;
        
            if (btn.Text == "+")
            {
                d3 = d1 + d2;
                resultTB.Text = d3 + "";
            }
            else
                if (btn.Text == "-")
                {
                    d3 = d1 - d2;
                    resultTB.Text = d3 + "";
                }
                else
                    if (btn.Text == "*")
                    {
                        d3 = d1 * d2;
                        resultTB.Text = d3 + "";
                    }
                    else if (btn.Text == "/")
                    {
                        d3 = d1 / d2;
                        resultTB.Text = d3 + "";
                    }
        }

        catch (Exception ex)
        {
            ErrorMsgLiteral.Visible = true;
            ErrorMsgLiteral.Text = "Error : " + ex.Message;
        }
    }
}
