<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="FormViewPage.aspx.cs" Inherits="FormViewPage" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <table border="1" align="center" cellpadding="4" cellspacing="0" width="400px">
<tr align="center"><td><u><b>Form View</b></u></td></tr>
<tr align="center">
<td>
<asp:FormView ID="FormView" runat="server" AllowPaging="True" CellPadding="4" 
        DataKeyNames="empid" DataSourceID="SqlDataSource1" ForeColor="#333333" Width="400px">
    <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
    <RowStyle BackColor="#E3EAEB" />
    <EditItemTemplate>
        empid:
        <asp:Label ID="empidLabel1" runat="server" Text='<%# Eval("empid") %>' />
        <br />
        empname:
        <asp:TextBox ID="empnameTextBox" runat="server" Text='<%# Bind("empname") %>' />
        <br />
        empqualification:
        <asp:TextBox ID="empqualificationTextBox" runat="server" 
            Text='<%# Bind("empqualification") %>' />
        <br />
        empsalary:
        <asp:TextBox ID="empsalaryTextBox" runat="server" 
            Text='<%# Bind("empsalary") %>' />
        <br />
        empdept:
        <asp:TextBox ID="empdeptTextBox" runat="server" Text='<%# Bind("empdept") %>' />
        <br />
        <asp:LinkButton ID="UpdateButton" runat="server" CausesValidation="True" 
            CommandName="Update" Text="Update" />
        &nbsp;<asp:LinkButton ID="UpdateCancelButton" runat="server" 
            CausesValidation="False" CommandName="Cancel" Text="Cancel" />
    </EditItemTemplate>
    <InsertItemTemplate>
        empname:
        <asp:TextBox ID="empnameTextBox" runat="server" Text='<%# Bind("empname") %>' />
        <br />
        empqualification:
        <asp:TextBox ID="empqualificationTextBox" runat="server" 
            Text='<%# Bind("empqualification") %>' />
        <br />
        empsalary:
        <asp:TextBox ID="empsalaryTextBox" runat="server" 
            Text='<%# Bind("empsalary") %>' />
        <br />
        empdept:
        <asp:TextBox ID="empdeptTextBox" runat="server" Text='<%# Bind("empdept") %>' />
        <br />
        <asp:LinkButton ID="InsertButton" runat="server" CausesValidation="True" 
            CommandName="Insert" Text="Insert" />
        &nbsp;<asp:LinkButton ID="InsertCancelButton" runat="server" 
            CausesValidation="False" CommandName="Cancel" Text="Cancel" />
    </InsertItemTemplate>
    <ItemTemplate>
        empid:
        <asp:Label ID="empidLabel" runat="server" Text='<%# Eval("empid") %>' />
        <br />
        empname:
        <asp:Label ID="empnameLabel" runat="server" Text='<%# Bind("empname") %>' />
        <br />
        empqualification:
        <asp:Label ID="empqualificationLabel" runat="server" 
            Text='<%# Bind("empqualification") %>' />
        <br />
        empsalary:
        <asp:Label ID="empsalaryLabel" runat="server" Text='<%# Bind("empsalary") %>' />
        <br />
        empdept:
        <asp:Label ID="empdeptLabel" runat="server" Text='<%# Bind("empdept") %>' />
        <br />
    </ItemTemplate>
    <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
    <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
    <EditRowStyle BackColor="#7C6F57" />
    </asp:FormView>
</td>
</tr>
</table>
<asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [employee]"></asp:SqlDataSource>
</asp:Content>

