<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    <table border="1" cellspacing="0" cellpadding="5" width="400" align="center" style="background-color:#dddddd; color:White;">
    <tr>
    <th style="background-color:#ffaa00; color:#0000bb; font-family:Times New Roman; font-size:x-large;">FILES</th>
    </tr>
    <tr align="center">
    <td><a href="files/Ami Bios Beep Codes.pdf">Ami Bios Beep Codes</a></td>
    </tr>
    <tr align="center">
    <td><a href="files/HTML Tutorial.rar">HTML Tutorial</a></td>
    </tr>
    <tr align="center">
    <td><a href="files/JavaScript Tutorial.doc">Javascript Tutorial</a></td>
    </tr>
    <tr align="center">
    <td><a href="files/pic.jpg">Wallpaper</a></td>
    </tr>
    <tr align="center">
    <td><asp:Literal ID="Literal1" runat="server" Text=""></asp:Literal></td>
    </tr>
    <tr align="center">
    <td><asp:Button ID="Button1" runat="server" Text="More Files....." OnClick="moreFiles"/></td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
