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

function ValidateForm() 
	{
				
	if(document.form1.txtname.value=="") {
	alert("Invalid Name");
	form1.txtname.focus();
	return;
	}
	if(document.form1.txtpassword.value=="") {
	alert("Invalid Password");
	form1.txtpassword.focus();
	return;
	}
	if(document.form1.txtdob.value=="") {
	alert("Invalid Date Of Birth");
	form1.txtdob.focus();
	return;
	}
	if(document.form1.txtaddress.value=="") {
	alert("Invalid Address");
	form1.txtaddress.focus();
	return;
	}
	if(document.form1.txtemail.value=="") {
	alert("Invalid Email Address");
	form1.txtnemail.focus();
	return;
	}
	if(document.form1.txtphone.value=="") {
	alert("Invalid Phone number");
	form1.txtphone.focus();
	return;
	}
	
	form1.action='/OnlineTest/registerstudent';
	form1.submit();
	}
</script>


	
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body link="white" alink="white" vlink="white">
<form name="form1" id="form1" method="post">
<div style="width: 100%; height: 70px;">
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
            <br />
        </table>
    </div>
	<br /><br />
	<div width="100%" style="height:400px; background-color:#dddddd;">
	<table width="100%" >
    <tr>
    <td>
        <img src="site_images/cover1.jpg" />
    </td>
    
        <td>
<fieldset>
	<legend>Registration</legend>
	<table align="center" width="500px" cellpadding="4" cellspacing="0">
	<tr>
	<td>Name</td>
	<td><input type="text" name="txtname" /></td>
	</tr>
	<tr>
	<td>Password</td>
	<td><input type="text" name="txtpassword" /></td>
	</tr>
	<tr>
	<td>Date Of Birth</td>
	<td><input type="text" name="txtdob" /></td>
	</tr>
	<tr>
	<td>Email</td>
	<td><input type="text" name="txtemail" /></td>
	</tr>
	<tr>
	<td>Address</td>
	<td><textarea rows="3" cols="30" name="txtaddress"></textarea></td>
	</tr>
	<tr>
	<td>Phone No</td>
	<td><input type="text" name="txtphone" /></td>
	</tr>
	<tr>
	<td colspan="2" align="center">
	<input type="button" name="b1" value="Register" onClick="ValidateForm()">
	<input type="reset" />
	</td>
	</tr>
	</table>
	</fieldset>
    </td>
    </tr>
    </table>
	
	
	</div>
	</form>
    <br />
    <div style="width: 100%; height: 30px; background-color: #000000; color: #ffffff;
            text-align: center;">
            All Rights Reserved with &copy; <a href='http://www.pacejbp.com'>Pace Bureau</a>
        </div>
		
</body>
</html>

