
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

function SampleTest()
{
    form1.action='/OnlineTest/sampletest';
	form1.submit();
}

function MainTest()
{
    form1.action='/OnlineTest/maintest';
    form1.submit();
}
</script>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>
<%
String authentication=(String) session.getAttribute("validity");
if(authentication!=null)
{
   if(authentication.equals("ValidUser"))
   {
     
   }
}
else
response.sendRedirect("home.jsp");

%>
<body link="white" alink="white" vlink="white">
<form name="form1" action="loginCheck.jsp" method="post">
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
			<a href="logout.jsp" onmouseover="fun1(this)" onmouseout="fun2(this)">Logout</a>
			</td>
			</tr>
          
        </table>
    </div>
    <br />
	
	<div style="width:100%; height:470px; background-color:#dddddd; font-size:16px; font-family:'Times New Roman', Times, serif"><br />
	<h2>&nbsp;&nbsp;<u><i>Instrcutions</i></u></h2><br />
	<ul>
	<li>There are 3 sections in the following paper.</li>
	<li>All questions carry equal weights.</li>
	<li>Every Question has 4 options.</li>
	<li>Select your answer, and push submit button.</li>
	<li>Use Next to go to the next question.</li>
	<li>Push End Test for exiting from exam. </li>
	<li>You can visit any question by clicking on the respective links.</li>
	<li>Push Main Exam for main exam.</li>
	<li>Push Sample Test for practice.</li>
	</ul>
	<br />
	<center>
	<input type="button" name="mainTestBtn" value="Main Exam" onclick="MainTest()" /> &nbsp;&nbsp;&nbsp;
	<input type="button" name="sampleTestBtn" value="Sample Test" onclick="SampleTest()"/>
	</center>
	</div>
    <div style="width: 100%; height: 30px; background-color: #000000; color: #ffffff;
            text-align: center;">
            All Rights Reserved with &copy; <a href='http://www.pacejbp.com'>Pace Bureau</a>
        </div>
		</form>
</body></html>
