import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Modif extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        HttpSession session = req.getSession(false);
        if (session != null && session.getAttribute("username") != null) {
            req.setCharacterEncoding("UTF-8");
            String deptno = req.getParameter("deptno");
            int no = Integer.parseInt(deptno);
            String name_ = req.getParameter("name");
            String dept = req.getParameter("dept");
            Connection con = null;
            PreparedStatement ps = null;
            int count = 0;
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                String url = "jdbc:mysql://localhost:3306/db02";
                String username = "root";
                String password = "zmy";
                con = DriverManager.getConnection(url, username, password);
                String sql = "update employee set deptname=?,`name`=? where deptno=?";
                ps = con.prepareStatement(sql);
                ps.setString(1, dept);
                ps.setString(2, name_);
                ps.setString(3, deptno);
                count = ps.executeUpdate();
            } catch (ClassNotFoundException | SQLException e) {
                e.printStackTrace();
            } finally {
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
            if (count == 1) {
                req.getRequestDispatcher("/list").forward(req, resp);
            } else {
                req.getRequestDispatcher("/erro.html").forward(req, resp);
            }
        }else{
            resp.sendRedirect("/oa");
        }
    }
}
