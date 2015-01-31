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
using System.Data.SqlClient;

public partial class StaffHome : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (Session.Count > 0)
        {
            if (Session["authentication"] != null)
            {
                if (Session["authentication"].ToString() == "valid")
                {

                    Database db = new Database();
                    string username = Session["username"] + "";
                    string query = "select * from employee where empname='" + username + "'";
                    SqlDataReader dr = db.getdata(query);
                    if (dr.Read())
                    {
                        idLB.Text = dr[0] + "";
                        nameLB.Text = dr[1] + "";
                        phoneLB.Text = dr[3] + "";
                        emailLB.Text = dr[4] + "";
                    }
                }
            }
        }
        else
        {
            Response.Redirect("Default.aspx");
        }

    }
}
