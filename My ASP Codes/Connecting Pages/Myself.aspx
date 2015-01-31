<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Myself.aspx.cs" Inherits="Myself" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Myself</title>
</head>
<body>
<h1>Myself</h1>
<div align="center">
<img src="myself.JPG" /></div>
    <form id="form1" runat="server">
    <div align="right">
    <asp:Button ID="HomeButton" runat="server" Text="Home" BackColor="Pink" OnClick="HomeClick" />
    </div>
    </form>
</body>
</html>
