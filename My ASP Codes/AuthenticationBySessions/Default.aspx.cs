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
        if (Request.QueryString["action"] == "logout")
        {
            Session.RemoveAll();
            Response.Redirect("Default.aspx");
        }

        int id = 1;
        try
        {
            string line;
            StreamReader sr = new StreamReader(Request.PhysicalApplicationPath + "/Database/users.txt");
            while ((line = sr.ReadLine()) != null)
            {
                id += 1;
            }
            sr.Close();
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.Message);
        }
        TextBox1.Text = id + "";
        
    }
    protected void Save_Click(object sender, EventArgs e)
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
            string data = TextBox1.Text + "%" + TextBox2.Text + "%" + TextBox3.Text+"%"+TextBox4.Text+"%"+TextBox5.Text;
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
    protected void Reset_Click(object sender, EventArgs e)
    {
        TextBox1.Text = "";
        TextBox2.Text = "";
        TextBox3.Text = "";
        TextBox4.Text = "";
        TextBox5.Text = "";
    }
}
