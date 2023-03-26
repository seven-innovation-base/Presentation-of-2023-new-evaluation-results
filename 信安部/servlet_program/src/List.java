import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

public class List extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doGet(req, resp);
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);
        if (session != null && session.getAttribute("username") != null) {
            resp.setContentType("text/html;charset=GBK");
            PrintWriter out = resp.getWriter();
            Connection conn = null;
            PreparedStatement ps = null;
            ResultSet rs = null;
            out.print("<!DOCTYPE html>");
            out.print("<html lang='en'>");
            out.print("<head>");
            out.print("    <meta charset='UTF-8'>");
            out.print("<title>list</title>");
            out.print("    <script type='text/javascript'>");
            out.print("   function del(deptno){");
            out.print("        if(window.confirm('确认删除吗？'))");
            out.print("            window.location='/oa/delet?deptno='+deptno");
            out.print("    }");
            out.print("</script>");
            out.print("</head>");
            out.print("<body>");
            out.print("<h1>成员名单</h1>");
            out.print("<table align='center' border='1px' width='50%'>");
            out.print("<th>序号</th>");
            out.print("<th>部门编号</th>");
            out.print("<th>部门</th>");
            out.print("<th>姓名</th>");
            //Statement statement=null;
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                String url = "jdbc:mysql://localhost:3306/db02";
                String username = "root";
                String password = "zmy";
                conn = DriverManager.getConnection(url, username, password);
                String sql = "select * from employee";
                ps = conn.prepareStatement(sql);
                rs =ps.executeQuery();
                //statement=conn.createStatement();
                //rs=statement.executeQuery(sql);
                int id = 1;
                while (rs.next()) {
                    String deptno = rs.getString("deptno");
                    String deptnoname = rs.getString("deptname");
                    String name = rs.getString("name");
                    String path = req.getContextPath();
                    out.print("<tr>");
                    out.print("<td>" + (id++) + "</td>");
                    out.print("<td>" + deptno + "</td>");
                    out.print("<td>" + deptnoname + "</td>");
                    out.print("<td>" + name + "</td>");
                    out.print("<td><a href='javascript:void(0)'onclick=del(" + deptno + ")>删除</a> <a href='/oa/change?deptno=" + deptno + "'>修改</a> <a href=" + path + "/detial?deptno=" + deptno + ">详情</a> </td>");
                    out.print(" </tr>");
                }
                out.print("           </table>");
                out.print("<a href='/oa/add.html'>增加</a>");
                out.print("</body>");
                out.print("</html>");
            } catch (SQLException | ClassNotFoundException e) {
                e.printStackTrace();
            } finally {
                if (rs != null) {
                    try {
                        rs.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
                if (ps != null) {
                    try {
                        ps.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
                if (conn != null) {
                    try {
                        conn.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
            }
        }else{
            resp.sendRedirect("/oa");
        }
    }
}
