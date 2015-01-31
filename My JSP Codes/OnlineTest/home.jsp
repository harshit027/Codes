<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<script type="text/javascript">
function fun1(arg)
{
   arg.style.backgroundColor='#dddddd';
   arg.style.color='black';
}

function fun2(arg)
{
   arg.style.backgroundColor='black';
   arg.style.color='#dddddd';
}

function LoginCheck()
{
   form1.action='/OnlineTest/logincheck';
   form1.submit();
}
</script>


<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body link="white" alink="white" vlink="white">
<form name="form1" action="loginCheck.jsp" method="post">
<div style="width: 100%; height: 550px;">
        <table width="100%" cellpadding="0" cellspacing="0" border="0" align="center">
            <tr>
            <th colspan="2" style="width:100%; height:30px; background-color:#dddddd">
            <h3><u><b>EXAMINATION CENTER</b></u></h3>
            </th>
            </tr>
			<tr align="left" style="background-color:#000000;">
			<td colspan="2">
			<a href='home.jsp' onmouseover="fun1(this)" onmouseout="fun2(this)" >Home</a> &nbsp;&nbsp;&nbsp;
			<a href='register.jsp' onmouseover="fun1(this)" onmouseout="fun2(this)">Registration</a>&nbsp;&nbsp;&nbsp;
			<a href="test.jsp" onmouseover="fun1(this)" onmouseout="fun2(this)">Exam</a> &nbsp;&nbsp;&nbsp;
			
			</td>
			</tr>
            <tr >
                <td colspan="2" style="width:100%; height:270px">
                    <img src="site_images/cover.jpg" alt="CoverImage" style="width:100%; height:270px;"/>
                </td>
            </tr>
            <tr>
                <td align="center" style="width:50%; height:250px; background-color:#cccccc; font-family:'Times New Roman', Times, serif;" >
                    <h1><i> Pace Bureau<br />
					Computer Center</i></h1>
                </td>
                <td style="width:50%; height:250px; background-color:#cccccc;">
                    <fieldset>
					<legend>Login</legend>
					<table align="center" cellpadding="10" cellspacing="0" border="0" width="100%" style="background-color:#cccccc; color:#000000;">
                        
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
                                <input type="button" value="Login" onclick="LoginCheck()" />
                            </th>
                        </tr>
                    </table>
					</fieldset>
                </td>
            </tr>
            
        </table>
    </div>
    <br />
    <div style="width: 100%; height: 30px; background-color: #000000; color: #ffffff;
            text-align: center;">
            All Rights Reserved with &copy; <a href='http://www.pacejbp.com'>Pace Bureau</a>
        </div>
		</form>
</body>
</html>
