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
    protected void moveup(object sender, EventArgs e)
    {
        string temp;
        Button btn = (Button) sender;
        if (btn.ID == "upList1")
        {
            if (ListBox1.SelectedIndex > 0)
            {
                temp = ListBox1.SelectedItem.Text;
                int ind = ListBox1.SelectedIndex;
                ListBox1.Items[ind].Text = ListBox1.Items[ind - 1].Text;
                ListBox1.Items[ind - 1].Text = temp;
                ListBox1.Items[ind - 1].Selected = true;
                ListBox1.Items[ind].Selected = false;
            }
            else
                Response.Write("<h2>Cannot move up further</h2>");
        }
        else if (btn.ID == "upList2")
        {
            if (ListBox2.SelectedIndex > 0)
            {
                temp = ListBox2.SelectedItem.Text;
                int ind = ListBox2.SelectedIndex;
                ListBox2.Items[ind].Text = ListBox2.Items[ind - 1].Text;
                ListBox2.Items[ind - 1].Text = temp;
                ListBox2.Items[ind - 1].Selected = true;
                ListBox2.Items[ind].Selected = false;
            }
            else
                Response.Write("<h2>Cannot move up further</h2>");
        }

    }
    protected void movedown(object sender, EventArgs e)
    {
        Button btn = (Button)sender;
        string temp;

        if (btn.ID == "downList1")
        {
            if (ListBox1.SelectedIndex != ListBox1.Items.Count - 1)
            {
                temp = ListBox1.SelectedItem.Text;
                int ind = ListBox1.SelectedIndex;
                ListBox1.Items[ind].Text = ListBox1.Items[ind + 1].Text;
                ListBox1.Items[ind + 1].Text = temp;
                ListBox1.Items[ind].Selected = false;
                ListBox1.Items[ind + 1].Selected = true;
            }
            else
                Response.Write("<h2>Cannot move down further</h2>");
        }

        if (btn.ID == "downList2")
        {
            if (ListBox2.SelectedIndex != ListBox2.Items.Count - 1)
            {
                temp = ListBox2.SelectedItem.Text;
                int ind = ListBox2.SelectedIndex;
                ListBox2.Items[ind].Text = ListBox2.Items[ind + 1].Text;
                ListBox2.Items[ind + 1].Text = temp;
                ListBox2.Items[ind].Selected = false;
                ListBox2.Items[ind + 1].Selected = true;
            }
            else
                Response.Write("<h2>Cannot move down further</h2>");
        }
    }
    protected void moveItems(object sender, EventArgs e)
    {
        Button btn = (Button)sender;
     
        if (btn.ID == "moveItemsRight")
        { 
            for (int i = 0; i < ListBox1.Items.Count; i++)
            {
                
                if (ListBox1.Items[i].Selected == true)
                {
                    int j = 0;
                    for (j=0; j < ListBox2.Items.Count; j++)
                    {
                        if (ListBox1.Items[i].Text == ListBox2.Items[j].Text)
                        {
                            break;
                        }
                    }
                    if (j == ListBox2.Items.Count)
                    {
                        ListBox2.Items.Add(ListBox1.Items[i].Text);
                        moveItemsLeft.Enabled = true;
                        moveAllLeft.Enabled = true;
                        upList2.Enabled=true;
                        downList2.Enabled=true;
                    }
                }
                
            }

            for (int k = ListBox1.Items.Count - 1; k >= 0; k--)
            {
                if (ListBox1.Items[k].Selected)
                {
                    ListBox1.Items.RemoveAt(k);
                }
            }
            
        }

     
        
        if (btn.ID == "moveItemsLeft")
        {
            for (int i = 0; i < ListBox2.Items.Count; i++)
            {
                
                if (ListBox2.Items[i].Selected == true)
                {
                    int j = 0;
                    for (; j < ListBox1.Items.Count; j++)
                    {
                        if (ListBox2.Items[i].Text == ListBox1.Items[j].Text)
                        {
                            break;
                        }
                    }
                    if (j == ListBox1.Items.Count)
                    {
                        ListBox1.Items.Add(ListBox2.Items[i].Text);
                        moveItemsRight.Enabled = true;
                        moveAllRight.Enabled = true;
                        upList1.Enabled=true;
                        downList1.Enabled=true;
                    }
                }
                
            }

            for (int k = ListBox2.Items.Count - 1; k >= 0; k--)
            {
                if (ListBox2.Items[k].Selected)
                {
                    ListBox2.Items.RemoveAt(k);
                }
            }
            
        }
        if (ListBox2.Items.Count == 0)
        {
            moveItemsLeft.Enabled = false;
            moveAllLeft.Enabled = false;
            upList2.Enabled=false;
            downList2.Enabled=false;
        }
        if (ListBox1.Items.Count == 0)
        {
            moveItemsRight.Enabled = false;
            moveAllRight.Enabled = false;
            upList1.Enabled = false;
            downList1.Enabled=false;
        }

    }
    protected void moveAllItems(object sender, EventArgs e)
    {
        Button btn = (Button)sender;

        if (btn.ID == "moveAllRight")
        {
            for (int i = 0; i < ListBox1.Items.Count; i++)
            {
                    int j = 0;
                    for (j = 0; j < ListBox2.Items.Count; j++)
                    {
                        if (ListBox1.Items[i].Text == ListBox2.Items[j].Text)
                        {
                            break;
                        }
                    }
                    if (j == ListBox2.Items.Count)
                    {
                        ListBox2.Items.Add(ListBox1.Items[i].Text);
                        moveItemsLeft.Enabled = true;
                        moveAllLeft.Enabled = true;
                        upList2.Enabled = true;
                        downList2.Enabled = true;
                    }
            }

            for (int k = ListBox1.Items.Count - 1; k >= 0; k--)
            {
                ListBox1.Items.RemoveAt(k);
            }
        }

        if (btn.ID == "moveAllLeft")
        {
            for (int i = 0; i < ListBox2.Items.Count; i++)
            {
                int j = 0;
                for (; j < ListBox1.Items.Count; j++)
                {
                    if (ListBox2.Items[i].Text == ListBox1.Items[j].Text)
                    {
                        break;
                    }
                }
                if (j == ListBox1.Items.Count)
                {
                    ListBox1.Items.Add(ListBox2.Items[i].Text);
                    moveItemsRight.Enabled = true;
                    moveAllRight.Enabled = true;
                    upList1.Enabled = true;
                    downList1.Enabled = true;
                }
            }

            for (int k = ListBox2.Items.Count - 1; k >= 0; k--)
            {
                ListBox2.Items.RemoveAt(k);
            }
        }

        if (ListBox2.Items.Count == 0)
        {
            moveItemsLeft.Enabled = false;
            moveAllLeft.Enabled = false;
            upList2.Enabled=false;
            downList2.Enabled=false;
        }
        if (ListBox1.Items.Count == 0)
        {
            moveItemsRight.Enabled = false;
            moveAllRight.Enabled = false;
            upList1.Enabled = false;
            downList1.Enabled=false;
        }
    }
}
