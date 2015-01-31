<%@ Page Language="C#" AutoEventWireup="true" MasterPageFile="~/MasterPage.master" CodeFile="GridViewPage.aspx.cs" Inherits="GridViewPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div>
    <table border="1" cellspacing="0" cellpadding="4" align="center">
    <tr align="center">
    <td>
    <u><b>DropDownList and GridView</b></u>
    </td>
    </tr>
    <tr align="center">
    <td>
    <asp:DropDownList ID="DropDownList1" runat="server" AutoPostBack="True" 
            AppendDataBoundItems="True" DataSourceID="SqlDataSource1" 
            DataTextField="deptname" DataValueField="deptno" 
            onselectedindexchanged="DropDownList1_SelectedIndexChanged">
    <asp:ListItem Text="Select"></asp:ListItem>
    </asp:DropDownList> 
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT [deptno], [deptname] FROM [department]">
        </asp:SqlDataSource>
    </td>
    </tr>
    <tr>
    <td>
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            BackColor="White" BorderColor="#CC9966" BorderStyle="None" BorderWidth="1px" 
            CellPadding="4" DataKeyNames="empid" DataSourceID="SqlDataSource2">
        <FooterStyle BackColor="#FFFFCC" ForeColor="#330099" />
        <RowStyle BackColor="White" ForeColor="#330099" />
        <Columns>
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
        </Columns>
        <PagerStyle BackColor="#FFFFCC" ForeColor="#330099" HorizontalAlign="Center" />
        <SelectedRowStyle BackColor="#FFCC66" Font-Bold="True" ForeColor="#663399" />
        <HeaderStyle BackColor="#990000" Font-Bold="True" ForeColor="#FFFFCC" />
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource2" runat="server" 
            ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
            SelectCommand="SELECT * FROM [employee]"></asp:SqlDataSource>
    </td>
    </tr>
    </table>
    </div>
</asp:Content>    
