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
using System.Data.SqlClient;

public partial class SearchMember : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        SqlConnection con = null;
        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "select * from members where memberid=" + TextBox1.Text;
            com.CommandText = qry;
            SqlDataReader reader = com.ExecuteReader();
            TableHeaderRow thr = new TableHeaderRow();
            TableHeaderCell thc1 = new TableHeaderCell();
            TableHeaderCell thc2 = new TableHeaderCell();
            TableHeaderCell thc3 = new TableHeaderCell();
            TableHeaderCell thc4 = new TableHeaderCell();
            TableHeaderCell thc5 = new TableHeaderCell();
            TableHeaderCell thc6 = new TableHeaderCell();
            thc1.Text = "UserID";
            thc2.Text = "Name";
            thc3.Text = "Address";
            thc4.Text = "PhoneNo";
            thc5.Text = "Mobile";
            thc6.Text = "Email";
            thr.Cells.Add(thc1);
            thr.Cells.Add(thc2);
            thr.Cells.Add(thc3);
            thr.Cells.Add(thc4);
            thr.Cells.Add(thc5);
            thr.Cells.Add(thc6);
            Table1.Rows.Add(thr);
            thr.BackColor = System.Drawing.Color.White;
            while (reader.Read())
            {
                TableRow tr = new TableRow();
                TableCell tc1 = new TableCell();
                TableCell tc2 = new TableCell();
                TableCell tc3 = new TableCell();
                TableCell tc4 = new TableCell();
                TableCell tc5 = new TableCell();
                TableCell tc6 = new TableCell();
                tr.BackColor = System.Drawing.Color.Thistle;
                tr.Attributes.Add("align", "center");

                tc1.Text = reader[0] + "";
                tc2.Text = reader[1] + "";
                tc3.Text = reader[2] + "";
                tc4.Text = reader[3] + "";
                tc5.Text = reader[4] + "";
                tc6.Text = reader[5] + "";
                tr.Cells.Add(tc1);
                tr.Cells.Add(tc2);
                tr.Cells.Add(tc3);
                tr.Cells.Add(tc4);
                tr.Cells.Add(tc5);
                tr.Cells.Add(tc6);
                Table1.Rows.Add(tr);
            }
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message);
        }
        finally
        {
            if (con.State == ConnectionState.Open)
                con.Close();
        }
    }
}
