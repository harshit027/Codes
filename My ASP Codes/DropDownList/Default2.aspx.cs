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
    protected void btn1_Click(object sender, EventArgs e)
    {
        txt1.Attributes.Add("style", "background-color:" + ddlColor.SelectedItem.Value);
        //txt1.Attributes.Add("style", "background-color:" + ddlColor.SelectedValue);

        /*txt1.BackColor 
            = System.Drawing.Color.FromName(ddlColor.SelectedItem.Text);*/
        /*switch(ddlColor.SelectedIndex)
        {
            case 0:
                txt1.BackColor = System.Drawing.Color.Red;
                break;
            case 1:
                txt1.BackColor = System.Drawing.Color.Green;
                break;
            case 2:
                txt1.BackColor = System.Drawing.Color.Blue;
                break;
            case 3:
                txt1.BackColor = System.Drawing.Color.Yellow;
                break;
            case 4:
                txt1.BackColor = System.Drawing.Color.Cyan;
                break;
        }*/
    }
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        btn1.BackColor = System.Drawing.Color.FromName(DropDownList1.SelectedValue);
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        
        string[] arr = { "harshit", "vaibhav", "mohit", "pradeep", "rahul", "gourav", "benny" };
        string[] col = { "red", "green", "blue", "yellow", "cyan", "magenta", "gray" };
        for (int i = 0; i <= arr.Length - 1; i++)
        {
            ListItem li = new ListItem(arr[i]);
            li.Attributes.Add("style", "color:" + col[i]);
            ddlnew.Items.Add(li);
        }
    }
}
