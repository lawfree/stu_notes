package cn.lowfree.servlet;

import javax.servlet.*;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "MyServlet",urlPatterns = {"/my"},
            initParams = {
                @WebInitParam(name = "admin" , value = "lowfree"),
                @WebInitParam(name = "email", value =  "745363151@qq.com")
            }
)

public class MyServlet implements Servlet {
    private  transient  ServletConfig servletConfig;

    @Override
    public void init(ServletConfig servletConfig) throws ServletException {
        System.out.println("servlet has been init ==========================================================");
        this.servletConfig = servletConfig;
    }

    @Override
    public ServletConfig getServletConfig() {
        return servletConfig;
    }

    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {
        String servletName = servletConfig.getServletName();

        String email = servletConfig.getInitParameter("email");     //通过 servletConfig 获得 初始化参数key的value

        ServletContext  servletContext =  servletConfig.getServletContext();    // 通过 servletConfig 获得 ServletContext


        servletResponse.setContentType("text/html");
        PrintWriter writer = servletResponse.getWriter();
        writer.print("<html> <head> first </head>" + "<body>  hello from"+
                servletName  + " <br>" +
                servletRequest.getProtocol() + "<br>" +
                servletConfig.toString()  + "<br>" +
                servletConfig.getInitParameterNames().nextElement() + " = " + getServletConfig().getInitParameter("admin") + "<br>" +
                //servletConfig.+ "<br>" +
                "email = " + email +


                "</body></html>" );
    }

    @Override
    public String getServletInfo() {
        return "my first servlet";
    }

    @Override
    public void destroy() {
        System.out.println("servlet has been destroy ==========================================================");
    }
}
