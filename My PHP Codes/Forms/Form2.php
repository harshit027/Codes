<html>
 <head>
 <title>Listing 9.2 A simple HTML form</title>
 </head>
<body>
<u><b><h3>A simple php form using post method</h3></b></u><br><br>
<form action="ProcessForm2.php" method="post">
<table border="1" cellspacing="0" cellpadding="4" align="center" style="background-color:#999999;" width="500">
<tr>
<th colspan="2">Student Details</th>
</tr>
<tr>
<td>Book Name</td>
<td><input type="text" name="bookname"></td>
</tr>
<tr>
<td>Author</td>
<td><input type="text" name="author"></td>
</tr>
<tr>
<td>Price</td>
<td><input type="text" name="price"></td>
</tr>
<tr>
<td align="center" colspan="2"><input type="submit" value="Submit">
<input type="reset"></form>
</body>
</html>