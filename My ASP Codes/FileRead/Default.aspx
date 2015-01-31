<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body style="background-color:#000044;">

    <form id="form1" runat="server">
    <center>
    <div style=" width:600px; height:50px; background-color:#ff9900; color:#0000aa; font-family:Verdana;  font-size:x-large;">
    USER INFORMATION
    </div>
    <div>
    <asp:Table ID="Table1" runat="server" BorderStyle="Double" GridLines="Both" BorderWidth="2" Width="600px" Font-Size="Large" BackColor="#dddddd">
    </asp:Table>
    </div><br /><br />
    <div>
    <asp:Button ID="Button1" runat="server" Text="Show Info" OnClick="ShowInfo" />&nbsp;&nbsp;
        <input id="Button2" type="button" value="Print" onclick="javascript:print();" />
    </div>
    </center>
    </form>
</body>
</html>
