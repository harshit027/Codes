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

public partial class Search : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void searchBtn_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        try
        {
            string searchQuery = "select * from student where ID =" + TextBox1.Text ;
            AccessDataSource1.SelectCommand = searchQuery;
            OleDbDataReader obj = (OleDbDataReader) AccessDataSource1.Select(DataSourceSelectArguments.Empty);
            
            int flag = 1;
            if (obj.Read())
            {
                TableHeaderRow thr = new TableHeaderRow();
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
                thr.Cells.Add(thc1);
                thr.Cells.Add(thc2);
                thr.Cells.Add(thc3);
                thr.Cells.Add(thc4);
                thr.Cells.Add(thc5);
                Table1.Rows.Add(thr);
                TableRow tr = new TableRow();
                TableCell tc1 = new TableCell();
                TableCell tc2 = new TableCell();
                TableCell tc3 = new TableCell();
                TableCell tc4 = new TableCell();
                TableCell tc5 = new TableCell();
                tc1.Text = obj[0].ToString();
                tc2.Text = obj[1].ToString();
                tc3.Text = obj[2].ToString();
                tc4.Text = obj[3].ToString();
                tc5.Text = obj[4].ToString();
                Table1.Rows.Add(tr);
                tr.Cells.Add(tc1);
                tr.Cells.Add(tc2);
                tr.Cells.Add(tc3);
                tr.Cells.Add(tc4);
                tr.Cells.Add(tc5);

                Table1.BackColor = System.Drawing.Color.Thistle;
                flag = 0;
            }
            if (flag == 1)
            {
                Label1.Visible = true;
                Label1.Text = "<h4 style='background-color:white; color:red;'>No Record Found</h4>";
            }
            else
            {
                Label1.Visible = true;
                Label1.Text = "<h4 style='background-color:white; color:red;'>Record Found</h4>";
            }
        }
        catch(Exception ex)
        {
            Response.Write(ex);
        }
        
    }
}
