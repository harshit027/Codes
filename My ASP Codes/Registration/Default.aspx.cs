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
    protected void submitbtn_Click(object sender, EventArgs e)
    {
        datalb.Text = "";
        datalb.Text = "Your Details are :- " + "<br/>";
        datalb.Text +="Name : "+ nametb.Text + "<br/>";
        datalb.Text +="Password : " +passwordtb.Text + "<br/>";
        datalb.Text +="Date Of Birth : " +datetb.Text + "/" + monthtb.Text + "/" + yeartb.Text + "<br/>";
        datalb.Text += "Qualification : "+qualificationddl.SelectedItem.Text+"<br/>"+"Hobbies : ";
        for (int i = 0; i < hobbiescbl.Items.Count; i++)
        {
            if (hobbiescbl.Items[i].Selected == true)
                datalb.Text += hobbiescbl.Items[i].Text + " , ";
        }
        datalb.Text += "<br/>";
        datalb.Text += "Language : "+languagerbl.SelectedItem.Text + "<br/>";
        datalb.Text += "Database : "+databaserbl.SelectedItem.Text ;
        datalb.Visible = true;
    }
}
