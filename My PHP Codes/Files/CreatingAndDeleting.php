<html>
<head>
</head>
<body>
<?php
if(touch("MyFile.txt"))
print("File created");

if(unlink("MyFile.txt"))
print("File Deleted");
?>
</body>
</html>
