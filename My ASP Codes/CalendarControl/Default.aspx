<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <asp:Literal ID="literal1" runat="server" Text="" Visible=false></asp:Literal>
    <asp:Calendar ID="calendar1" runat="server" ></asp:Calendar><br />
    <asp:Button ID="currentDate" runat="server" Text="Current Date" OnClick="ShowDate"/>
    <asp:Button ID="selectedDate" runat="server" Text="Selected Date" OnClick="ShowDate"/>
    </div>
    </form>
</body>
</html>
