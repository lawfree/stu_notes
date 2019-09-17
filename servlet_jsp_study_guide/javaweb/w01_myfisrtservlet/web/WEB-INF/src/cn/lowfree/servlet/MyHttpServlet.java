package cn.lowfree.servlet;

import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet (name = "MyHttpServlet" ,  urlPatterns =  {"/myhttp" })
public class MyHttpServlet extends HttpServlet {

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {


        resp.setContentType("text/html");
        resp.getWriter().print(
                "<html>  <head>  </head>" +
                       " <body> " +
                        "req.getContextPath() = "  + req.getContextPath() +      //   /w01
                        "<hr>" + " req.getRequestURI() " + req.getRequestURI() + //  w01/myhttp
                        "</body> </html>"
        );
    }

    @Override
    public void service(ServletRequest req, ServletResponse res) throws ServletException, IOException {
        HttpServletRequest request ;
        HttpServletResponse response;

        request = (HttpServletRequest) req;
        response = (HttpServletResponse) res;

        //service(request ,response);
        doPost(request , response);
    }
}


/**
 原始的service方法将请求和响应对象进行向下转换, 分别从Servlet容器转换成HttpServletRequest 和 HttpServletResponse, 并调用新的service方法

 向下转型总是会成功, 因为在调用一个Servlet 的 service 方法是, Servlet 容器总是会预计使用 HTTP , 所以传递一个 Http...Request

 之后, HttpServlet中新的service 方法会查看用来发送请求(通常用 request.getMethod)的HTTP方法, 并调用以下某个方法(doGet , doPost , doHead ,doPut, doTrace , doOption和 doDelete)
 这7个方法各自表示一个HTTP方法, 因此通常不需要再覆盖service方法,而是覆盖doGet和doPost

 总之,HttpServlet中有两个特性是GenericServlet所没有的:
    不覆盖service方法,而是覆盖 doGet ,doPost. 有时还有其他
    将用HttpServletRequest 和 HttpServletResponse 代替 ServletRequest...
 */