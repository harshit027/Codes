<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>MyDetails</title>
</head>
<body>
    
<div align="Left" >
<h1>Harshit</h1>
</div>
<form id="form1" runat="server">
    <div align="left"> 
        <asp:Button ID="Button1" runat="server" Text="My Education" Width="134px" 
            BackColor="DarkBlue" ForeColor="AntiqueWhite"
    onclick="MyEducationClick" Height="39px"/><br /><br /></div>
    <div align="center">
    <asp:Button ID="Button2" runat="server" Text="My Hobbies" Height="39px"  
            BackColor="DarkBlue" ForeColor="AntiqueWhite"
    onclick="MyHobbiesClick" Width="135px"/><br /><br /></div>
    <div align="right">
    <asp:Button ID="Button3" runat="server" Text="My College" Width="135px" 
            BackColor="DarkBlue" ForeColor="AntiqueWhite"
    onclick="MyCollegeClick" Height="39px" style="margin-left: 0px"/><br /><br /></div>
    <div align="center">
    <asp:Button ID="Button4" runat="server" Text="My Friends" Width="135px" 
            BackColor="DarkBlue" ForeColor="AntiqueWhite"
    onclick="MyFriendsClick" Height="39px"/><br /><br /></div>
    <div align="left">
    <asp:Button ID="Button5" runat="server" Text="Myself" Width="135px" 
            BackColor="DarkBlue" ForeColor="AntiqueWhite"
    onclick="MyselfClick" Height="39px"/></div>
    </form>
</body>
</html>
