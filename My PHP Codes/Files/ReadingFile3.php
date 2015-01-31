<html>
<head>
</head>
<body>
<h3>Reading file through fread() and fseek()</h3>

<?php
$filename="MyFile.txt";
$fp=fopen($filename,r) or die("Couldn't open $filename") ;
fseek($fp,16);
while ( ! feof( $fp ) )
{
$chunk = fread( $fp, 8);
print "$chunk<br>";
}
?>
</body>
</html>

