<%
//session.removeAttribute("validity");
session.invalidate();
response.sendRedirect("login.jsp");
%>