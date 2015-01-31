<%@ Page Language="C#" AutoEventWireup="true" CodeFile="MyEducation.aspx.cs" Inherits="MyEducation" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>My Education</title>
</head>
<body>
<h1>My Education</h1>
<br />
<br />
<h2>MySchool</h2>
<div align="center">
<img src="myschool.jpg" /></div>
<div align="left">
<h2>MyCollege</h2></div>
<div align="center"><img src="mycollege.jpg" />
</div>
    <form id="form1" runat="server">
    <div align="right">
    
        <asp:Button ID="Button1" runat="server" Text="Home" BackColor="Pink" onclick="HomeClick"/>
    
    </div>
    </form>
</body>
</html>
