<html>
<head><title>My First PHP</title>
</head>
<body>
<?php
$testvar=5;
print ("testvar : $testvar , ");
print (gettype($testvar));
print ("<br>");
$testvar="Harshit";
print ("testvar : $testvar , ");
print (gettype($testvar));
print ("<br>");
$testvar=5.0;
print ("testvar : $testvar , ");
print (gettype($testvar));
print ("<br>");
$testvar=True;
print ("testvar : $testvar , ");
print (gettype($testvar));
print ("<br>");
?>

</body>
</html>