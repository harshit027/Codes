<html>
<head><title>Associative Arrays</title>
</head>
<body>
<u><b><h3>Accessing data through $HTTP_GET_VARS</h3></b></u><br><br>
<form method="get" action="ProcessForm3.php">
<table border="1" cellspacing="0" cellpadding="4" align="center" style="background-color:#FF9933;" width="500">
<tr>
<th colspan="2">Student Details</th>
</tr>
<tr>
<td>Name</td>
<td><input type="text" name="name"></td>
</tr>
<tr>
<td>Branch</td>
<td><input type="text" name="branch"></td>
</tr>
<tr>
<td>College</td>
<td><input type="text" name="college"></td>
</tr>
<tr>
<td>Category</td>
<td>
<select name="category">
<option>SC</option>
<option>ST</option>
<option>OBC</option>
<option>GEN</option>
</select>
</td>
</tr>
<tr>
<td>Sex</td>
<td><input type="radio" name="sex" value="M">Male
<input type="radio" name="sex" value="F">Female</td>
</tr>
<tr>
<td style="vertical-align:top">Sports</td>
<td>
<input type="checkbox" name="sport" value="Cricket">Cricket<br>
<input type="checkbox" name="sport" value="Football">Football<br>
<input type="checkbox" name="sport" value="VolleyBall">VolleyBall<br>
<input type="checkbox" name="sport" value="BasketBall">BasketBall<br>
</td>
</tr>
<tr>
<td align="center" colspan="2"><input type="submit" value="Submit">
<input type="reset">
</td>
</tr>
</table>
</form>
</body>
</html>