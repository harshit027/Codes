<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <asp:Button ID="button" runat="server" Text="Button" OnClick="myTest" />
    <br /><br />
    <asp:Literal ID="literal" runat="server" Text="Literal"></asp:Literal>
    <br /><br />
    <asp:Label ID="label" runat="server" Text="Label"></asp:Label>
    <br /><br />
    <asp:LinkButton ID="linkButton" runat=server Text="LinkButton" OnClick="myTest"></asp:LinkButton>
    <br /><br />
    <asp:ImageButton ID="imageButton" runat=server ImageUrl="~/2cdkc8x.jpg" OnClick="myTest"/>
    <br /><br />
    <asp:HyperLink ID="hyperLink" runat=server NavigateUrl="~/test.html" Text="HyperLink"></asp:HyperLink>
    <br /><br />
    <asp:TextBox ID="textbox" runat="server" Text=""></asp:TextBox>
    <br /><br />
    <asp:DropDownList ID="dropDownList" runat="server" AutoPostBack="True" 
            onselectedindexchanged="dropDownList_SelectedIndexChanged" >
    <asp:ListItem Text="Red" Value="Red"  ></asp:ListItem>
    <asp:ListItem Text="Blue" Value="Blue" ></asp:ListItem>
    <asp:ListItem Text="Green" Value="Green" ></asp:ListItem>
    <asp:ListItem Text="Yellow" Value="Yellow" ></asp:ListItem>
    </asp:DropDownList>
    <asp:Button ID="Button1" Text="changeColor" runat="server" OnClick="changeColor" />
    </div>
    </form>
</body>
</html>
