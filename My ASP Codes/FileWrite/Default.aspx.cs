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
using System.IO;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
   
    protected void submitClick(object sender, EventArgs e)
    {
        try
        {
            string dirpath = Request.PhysicalApplicationPath + "/Database";
            if (!Directory.Exists(dirpath))
            {
                Directory.CreateDirectory(dirpath);
            }
            if (!File.Exists(dirpath + "/users.txt"))
            {
                File.Create(dirpath + "/users.txt");
            }
            string data = TextBox1.Text + "%" + TextBox2.Text + "%" + TextBox3.Text;
            FileStream fs = File.Open(dirpath + "/users.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine(data);
            sw.Close();
            fs.Close();
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.ToString());
        }

    }
    protected void resetClick(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        TextBox2.Text = "";
        TextBox3.Text = "";
    }
}
