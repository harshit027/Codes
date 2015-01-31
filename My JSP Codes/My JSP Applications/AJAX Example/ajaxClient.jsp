<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>

<script type="text/javascript">
var xhr;

function AsynchronousCall()
{
if(window.XMLHttpRequest)
xhr=new window.XMLHttpRequest()
else
xhr=new window.ActiveXObject("Microsoft.XMLHTTP");
if(xhr) 
    {
	    var url="ajaxServer.jsp?nm="+document.form1.tb1.value;
		xhr.open("GET",url,true);
		xhr.onreadystatechange = recieverFucntion;
		xhr.send(null);
	}     
}

function recieverFucntion()
{
 if(xhr.readyState==4 && xhr.status==200)
   {
       var obj = document.getElementById("div1");
		obj.innerHTML = "<b>You entered : "+xhr.responseText+"</b>";
   }
}
</script>
</head>

<body>
<form name="form1" >
<input type="text" id='tb1' name="tb1" />
<input type="button" name="btn1" value="Asynchronous Call" onclick="AsynchronousCall()" />
<br /><br />

<div style="width:100%; height:20px; background-color:#dddddd; text-align:center;" id="div1">
</div>
</form>
</body>
</html>
