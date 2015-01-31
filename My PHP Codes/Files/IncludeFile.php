<html>
<head><title>Including a file in page</title>
</head>
<body>
<?php 
include("TestFile.txt");
echo("<br><hr>");
include("File1.php");
echo("<br><hr>");
$sum=include("File2.php");
print($sum);
?>
</body>
</html>