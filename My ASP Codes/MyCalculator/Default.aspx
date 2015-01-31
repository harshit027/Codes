<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <center>
    <div style="background-color:Green; height:60px ;width:500px">
    <h1 style="text-align: center">CALCULATOR</h1>
    <div style="background-color:Olive; height:200px ;width:500px; font-family:verdana;">
    <table border =1 width=500px>
    <tr>
    <td>FirstNumber</td>
    <td><asp:TextBox ID="firstNumberTB" runat="server"></asp:TextBox></td>
    </tr>
    <tr>
    <td>SecondNumber</td>
    <td><asp:TextBox ID="secondNumberTB" runat="server"></asp:TextBox></td>
    </tr>
    <tr>
    <td>Result</td>
    <td><asp:TextBox ID="resultTB" runat="server" ReadOnly="true"></asp:TextBox></td>
    </tr>
    <tr>
    <td colspan=2><asp:Literal ID="ErrorMsgLiteral" runat="server" Visible="false" Text=""></asp:Literal>
    </td>
    </tr>
    <tr>
    <td>Operation</td>
    <td>
    <asp:Button ID="Button1" runat="server" Width=40px Height=40px OnClick="Calculate" Text="+" Font-Size=Large/>
    <asp:Button ID="Button2" runat="server" Width=40px Height=40px OnClick="Calculate" Text="-" Font-Size=Large/>
    <asp:Button ID="Button3" runat="server" Width=40px Height=40px OnClick="Calculate" Text="*" Font-Size=Large/>
    <asp:Button ID="Button4" runat="server" Width=40px Height=40px OnClick="Calculate" Text="/" Font-Size=Large/>
    </td>
    </tr>
    </table>
    </div>
    <div style="background-color:Green; height:20px ;width:500px; color:#ffffff;">
    All Right reserved @ <a href="http://localhost:1829/MyCalculator/calculator.aspx">Calculator</a>
    </div>
    </div></center>
    </form>
</body>
</html>
