<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Grid View Control</title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="text-align: center">
        <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" 
            BackColor="White" BorderColor="#336666" BorderStyle="Double" BorderWidth="3px" 
            CellPadding="4" GridLines="Horizontal" AllowPaging="True" 
            onpageindexchanging="SetNewPage" PageSize="5" AllowSorting="True" 
            onsorting="ArrangeRows">
            <FooterStyle BackColor="White" ForeColor="#333333" />
            <RowStyle BackColor="White" ForeColor="#333333" />
            <Columns>
                <asp:BoundField DataField="empid" HeaderText="EMPLOYEE ID" />
                <asp:BoundField DataField="ename" HeaderText ="EMPLOYEE NAME" 
                    SortExpression="ename" />
                <asp:BoundField DataField="esalary" HeaderText="EMPLOYEE SALARY" />
                <asp:CheckBoxField DataField="issuspended" HeaderText="SUSPENDED ?" />
                <asp:TemplateField HeaderText="MY ISSUSPENDED?">
                    <ItemTemplate>
                        <asp:CheckBox ID="cbsuspened" runat="server" AutoPostBack="true" OnCheckedChanged="SetSuspended" />
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:ImageField DataImageUrlField="userphoto" HeaderText="USER PHOTO" ControlStyle-Width="100px" ControlStyle-Height="100px">
<ControlStyle Height="100px" Width="100px"></ControlStyle>
                </asp:ImageField>
            </Columns>
            <PagerStyle BackColor="#336666" ForeColor="White" HorizontalAlign="Center" />
            <SelectedRowStyle BackColor="#339966" Font-Bold="True" ForeColor="White" />
            <HeaderStyle BackColor="#336666" Font-Bold="True" ForeColor="White" />
        </asp:GridView>
    </div>
    </form>
</body>
</html>
