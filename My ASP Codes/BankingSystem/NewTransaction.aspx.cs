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
    private string custId,dateOfTrans;
    bool flag=false;

    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void submitBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        Database db = new Database();
        
        DateTime todayDate = DateTime.Today;
        int mm = todayDate.Month;
        int dd = todayDate.Day;
        int yy = todayDate.Year;
        dateOfTrans = "" + mm + "/" + dd + "/" + yy;
        string query = "select * from account where accno=" + accountNoTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            custId = reader[1] + "";
            checkCurrentBalance();
            if (transtypeDDL.SelectedValue.Equals("W"))
            {
                if (flag == true)
                {
                    Label1.Visible = true;
                    Label1.Text = "<h4 style='background-color:white; color:red; text-align:center;'>Failed,Balance Falling below 500/-</h4>";
                    return;
                }
            }
            performTransaction();
            updateReportTable();
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red; text-align:center;'>No Such Record</h4>";
            return;
            
        }

    }

    protected void performTransaction()
    {
        Database db = new Database();

        string query = null; 
        if(transtypeDDL.SelectedValue.Equals("D"))
            query= "update account set balance=balance+" + amountTB.Text+"where accno="+accountNoTB.Text;
        else
            query = "update account set balance=balance-" + amountTB.Text+"where accno="+accountNoTB.Text;

        if (db.setdata(query) > 0)
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:blue; text-align:center;'>Transaction Completed</h4>";
        }
        else
        {
            Label1.Visible = true;
            Label1.Text = "<h4 style='background-color:white; color:red; text-align:center;'>Error in transaction</h4>";
        }
    }

    protected void updateReportTable()
    {
            Database db = new Database();
            string query = "insert into report (cid,accno,type,dateoftrans,amount) values (" + custId+ "," + accountNoTB.Text + ",'" + transtypeDDL.SelectedValue + "','"+dateOfTrans+"'," + amountTB.Text + ")";
            int n=db.setdata(query);
            if ( n> 0)
            {
                Label1.Visible = true;
                //Label1.Text = "Transaction Table Updated";
            }
            else
            {
                Label1.Visible = true;
                Label1.Text = "Problem in updating";
            }
    }
    protected void resetBTN_Click(object sender, EventArgs e)
    {
        Label1.Visible = false;
        accountNoTB.Text = "";
        amountTB.Text = "";
    }

    protected void checkCurrentBalance()
    {
        float currentBal=0;
        Database db = new Database();
        string query = "select * from account where accno=" + accountNoTB.Text;
        SqlDataReader reader = db.getdata(query);
        if (reader.Read())
        {
            currentBal = float.Parse(reader[4]+"");
        }

        float requestedBal;
        requestedBal = float.Parse(amountTB.Text);

        if (currentBal - requestedBal <= 500)
        {
            flag = true;
        }
        else
            flag = false;
    }
}
