<html>
<head><title>Including a file in page</title>
</head>
<body>
<?php
$filename="File1.php";
print("Status of $filename<br>"); 
if(file_exists($filename))
print("File exists");
if(is_readable($filename))
print("$filename is readable");
if(is_writable($filename))
print("$filename is writable");
if ( is_executable( $filename ))
print("$filename is executable");
print("<br><hr>");

print("Size of $filename is ".filesize($filename)." Bytes<br><hr>");
print("Access time of $filename<br>");
print "$filename was accessed on ".date( "D d M Y g:i A", fileatime($filename) )."<br>";
print "$filename was modified on ".date( "D d M Y g:i A", filemtime($filename ) )."<br>";
print "$filename was changed on ".date( "D d M Y g:i A", filectime($filename) )."<br>";

?>
</body>
</html>