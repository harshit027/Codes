<%@ Page Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="ListViewPage.aspx.cs" Inherits="ListViewPage" Title="Untitled Page" %>


<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <table border="1" align="center" cellpadding="4" cellspacing="0" width="400px">
<tr><td><b><u>List View</u></b></td></tr>
<tr>
<td>
<asp:ListView ID="ListView1" runat="server" DataKeyNames="empid" 
        DataSourceID="SqlDataSource1">
    <AlternatingItemTemplate>
        <tr style="background-color: #FAFAD2;color: #284775;">
            <td>
                <asp:Label ID="empidLabel" runat="server" Text='<%# Eval("empid") %>' />
            </td>
            <td>
                <asp:Label ID="empnameLabel" runat="server" Text='<%# Eval("empname") %>' />
            </td>
            <td>
                <asp:Label ID="empqualificationLabel" runat="server" 
                    Text='<%# Eval("empqualification") %>' />
            </td>
            <td>
                <asp:Label ID="empsalaryLabel" runat="server" Text='<%# Eval("empsalary") %>' />
            </td>
            <td>
                <asp:Label ID="empdeptLabel" runat="server" Text='<%# Eval("empdept") %>' />
            </td>
        </tr>
    </AlternatingItemTemplate>
    <LayoutTemplate>
        <table runat="server">
            <tr runat="server">
                <td runat="server">
                    <table ID="itemPlaceholderContainer" runat="server" border="1" 
                        style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;font-family: Verdana, Arial, Helvetica, sans-serif;">
                        <tr runat="server" style="background-color: #FFFBD6;color: #333333;">
                            <th runat="server">
                                empid</th>
                            <th runat="server">
                                empname</th>
                            <th runat="server">
                                empqualification</th>
                            <th runat="server">
                                empsalary</th>
                            <th runat="server">
                                empdept</th>
                        </tr>
                        <tr ID="itemPlaceholder" runat="server">
                        </tr>
                    </table>
                </td>
            </tr>
            <tr runat="server">
                <td runat="server" 
                    style="text-align: center;background-color: #FFCC66;font-family: Verdana, Arial, Helvetica, sans-serif;color: #333333;">
                    <asp:DataPager ID="DataPager1" runat="server">
                        <Fields>
                            <asp:NextPreviousPagerField ButtonType="Button" ShowFirstPageButton="True" 
                                ShowLastPageButton="True" />
                        </Fields>
                    </asp:DataPager>
                </td>
            </tr>
        </table>
    </LayoutTemplate>
    <InsertItemTemplate>
        <tr style="">
            <td>
                <asp:Button ID="InsertButton" runat="server" CommandName="Insert" 
                    Text="Insert" />
                <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" 
                    Text="Clear" />
            </td>
            <td>
                &nbsp;</td>
            <td>
                <asp:TextBox ID="empnameTextBox" runat="server" Text='<%# Bind("empname") %>' />
            </td>
            <td>
                <asp:TextBox ID="empqualificationTextBox" runat="server" 
                    Text='<%# Bind("empqualification") %>' />
            </td>
            <td>
                <asp:TextBox ID="empsalaryTextBox" runat="server" 
                    Text='<%# Bind("empsalary") %>' />
            </td>
            <td>
                <asp:TextBox ID="empdeptTextBox" runat="server" Text='<%# Bind("empdept") %>' />
            </td>
        </tr>
    </InsertItemTemplate>
    <SelectedItemTemplate>
        <tr style="background-color: #FFCC66;font-weight: bold;color: #000080;">
            <td>
                <asp:Label ID="empidLabel" runat="server" Text='<%# Eval("empid") %>' />
            </td>
            <td>
                <asp:Label ID="empnameLabel" runat="server" Text='<%# Eval("empname") %>' />
            </td>
            <td>
                <asp:Label ID="empqualificationLabel" runat="server" 
                    Text='<%# Eval("empqualification") %>' />
            </td>
            <td>
                <asp:Label ID="empsalaryLabel" runat="server" Text='<%# Eval("empsalary") %>' />
            </td>
            <td>
                <asp:Label ID="empdeptLabel" runat="server" Text='<%# Eval("empdept") %>' />
            </td>
        </tr>
    </SelectedItemTemplate>
    <EmptyDataTemplate>
        <table runat="server" 
            style="background-color: #FFFFFF;border-collapse: collapse;border-color: #999999;border-style:none;border-width:1px;">
            <tr>
                <td>
                    No data was returned.</td>
            </tr>
        </table>
    </EmptyDataTemplate>
    <EditItemTemplate>
        <tr style="background-color: #FFCC66;color: #000080;">
            <td>
                <asp:Button ID="UpdateButton" runat="server" CommandName="Update" 
                    Text="Update" />
                <asp:Button ID="CancelButton" runat="server" CommandName="Cancel" 
                    Text="Cancel" />
            </td>
            <td>
                <asp:Label ID="empidLabel1" runat="server" Text='<%# Eval("empid") %>' />
            </td>
            <td>
                <asp:TextBox ID="empnameTextBox" runat="server" Text='<%# Bind("empname") %>' />
            </td>
            <td>
                <asp:TextBox ID="empqualificationTextBox" runat="server" 
                    Text='<%# Bind("empqualification") %>' />
            </td>
            <td>
                <asp:TextBox ID="empsalaryTextBox" runat="server" 
                    Text='<%# Bind("empsalary") %>' />
            </td>
            <td>
                <asp:TextBox ID="empdeptTextBox" runat="server" Text='<%# Bind("empdept") %>' />
            </td>
        </tr>
    </EditItemTemplate>
    <ItemTemplate>
        <tr style="background-color: #FFFBD6;color: #333333;">
            <td>
                <asp:Label ID="empidLabel" runat="server" Text='<%# Eval("empid") %>' />
            </td>
            <td>
                <asp:Label ID="empnameLabel" runat="server" Text='<%# Eval("empname") %>' />
            </td>
            <td>
                <asp:Label ID="empqualificationLabel" runat="server" 
                    Text='<%# Eval("empqualification") %>' />
            </td>
            <td>
                <asp:Label ID="empsalaryLabel" runat="server" Text='<%# Eval("empsalary") %>' />
            </td>
            <td>
                <asp:Label ID="empdeptLabel" runat="server" Text='<%# Eval("empdept") %>' />
            </td>
        </tr>
    </ItemTemplate>

</asp:ListView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
        ConnectionString="<%$ ConnectionStrings:ConnectionString %>" 
        SelectCommand="SELECT * FROM [employee]"></asp:SqlDataSource>
</td>
</tr>
</table>
</asp:Content>

