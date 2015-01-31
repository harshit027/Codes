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


    protected void first_Click1(object sender, EventArgs e)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        Session.Remove("currentvalue");
        Session.Add("currentvalue", 0 + "");
        showRecord(0);
    }
    protected void next_Click(object sender, EventArgs e)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        int current = int.Parse(Session["currentvalue"].ToString());
        if(current!=dv.Count-1)
        current++;

        Session.Remove("currentvalue");
        Session.Add("currentvalue", current + "");
        showRecord(current);
    }
    protected void previous_Click(object sender, EventArgs e)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        int current = int.Parse(Session["currentvalue"].ToString());
        if (current > 0)
            current--;

        Session.Remove("currentvalue");
        Session.Add("currentvalue", current + "");
        showRecord(current);
    }
    protected void last_Click(object sender, EventArgs e)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        Session.Remove("currentvalue");
        Session.Add("currentvalue",dv.Count-1+"");
        showRecord(dv.Count - 1);
    }
    public void showRecord(int index)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);

        TextBox1.Text = dv[index][0] + "";
        TextBox2.Text = dv[index][1] + "";
        TextBox3.Text = dv[index][2] + "";
    }
}


