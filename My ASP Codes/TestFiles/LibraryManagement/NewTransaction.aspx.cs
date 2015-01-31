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

public partial class NewTransaction : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void cancelBTN_Click(object sender, EventArgs e)
    {
        memberidTB.Text = "";
        bookidTB.Text = "";
        dateTB.Text = "";
        Response.Redirect("Default.aspx");
    }
    protected void okBTN_Click(object sender, EventArgs e)
    {
        SqlConnection con = null;
        Label1.Visible=false;
        string status=null;
        string count = null;
        try
        {
            if(type_of_transLT.SelectedValue.ToString()=="I")
                status="Due";
            else
                status="Clear";
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";

            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "insert into transactions (bookID, memberID, dateOfTrans, typeOfTrans) values (" + bookidTB.Text + "," + memberidTB.Text + ",'" + dateTB.Text + "','" + type_of_transLT.SelectedValue.ToString()+ "')" ;

            com.CommandText = qry;
            if (com.ExecuteNonQuery() > 0)
            {
                Label1.Visible = true;
                Label1.Text = "<span style='color:green'>Transaction Succeeded</span>";
            }
            else
            {
                Label1.Visible = true;
                Label1.Text = "<span style='color:green'>Transaction Failed</span>";
            }
            
            //for memberstatus table
            qry="insert into memberstatus (memberid,status,bookid) values(" + memberidTB.Text + ",'" + status + "'," + bookidTB.Text + ")";
            com.CommandText = qry;
            com.ExecuteNonQuery();

            //for getting the count from books table

            qry = "select * from books where bookid=" + bookidTB.Text;
            com.CommandText = qry;
            SqlDataReader reader = com.ExecuteReader();
            while (reader.Read())
            {
                count = reader[6] + "";
            }
            reader.Close();

            //for updating the books table
            int x = int.Parse(count);
             qry = "update books set numberofbooks=" + x-- + " where bookid=" + bookidTB.Text;
            com.CommandText = qry;
            com.ExecuteNonQuery();
            
        }
        catch (Exception ex)
        {
            Label1.Visible = true;
            Label1.Text = "<span style='color:green'>"+ex.Message+"</span>";
        }

        /*SqlConnection con1 = null;
        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con1 = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.CommandType = CommandType.Text;
            com.Connection=con1;
            string qry = "insert into memberstatus (memberid,status,bookid) values(" + memberidTB.Text + ",'" + status + "'," + bookidTB.Text + ")";
            com.CommandText = qry;
            com.ExecuteNonQuery();
            con1.Close();
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message + "1");
        }

        SqlConnection con2 = null;
        
        try
        {
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con2 = new SqlConnection(conn_string);
            con2.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con2;
            com.CommandType = CommandType.Text;

            string qry = "select * from books where bookid=" + bookidTB.Text;
            com.CommandText = qry;
            SqlDataReader reader = com.ExecuteReader();
            while (reader.Read())
            {
                count = reader[6] + "";
            }
            con2.Close();
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message+"2");
        }

        SqlConnection con3 = null;
        try
        {
            
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con3 = new SqlConnection(conn_string);
            con3.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con3;
            com.CommandType = CommandType.Text;
            int x = int.Parse(count);
            string qry = "update books set numberofbooks=" +x--  + " where bookid=" + bookidTB.Text;
            com.CommandText = qry;
            com.ExecuteNonQuery();
            con3.Close();
        }
        catch (Exception ex)
        {
            Response.Write(ex.Message+"3");
        }*/



    }
}
