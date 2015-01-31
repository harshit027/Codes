<%@ Page Language="C#" AutoEventWireup="true" MasterPageFile="~/MasterPage.master" CodeFile="DataListPage.aspx.cs" Inherits="DataListPage" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div>
    <table  align="center" border="1" cellpadding="4" cellspacing="0">
    <tr align="center"><td><u><b>DataList</b></u></td></tr>
    <tr >
    <td><asp:DataList ID="DataList1" runat="server" BackColor="White" 
            BorderColor="#3366CC" BorderStyle="None" BorderWidth="1px" CellPadding="4" 
            DataKeyField="deptno" DataSourceID="SqlDataSource1" GridLines="Both" 
            RepeatColumns="3">
        <FooterStyle BackColor="#99CCCC" ForeColor="#003399" />
        <ItemStyle BackColor="White" ForeColor="#003399" />
        <SelectedItemStyle BackColor="#009999" Font-Bold="True" ForeColor="#CCFF99" />
        <HeaderStyle BackColor="#003399" Font-Bold="True" ForeColor="#CCCCFF" />
        <ItemTemplate>
            deptno:
            <asp:Label ID="deptnoLabel" runat="server" Text='<%# Eval("deptno") %>' />
            <br />
            deptname:
            <asp:Label ID="deptnameLabel" runat="server" Text='<%# Eval("deptname") %>' />
            <br />
            deptlocation:
            <asp:Label ID="deptlocationLabel" runat="server" 
                Text='<%# Eval("deptlocation") %>' />
            <br />
            <br />
        </ItemTemplate>
    </asp:DataList></td>
    </tr>
    </table>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
                ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
                SelectCommand="SELECT * FROM [department]"></asp:SqlDataSource>
    </div>
    
</asp:Content>