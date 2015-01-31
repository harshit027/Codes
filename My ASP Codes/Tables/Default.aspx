<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <center>
    <div>
    <asp:Table ID="table1" runat="server" Width="600px" BorderStyle="Double" BorderWidth="5" BackColor="CadetBlue" ForeColor="White" GridLines="Both">
    <asp:TableHeaderRow ID="TableHeaderRow1" runat="server" >
    <asp:TableHeaderCell ID="TableHeaderCell1" runat="server" Text="ID"></asp:TableHeaderCell>
    <asp:TableHeaderCell ID="TableHeaderCell2" runat="server" Text="Name"></asp:TableHeaderCell>
    <asp:TableHeaderCell ID="TableHeaderCell3" runat="server" Text="Salary"></asp:TableHeaderCell>
    
    </asp:TableHeaderRow>
    <asp:TableRow ID="TableRow1" runat="server">
    <asp:TableCell ID="TableCell1" runat="server" Text="1001" ></asp:TableCell>
    <asp:TableCell ID="TableCell2" runat="server" Text="John" ></asp:TableCell>
    <asp:TableCell ID="TableCell3" runat="server" Text="20000" ></asp:TableCell>
    </asp:TableRow>
    <asp:TableRow ID="TableRow2" runat="server">
    <asp:TableCell ID="TableCell4" runat="server" Text="1002" ></asp:TableCell>
    <asp:TableCell ID="TableCell5" runat="server" Text="Mark" ></asp:TableCell>
    <asp:TableCell ID="TableCell6" runat="server" Text="20000" ></asp:TableCell>
    </asp:TableRow>
    <asp:TableRow ID="TableRow3" runat="server">
    <asp:TableCell ID="TableCell7" runat="server" Text="1003" ></asp:TableCell>
    <asp:TableCell ID="TableCell8" runat="server" Text="Andy" ></asp:TableCell>
    <asp:TableCell ID="TableCell9" runat="server" Text="20000" ></asp:TableCell>
    </asp:TableRow>
    </asp:Table>
    <br /><br /><br />
    <asp:Button ID="Button1" runat="server" Text="Add Data" OnClick="addData" /> 
    </div></center>
    </form>
</body>
</html>
