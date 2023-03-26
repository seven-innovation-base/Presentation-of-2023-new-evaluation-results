import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

public class Change extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);
        if (session != null && session.getAttribute("username") != null) {
            resp.setContentType("text/html");
            PrintWriter out = resp.getWriter();
            String deptno = req.getParameter("deptno");
            Connection con = null;
            PreparedStatement ps = null;
            ResultSet rs = null;
            out.print("        <!DOCTYPE html>");
            out.print("<html lang='en'>");
            out.print("<head>");
            out.print("    <meta charset='UTF-8'>");
            out.print("    <title>Title</title>");
            out.print("</head>");
            out.print("<body>");
            out.print("<h1>修改</h1>");
            out.print("<form action='/oa/modif' method='post'>");
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                String url = "jdbc:mysql://localhost:3306/db02";
                String username = "root";
                String password = "zmy";
                con = DriverManager.getConnection(url, username, password);
                String sql = "select * from employee where deptno=?";
                ps = con.prepareStatement(sql);
                ps.setString(1, deptno);
                rs = ps.executeQuery();
                if (rs.next()) {
                    String deptnoname = rs.getString("deptname");
                    String name = rs.getString("name");
                    out.print("                普门编号:<input type='text' name='deptno' value='" + deptno + "'readonly><br>");
                    out.print("                姓名:<input type='text' name='name' value='" + name + "'><br>");
                    out.print("                部门:<input type='text' name='dept'value='" + deptnoname + "'><br>");
                }
            } catch (ClassNotFoundException | SQLException e) {
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
                if (con != null) {
                    try {
                        con.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
            }
            out.print("    <input type='submit' value='修改'>");
            out.print("</form>");
            out.print("</body>");
            out.print("</html>");
        }else{
            resp.sendRedirect("/oa");
        }
    }

}
