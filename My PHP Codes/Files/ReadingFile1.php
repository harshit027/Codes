<html>
<head>
</head>
<body>
<h3>Reading file through fgets()</h3>
<?php
$filename="MyFile.txt";
$fp=fopen($filename,r) or die("Couldn't open $filename") ;
while ( ! feof( $fp ) )
{
$line = fgets( $fp, 1024 );
print "$line<br>";
}
?>
</body>
</html>
