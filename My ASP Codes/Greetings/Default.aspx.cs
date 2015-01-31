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
    protected void list1_SelectedIndexChanged(object sender, EventArgs e)
    {
        int ind=list1.SelectedIndex;
        switch (ind)
        {
            case 0:
                {
                    imgBase.ImageUrl = "~/main/diwali.jpg";
                    label1.Text = "Diwali Greetings : The Festival of lights";

                    for (int i = list2.Items.Count-1; i >=0 ; i--)
                    {
                        list2.Items.RemoveAt(i);
                    }
                    list2.Items.Add("Diwali_Special");
                    list2.Items.Add("Flowers");
                    list2.Items.Add("Crackers");
                    list2.Items.Add("Candles");
                    list2.Items.Add("Teddies");
                    break;
                }
            case 1:
                {
                    imgBase.ImageUrl = "~/main/christmas.jpg";
                    label1.Text = "Christmas Greetings : Jesus's birthday";

                    for (int i = list2.Items.Count - 1; i >= 0; i--)
                    {
                        list2.Items.RemoveAt(i);
                    }
                    list2.Items.Add("Christmas_Special");
                    list2.Items.Add("Candles");
                    list2.Items.Add("Teddies");
                    break;
                }
            case 2:
                {
                    imgBase.ImageUrl = "~/main/holi.jpg";
                    label1.Text = "Holi Greetings : The Festival of Colors";

                    for (int i = list2.Items.Count - 1; i >= 0; i--)
                    {
                        list2.Items.RemoveAt(i);
                    }
                    list2.Items.Add("Holi_Special");
                    list2.Items.Add("Flowers");
                    break;
                }
            case 3:
                {
                    imgBase.ImageUrl = "~/main/valentine.jpg";
                    label1.Text = "Valentine Day Greetings";

                    for (int i = list2.Items.Count - 1; i >= 0; i--)
                    {
                        list2.Items.RemoveAt(i);
                    }
                    list2.Items.Add("Valentine_Special");
                    list2.Items.Add("Flowers");
                    list2.Items.Add("Candles");
                    list2.Items.Add("Teddies");
                    break;
                }
            case 4:
                {
                    imgBase.ImageUrl = "~/main/birthday.jpg";
                    label1.Text = "Birthday Greetings";

                    for (int i = list2.Items.Count - 1; i >= 0; i--)
                    {
                        list2.Items.RemoveAt(i);
                    }
                    list2.Items.Add("Birthday_Special");
                    list2.Items.Add("Flowers");
                    list2.Items.Add("Balloons");
                    list2.Items.Add("Candles");
                    list2.Items.Add("Teddies");
                    break;
                }
        }
    }
    protected void list2_SelectedIndexChanged(object sender, EventArgs e)
    {
        ImageButton1.ImageUrl = "";
        ImageButton2.ImageUrl = "";
        ImageButton3.ImageUrl = "";
        ImageButton4.ImageUrl = "";
        ImageButton5.ImageUrl = "";
        if (list2.SelectedItem.Text == "Flowers")
        {
            ImageButton1.ImageUrl = "~/flowers/1.jpg";
            ImageButton2.ImageUrl = "~/flowers/2.jpg";
            ImageButton3.ImageUrl = "~/flowers/3.jpg";
            ImageButton4.ImageUrl = "~/flowers/4.jpg";
            label1.Text =" 4 cards available";
        }
        else
            if (list2.SelectedItem.Text == "Balloons")
            {
                ImageButton1.ImageUrl = "~/balloons/1.jpg";
                ImageButton2.ImageUrl = "~/balloons/2.jpg";
                ImageButton3.ImageUrl = "~/balloons/3.jpg";
                ImageButton4.ImageUrl = "~/balloons/4.jpg";
                label1.Text = " 4 cards available";
            }
            else
                if (list2.SelectedItem.Text == "Teddies")
                {
                    ImageButton1.ImageUrl = "~/teddies/1.jpg";
                    ImageButton2.ImageUrl = "~/teddies/2.jpg";
                    ImageButton3.ImageUrl = "~/teddies/3.jpg";
                    
                    label1.Text= "3 cards available";
                }
                else
                    if (list2.SelectedItem.Text == "Crackers")
                    {
                        ImageButton1.ImageUrl = "~/fire/1.jpg";
                        ImageButton2.ImageUrl = "~/fire/2.jpg";
                        ImageButton3.ImageUrl = "~/fire/3.jpg";
                        ImageButton4.ImageUrl = "~/fire/4.jpg";
                        label1.Text = "4 cards available";
                    }
                    else
                        if (list2.SelectedItem.Text == "Candles")
                        {
                            ImageButton1.ImageUrl = "~/candles/1.jpg";
                            ImageButton2.ImageUrl = "~/candles/2.jpg";
                            ImageButton3.ImageUrl = "~/candles/3.jpg";
                            ImageButton4.ImageUrl = "~/candles/4.jpg";
                            label1.Text = "4 cards available";
                        }
                        else
                            if (list2.SelectedItem.Text == "Holi_Special")
                            {
                                ImageButton1.ImageUrl = "~/holi/1.jpg";
                                ImageButton2.ImageUrl = "~/holi/2.jpg";
                                ImageButton3.ImageUrl = "~/holi/3.jpg";
                                ImageButton4.ImageUrl = "~/holi/4.jpg";
                                ImageButton5.ImageUrl = "~/holi/5.jpg";
                                label1.Text = "5 cards available";
                            }
                            else
                                if (list2.SelectedItem.Text == "Diwali_Special")
                                {
                                    ImageButton1.ImageUrl = "~/diwali/1.jpg";
                                    ImageButton2.ImageUrl = "~/diwali/2.jpg";
                                    ImageButton3.ImageUrl = "~/diwali/3.jpg";

                                    label1.Text = "3 cards available";
                                }
                                else
                                    if (list2.SelectedItem.Text == "Valentine_Special")
                                    {
                                        ImageButton1.ImageUrl = "~/valentine/1.jpg";
                                        ImageButton2.ImageUrl = "~/valentine/2.jpg";
                                        ImageButton3.ImageUrl = "~/valentine/3.jpg";
                                        
                                        label1.Text = "3 cards available";
                                    }
                                    else
                                        if (list2.SelectedItem.Text == "Christmas_Special")
                                        {
                                            ImageButton1.ImageUrl = "~/christmas/1.jpg";
                                            ImageButton2.ImageUrl = "~/christmas/2.jpg";
                                            ImageButton3.ImageUrl = "~/christmas/3.jpg";

                                            label1.Text = "3 cards available";
                                        }
                                        else
                                            if (list2.SelectedItem.Text == "Birthday_Special")
                                            {
                                                ImageButton1.ImageUrl = "~/birthday/1.jpg";
                                                ImageButton2.ImageUrl = "~/birthday/2.jpg";
                                                ImageButton3.ImageUrl = "~/birthday/3.jpg";

                                                label1.Text = "3 cards available";
                                            }
                                    

    }
}
