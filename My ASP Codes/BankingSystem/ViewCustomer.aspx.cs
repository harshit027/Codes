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

public partial class ViewCustomer : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        LoadGrid();
    }
    public void LoadGrid()
    {
        try
        {
            Database db = new Database();
            DataTable dt = db.GetDataTable("select * from customer  ");
            GridView1.DataSource = dt;
            GridView1.DataBind();


        }
        catch (Exception ex)
        {
        }
    }

    protected void SetNewPage(object sender, GridViewPageEventArgs e)
    {
        GridView1.PageIndex = e.NewPageIndex;
        LoadGrid();
    }
}
