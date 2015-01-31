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

public partial class EmpEntry : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void save_Click(object sender, EventArgs e)
    {
        Label1.Visible=true;
        string insertQuery = "insert into employee (empname,empqualification,empsalary,empdept) values ('" + TextBox1.Text + "','" + List1.SelectedItem.Text + "','" + TextBox3.Text + "','" + TextBox4.Text + "')";
        try
        {
            SqlDataSource1.InsertCommand = insertQuery;
            if (SqlDataSource1.Insert() > 0)
            {
                Label1.Text = "<h4 style='background-color:white; color:yellow;'>Saved Successfully</h4>";
            }
            else
                Label1.Text = "<h4 style='background-color:white; color:yellow;'>Problem in saving</h4>";
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }
    }
    protected void reset_Click(object sender, EventArgs e)
    {

    }
}
