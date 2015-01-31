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
    protected void addData(object sender, EventArgs e)
    {
        string[][] data ={
                            new string[]{"1004","Joe","10000"},
                            new string[]{"1005","David","10000"},
                            new string[]{"1006","Ricky","10000"}
                        };
        for (int i = 0; i < data.GetLength(0); i++)
        {
            TableRow tr = new TableRow();

            TableCell tc1 = new TableCell();
            TableCell tc2 = new TableCell();
            TableCell tc3 = new TableCell();

            tc1.Text = data[i][0];
            tc2.Text = data[i][1];
            tc3.Text = data[i][2];
            
            tr.Cells.Add(tc1);
            tr.Cells.Add(tc2);
            tr.Cells.Add(tc3);

            table1.Rows.Add(tr);
            
        }
    }
}
