<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body style="background-color:#006600;">
<center>
    <form id="form1" runat="server">
    <div style=" color:White; font-family:Verdana; ">
    <h1>JABALPUR ENGINEERING COLLEGE</h1>
    </div>
    <div >
    <asp:Image ID="logo" runat="server" ImageUrl="~/images/logo.png" />
    </div><br />
    <div>
    <asp:ImageMap ID="imagemap" runat="server" ImageUrl="~/images/jec.jpg" >
    <asp:CircleHotSpot  AlternateText="MathsDept" X="300" Y="100" Radius="50" NavigateUrl="~/mathmetics.aspx"/>
    <asp:CircleHotSpot AlternateText="Workshop" X="450" Y="80" Radius="50" NavigateUrl="~/workshop.aspx"/>
    <asp:CircleHotSpot AlternateText="CivilDept" X="470" Y="240" Radius="60" NavigateUrl="~/civil.aspx"/>
    <asp:CircleHotSpot AlternateText="ElectricalDept" X="690" Y="240" Radius="70" NavigateUrl="~/electrical.aspx"/>
    <asp:CircleHotSpot AlternateText="CSITDept" X="690" Y="380" Radius="60" NavigateUrl="~/csit.aspx"/>
    <asp:CircleHotSpot AlternateText="MechanicalDept" X="240" Y="250" Radius="70" NavigateUrl="~/mechanical.aspx"/>
    <asp:CircleHotSpot AlternateText="IndustrialProductionDept" X="80" Y="380" Radius="60" NavigateUrl="~/ip.aspx"/>
    <asp:CircleHotSpot AlternateText="ChemistryDept" X="200" Y="410" Radius="40" NavigateUrl="~/chemistry.aspx"/>
    <asp:CircleHotSpot AlternateText="PhysicsDept" X="290" Y="410" Radius="30" NavigateUrl="~/physics.aspx"/>
    <asp:CircleHotSpot AlternateText="E&TCDept" X="280" Y="580" Radius="50" NavigateUrl="~/ec.aspx"/>
    <asp:CircleHotSpot AlternateText="Administration" X="460" Y="440" Radius="80" NavigateUrl="~/adm.aspx"/>
    <asp:CircleHotSpot AlternateText="HighVoltageLab" X="650" Y="100" Radius="50" NavigateUrl="~/tifaccore.aspx"/>
    </asp:ImageMap>
    </div>
    </form>
    </center>
</body>
</html>
