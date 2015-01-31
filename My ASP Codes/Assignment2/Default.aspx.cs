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
    protected void list1_Click(object sender, BulletedListEventArgs e)
    {
        list2.Items.Clear();
        switch (e.Index)
        {
            case 0:
                list2.Items.Add("Engineering Chemistry");
                list2.Items.Add("Engineering Drawing");
                list2.Items.Add("Engineering Mathematics1");
                list2.Items.Add("Communication Skills");
                list2.Items.Add("Basic Electrical");
                break;
            case 1:
                list2.Items.Add("Engineering Physics");
                list2.Items.Add("Basic Mechanical");
                list2.Items.Add("Engineering Mathematics2");
                list2.Items.Add("Engineering Mechanics");
                list2.Items.Add("Basic Civil");
                break;
            case 2:
                list2.Items.Add("Instrumentation & Measurement");
                list2.Items.Add("Object Oriented Programming");
                list2.Items.Add("EEES");
                list2.Items.Add("Digital Electronics & Micro.");
                list2.Items.Add("Engineering Mathematics3");
                break;
            case 3:
                list2.Items.Add("Analog & Digital Communication");
                list2.Items.Add("Information Theory and Coding");
                list2.Items.Add("Comp. System Organization");
                list2.Items.Add("Discrete Structures");
                list2.Items.Add("Data Structures");
                break;
            case 4:
                list2.Items.Add("Computer Graphics");
                list2.Items.Add("Operating System");
                list2.Items.Add("DBMS");
                list2.Items.Add("Data Communication");
                list2.Items.Add("Principles of Management");
                break;
            case 5:
                list2.Items.Add("Cellular and Mobile Comm.");
                list2.Items.Add("Computer Networking");
                list2.Items.Add("Software Engineering");
                list2.Items.Add("Microprocessor and Interfacing");
                list2.Items.Add("Digital Signal Processing");
                break;
            case 6:
                list2.Items.Add("OOAD");
                list2.Items.Add("Compiler Design");
                list2.Items.Add("Artificial Intelligence");
                list2.Items.Add("Network Security");
                list2.Items.Add("Network Management");
                break;
            case 7:
                list2.Items.Add("Distributed Systems");
                list2.Items.Add("Web Engineering");
                list2.Items.Add("Embedded Systems");
                list2.Items.Add("Communication Skills");
                list2.Items.Add("Wireless Networks");
                break;
        }


    }
    protected void list2_Click(object sender, BulletedListEventArgs e)
    {
        int ind = e.Index;
        currentSelection.Text = list2.Items[ind].Text;
        ListBox1.Items.Add(hiddenField.Value);
        hiddenField.Value = list2.Items[ind].Text;
    }
}
