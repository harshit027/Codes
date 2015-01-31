<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body >
    <form id="form1" runat="server">
    <div style="height:550px">
    <div style="background-color:#000000; color:White; width:100%; height:100px; font-size:larger; text-align:center">
    <br />
    <h2>FILE UPLOADER</h2>
    </div>
    <div style="background-color:#cccccc; width:100%; height:450px;">
        <br /><br /><br /><br />
        <table border="2" cellpadding="10" cellspacing="0" align="center" width="400px" style="background-color:#ddaa00; font-family:Verdana; color:#000000;">
        <tr align="center">
        <th colspan=2 >FILE UPLOADER</th>
        </tr>
        <tr align="center">
        <td>
        Select File
        </td>
        <td>
        <asp:FileUpload ID="FileUpload1" runat="server" />
        <tr align="center">
        <td colspan=2>
            <asp:Literal ID="Literal1" runat="server"></asp:Literal>
        </td>
        </tr>
        <tr align="center">
        <td colspan=2>
        <asp:Button ID="Button1" runat="server" Text="Upload" OnClick="Upload" />
        </td>
        </tr>
        </table>
    </div>
    
    <div style="background-color:#000000;color:#ffffff;width:100%; height:30px; font-family:Verdana; font-size:10;text-align:center;">
    All rights reserved &copy Harshit
    </div>
    </div>
    </form>
</body>
</html>
