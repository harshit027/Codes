<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body style="background-color:#dddddd;">
    <form id="form1" runat="server">
    <center>
    <div align="left">
    <asp:Image ID="logo" runat="server" ImageUrl="~/logo-blue.jpg"/>
    <h3><u>Syllabus for Information Technology Branch</u></h3>
    </div>
    <div >
        <table border=2 width=600>
        <tr>
        <th>Semester</th>
        <th>Subjects</th>
        </tr>
            <tr>
                <td>
                    <asp:BulletedList ID="list1" runat="server" DisplayMode="LinkButton" 
                        Width="230px" onclick="list1_Click">
                        <asp:ListItem Text="Semester1"></asp:ListItem>
                        <asp:ListItem Text="Semester2"></asp:ListItem>
                        <asp:ListItem Text="Semester3"></asp:ListItem>
                        <asp:ListItem Text="Semester4"></asp:ListItem>
                        <asp:ListItem Text="Semester5"></asp:ListItem>
                        <asp:ListItem Text="Semester6"></asp:ListItem>
                        <asp:ListItem Text="Semester7"></asp:ListItem>
                        <asp:ListItem Text="Semester8"></asp:ListItem>
                    </asp:BulletedList>
                </td>
                <td>
                    <asp:BulletedList ID="list2" runat="server" DisplayMode="LinkButton"  Width="230px" onclick="list2_Click">
                    </asp:BulletedList>
                </td>
                
            </tr>
        </table>
    </div><br /><br />
    <div>
    <table border=2 width=600 >
    <tr>
    <th>Current Selection</th>
    <th>Previous Selections</th>
    </tr>
    <tr>
    <td>
    <asp:Label ID="currentSelection" runat="server" Text="" Font-Bold="true" Font-Size="Medium" Width="300px"></asp:Label>
    </td>
    <td>
    <asp:ListBox ID="ListBox1" runat="server" Width="300px"></asp:ListBox>
    </td>
    </tr>
    </table>
    </div>
    </center>
    <asp:HiddenField ID="hiddenField" runat="server" Value="" />
    </form>
</body>
</html>
