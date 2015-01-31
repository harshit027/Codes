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
using System.IO;

public partial class DataPage : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

        if (Session.Count > 0)
        {
            if (Session["Var1"] != null)
            {
                string temp = (string)Session["Var1"];
                if (temp.Equals("validuser"))
                {
                    TableRow tr = new TableRow();
                    TableCell tc1 = new TableCell();
                    TableCell tc2 = new TableCell();
                    TableCell tc3 = new TableCell();
                    TableCell tc4 = new TableCell();
                    TableCell tc5 = new TableCell();
                    Table1.BackColor = System.Drawing.Color.Thistle;

                    tc1.Text = "ID";
                    tc2.Text = "NAME";
                    tc3.Text = "PASSWORD ";
                    tc4.Text = "DEGREE";
                    tc5.Text = "SPECIALIZATION";
                    tr.Cells.Add(tc1);
                    tr.Cells.Add(tc2);
                    tr.Cells.Add(tc3);
                    tr.Cells.Add(tc4);
                    tr.Cells.Add(tc5);
                    tr.Attributes.Add("align", "center");
                    Table1.Rows.Add(tr);

                    try
                    {
                        //FileStream fs = File.Open(Request.PhysicalApplicationPath + "/Database/users.txt", FileMode.Truncate);
                        StreamReader sr = new StreamReader(Request.PhysicalApplicationPath + "/Database/users.txt");
                        string line;
                        while ((line = sr.ReadLine()) != null)
                        {
                            //data = sr.ReadLine();
                            //Response.Write("<br>" + line);
                            string[] arr = line.Split("%".ToCharArray());
                            TableRow tr1 = new TableRow();
                            TableCell tc11 = new TableCell();
                            TableCell tc12 = new TableCell();
                            TableCell tc13 = new TableCell();
                            TableCell tc14 = new TableCell();
                            TableCell tc15 = new TableCell();
                            tr1.Attributes.Add("align", "center");
                            tc11.Text = arr[0];
                            tc12.Text = arr[1];
                            tc13.Text = arr[2];
                            tc14.Text = arr[3];
                            tc15.Text = arr[4];

                            tr1.Cells.Add(tc11);
                            tr1.Cells.Add(tc12);
                            tr1.Cells.Add(tc13);
                            tr1.Cells.Add(tc14);
                            tr1.Cells.Add(tc15);
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
            
        }
        else
        {
            
            Response.Redirect("LoginPage.aspx");
        }
    }
}

