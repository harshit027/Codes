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
using System.Data.OleDb;

public partial class DataBase : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        
        OleDbDataReader obj = (OleDbDataReader)AccessDataSource1.Select(DataSourceSelectArguments.Empty);
        
        TableHeaderRow thr1 = new TableHeaderRow();
        TableHeaderCell thc1 = new TableHeaderCell();
        TableHeaderCell thc2 = new TableHeaderCell();
        TableHeaderCell thc3 = new TableHeaderCell();
        TableHeaderCell thc4 = new TableHeaderCell();
        TableHeaderCell thc5 = new TableHeaderCell();

        thc1.Text = "ID";
        thc2.Text = "Name";
        thc3.Text = "College";
        thc4.Text = "Branch";
        thc5.Text = "Contact";

        thr1.Cells.Add(thc1);
        thr1.Cells.Add(thc2);
        thr1.Cells.Add(thc3);
        thr1.Cells.Add(thc4);
        thr1.Cells.Add(thc5);

        Table1.Rows.Add(thr1);

        while (obj.Read())
        {

            TableRow tr = new TableRow();
            TableCell tc1 = new TableCell();
            TableCell tc2 = new TableCell();
            TableCell tc3 = new TableCell();
            TableCell tc4 = new TableCell();
            TableCell tc5 = new TableCell();

            tc1.Text = obj[0] + "";
            tc2.Text = obj[1] + "";
            tc3.Text = obj[2] + "";
            tc4.Text = obj[3] + "";
            tc5.Text = obj[4] + "";

            tr.Cells.Add(tc1);
            tr.Cells.Add(tc2);
            tr.Cells.Add(tc3);
            tr.Cells.Add(tc4);
            tr.Cells.Add(tc5);
            Table1.Rows.Add(tr);
            Table1.Attributes.Add("align", "center");
            Table1.BackColor = System.Drawing.Color.Thistle;
        }

    }
}
