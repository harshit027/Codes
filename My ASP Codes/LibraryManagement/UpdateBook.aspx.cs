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

public partial class UpdateBook : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        SqlConnection con = null;
        try
        {
            string conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con=new SqlConnection(conn_string);
            con.Open();
            SqlCommand com=new SqlCommand();
            com.Connection=con;
            com.CommandType=CommandType.Text;
            string qry="update books set booktitle='"+titleTB.Text+"', bookauthor='"+authorTB.Text+"', bookprice="+priceTB.Text+", bookpublisher='"+publisherTB.Text+"', bookedition='"+editionTB.Text+"', numberofbooks="+no_of_coipesTB.Text+" where bookid="+bidTB.Text;
            com.CommandText=qry;
            int n=com.ExecuteNonQuery();
            if (n >= 0)
            {
                Label1.Text = "<span style='color:green'>Updated Successfully</span>";
            }
            else
            {
                Label1.Text = "<span style='color:red'>Unable to update, Please check the data entered</span>";
            }
            Label1.Visible = true;


        }
        catch (Exception ex)
        {
            Label1.Text = "<span style='color:red'>Error :" + ex.ToString() + "</span>";
            Label1.Visible = true;

        }
        


    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        bidTB.Text = "";
        authorTB.Text = "";
        titleTB.Text = "";
        publisherTB.Text = "";
        editionTB.Text = "";
        priceTB.Text = "";
        Response.Redirect("Default.aspx");
    }
    protected void bidTB_TextChanged(object sender, EventArgs e)
    {
        SqlConnection con = null;
        try
        {
            string conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.CommandType = CommandType.Text;
            com.Connection = con;
            string qry = "select * from books where bookid=" + bidTB.Text;
            com.CommandText = qry;
            SqlDataReader reader = com.ExecuteReader();
            while (reader.Read())
            {
                titleTB.Text = reader[1] + "";
                authorTB.Text = reader[2] + "";
                priceTB.Text = reader[3] + "";
                editionTB.Text = reader[4] + "";
                publisherTB.Text = reader[5] + "";
                no_of_coipesTB.Text = reader[6] + "";

                titleTB.ReadOnly=true;
                authorTB.ReadOnly=true;
                priceTB.ReadOnly=true;
                editionTB.ReadOnly=true;
                publisherTB.ReadOnly=true;
                no_of_coipesTB.ReadOnly=true;
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
        if (Request.QueryString["var"] == "title")
        {
            titleTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "author")
        {
            authorTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "price")
        {
            priceTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "edition")
        {
            editionTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "publisher")
        {
            publisherTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "quantity")
        {
            no_of_coipesTB.ReadOnly = false;
        }
        
    }
}
