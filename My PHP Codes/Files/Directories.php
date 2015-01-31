<html>
<head>
</head>
<body>
<?php
$dirname="MyDirectory";
//if(mkdir("../$dirname"))
//print("$dirname created");
//if(rmdir("../$dirname"))
//print("$dirname removed");
$dh = opendir( "../$dirname" );
while ( gettype( $file = readdir( $dh )) != boolean )
{
if ( is_dir( "$dirname/$file" ) )
print "(D)";
print "$file<br>";
}
closedir( $dh );
?>
</body>
</html>