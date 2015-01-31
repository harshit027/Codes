<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body bgcolor=Pink>
    <form id="form1" runat="server">
    <center>
    <div style="font-family:Verdana; color:Red; font-size:40px;">
    <u>BirthDay Mania</u>
    </div><br /><br />
    
    <div>
    <table >
    <tr>
    <td>
    <marquee width="200px" height="400px" direction="up">
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
    <asp:Label ID="Label1" runat="server" Text="" Visible=false Font-Names="Verdana" Font-Size="40" ForeColor="Red"></asp:Label><br /><br /> 
    <asp:Image ID="Image1" runat="server" ImageUrl="~/image.gif" />
    </marquee>
    </td>
    
    <th>
    <asp:Label ID="dayLabel" runat="server" Text="Day : "></asp:Label> 
    <asp:DropDownList ID="dayList" runat="server" Width="53px">
    <asp:ListItem Text="1"></asp:ListItem>
    <asp:ListItem Text="2"></asp:ListItem>
    <asp:ListItem Text="3"></asp:ListItem>
    <asp:ListItem Text="4"></asp:ListItem>
    <asp:ListItem Text="5"></asp:ListItem>
    <asp:ListItem Text="6"></asp:ListItem>
    <asp:ListItem Text="7"></asp:ListItem>
    <asp:ListItem Text="8"></asp:ListItem>
    <asp:ListItem Text="9"></asp:ListItem>
    <asp:ListItem Text="10"></asp:ListItem>
    <asp:ListItem Text="11"></asp:ListItem>
    <asp:ListItem Text="12"></asp:ListItem>
    <asp:ListItem Text="13"></asp:ListItem>
    <asp:ListItem Text="14"></asp:ListItem>
    <asp:ListItem Text="15"></asp:ListItem>
    <asp:ListItem Text="16"></asp:ListItem>
    <asp:ListItem Text="17"></asp:ListItem>
    <asp:ListItem Text="18"></asp:ListItem>
    <asp:ListItem Text="19"></asp:ListItem>
    <asp:ListItem Text="20"></asp:ListItem>
    <asp:ListItem Text="21"></asp:ListItem>
    <asp:ListItem Text="22"></asp:ListItem>
    <asp:ListItem Text="23"></asp:ListItem>
    <asp:ListItem Text="24"></asp:ListItem>
    <asp:ListItem Text="25"></asp:ListItem>
    <asp:ListItem Text="26"></asp:ListItem>
    <asp:ListItem Text="27"></asp:ListItem>
    <asp:ListItem Text="28"></asp:ListItem>
    <asp:ListItem Text="29"></asp:ListItem>
    <asp:ListItem Text="30"></asp:ListItem>
    <asp:ListItem Text="31"></asp:ListItem>
    </asp:DropDownList>
    <asp:Label ID="monthLabel" runat="server" Text="Month : "></asp:Label>
    <asp:DropDownList ID="monthList" runat="server" Width="53px">
    <asp:ListItem Text="Jan" Value=1></asp:ListItem>
    <asp:ListItem Text="Feb" Value=2></asp:ListItem>
    <asp:ListItem Text="Mar" Value=3></asp:ListItem>
    <asp:ListItem Text="Apr" Value=4></asp:ListItem>
    <asp:ListItem Text="May" Value=5></asp:ListItem>
    <asp:ListItem Text="Jun" Value=6></asp:ListItem>
    <asp:ListItem Text="Jul" Value=7></asp:ListItem>
    <asp:ListItem Text="Aug" Value=8></asp:ListItem>
    <asp:ListItem Text="Sep" Value=9></asp:ListItem>
    <asp:ListItem Text="Oct" Value=10></asp:ListItem>
    <asp:ListItem Text="Nov" Value=11></asp:ListItem>
    <asp:ListItem Text="Dec" Value=12></asp:ListItem>
    </asp:DropDownList><br /><br />
    <asp:Button ID="findDays" runat="server" Text="Find Days Left" OnClick="findDaysLeft" /><br /><br />
    <asp:Label ID="leftDays" runat="server" Text="" Visible="false" ForeColor="Red" Font-Names="Verdana" Font-Size="Large"></asp:Label>

    </th>
    <td>
    <marquee width="200px" height="400px" direction="up">
    &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp
    <asp:Label ID="Label2" runat="server" Text="" Visible=false Font-Names="Verdana" Font-Size=40 ForeColor="Red"></asp:Label><br /><br />
    <asp:Image ID="Image2" runat="server" ImageUrl="~/image.gif" /> 
    </marquee>
    </td>
    </tr>
    </table>
        </div>
    </center>
    </form>
</body>
</html>
