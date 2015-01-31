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
    protected void MyEducationClick(object sender, EventArgs e)
    {
        Response.Redirect("MyEducation.aspx");
    }
    protected void MyHobbiesClick(object sender, EventArgs e)
    {
        Response.Redirect("MyHobbies.aspx");
    }
    protected void MyCollegeClick(object sender, EventArgs e)
    {
        Response.Redirect("MyCollege.aspx");
    }
    protected void MyFriendsClick(object sender, EventArgs e)
    {
        Response.Redirect("MyFriends.aspx");
    }
    protected void MyselfClick(object sender, EventArgs e)
    {
        Response.Redirect("Myself.aspx");
    }
}
