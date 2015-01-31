<%@ Page Language="C#" AutoEventWireup="true" Theme="SkinFile" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <h3 style="font-family:Verdana;">Named Themes</h3><br /><br />
    <asp:Button ID="Button1" runat="server" Text="Button1" SkinID="skinBlue" />&nbsp&nbsp&nbsp
    <asp:Button ID="Button2" runat="server" Text="Button2" SkinID="skinBlue"/>&nbsp&nbsp&nbsp
    <asp:Button ID="Button3" runat="server" Text="Button3" SkinID="skinBlue"/>&nbsp&nbsp&nbsp
    <asp:Button ID="Button4" runat="server" Text="Button4" SkinID="skinBlue"/>&nbsp&nbsp&nbsp
    <br /><br />
    <h3 style="font-family:Verdana;">Default Themes</h3><br /><br />
    <asp:Button ID="Button5" runat="server" Text="Button5" />&nbsp&nbsp&nbsp
    <asp:Button ID="Button6" runat="server" Text="Button6" />&nbsp&nbsp&nbsp
    <asp:Button ID="Button7" runat="server" Text="Button7" />&nbsp&nbsp&nbsp
    <asp:Button ID="Button8" runat="server" Text="Button8" />&nbsp&nbsp&nbsp
    <br /><br />
    
   
    </div>
    </form>
</body>
</html>
