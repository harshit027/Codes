<html>
<head>
<title>Table Of Ten</title>
</head>
<body>
<h3 align="center"><u>Table Of Ten</u></h3>
<table border="2"  cellpadding="6" cellspacing="0" align="center">
<tr>
<td style="text-align:center;">
<%
String s="<table algin='center' style='background-color:blue; color:white; width:300px; text-align:center;'>\n";
for(int i=1;i<=10;i++) 
{
  s+="<tr>\n";
  s+="\n<td>10</td><td>*</td><td>"+i+"</td>"+"<td>=</td><td>"+(10*i)+"</td>";
  s+="\n</tr>";
}
s+="\n</table>";
%>
<%= s %>
</td>
</tr>
</table>
</body>
</html>