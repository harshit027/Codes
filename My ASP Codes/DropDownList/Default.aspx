<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <center>
    <div >
    <table cellpadding="2" border="1">
    <tr>
    <td>
    <asp:Button ID="upList1" runat="server" Text="up" OnClick="moveup" BackColor="#00ff00" /><br />
    <asp:Button ID="downList1" runat="server" Text="down" OnClick="movedown" BackColor="#00ff00"/>
    </td>
    <td><asp:ListBox ID="ListBox1" runat="server" Height=200px Width=100px SelectionMode="Multiple">
    <asp:ListItem Text="Red" Value="Red" ></asp:ListItem>
    <asp:ListItem Text="Blue" Value="Blue"></asp:ListItem>
    <asp:ListItem Text="Green" Value="Green"></asp:ListItem>
    <asp:ListItem Text="Yellow" Value="Yellow"></asp:ListItem>
    </asp:ListBox> </td>
    
    <td>
    <asp:Button ID="moveItemsRight" runat="server" Text=">" OnClick="moveItems" BackColor="#ffff00"/><br />
    <asp:Button ID="moveItemsLeft" runat="server" Text="<" OnClick="moveItems" BackColor="#ffff00"/><br />
    <asp:Button ID="moveAllRight" runat="server" Text=">>" OnClick="moveAllItems" BackColor="#ffff00"/><br />
    <asp:Button ID="moveAllLeft" runat="server" Text="<<" OnClick="moveAllItems" BackColor="#ffff00"/>
    </td>
    
    <td><asp:ListBox ID="ListBox2" runat="server" Height=200px Width=100px SelectionMode="Multiple">
    <asp:ListItem Text="Magenta" Value="Magenta"></asp:ListItem>
    <asp:ListItem Text="Cyan" Value="Cyan"></asp:ListItem>
    <asp:ListItem Text="White" Value="White"></asp:ListItem>
    <asp:ListItem Text="Black" Value="Black"></asp:ListItem>
    
    </asp:ListBox> </td>
    
    <td>
    <asp:Button ID="upList2" runat="server" Text="up" OnClick="moveup" BackColor="#00ff00"/><br />
    <asp:Button ID="downList2" runat="server" Text="down" OnClick="movedown" BackColor="#00ff00"/>
    </td>
    </tr>
    </table>
    
    </div>
    </center>
    </form>
</body>
</html>
