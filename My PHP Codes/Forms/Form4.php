<html>
<head><title>PHP_SELF</title>
</head>
<body>
<u><b><h3>Self Accessing through $PHP_SELF</h3></b></u><br><br>
<form method="get" action="<?php print $PHP_SELF?>">
Enter any string : <input type="text" name="tb1">
<br>
<input type="submit" value="Click"> 

</form>
<?php
$string=$_GET[tb1];
print $string;
?>
</body>
</html>