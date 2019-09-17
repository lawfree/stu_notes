package cn.lowfree.servlet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Enumeration;

@WebServlet(name = "MyFormServlet" , urlPatterns = {"/myform"})
public class MyFormServlet extends HttpServlet {

    private static final String TITLE = "Order Form";

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        String name = req.getParameter("name");
        String age = req.getParameter("age");
        String email = req.getParameter("email");
        String address = req.getParameter("address");

        resp.setContentType("text/html");
        resp.getWriter().print(
                "<html>" +
                        "<head><title> " +  TITLE  + "</title></head>" +
                        "<body>" +
                        "<h1>"+ TITLE + "</h1><br>" +
                        "<hr/>" +
                        "<form name = 'form_1' method = 'post'>"  +
                        "<table>" +
                        "<tr>" +
                        "<td>" + "Name:" +  name  +" </td>" +
                        "<td>" + "Age:" + age  + "</td>" +
                        "</tr>" +
                        "<tr>" +
                        "<td>" + "Email:" +  email + " </td>" +
                        "<td>" + "Address:" + address  + "</td>" +
                        "</tr>" +
                        "<tr>" +
                        "<td>" + "UserName:" +" <input type='text' name ='username'/>  </td>" +
                        "<td>" + "Password:" +" <input type='password' name ='psw'/>  </td>" +
                        "</tr>" +
                        "<tr>" +
                        "<input type ='submit'  name ='submit'  value = 'Submit' />" +
                        "</tr>" +
                        "</table>" +
                        "</body>" +
                "</html>  "
         );
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        resp.setContentType("text/html");


        resp.getWriter().print(
                "<html>" +
                "<head><title> " +  TITLE  + "</title></head>" +
                "<body>" +
                    "<h1>"+ TITLE + "</h1><br>" +
                        "<hr/>" +
                    "<form name = 'form_1' method = 'post'>"  +
                    "<table>" +
                        "<tr>" +
                            "<td>" + "Name:" + "<input type='text' name = 'name' />  </td>" +
                            "<td>" + "Age:" + "<input  type='text' name = 'age' />  </td>" +
                        "</tr>" +
                        "<tr>" +
                            "<td>" + "Email:" + "<input type='text' name = 'email' />  </td>" +
                            "<td>" + "Address:" + "<input type='text' name = 'address' />  </td>" +
                        "</tr>" +
                        "<tr>" +
                            "<td>" + "UserName:" +" <input type='text' name ='username'/>  </td>" +
                            "<td>" + "Password:" +" <input type='password' name ='psw'/>  </td>" +
                        "</tr>" +
                        "<tr>" +
                             "<input type ='submit'  name ='submit'  value = 'Submit' />" +
                        "</tr>" +
                     "</table>" +
                "</body>" +
                "</html>"
        );






    }
}
