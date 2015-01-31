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

public partial class Delete : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void deleteBtn_Click(object sender, EventArgs e)
    {
        Label1.Visible = true;
        try
        {
            string deleteQuery = "delete from student where ID=" + TextBox1.Text;
            AccessDataSource1.DeleteCommand = deleteQuery;
            if (AccessDataSource1.Delete() > 0)
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Record Deleted</h4>";
            }
            else
            {
                Label1.Text = "<h4 style='background-color:white; color:red;'>Cannot be Deleted</h4>";
            }


        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }

    }
    protected void cancelBtn_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "";
    }
}
