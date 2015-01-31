<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1
        {
            height: 28px;
        }
        .style2
        {
            width: 123px;
        }
        .style3
        {
            width: 153px;
        }
    </style>
</head>
<body style="background-color:red; color:White;">
    <center>
        <form id="form1" runat="server">
            <div style=" height:auto; width:750px; background-color:white; color:Red; ">
            <font  size=30 >Greetings Gallery</font><br /><br /><br />
        </div>
        <div style="height: auto; width: 750px">
        <table cellpadding=1 border=1>
        <tr>
        <td>
        <asp:ListBox ID="list1" runat="server" Height="294px" Width="152px" 
                AutoPostBack="True" onselectedindexchanged="list1_SelectedIndexChanged" >
        <asp:ListItem Text="Diwali"></asp:ListItem>
        <asp:ListItem Text="Christmas"></asp:ListItem>
        <asp:ListItem Text="Holi"></asp:ListItem>
        <asp:ListItem Text="Valentine"></asp:ListItem>
        <asp:ListItem Text="Birthday"></asp:ListItem>
        </asp:ListBox>
        </td>
        <td class="style2">
        <asp:Image ID="imgBase" runat="server" ImageUrl="~/Tulips1.JPG" />
        </td>
        <td class="style3">
        <asp:ListBox ID="list2" runat="server" Height="294px" Width="152px" 
                onselectedindexchanged="list2_SelectedIndexChanged" AutoPostBack="True" >
        </asp:ListBox>
        </td>
        </tr>
        <tr>
        <td colspan=3 class="style1">
        <asp:Label ID="label1" runat="server" Text="Gallery" Font-Bold=true></asp:Label>
        <td class="style1">
            </td>
        </tr>
        <tr>
        <td colspan=3>
        <asp:ImageButton ID="ImageButton1" runat="server" ImageUrl="" />
        <asp:ImageButton ID="ImageButton2" runat="server" ImageUrl="" />
        <asp:ImageButton ID="ImageButton3" runat="server" ImageUrl="" />
        <asp:ImageButton ID="ImageButton4" runat="server" ImageUrl="" />
        <asp:ImageButton ID="ImageButton5" runat="server" ImageUrl="" />
        </td>
        </tr>
        </table>
        </div>
        <div style="font-family:Tahoma; height:auto; width:750px; color:White ">
        All Rights reserved at 
        <asp:HyperLink ID="hprLink" runat="server" Text="www.galleries.com" NavigateUrl="~/galleries.aspx" ForeColor=White></asp:HyperLink>
        </div>
        </form>
    </center>
</body>
</html>
