<%--
  Created by IntelliJ IDEA.
  User: ming
  Date: 2022/9/17
  Time: 17:17
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
  <title>Title</title>
</head>
<body>
<form action="<%=request.getContextPath()%>/login"method="post">
  username<input type="text" name="username"><br>
  password<input type="password" name="password"><br>
  <input type="submit" value="提交">
</form>

</body>
</html>
