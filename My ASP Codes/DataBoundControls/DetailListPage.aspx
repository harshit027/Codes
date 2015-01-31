<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="DetailListPage.aspx.cs" Inherits="DetailListPage" Title="Untitled Page" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <br /><br />
<table align="center" border="1" cellpadding="4" cellspacing="0" width="500px">
<tr align="center">
<td><u><b>Detail List</b></u></td>
</tr>
<tr align="center">
<td>
<asp:DetailsView ID="DetailsView1" runat="server" AllowPaging="True" 
        AutoGenerateRows="False" BackColor="#DEBA84" BorderColor="#DEBA84" 
        BorderStyle="None" BorderWidth="1px" CellPadding="3" DataKeyNames="empid" 
        DataSourceID="SqlDataSource1" CellSpacing="2">
    <FooterStyle BackColor="#F7DFB5" ForeColor="#8C4510" />
    <RowStyle BackColor="#FFF7E7" ForeColor="#8C4510" />
    <PagerStyle ForeColor="#8C4510" HorizontalAlign="Center" />
    <Fields>
        <asp:BoundField DataField="empid" HeaderText="empid" InsertVisible="False" 
            ReadOnly="True" SortExpression="empid" />
        <asp:BoundField DataField="empname" HeaderText="empname" 
            SortExpression="empname" />
        <asp:BoundField DataField="empqualification" HeaderText="empqualification" 
            SortExpression="empqualification" />
        <asp:BoundField DataField="empsalary" HeaderText="empsalary" 
            SortExpression="empsalary" />
        <asp:BoundField DataField="empdept" HeaderText="empdept" 
            SortExpression="empdept" />
        <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" 
            ShowInsertButton="True" />
    </Fields>
    <HeaderStyle BackColor="#A55129" Font-Bold="True" ForeColor="White" />
    <EditRowStyle BackColor="#738A9C" Font-Bold="True" ForeColor="White" />
    </asp:DetailsView>
</td>
</tr>
</table>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
    ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
    DeleteCommand="DELETE FROM [employee] WHERE [empid] = @empid" 
    InsertCommand="INSERT INTO [employee] ([empname], [empqualification], [empsalary], [empdept]) VALUES (@empname, @empqualification, @empsalary, @empdept)" 
    SelectCommand="SELECT * FROM [employee]" 
    UpdateCommand="UPDATE [employee] SET [empname] = @empname, [empqualification] = @empqualification, [empsalary] = @empsalary, [empdept] = @empdept WHERE [empid] = @empid">
        <DeleteParameters>
            <asp:Parameter Name="empid" Type="Int32" />
        </DeleteParameters>
        <UpdateParameters>
            <asp:Parameter Name="empname" Type="String" />
            <asp:Parameter Name="empqualification" Type="String" />
            <asp:Parameter Name="empsalary" Type="String" />
            <asp:Parameter Name="empdept" Type="Int32" />
            <asp:Parameter Name="empid" Type="Int32" />
        </UpdateParameters>
        <InsertParameters>
            <asp:Parameter Name="empname" Type="String" />
            <asp:Parameter Name="empqualification" Type="String" />
            <asp:Parameter Name="empsalary" Type="String" />
            <asp:Parameter Name="empdept" Type="Int32" />
        </InsertParameters>
</asp:SqlDataSource>
</asp:Content>


