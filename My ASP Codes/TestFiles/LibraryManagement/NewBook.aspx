﻿<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewBook.aspx.cs" Inherits="NewBook" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
<br /><br /><br />
<table width="500px" cellpadding="5" cellspacing="0" border="1" align="center">
<tr>
<th colspan="2"><b><u>NEW BOOK ENTRY</u></b></th>
</tr>
<tr align="left">
<td>Book Title</td>
<td><asp:TextBox ID="titleTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Book Author</td>
<td><asp:TextBox ID="authorTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Book Publisher</td>
<td><asp:TextBox ID="publisherTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Book Price</td>
<td><asp:TextBox ID="priceTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Book Edition</td>
<td><asp:TextBox ID="editionTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="left">
<td>Number of Copies</td>
<td><asp:TextBox ID="no_of_copiesTB" runat="server" Text=""></asp:TextBox></td>
</tr>
<tr align="center">
<th colspan="2">
    <asp:Label ID="Label1" runat="server" Text="Label" Visible="false"></asp:Label>
    </th>
</tr>
<tr>
<th colspan="2"><asp:Button ID="Button1" runat="server" Text="Save" 
        onclick="Button1_Click" />&nbsp;&nbsp;
<asp:Button ID="Button2" runat="server" Text="Reset" onclick="Button2_Click" /></th>
</tr>
</table>
</asp:Content>

