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
        if (!Page.IsPostBack)
        {
            LoadGrid("asc");
            SetCheckBoxes();
        }

    }
    public void SetCheckBoxes()
    {
        try
        {
            Database db = new Database();
            DataTable dt = db.GetDataTable("select * from employee");
            for (int i = 0; i < dt.Rows.Count;i++ )
            {
                string status = dt.Rows[i][7].ToString();
                CheckBox cb = (CheckBox) GridView1.Rows[i].FindControl("cbsuspened");
                cb.Text = dt.Rows[i][0].ToString();
                if (status == "True")
                {
                    cb.Checked = true;
                }
                else
                {
                    cb.Checked = false;
                }

            }

        }
        catch (Exception ex)
        {
        }
    }
    public void LoadGrid(string direction)
    {
        try
        {
            Database db = new Database();
            DataTable dt = db.GetDataTable("select * from employee order by ename "+ direction);
            GridView1.DataSource = dt;
            GridView1.DataBind();
            bool flag = true;
            foreach (GridViewRow row in GridView1.Rows)
            {
                string color = "#7777ff";
                if (flag != true)
                {
                    color = "#ff7777";
                    flag = true;
                }
                else
                {
                    flag = false;
                }
                row.Attributes.Add("style", "background-color:"+color+";");
            }
        }
        catch (Exception ex)
        {
        }
    }
    protected void SetSuspended(object sender,  EventArgs e)
    {
        try
        {
            Database db = new Database();
            CheckBox cb = (CheckBox)sender;
            string empid = cb.Text;
            string n =  "0";
            if (cb.Checked)
            {
                n = "1";
            }
            db.setdata("update employee set issuspended="+n+" where empid="+empid);
            LoadGrid("Asc");
            SetCheckBoxes();
        }
        catch (Exception ex)
        {
        }

    }
    protected void SetNewPage(object sender, GridViewPageEventArgs e)
    {
        GridView1.PageIndex = e.NewPageIndex;
        LoadGrid("asc");
    }
    protected void ArrangeRows(object sender, GridViewSortEventArgs e)
    {
        if (e.SortDirection == SortDirection.Ascending)
        {
            LoadGrid("asc");
        }
        else
        {
            LoadGrid("desc");
        }
    }
}
