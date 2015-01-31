<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <center>
    <div style=" background-color:#005500; color:#ffffff; font-family:Verdana; height:50px; width:400px;">
    <h1>LOGIN</h1>
    </div>
    <div style=" background-color:Olive; color:#ffffff; font-family:Verdana; height:300px; width:400px;" >
    <br /><br /><br />
        <table border=0 width=300px >
        <tr>
        <td>
        <asp:Label runat="server" ID="usernameLB" Text="USERNAME" Font-Bold="true"></asp:Label>
        </td>
        <td>
        <asp:TextBox runat="server" ID="usernameTB" ></asp:TextBox>
        </td>
        </tr>
        <tr>
        <td>
        <asp:Label runat="server" ID="passwordLB" Text="PASSWORD" Font-Bold="true"></asp:Label>
        </td>
        <td>
        <asp:TextBox runat="server" ID="passwordTB" TextMode=Password></asp:TextBox>
        </td>
        </tr>
        <tr>
        <td colspan=2>
        <asp:Literal ID="messageLit" runat="server" Text="" Visible="false"></asp:Literal>
        </td></tr>
        </table>
        <br />
        <br />
        <br />
        <asp:Button ID="loginBtn" runat="server" Text="Sign In" OnClick="loginCheck" />
    </div>
    
    </center>
    </form>
</body>
</html>
