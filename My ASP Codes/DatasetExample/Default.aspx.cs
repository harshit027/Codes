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
    protected void Button1_Click(object sender, EventArgs e)
    {
        DataView dv = (DataView)SqlDataSource1.Select(DataSourceSelectArguments.Empty);
        TableHeaderRow thr = new TableHeaderRow();
        TableHeaderCell thc1 = new TableHeaderCell();
        TableHeaderCell thc2 = new TableHeaderCell();
        TableHeaderCell thc3 = new TableHeaderCell();
        thc1.Text = "NAME";
        thc2.Text = "COLLEGE";
        thc3.Text = "BRANCH";
        thr.Cells.Add(thc1);
        thr.Cells.Add(thc2);
        thr.Cells.Add(thc3);
        Table1.Rows.Add(thr);
        for (int i = 0; i < dv.Count; i++)
        {
            TableRow tr = new TableRow();
            TableCell tc1 = new TableCell();
            TableCell tc2 = new TableCell();
            TableCell tc3 = new TableCell();
            tc1.Text = dv[i][0].ToString();
            tc2.Text = dv[i][1].ToString();
            tc3.Text = dv[i][2].ToString();
            tr.Cells.Add(tc1);
            tr.Cells.Add(tc2);
            tr.Cells.Add(tc3);
            tr.Attributes.Add("align", "center");
            Table1.Rows.Add(tr);
        }
    }
}
