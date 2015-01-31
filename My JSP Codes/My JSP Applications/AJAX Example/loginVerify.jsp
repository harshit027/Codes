<%
String username=request.getParameter("un");
String password=request.getParameter("pwd");

if(username.equals("pace") && password.equals("bureau"))
out.print("valid");
else
out.print("invalid");
%>
