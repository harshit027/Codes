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
    
    protected void findDaysLeft(object sender, EventArgs e)
    {
        leftDays.Visible = true;
        Label1.Visible = true;
        Label2.Visible = true;
        DateTime dateToday=DateTime.Today;
        int dd = dateToday.Day;
        int mm = dateToday.Month;
        int yy = dateToday.Year;
        DateTime dt = new DateTime(yy, mm, dd);
        int dd1 = int.Parse(dayList.SelectedItem.Text);
        int mm1 = int.Parse(monthList.SelectedValue);
        int yy1 = dateToday.Year;
        DateTime dt1 = new DateTime(yy1,mm1, dd1);
        TimeSpan ts = dt1 - dt;
        if (mm1 < mm)
        {
            leftDays.Text = 365 + ts.Days + "" + " Days Left For Birthday";
            Label1.Text = 365 + ts.Days + ""  ;
            Label2.Text = 365 + ts.Days + "" ;
        }
        else if (mm1 > mm)
        {
            leftDays.Text = ts.Days + "" + " Days Left For Birthday";
            Label1.Text = ts.Days + ""  ;
            Label2.Text = ts.Days + "" ;
        }
        else if (mm1 == mm)
        {
            if (dd1 >= dd)
            {
                leftDays.Text = ts.Days + "" ;
                Label1.Text = ts.Days + "" ;
                Label2.Text = ts.Days + "" ;
            }
            else if (dd1 < dd)
            {
                leftDays.Text = 365 + ts.Days + "" + " Days Left For Birthday";
                Label1.Text = 365 + ts.Days + ""  ;
                Label2.Text = 365 + ts.Days + "" ;
            }
        }
            
    }
}
