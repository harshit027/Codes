<html>
<head>
</head>
<body>
<h3>Reding file through fgetc()</h3>
<?php
$filename="MyFile.txt";
$fp=fopen($filename,r) or die("Couldn't open the file");
while ( ! feof( $fp ) )
{
$char = fgetc( $fp );
print "$char";
}
?>
</body>
</html>