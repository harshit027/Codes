<html>
<head>
</head>
<body>
<h3>Writing the file through fwrite()</h3><br>
<form action="<?php print $PHP_SELF?>" method="post">
Filename :<input type="text" name="filename" /><br />
Data : <textarea rows="4" cols="30" name="data"></textarea><br />
<input type="submit" value="Save To File"/>
</form>
<?php
$buffer=$_POST[data];
$filename=$_POST[filename];
$fp=fopen($filename,w) or die("Couldn't open the file");
if(fwrite($fp,$buffer))
print("Data written successfully !");
fclose($fp);
?>
</body>
</html>