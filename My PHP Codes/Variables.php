<html>
<head><title>My First PHP</title>
</head>
<body>
<?php
$a=5;
print ("a : $a <br>");
$name="John";
print ("$name : name<br>");
$var1=25;
print("var1 : $var1<br>");
$var2=&$var1;
$var1=50;
print("var2 : $var1<br>");
?>

</body>
</html>