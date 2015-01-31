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

public partial class GridViewPage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        string qry = "select * from employee where empdept=" + DropDownList1.SelectedValue;
        SqlDataSource2.SelectCommand = qry;
        SqlDataSource2.Select(DataSourceSelectArguments.Empty);
        GridView1.DataBind();
    }
}
