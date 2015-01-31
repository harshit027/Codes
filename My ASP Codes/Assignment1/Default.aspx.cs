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
    protected void ddl1_SelectedIndexChanged(object sender, EventArgs e)
    {
        String[] indiaStates = { "Rajasthan", "Punjab", "Kerala", "Assam" };
        String[] pakistanStates = { "Lahore", "Karachi", "Islamabad", "Rawalpindi" };
        String[] russiaStates = { "Moscow", "Saint Petersburg", "Novosirisk", "Kazan" };
        String[] chinaStates = { "Beijing", "Fuzhou", "Shaghai", "Lhasa" };
        String[] colors = { "red", "blue", "green", "yellow" };

        if (ddlCountries.SelectedValue == "India")
        {
            for (int i = 0; i < 4; i++)
            {
                ddlStates.Items.Add(indiaStates[i]);
            }
        }
        else if (ddlCountries.SelectedValue == "China")
        {
            for (int i = 0; i < 4; i++)
            {
                ddlStates.Items.Add(chinaStates[i]);
            }
        }
        else if (ddlCountries.SelectedValue == "Pakistan")
        {
            for (int i = 0; i < 4; i++)
            {
                ddlStates.Items.Add(pakistanStates[i]);
            }
        }
        else if (ddlCountries.SelectedValue == "Russia")
        {
            for (int i = 0; i < 4; i++)
            {
                ddlStates.Items.Add(russiaStates[i]);
            }
        }
    }
}
