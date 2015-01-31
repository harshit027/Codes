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
using System.Drawing;



public partial class _Default : System.Web.UI.Page 
{
    
     
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void ButtonClick(object sender, EventArgs e)
    {
        Button btn= (Button)sender;
        if(Literal1.Text=="O")
        {
            btn.Text="O";
            Literal1.Text = "X";
            btn.Enabled = false;
            checkWinner();
        }
        else 
        {
            btn.Text = "X";
            Literal1.Text = "O";
            btn.Enabled = false;
            checkWinner();
        }
        
    }
    protected void Reset_Click(object sender, EventArgs e)
    {
        Button1.Text = " ";
        Button2.Text = "  ";
        Button3.Text = "   ";
        Button4.Text = "    ";
        Button5.Text = "     ";
        Button6.Text = "      ";
        Button7.Text = "       ";
        Button8.Text = "        ";
        Button9.Text = "         ";

        Button1.Enabled = true;
        Button2.Enabled = true;
        Button3.Enabled = true;
        Button4.Enabled = true;
        Button5.Enabled = true;
        Button6.Enabled = true;
        Button7.Enabled = true;
        Button8.Enabled = true;
        Button9.Enabled = true;

        Button1.BackColor = System.Drawing.Color.White;
        Button2.BackColor = System.Drawing.Color.White;
        Button3.BackColor = System.Drawing.Color.White;
        Button4.BackColor = System.Drawing.Color.White;
        Button5.BackColor = System.Drawing.Color.White;
        Button6.BackColor = System.Drawing.Color.White;
        Button7.BackColor = System.Drawing.Color.White;
        Button8.BackColor = System.Drawing.Color.White;
        Button9.BackColor = System.Drawing.Color.White;



    }

    void checkWinner()
    {
        if (Button1.Text == Button2.Text && Button2.Text == Button3.Text && Button3.Text == Button1.Text)
        {
            Button1.BackColor = System.Drawing.Color.Yellow;
            Button2.BackColor = System.Drawing.Color.Yellow;
            Button3.BackColor = System.Drawing.Color.Yellow;
            DisableButtons();
            Winner.Visible = true;
            Winner.Text = Button1.Text + " wins : Click";
        }
        else
            if (Button4.Text == Button5.Text && Button5.Text == Button6.Text && Button6.Text == Button4.Text)
            {
                Button4.BackColor = System.Drawing.Color.Yellow;
                Button5.BackColor = System.Drawing.Color.Yellow;
                Button6.BackColor = System.Drawing.Color.Yellow;

                DisableButtons();
                Winner.Visible = true;
                Winner.Text = Button4.Text + " wins : Click";
            }
            else
                if (Button7.Text == Button8.Text && Button8.Text == Button9.Text && Button9.Text == Button7.Text)
                {
                    Button7.BackColor = System.Drawing.Color.Yellow;
                    Button8.BackColor = System.Drawing.Color.Yellow;
                    Button9.BackColor = System.Drawing.Color.Yellow;

                    DisableButtons();
                    Winner.Visible = true;
                    Winner.Text = Button7.Text + " wins : Click";
                }
                else
                    if (Button1.Text == Button4.Text && Button4.Text == Button7.Text && Button7.Text == Button1.Text)
                    {
                        Button1.BackColor = System.Drawing.Color.Yellow;
                        Button4.BackColor = System.Drawing.Color.Yellow;
                        Button7.BackColor = System.Drawing.Color.Yellow;

                        DisableButtons();
                        Winner.Visible = true;
                        Winner.Text = Button1.Text + " wins : Click";
                    }
                    else
                        if(Button2.Text == Button5.Text && Button5.Text == Button8.Text && Button8.Text == Button2.Text)
                        {
                            Button2.BackColor = System.Drawing.Color.Yellow;
                            Button5.BackColor = System.Drawing.Color.Yellow;
                            Button8.BackColor = System.Drawing.Color.Yellow;

                            DisableButtons();
                            Winner.Visible = true;
                            Winner.Text = Button2.Text + " wins : Click";
                        }
                    else
                        if(Button3.Text == Button6.Text && Button6.Text == Button9.Text && Button9.Text == Button3.Text)
                        {
                            Button3.BackColor = System.Drawing.Color.Yellow;
                            Button6.BackColor = System.Drawing.Color.Yellow;
                            Button9.BackColor = System.Drawing.Color.Yellow;

                            DisableButtons();
                            Winner.Visible = true;
                            Winner.Text = Button3.Text + " wins : Click";
                        }
                        else
                           if(Button1.Text == Button5.Text && Button5.Text == Button9.Text && Button9.Text == Button1.Text)
                           {
                               Button1.BackColor = System.Drawing.Color.Yellow;
                               Button5.BackColor = System.Drawing.Color.Yellow;
                               Button9.BackColor = System.Drawing.Color.Yellow;

                               DisableButtons();
                               Winner.Visible = true;
                               Winner.Text = Button1.Text + " wins : Click";
                           }
                           else
                            if(Button7.Text == Button5.Text && Button5.Text == Button3.Text && Button3.Text == Button7.Text)
                            {
                                Button7.BackColor = System.Drawing.Color.Yellow;
                                Button5.BackColor = System.Drawing.Color.Yellow;
                                Button3.BackColor = System.Drawing.Color.Yellow;

                                DisableButtons();
                                Winner.Visible = true;
                                Winner.Text = Button7.Text + " wins : Click";
                            }
    }

    void DisableButtons()
    {
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

    protected void Winner_Click(object sender, EventArgs e)
    {
        Winner.Visible = false;
    }
}



