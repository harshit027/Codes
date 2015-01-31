<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Update.aspx.cs" Inherits="Update" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br /><br />

<table width="500px" border="1" cellpadding="5" cellspacing="0" align="center">
<tr>
<th colspan="2"><u>UPDATE RECORD</u></th>
</tr>
<tr>
<td>ID</td>
<td><asp:TextBox ID="TextBox1" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<td>Name</td>
<td><asp:TextBox ID="TextBox2" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<td>College</td>
<td><asp:TextBox ID="TextBox3" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<td>Branch</td>
<td><asp:TextBox ID="TextBox4" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<td>Contact</td>
<td><asp:TextBox ID="TextBox5" runat="server" ></asp:TextBox></td>
</tr>
<tr>
<th colspan="2">
    <asp:Label ID="Label1" runat="server"  Visible="false"></asp:Label>
</th>
</tr>
<tr>
<th colspan="2">
<asp:Button ID="updateBtn" runat="server" Text="Update"  />&nbsp;&nbsp;
<asp:Button ID="cancelBtn" runat="server" Text="Cancel" 
        onclick="cancelBtn_Click"  />
</th>
</tr>
</table>
<asp:AccessDataSource ID="AccessDataSource1" runat="server" 
        DataFile="~/App_Data/studentDatabase.mdb" DataSourceMode="DataReader" 
        SelectCommand="SELECT * FROM [student]"></asp:AccessDataSource>
</asp:Content>

