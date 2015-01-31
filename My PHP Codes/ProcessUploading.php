<html>
<head>
<title>Process Uploaded File</title>
</head>
<body>
<?php

if(move_uploaded_file ($_FILES['uploadFile'] ['tmp_name'],"G:/Program Files/wamp/www/MyApplications/uploads/{$_FILES['uploadFile'] ['name']}"))
print("File Uploaded");
else
print("Error in uploading");

?>
</body>
</html>