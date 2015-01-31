<?php
$buffer=$_POST[data];
$filename=$_POST[filename];
$fp=fopen($filename,a) or die("Couldn't open the file");
if(fwrite($fp,$buffer))
print("Data written successfully !");
fclose($fp);
?>