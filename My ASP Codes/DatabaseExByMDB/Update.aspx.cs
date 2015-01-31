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

public partial class Update : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        try
        {
            Label1.Visible = true;
            string updateQuery = "update student set sname='" + TextBox2.Text + "' , scollege='" + TextBox3.Text + "' , sbranch='" + TextBox4.Text + "' , sphoneno='" + TextBox5.Text + "' where ID = " + TextBox1.Text;
            AccessDataSource1.UpdateCommand = updateQuery;
            if (AccessDataSource1.Update() > 0)
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Updated Successfully</h4>";
            }
            else
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Cannot be updated</h4>";

            }


        }
        catch (Exception ex)
        {
            //Response.Write(ex);
        }
    }
    protected void cancelBtn_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        TextBox2.Text = "";
        TextBox3.Text = "";
        TextBox4.Text = "";
        TextBox5.Text = "";

    }
}
