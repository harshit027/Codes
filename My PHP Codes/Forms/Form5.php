<?php

$url=$_GET[url];
if($url!="")
header("Location:$url");
else
print ("URL not entered !!!"); 
?>
<html>
<head><title>Redirecting the user</title>
</head>
<body>
<u><b><h3>Redirecting User Thorugh Location:url</h3></b></u><br><br>
<form method="get" action="<?php print $PHP_SELF?>">
<input type="text" name="url">
<input type="submit" value="Go to above URL"> 
</form>
</body>
</html>