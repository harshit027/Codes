<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div style="text-align:center; font-family:Verdana; width:100%; font-size:x-large">
            
            <h2>Multiview Control</h2><br /><br />
            <asp:Button ID="Button1" runat="server" Text="View 1" BackColor="Red" OnClick="ShowView" />&nbsp;
            <asp:Button ID="Button2" runat="server" Text="View 2" BackColor="Blue" OnClick="ShowView" />&nbsp;
            <asp:Button ID="Button3" runat="server" Text="View 3" BackColor="Green" OnClick="ShowView" />&nbsp;
            <asp:Button ID="Button4" runat="server" Text="View 4" BackColor="Yellow" OnClick="ShowView" />&nbsp;
            <br /><br /><br />
            <div>
            <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="-1">
            <asp:View ID="View1" runat="server">
            <div style="background-color:Red; width:100%; height:100px; ">
            View1
            </div>
            </asp:View>
            <asp:View ID="View2" runat="server">
            <div style="background-color:Blue; width:100%; height:100px;">
            View2
            </div>
            </asp:View>
            <asp:View ID="View3" runat="server">
            <div style="background-color:Green; width:100%; height:100px;">
            View3
            </div>
            </asp:View>
            <asp:View ID="View4" runat="server">
            <div style="background-color:Yellow; width:100%; height:100px;">
            View4
            </div>
            </asp:View>
            </asp:MultiView>
            </div>   
    </div>
    </form>
</body>
</html>
