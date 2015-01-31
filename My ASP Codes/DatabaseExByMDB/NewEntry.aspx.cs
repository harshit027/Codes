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
using System.Data.OleDb;

public partial class NewEntry : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void save_Click(object sender, EventArgs e)
    {
        Label1.Visible = true;
        try
        {
            string insertQuery = "INSERT INTO student(sname, scollege, sbranch, sphoneno) values ('" + TextBox1.Text + "','" + TextBox2.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "')";
            AccessDataSource1.InsertCommand = insertQuery;
            if (AccessDataSource1.Insert() > 0)
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Saved Successfully</h4>";
            }
            else
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Error in saving</h4>";
            }
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }

    }
    protected void reset_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        TextBox2.Text = "";
        TextBox3.Text = "";
        TextBox4.Text = "";
    }
}
