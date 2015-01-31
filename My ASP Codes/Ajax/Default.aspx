<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
    <div>
       <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Synchronous Call" />
       <asp:UpdatePanel ID="UpdatePanel1" runat="server">
       <ContentTemplate>
       <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Asynchronous Call" />
       <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
       </ContentTemplate>
       </asp:UpdatePanel>
    </div>
    </form>
</body>
</html>
