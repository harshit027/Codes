<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>
<form name="form1" action="loginCheck.jsp" method="post">
<div style="width: 100%; height: 550px;">
        <table width="100%" cellpadding="0" cellspacing="0" border="0" align="center">
            <tr>
            <th colspan="2" style="width:100%; height:30px; background-color:#6688ff">
            <h3><u><b>BOOK MANAGEMENT SYSTEM</b></u></h3>
            </th>
            </tr>
            <tr >
                <td colspan="2" style="width:100%; height:270px">
                    <img src="site_images/cover.JPG" alt="CoverImage" style="width:100%; height:270px;"/>
                </td>
            </tr>
            <tr>
                <td style="width:50%; height:250px; background-color:#6688ff;">
                    <marquee direction="up" scrolldelay="150" scrollamount="5" height="160px">
             
             <h4 style="text-align:center;"><u>Benefits and Clauses </u></h4>
             <ul >
<li>Membership is not transferrable</li>
<li>Security Fee 400Rs</li>
<li>Monthly Fee 100Rs</li>
<li>Fine will be charged @ 1Re /day after due date</li>
<li>Books, if lost or damaged will be fined as per its price</li>
<li>Late Fee will be charged @ 5 Re /day</li>
</ul></marquee>
                </td>
                <td style="width:50%; height:250px; background-color:#6688ff;">
                    <table align="center" cellpadding="10" cellspacing="0" border="0" width="100%" style="background-color:#dddddd; color:black;">
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
                                <input type="text" name="txtusername" />
                            </td>
                        </tr>
                        <tr>
                            <td>
                                Password
                            </td>
                            <td>
                                <input type="password" name="txtpassword" />
                            </td>
                        </tr>
                        <tr>
                            <th colspan="2" style="text-align:center;">
                                <%
                                 String message=(String) session.getAttribute("message");
                                 if(message==null || message.equals(""))
                                 {
                                 }
                                 else
                                 out.print(message);
                                 %>
                            </th>
                        </tr>
                        <tr>
                            <th colspan="2">
                                <input type="submit" value="Login" />
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
            All Rights Reserved with &copy; <a href='http://www.pacejbp.com'>Pace Bureau</a>
        </div>
		</form>
</body>
</html>
