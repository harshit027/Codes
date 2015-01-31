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
using System.IO;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void ShowInfo(object sender, EventArgs e)
    {
        Button1.Visible = false;
        
        TableRow tr = new TableRow();
        TableCell tc1 = new TableCell();
        TableCell tc2 = new TableCell();
        TableCell tc3 = new TableCell();

        tc1.Text = "NAME";
        tc2.Text = "PASSWORD";
        tc3.Text = "EMAIL ID";
        tr.Cells.Add(tc1);
        tr.Cells.Add(tc2);
        tr.Cells.Add(tc3);
        tr.Attributes.Add("align","center");
        Table1.Rows.Add(tr);

        try
        {
            //FileStream fs = File.Open(Request.PhysicalApplicationPath + "/Database/users.txt", FileMode.Truncate);
            StreamReader sr = new StreamReader(Request.PhysicalApplicationPath + "/Database/users.txt");
            string line;
            while ((line=sr.ReadLine() )!= null)
            {
                //data = sr.ReadLine();
                //Response.Write("<br>" + line);
                string[] arr = line.Split("%".ToCharArray());
                TableRow tr1 = new TableRow();
                TableCell tc11 = new TableCell();
                TableCell tc12 = new TableCell();
                TableCell tc13 = new TableCell();
                tr1.Attributes.Add("align", "center");
                tc11.Text = arr[0];
                tc12.Text = arr[1];
                tc13.Text = arr[2];
                tr1.Attributes.Add("font-size", "large");
                tr1.Cells.Add(tc11);
                tr1.Cells.Add(tc12);
                tr1.Cells.Add(tc13);
                Table1.Rows.Add(tr1);

            }
            //fs.Close();
            sr.Close();
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.Message);
        }



    }
}
