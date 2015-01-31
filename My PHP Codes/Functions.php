<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<title>Untitled Document</title>
</head>

<body>

<?php
function tableFinder($value)
{
print("<table border='1' cellpadding='2' cellspacing='0' align='center' width='400'>
<tr>
<th colspan='2'>Table of ".$value."</th>
</tr>");
for($counter=1;$counter<=10;$counter++)
{
$table=$counter*$value;
print ("<tr style='text-align:center;'><td>$value * $counter </td><td>".$table."</td></tr>");
}
print("</table>");
}

tableFinder(126);
?>
</body>
</html>
