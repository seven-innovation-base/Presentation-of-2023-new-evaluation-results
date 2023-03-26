import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

public class Detail extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();
        String deptno = req.getParameter("deptno");
        System.out.println(deptno);
        Connection con = null;
            PreparedStatement ps = null;
            Statement statement=null;
            ResultSet rs = null;
            out.print("           <!DOCTYPE html>");
            out.print("<html lang='en'>");
            out.print("<head>");
            out.print("   <meta charset='UTF-8'>");
            out.print("   <title>Title</title>");
            out.print("</head>");
            out.print("<body>");
            out.print("<h1>详情</h1>");
            try {
                Class.forName("com.mysql.cj.jdbc.Driver");
                String url="jdbc:mysql://localhost:3306/db02";
                String username="root";
                String password="zmy";
                con= DriverManager.getConnection(url,username,password);
                String sql="select * from employee where deptno=?";
                String sql01="select * from employee where deptno="+deptno;
//                ps=con.prepareStatement(sql);
//                ps.setString(1,deptno);
//                rs=ps.executeQuery();
                statement=con.createStatement();
                rs=statement.executeQuery(sql01);
                    if(rs.next()){
                    String t=rs.getString("deptno");
                    String deptnoname=rs.getString("deptname");
                    String name=rs.getString("name");
                    out.print(t+"<br>");
                    out.print(deptnoname+"<br>");
                    out.print(name+"<br>");
                    }
            } catch (ClassNotFoundException | SQLException e) {
                e.printStackTrace();
            }finally {
                if(rs!=null){
                    try {
                        rs.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
                if(ps!=null){
                    try {
                        ps.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
                if(con!=null){
                    try {
                        con.close();
                    } catch (SQLException e) {
                        e.printStackTrace();
                    }
                }
            }
        out.print("</body>");
        out.print("</html>");
    }

}
