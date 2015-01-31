<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body style="font-family:Verdana; font-size:medium">
    <form id="form1" runat="server">
    <asp:ScriptManager ID="ScriptManager1" runat="server" >
    
    </asp:ScriptManager>
    <div>
    <table width="500px" border="1" cellspacing="0" cellpadding="5" align="center" style="background-color:#00aaff; color:White;">
    <tr style="background-color:#dddddd; color:Black;">
    <th colspan="2" >Doctor's Data Handling</th>
    </tr>
    
    <tr align="center">
    <td>
    <asp:UpdatePanel ID="UpdatePanel1" runat="server" Visible="false">
    <ContentTemplate>
    <table width="500px" align="center">
    <tr >
    <th colspan="2"><u>New Entry</u><br /><br /></th>
    </tr>
    
    <tr >
    
    <td>ID</td>
    <td><asp:TextBox ID="idTB" runat="server" Text=""></asp:TextBox> </td>
    </tr>
    <tr >
    <td >Name</td>
    <td><asp:TextBox ID="nameTB" runat="server" Text=""></asp:TextBox> </td>
    </tr>
    <tr >
    <td >Degree</td>
    <td><asp:TextBox ID="degreeTB" runat="server" Text=""></asp:TextBox> </td>
    </tr>
    <tr >
    <td>Specialization</td>
    <td><asp:TextBox ID="specialityTB" runat="server" Text=""></asp:TextBox> </td>
    </tr>
    <tr align="center">
    <td colspan="2"><asp:Button ID="registerBTN" runat="server" Text="Save" 
            onclick="registerBTN_Click" /></td>
    </tr>
    </table>
    </ContentTemplate>
    </asp:UpdatePanel>
    
    <asp:UpdatePanel ID="UpdatePanel2" runat="server" Visible="false">
    <ContentTemplate>
    <u><b>Database</b></u><br /><br />
    <asp:Table ID="Table1" runat="server" Width="500px" GridLines="Both"></asp:Table>
    <br />
    <asp:Button ID="showBTN" runat="server" Text="Show" onclick="showBTN_Click" />
    </ContentTemplate>
    </asp:UpdatePanel>
    
    </td>
    </tr>
    <tr align="center">
    <td colspan="2">
    
    <asp:Button ID="updateBTN" runat="server" Text="Update" onclick="updateBTN_Click" /> &nbsp;&nbsp;&nbsp;
    <asp:Button ID="showdataBTN" runat="server" Text="Showdata" 
            onclick="showdataBTN_Click" /> 
    
    </td>
    </tr>
    </table>
    </div>
    </form>
</body>
</html>
