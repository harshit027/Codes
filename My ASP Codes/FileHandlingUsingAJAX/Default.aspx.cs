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
    protected void showdataBTN_Click(object sender, EventArgs e)
    {
        UpdatePanel1.Visible = false;
        UpdatePanel2.Visible = true;

        
    }
    protected void updateBTN_Click(object sender, EventArgs e)
    {
        UpdatePanel2.Visible = false;
        UpdatePanel1.Visible = true;
    }
    protected void registerBTN_Click(object sender, EventArgs e)
    {
        try
        {
            string dirpath = Request.PhysicalApplicationPath + "/Database";
            if (!Directory.Exists(dirpath))
            {
                Directory.CreateDirectory(dirpath);
            }
            if (!File.Exists(dirpath + "/users.txt"))
            {
                File.Create(dirpath + "/users.txt");
            }
            string data = idTB.Text+ "%" + nameTB.Text+ "%" + degreeTB.Text+"%"+specialityTB.Text;
            FileStream fs = File.Open(dirpath + "/users.txt", FileMode.Append);
            StreamWriter sw = new StreamWriter(fs);
            sw.WriteLine(data);
            sw.Close();
            fs.Close();
            idTB.Text = "";
            degreeTB.Text = "";
            nameTB.Text = "";
            specialityTB.Text = "";
        }
        catch (Exception ex)
        {
            Response.Write("Error : " + ex.ToString());
        }
    }
    protected void showBTN_Click(object sender, EventArgs e)
    {
        TableRow tr = new TableRow();
        TableCell tc1 = new TableCell();
        TableCell tc2 = new TableCell();
        TableCell tc3 = new TableCell();
        TableCell tc4 = new TableCell();

        tr.BackColor = System.Drawing.Color.Blue;
        tc1.Text = "ID";
        tc2.Text = "Name";
        tc3.Text = "Degree";
        tc4.Text = "Specialization";

        tr.Cells.Add(tc1);
        tr.Cells.Add(tc2);
        tr.Cells.Add(tc3);
        tr.Cells.Add(tc4);
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

                tr1.Attributes.Add("align", "center");
                tr1.BackColor = System.Drawing.Color.White;
                tr1.ForeColor = System.Drawing.Color.Black;
                tc11.Text = arr[0];
                tc12.Text = arr[1];
                tc13.Text = arr[2];
                tc14.Text = arr[3];
                tr1.Cells.Add(tc11);
                tr1.Cells.Add(tc12);
                tr1.Cells.Add(tc13);
                tr1.Cells.Add(tc14);
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
