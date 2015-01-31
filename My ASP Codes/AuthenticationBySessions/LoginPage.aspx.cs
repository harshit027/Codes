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
using System.IO;

public partial class LoginPage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {    
    }
    protected void Login_Click(object sender, EventArgs e)
    {
        int flag = 0;
        try
        {
            StreamReader sr = new StreamReader(Request.PhysicalApplicationPath + "/Database/users.txt");
            string line1;
            while ((line1 = sr.ReadLine()) != null)
            {
                //data = sr.ReadLine();
                //Response.Write("<br>" + line);
                string[] authentication = line1.Split("%".ToCharArray());
                if (TextBox1.Text == authentication[1] && TextBox2.Text == authentication[2])
                {
                    flag = 1;
                    break;
                }
                else
                {
                    Literal1.Text = "<h4 style='background-color:Red; color:Yellow;'>Invalid Username/Password</h4>";
                    Literal1.Visible = true;
                }
            }
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }

        if (flag == 1)
        {
            Session.Add("Var1", "validuser");
            Response.Redirect("DataPage.aspx");
        }
        
    }
}
