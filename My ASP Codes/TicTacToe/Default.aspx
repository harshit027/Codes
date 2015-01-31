<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>TIC TAC TOE</title>
    <style type="text/css">
        #form1 {
            width: 310px;
        }
    </style>
</head>
<body bgcolor="black">
<div align="center">
<h1><font color="white" size=40>TIC TAC TOE</font></h1></div><br /><br />
   

    <div align="center">
    <form id="form1" runat="server" >
    <asp:Button id="Button1" text=" " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button2" text="  " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button3" text="   " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/><br />
    
    <asp:Button id="Button4" text="    " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button5" text="     " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button6" text="      " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/><br />
    
    <asp:Button id="Button7" text="       " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button8" text="        " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/>
    <asp:Button id="Button9" text="         " runat="server" Height="100px" Width="100px" BackColor="white" onclick="ButtonClick" Font="Bold" Font-Size=50 BorderColor="black" BorderWidth=3/><br />
    <br />
    <br />
    <br />
    <asp:Button ID="Winner" Text="" runat="server" Height=60px Width=150px Font-Size=Large BackColor="black" ForeColor="White" Visible=false OnClick="Winner_Click" />
    <br />
    <br />
    <br />
    <br />
    <asp:Button ID="Reset" Text="RESET" runat="server" Height=44px Width=103px 
        Font-Size=X-Large BackColor="black" ForeColor="White" onclick="Reset_Click" />
    
    </form>
    </div>
    
    <asp:Literal ID="Literal1" runat="server" Text=  "O" Visible=false />
    
</body>
</html>
