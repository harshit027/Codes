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
using System.Net.Mail;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        try
        {
            MailAddress to = new MailAddress(TextBox1.Text);
            MailAddress from = new MailAddress(TextBox2.Text);
            MailMessage msg = new MailMessage(from, to);
            msg.Subject = TextBox3.Text;
            msg.IsBodyHtml = true;
            msg.Body = TextBox4.Text;
            msg.Priority = MailPriority.High;
            SmtpClient sc = new SmtpClient("localhost");
            sc.Send(msg);
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }
    }
}
