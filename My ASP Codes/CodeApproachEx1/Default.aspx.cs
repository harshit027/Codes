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
        Database db = new Database();
        string qry="select * from employee";
        DataSet ds = db.GetDataSet(qry);
        GridView1.DataSource = ds;
        GridView1.DataBind();
    }
}
