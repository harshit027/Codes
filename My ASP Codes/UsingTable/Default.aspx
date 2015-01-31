<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table border="1" align="center" style="height: 125px; background-color:Navy; color:White; width:800px; font-weight: bold">
            <tr>
                <th>ROLLNO</th>
                <th>NAME</th>
                <th>PERCENT</th>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%</td>
            </tr>
            <tr>
                <td>1</td>
                <td>Vivek</td>
                <td>80%<img alt="" src="header.png" style="width: 220px; height: 124px" /></td>
            </tr>
        </table>
    </div>
    <asp:Button ID="Button1" runat="server" Text="Show Code Behind" 
        onclick="Button1_Click" />
    <asp:Button ID="btnGoToNextPage" runat="server" Text= "Go To Next Page" 
        onclick="btnGoToNextPage_Click" />
    </form>
</body>
</html>
