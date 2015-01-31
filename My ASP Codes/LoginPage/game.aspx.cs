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

public partial class game : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void swapFun(object sender, EventArgs e)
    {
        Button btn = (Button)sender;
        int counter;
        counter = int.Parse(score.Text);
        counter += 1;
        score.Text = counter + "";
        if (btn.ID == "Button1")                        //button1
        {
            if (Button2.Text == "")
            {
                Button2.Text = Button1.Text;
                Button1.Text = "";
                Button1.BackColor = System.Drawing.Color.Red;
                Button2.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button4.Text == "")
                {
                    Button4.Text = Button1.Text;
                    Button1.Text = "";
                    Button1.BackColor = System.Drawing.Color.Red;
                    Button4.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
        }

        else if (btn.ID == "Button2")                       //button2
        {
            if (Button1.Text == "")
            {
                Button1.Text = Button2.Text;
                Button2.Text = "";
                Button2.BackColor = System.Drawing.Color.Red;
                Button1.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button3.Text == "")
                {
                    Button3.Text = Button2.Text;
                    Button2.Text = "";
                    Button2.BackColor = System.Drawing.Color.Red;
                    Button3.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
                else
                    if (Button5.Text == "")
                    {
                        Button5.Text = Button2.Text;
                        Button2.Text = "";
                        Button2.BackColor = System.Drawing.Color.Red;
                        Button5.BackColor = System.Drawing.Color.Yellow;
                        checkWinner();
                    }
        }


        else if (btn.ID == "Button3")                        //button3
        {
            if (Button2.Text == "")
            {
                Button2.Text = Button3.Text;
                Button3.Text = "";
                Button3.BackColor = System.Drawing.Color.Red;
                Button2.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button6.Text == "")
                {
                    Button6.Text = Button3.Text;
                    Button3.Text = "";
                    Button3.BackColor = System.Drawing.Color.Red;
                    Button6.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
        }


        else if (btn.ID == "Button4")                       //button4
        {
            if (Button1.Text == "")
            {
                Button1.Text = Button4.Text;
                Button4.Text = "";
                Button4.BackColor = System.Drawing.Color.Red;
                Button1.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button7.Text == "")
                {
                    Button7.Text = Button4.Text;
                    Button4.Text = "";
                    Button4.BackColor = System.Drawing.Color.Red;
                    Button7.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
                else
                    if (Button5.Text == "")
                    {
                        Button5.Text = Button4.Text;
                        Button4.Text = "";
                        Button4.BackColor = System.Drawing.Color.Red;
                        Button5.BackColor = System.Drawing.Color.Yellow;
                        checkWinner();
                    }
        }

        else if (btn.ID == "Button5")                        //button5
        {
            if (Button2.Text == "")
            {
                Button2.Text = Button5.Text;
                Button5.Text = "";
                Button5.BackColor = System.Drawing.Color.Red;
                Button2.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button4.Text == "")
                {
                    Button4.Text = Button5.Text;
                    Button5.Text = "";
                    Button5.BackColor = System.Drawing.Color.Red;
                    Button4.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
                else
                    if (Button6.Text == "")
                    {
                        Button6.Text = Button5.Text;
                        Button5.Text = "";
                        Button5.BackColor = System.Drawing.Color.Red;
                        Button6.BackColor = System.Drawing.Color.Yellow;
                        checkWinner();
                    }
                    else
                        if (Button8.Text == "")
                        {
                            Button8.Text = Button5.Text;
                            Button5.Text = "";
                            Button5.BackColor = System.Drawing.Color.Red;
                            Button8.BackColor = System.Drawing.Color.Yellow;
                            checkWinner();
                        }
        }


        else if (btn.ID == "Button6")                            //button6
        {
            if (Button3.Text == "")
            {
                Button3.Text = Button6.Text;
                Button6.Text = "";
                Button6.BackColor = System.Drawing.Color.Red;
                Button3.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button5.Text == "")
                {
                    Button5.Text = Button6.Text;
                    Button6.Text = "";
                    Button6.BackColor = System.Drawing.Color.Red;
                    Button5.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
                else
                    if (Button9.Text == "")
                    {
                        Button9.Text = Button6.Text;
                        Button6.Text = "";
                        Button6.BackColor = System.Drawing.Color.Red;
                        Button9.BackColor = System.Drawing.Color.Yellow;
                        checkWinner();
                    }
        }


        else if (btn.ID == "Button7")                             //button7
        {
            if (Button4.Text == "")
            {
                Button4.Text = Button7.Text;
                Button7.Text = "";
                Button7.BackColor = System.Drawing.Color.Red;
                Button4.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button8.Text == "")
                {
                    Button8.Text = Button7.Text;
                    Button7.Text = "";
                    Button7.BackColor = System.Drawing.Color.Red;
                    Button8.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
        }


        else if (btn.ID == "Button8")                             //button8
        {
            if (Button7.Text == "")
            {
                Button7.Text = Button8.Text;
                Button8.Text = "";
                Button8.BackColor = System.Drawing.Color.Red;
                Button7.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button5.Text == "")
                {
                    Button5.Text = Button8.Text;
                    Button8.Text = "";
                    Button8.BackColor = System.Drawing.Color.Red;
                    Button5.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
                else
                    if (Button9.Text == "")
                    {
                        Button9.Text = Button8.Text;
                        Button8.Text = "";
                        Button8.BackColor = System.Drawing.Color.Red;
                        Button9.BackColor = System.Drawing.Color.Yellow;
                        checkWinner();
                    }
        }


        else if (btn.ID == "Button9")                                       //button9
        {
            if (Button6.Text == "")
            {
                Button6.Text = Button9.Text;
                Button9.Text = "";
                Button9.BackColor = System.Drawing.Color.Red;
                Button6.BackColor = System.Drawing.Color.Yellow;
                checkWinner();
            }
            else
                if (Button8.Text == "")
                {
                    Button8.Text = Button9.Text;
                    Button9.Text = "";
                    Button9.BackColor = System.Drawing.Color.Red;
                    Button8.BackColor = System.Drawing.Color.Yellow;
                    checkWinner();
                }
        }

    }

    void checkWinner()
    {
        if (Button1.Text == "1" &&
            Button2.Text == "2" &&
            Button3.Text == "3" &&
            Button4.Text == "4" &&
            Button5.Text == "5" &&
            Button6.Text == "6" &&
            Button7.Text == "7" &&
            Button8.Text == "8")
        {
            Button1.BackColor = System.Drawing.Color.Green;
            Button2.BackColor = System.Drawing.Color.Green;
            Button3.BackColor = System.Drawing.Color.Green;
            Button4.BackColor = System.Drawing.Color.Green;
            Button5.BackColor = System.Drawing.Color.Green;
            Button6.BackColor = System.Drawing.Color.Green;
            Button7.BackColor = System.Drawing.Color.Green;
            Button8.BackColor = System.Drawing.Color.Green;

            Button1.Enabled = false;
            Button2.Enabled = false;
            Button3.Enabled = false;
            Button4.Enabled = false;
            Button5.Enabled = false;
            Button6.Enabled = false;
            Button7.Enabled = false;
            Button8.Enabled = false;
            Button9.Enabled = false;
        }
    }



    protected void resetBtn_Click(object sender, EventArgs e)
    {
        generator();

        if (Button1.Text == "0")
        {
            Button1.BackColor = System.Drawing.Color.Red;
            Button1.Text = "";
        }
        else
            Button1.BackColor = System.Drawing.Color.Yellow;
        if (Button2.Text == "0")
        {
            Button2.BackColor = System.Drawing.Color.Red;
            Button2.Text = "";
        }
        else
            Button2.BackColor = System.Drawing.Color.Yellow;
        if (Button3.Text == "0")
        {
            Button3.BackColor = System.Drawing.Color.Red;
            Button3.Text = "";
        }
        else
            Button3.BackColor = System.Drawing.Color.Yellow;
        if (Button4.Text == "0")
        {
            Button4.BackColor = System.Drawing.Color.Red;
            Button4.Text = "";
        }
        else
            Button4.BackColor = System.Drawing.Color.Yellow;
        if (Button5.Text == "0")
        {
            Button5.BackColor = System.Drawing.Color.Red;
            Button5.Text = "";
        }
        else
            Button5.BackColor = System.Drawing.Color.Yellow;
        if (Button6.Text == "0")
        {
            Button6.BackColor = System.Drawing.Color.Red;
            Button6.Text = "";
        }
        else
            Button6.BackColor = System.Drawing.Color.Yellow;
        if (Button7.Text == "0")
        {
            Button7.BackColor = System.Drawing.Color.Red;
            Button7.Text = "";
        }
        else
            Button7.BackColor = System.Drawing.Color.Yellow;
        if (Button8.Text == "0")
        {
            Button8.BackColor = System.Drawing.Color.Red;
            Button8.Text = "";
        }
        else
            Button8.BackColor = System.Drawing.Color.Yellow;
        if (Button9.Text == "0")
        {
            Button9.BackColor = System.Drawing.Color.Red;
            Button9.Text = "";
        }
        else
            Button9.BackColor = System.Drawing.Color.Yellow;

        Button1.Enabled = true;
        Button2.Enabled = true;
        Button3.Enabled = true;
        Button4.Enabled = true;
        Button5.Enabled = true;
        Button6.Enabled = true;
        Button7.Enabled = true;
        Button8.Enabled = true;
        Button9.Enabled = true;

        score.Text = "0";
    }

    void generator()
    {
        Random rnd = new Random();
        String temp;
        int[] n = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int[] m = new int[10];
        int p = 9, k = 0;
        do
        {
            int i = rnd.Next(p);
            m[k] = n[i];
            for (int j = i; j < p; j++)
            {
                n[j] = n[j + 1];
            }
            p--;
            k++;
        } while (p > 0);


        Button1.Text = m[0].ToString();
        Button2.Text = m[1].ToString();
        Button3.Text = m[2].ToString();
        Button4.Text = m[3].ToString();
        Button5.Text = m[4].ToString();
        Button6.Text = m[5].ToString();
        Button7.Text = m[6].ToString();
        Button8.Text = m[7].ToString();
        Button9.Text = m[8].ToString();

    }
    protected void signOutBtn_click(object sender, EventArgs e)
    {
        Response.Redirect("default.aspx");
    }
}
