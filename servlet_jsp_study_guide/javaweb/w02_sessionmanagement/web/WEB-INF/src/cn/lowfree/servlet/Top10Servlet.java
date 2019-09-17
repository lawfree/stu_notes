package cn.lowfree.servlet;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "Top10Servlet" , urlPatterns = {"/top10"})
public class Top10Servlet extends HttpServlet {

    private List<String> londonAttractions;
    private List<String> parisAttractions;

    @Override
    public void init() throws ServletException {
        londonAttractions = new ArrayList<String>(10);
        for(int i = 0 ; i < 10 ; i ++)
            londonAttractions.add("London attraction" + String.valueOf(i));

        parisAttractions = new ArrayList<String>(10);
        for(int i = 0 ; i < 10 ; i ++)
            parisAttractions.add("Paris attraction" + String.valueOf(i));
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String city = req.getParameter("city");
        if (city != null &&
                (  city.equals("london") || city.equals("paris"))  ){
            //show attraction
            showAttractions(req, resp ,city);
        }else{
            showMainPage(req , resp);
        }
    }

    private  void showMainPage(HttpServletRequest request , HttpServletResponse response) throws IOException {

        response.setContentType("text/html");

        response.getWriter().print(
                "<html> <head> " +
                            "<title> Top10 attractions </title>"+
                        " </head>" +
                        " <body> " +
                        "Please select a city :" +

                        "<br/> <a  href = '?city=london'> london </a>" +
                        "<br/><a href = '?city=paris'> Paris</a>"+

                        "</body> </html>"
        );
    }
    private  void showAttractions (HttpServletRequest request, HttpServletResponse response ,String city ) throws IOException {

        int page = 1;
        String pageParameter = request.getParameter("page");
        if (pageParameter != null)  {
            try {
                page = Integer.parseInt(pageParameter);
            }catch (NumberFormatException e){
                //do nothing and retain default value for page
            }
            if(page > 2){
                page = 1;
            }
        }
        List<String> attractions = null;
        if (city.equals("london")){
            attractions = londonAttractions;
        }else{
            attractions = parisAttractions;
        }

        response.setContentType("text/html");
        response.getWriter().print(
                "<html> <head> " +
                            "<title> Top10 attractions </title>"+
                        " </head>" +
                        " <body> "  +
                        "<br/> <a  href = 'top10'> Select City </a>" +
                        "<br/>Page" + page + "<hr/>"
        );
        int start = page * 5 -5;
        for (int i = start ; i < start + 5 ; i++) {
            response.getWriter().print(
                    attractions.get(i) + "<br/>"
            );
        };
            response.getWriter().print("" +
                    "<hr style = 'color:blue'/>" +

                    "<a href='?city=" + city + "&page=1'> Page 1 </a> " +
                    "&nbsp;" +
                    " <a href='?city=" + city + "&page=2'> Page 2 </a> " +
                    "");


        response.getWriter().print(    "</body> </html>"  );

    }

}
