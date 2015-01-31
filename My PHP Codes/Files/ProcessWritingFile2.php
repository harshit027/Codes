<?php
$buffer=$_POST[data];
$filename=$_POST[filename];
$fp=fopen($filename,w) or die("Couldn't open the file");
//flock($fp,1);
if(fputs($fp,$buffer))
print("Data written successfully !");
//flock($fp,3);
fclose($fp);
?>