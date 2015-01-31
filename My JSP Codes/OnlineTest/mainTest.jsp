<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
<script type="text/javascript">
function SubmitAnswers()
{
  form1.action='/OnlineTest/submitanswers';
  form1.submit();
}

function NextQuestion()
{
  form1.action='/OnlineTest/maintest';
  form1.submit();
}

function EndTest()
{
   form1.action='/OnlineTest/endtest';
   form1.submit();
}
</script>
</head>

<body>


<br />
<div style="width:100%; height:50px; background-color:#dddddd; text-align:center">
<h2><i><u>Pace Bureau Computer Center</u></i></h2>
</div><br />
<div style="width:100%; height:20px; background-color:#dddddd; text-align:right">
Timer
</div>
<form name="form1" method="post">
<div style="width:100%; height:300px; background-color:#6688ff; color:white; font-family:'Times New Roman', Times, serif; font-size:24px">
<%

String temp[]=(session.getAttribute("questionParameters")+"").split("%");


out.print(temp[0]+" : ");
out.println(temp[1]);
%><br /><br />
1 : <input type="radio" name="option1" value='1' /><%out.print(temp[2]);%><br />
2 : <input type="radio" name="option2"  value='2'/><%out.print(temp[3]);%><br />
3 : <input type="radio" name="option3"  value='3'/><%out.print(temp[4]);%><br />
4 : <input type="radio" name="option4"  value='4'/><%out.print(temp[5]);%><br />
<br />
</div><br />
<center>
<input type="button" name="submitBtn" value="Submit" onclick="SubmitAnswers()"/>
<input type="button" name="nextBtn" value="Next" onclick="NextQuestion()"/>
<input type="button" name="exitBtn" value="Exit Sample Test" onclick="EndTest()" />
</center>
</form>
</body>
</html>
