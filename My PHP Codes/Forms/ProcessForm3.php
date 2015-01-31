<html>
<head>
</head>
<body>
<?php
$params=(isset($HTTP_GET_VARS ))? $HTTP_POST_VARS : $HTTP_GET_VARS;
foreach($params as $key=>$value)
{
print "$key == $value<BR>\n";
//print "<b>$HTTP_GET_VARS[0]</br>";
}
?>

</body>
</html>
