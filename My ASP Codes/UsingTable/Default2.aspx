<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    protected void MyFunction(object sender, EventArgs e)
    {
        Response.Redirect("Default.aspx");
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Response.Write("<h1>RAJNEESH AGRAWAL</h1>");
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <asp:Button ID="Button1" runat="server" Text="Show Code Inline" 
            onclick="Button1_Click" />
        <asp:Button ID="btnGoToDefaultPage" runat="server" Text= "Go To First Page" OnClick="MyFunction" />
        <img alt="" src="header.png" style="width: 370px; height: 220px" /></div>
    </form>
</body>
</html>
