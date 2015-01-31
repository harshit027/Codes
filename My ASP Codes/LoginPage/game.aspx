<%@ Page Language="C#" AutoEventWireup="true" CodeFile="game.aspx.cs" Inherits="game" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
<center>
    <form id="form1" runat="server">
    <div style=" background-color:#888888 ; color:#ffffff; font-family:Verdana; font-size:x-large; width:600px; height:50px">
    <h1>PUZZLE</h1>
    </div>
    <div style=" background-color:#000000; color:#ffffff; font-family:Verdana; font-size:x-large; width:600px; height:400px">
    <br />
    <br />
    <br />
    <table border=0>
    <tr>
    <td><asp:Button ID="Button1" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="1" BackColor=yellow/>
    </td>
    <td><asp:Button ID="Button2" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="2" BackColor=yellow/>
    </td>
    <td><asp:Button ID="Button3" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="3" BackColor=yellow/>
    </td>
    </tr>
    <tr>
    <td><asp:Button ID="Button4" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="4" BackColor=yellow/>
    </td>
    <td><asp:Button ID="Button5" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="5" BackColor=yellow/>
    </td>
    <td><asp:Button ID="Button6" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="6" BackColor=yellow/>
    </td>
    </tr>
    <tr>
    <td><asp:Button ID="Button7" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="7" BackColor=yellow/>
    </td>
    <td><asp:Button ID="Button8" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="" BackColor=Red/>
    </td>
    <td><asp:Button ID="Button9" runat="server" OnClick="swapFun" Height=80px Width=80px Font-Bold="true" Font-Size=30 Text="8" BackColor=yellow/>
    </td>
    </tr>    
    </table>
    </div>
    <div style=" background-color:#000000; color:#ffffff; font-family:Verdana; font-size:xx-large; width:600px; height:50px">
    <asp:Literal ID="score" runat=server Text="0"></asp:Literal>
    </div>
    <div style=" background-color:#888888; color:#ffffff; width:600px; height:60px;">
     <asp:Button ID="resetBtn" runat="server" Text="RESET" Font-Bold=true 
            onclick="resetBtn_Click"/>
     <asp:Button ID="signout" runat="server" Text="SIGN OUT" Font-Bold=true 
            onclick="signOutBtn_click"/>       
    </div>
    </form>
    </center>
</body>
</html>
