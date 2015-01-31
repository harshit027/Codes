<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
    <style type="text/css">
        .style1
        {
            width: 469px;
        }
        .style2
        {
            width: 212px;
        }
        .style3
        {
            width: 212px;
            height: 14px;
        }
        .style4
        {
            width: 469px;
            height: 14px;
        }
    </style>
</head>
<body style="background-color:Green;">
<center>
    <form id="form1" runat="server">
    <div style="height:auto; width:750px; background-color:White; color:Olive;font-family:Verdana;">
    <h2> Registration Form</h2>
    </div>
    <div style="background-color:Olive; color:White;width:750px;">
    <table border=1>
    <tr>
    <td class="style2"><asp:Label ID="namelb" runat="server" Text="Name"></asp:Label></td>
    <td class="style1"><asp:TextBox ID="nametb" runat="server" 
            style="margin-right: 1px" Width="143px"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style3"><asp:Label ID="passwordlb" runat="server" Text="Password"></asp:Label></td>
    <td class="style4">
        <asp:TextBox ID="passwordtb" runat="server" TextMode=Password 
            Height="21px" Width="142px"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style2"><asp:Label ID="dob" runat="server" Text="DateOfBirth"></asp:Label>
    <td class="style1"><asp:TextBox ID="datetb" runat=server Text="dd" ></asp:TextBox>
    <asp:TextBox ID="monthtb" runat=server Text="mmm" ></asp:TextBox>
    <asp:TextBox ID="yeartb" runat=server Text="yyyy"></asp:TextBox></td>
    </tr>
    <tr>
    <td class="style2"><asp:Label ID="qualificationlb" runat="server" Text="Qualification"></asp:Label></td>
    <td class="style1">
    <asp:DropDownList ID="qualificationddl" runat="server">
    <asp:ListItem Text="UnderGraduate"></asp:ListItem>
    <asp:ListItem Text="Graduate"></asp:ListItem>
    <asp:ListItem Text="PostGraduate"></asp:ListItem>
    </asp:DropDownList>
    </td>
    </tr>
    <tr>
    <td class="style2">
    <asp:Label ID="hobbieslb" runat="server" Text="Hobbies"></asp:Label>
    </td>
    <td class="style1">
    <asp:CheckBoxList ID="hobbiescbl" runat="server">
    <asp:ListItem Text="Music"></asp:ListItem>
    <asp:ListItem Text="Sports"></asp:ListItem>
    <asp:ListItem Text="Cooking"></asp:ListItem>
    <asp:ListItem Text="Travelling"></asp:ListItem>
    <asp:ListItem Text="StampCollection"></asp:ListItem>
    <asp:ListItem Text="Others"></asp:ListItem>
    </asp:CheckBoxList>
    </td>
    </tr>
    <tr>
    <td class="style2">
    <asp:Label ID="languagelb" runat="server" Text="Language"></asp:Label>
    </td>
    <td class="style1">
    <asp:RadioButtonList ID="languagerbl" runat="server">
    <asp:ListItem Text="C"></asp:ListItem>
    <asp:ListItem Text="Pascal"></asp:ListItem>
    <asp:ListItem Text="Fortran"></asp:ListItem>
    <asp:ListItem Text="Java"></asp:ListItem>
    <asp:ListItem Text="ColdFusion"></asp:ListItem>    
    </asp:RadioButtonList>
    
    </td>
    </tr>
    <tr>
    <td class="style2">
    <asp:Label ID="databaselb" runat="server" Text="Database"></asp:Label>
    </td>
    <td class="style1">
    <asp:RadioButtonList ID="databaserbl" runat="server">
    <asp:ListItem Text="Oracle"></asp:ListItem>
    <asp:ListItem Text="MS Access"></asp:ListItem>
    <asp:ListItem Text="MS Sql"></asp:ListItem>
    <asp:ListItem Text="Informix"></asp:ListItem>
    <asp:ListItem Text="IBM-DB2"></asp:ListItem>    
    </asp:RadioButtonList>
    
    </td>
    </tr>
    <tr>
    <td colspan=4 align="center">
    <asp:Button ID="submitbtn" runat="server" Text="Submit" onclick="submitbtn_Click" />
    </td>
    </tr>
    <tr>
    <td>
     <asp:Label ID="datalb" runat="server" Visible="false" Text="" Font-Bold=true></asp:Label>
    </td>
    </tr>
    </table>
    </div>
    </form>
    </center>
</body>
</html>
