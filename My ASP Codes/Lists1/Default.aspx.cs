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

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void btn1_Click(object sender, EventArgs e)
    {
        for (int i = 0; i <= lst1.Items.Count - 1; i++)
        {
            if (lst1.Items[i].Selected == true)
            {
                int j=0;
                for ( j= 0; j <= ListBox1.Items.Count - 1; j++)
                {
                    if (ListBox1.Items[j].Text == lst1.Items[i].Text)
                    {
                        break;
                    }
                }
                if(j==ListBox1.Items.Count)
                {
                    ListBox1.Items.Add(lst1.Items[i].Text);
                }
            }
        }
        for (int k =  lst1.Items.Count - 1; k >=0; k--)
        {
            if (lst1.Items[k].Selected)
            {
                lst1.Items.RemoveAt(k);
            }
        }
    }
    /*
        bool flag = false;
        for (int i = 0; i <= lst1.Items.Count - 1; i++)
        {
            if (lst1.Items[i].Selected == true)
            {
                flag = true;
                for (int j= 0; j <= ListBox1.Items.Count - 1; j++)
                {
                    if (ListBox1.Items[j].Text == lst1.Items[i].Text)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == true)
                {
                    ListBox1.Items.Add(lst1.Items[i].Text);
                }
            }
        }
     */
    protected void btn5_Click(object sender, EventArgs e)
    {
        if (lst1.SelectedIndex > 0)
        {
            string temp = lst1.SelectedItem.Text;
            int ind = lst1.SelectedIndex;
            lst1.Items[ind].Text = lst1.Items[ind - 1].Text;
            lst1.Items[ind - 1].Text = temp;
            lst1.SelectedIndex = ind - 1;
        }
        else
        {
            Response.Write("<h1>KYON RE</h1>");
        }
    }
}
