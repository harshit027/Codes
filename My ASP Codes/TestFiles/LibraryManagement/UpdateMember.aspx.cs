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

public partial class UpdateMember : System.Web.UI.Page
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
            String conn_string = @"Data Source=.\SQLExpress;AttachdbFileName=|DataDirectory|library.mdf; Integrated Security=true; User Instance=true;";
            con = new SqlConnection(conn_string);
            con.Open();
            SqlCommand com = new SqlCommand();
            com.Connection = con;
            com.CommandType = CommandType.Text;
            string qry = "update members set mname='" + nameTB.Text + "' , maddress='" + addressTB.Text + "', mphone='" + phoneTB.Text + "', mmobile='" + mobileTB.Text + "', memail='" + emailTB.Text + "' where memberid=" + midTB.Text;
            com.CommandText = qry;

            int n = com.ExecuteNonQuery();
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
        finally
        {
            if(con.State==ConnectionState.Open)
            con.Close();
        }

    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        nameTB.Text = "";
        addressTB.Text = "";
        phoneTB.Text = "";
        emailTB.Text = "";
        mobileTB.Text = "";
        midTB.Text = "";
        Response.Redirect("Default.aspx");
    }

    protected void midTB_TextChanged(object sender, EventArgs e)
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
            string qry = "select * from members where memberid=" + midTB.Text;
            com.CommandText = qry;
            SqlDataReader reader = com.ExecuteReader();
            while (reader.Read())
            {
                nameTB.Text = reader[1] + "";
                addressTB.Text = reader[2] + "";
                phoneTB.Text = reader[3] + "";
                mobileTB.Text = reader[4] + "";
                emailTB.Text = reader[5] + "";
                
            }
            nameTB.ReadOnly=true;
            addressTB.ReadOnly=true;
            phoneTB.ReadOnly=true;
            mobileTB.ReadOnly=true;
            emailTB.ReadOnly=true;
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

        if (Request.QueryString["var"] == "name")
        {
            nameTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "address")
        {
            addressTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "phone")
        {
            phoneTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "mobile")
        {
            mobileTB.ReadOnly = false;
        }
        if (Request.QueryString["var"] == "email")
        {
            emailTB.ReadOnly = false;
        }
   
    }
}
