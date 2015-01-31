<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body link="0000ff">
    <form id="form1" runat="server">
    <div style="width: 100%; height: 550px;">
        <table width="100%" cellpadding="0" cellspacing="0" border="0" align="center">
            <tr>
            <th colspan="2" style="width:100%; height:30px; background-color:#6688ff">
            <h3><u><b>AXIS BANK WELCOMES YOU</b></u></h3>
            </th>
            </tr>
            <tr >
                <td colspan="2" style="width:100%; height:270px">
                    <img src="images/cover.JPG" alt="CoverImage" style="width:100%; height:270px;"/>
                </td>
            </tr>
            <tr>
                <td style="width:50%; height:250px; background-color:#6688ff;">
                    <marquee direction="up" scrolldelay="150" scrollamount="5" height="160px">
             
             <h4 style="text-align:center;"><u>Benefits and Clauses </u></h4>
             <ul >
<li>Minimum accessible balance is 2000</li>
<li>Get interest rates upto 15% in savings account</li>
<li>Core Banking Facilities</li>
<li>Optimal loan plans</li>
<li>New Home loan plans at 5 % interest</li>
<li>Our duty is customers satisfaction</li>
<li>24 hour helpline for any query</li>
<li>Special packages at festivals</li>
</ul></marquee>
                </td>
                <td style="width:50%; height:250px; background-color:#6688ff;">
                    <table align="center" cellpadding="10" cellspacing="0" border="1" width="100%" style="background-color:#dddddd; color:#0099ff;">
                        <tr>
                            <th colspan="2">
                                LOGIN
                            </th>
                        </tr>
                        <tr>
                            <td>
                                Username
                            </td>
                            <td>
                                <asp:TextBox ID="usernameTB" runat="server"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Password
                            </td>
                            <td>
                                <asp:TextBox ID="passwordTB" runat="server" TextMode="Password"></asp:TextBox>
                            </td>
                        </tr>
                        <tr>
                            <th colspan="2" style="text-align:center;">
                                <asp:Label ID="Label1" runat="server" Text="Label" Visible="false"></asp:Label>
                            </th>
                        </tr>
                        <tr>
                            <th colspan="2">
                                <asp:Button ID="loginBTN" runat="server" Text="Login" 
                                    onclick="loginBTN_Click" />
                            </th>
                        </tr>
                    </table>
                </td>
            </tr>
            
        </table>
    </div>
    <br />
    <div style="width: 100%; height: 30px; background-color: #dddddd; color: #0000ff;
            text-align: center;">
            All Rights Reserved &copy; <a href='http://www.axisbanks.com'>Axis Bank</a>
        </div>
    </form>
</body>
</html>
