<%@ page contentType="text/html; charset=iso-8859-1" language="java" import="java.sql.*" errorPage="" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<script type="text/javascript">
function ShowResult()
{
   form1.action='/OnlineTest/showresult';
   form1.submit();
}
</script>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>
<div style="text-align:center">
Thanks for giving test ! <br />Click on the button to see your result<br /><br />
<input type="button" value="Show Result" onclick="ShowResult()" />
</div>
</body>
</html>
