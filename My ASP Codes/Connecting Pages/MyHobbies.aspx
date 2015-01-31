<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MyHobbies.aspx.cs" Inherits="MyHobbies" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>My Hobbies</title>
</head>
<body>
<h1>My Hobbies</h1>
<h2>Cricket</h2>
<div align="center">
<img src="cricket.bmp" /></div>
<h2>Music</h2>
<div align="center">
<img src="music.jpg" /></div>
<h2>Pool</h2>
<div align="center">
<img src="pool.bmp" /></div>
    <form id="form1" runat="server">
    <div align="right">
    <asp:Button Text="Home" BackColor="Pink" id="HomeButton" runat="server" OnClick="HomeClick" />
    
    </div>
    </form>
</body>
</html>
