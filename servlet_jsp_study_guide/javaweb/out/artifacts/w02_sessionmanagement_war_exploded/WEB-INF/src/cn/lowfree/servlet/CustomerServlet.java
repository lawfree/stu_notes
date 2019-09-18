package cn.lowfree.servlet;

import cn.lowfree.entity.Customer;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

@WebServlet(name = "CustomerServlet", urlPatterns = {
        "/customer", "/editCustomer" , "/updateCustomer"
})
public class CustomerServlet extends HttpServlet {

    private List<Customer>  customers = new ArrayList<Customer>();

    @Override
    public void init() throws ServletException {
        Customer customer1 = new Customer();
        customer1.setId(1);
        customer1.setName("Don.D");
        customer1.setCity("Miami");
        customers.add(customer1);

        Customer customer2 = new Customer();
        customer2.setId(2);
        customer2.setName("Mok.K");
        customer2.setCity("Orlando");
        customers.add(customer2);
    }




    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String uri = req.getRequestURI();
        if (uri.endsWith("/customer")){
            sendCustomerList(resp);
        }else if(uri.endsWith("/editCustomer")){
            sendEditCustomerForm(req,resp);
        }
    }

    private void sendEditCustomerForm(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html");
        PrintWriter writer = resp.getWriter();
        int customerId = 0;
        try{
            customerId = Integer.parseInt(req.getParameter("id"));

        }catch (NumberFormatException e){

        }
        Customer customer =getCustomer(customerId);
        if (customer != null){
            writer.print(
                "<html>" +
                    "<head><title>  Edit Customer  </title></head>" +
                    "<body>" +
                    "<h1> Edit Customer </h1><br>" +
                    "<hr/>" +
                    "<form name = 'form_1' action='updateCustomer'  method = 'post'>"  +

                    "<input type= 'hidden' name ='id' value='" + customerId + "' />" +
                    "<table>" +
                    "<td>" + "Name:" +" <input type='text' name ='name'   value = '" + customer.getName().replaceAll("'","&#39;") +  "' />  </td>" +
                    "<td>" + "City:" +" <input type='text' name ='city'   value = '" + customer.getCity() .replaceAll("'","&#39;")+  "' />  </td>" +
                    "</tr>" +
                    "<tr>" +
                    "<input type ='submit'  name ='submit'  value = 'update' />" +
                    "</tr>" +
                    "</table>" +
                        "<hr/><a href= 'customer'>Customer List </a>" +

                    "</body>" +
                    "</html>  "
            );
        }else{
            writer.print("No customer found");
        }

    }

    private Customer getCustomer(int customerId) {
        for(Customer customer : customers){
            if (customer.getId() == customerId){
              return  customer;
            }
        }
        return null;
    }

    private void sendCustomerList(HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html");

        resp.getWriter().print(
                "<html> <head> " +
                        "<title> Customer </title>"+
                        " </head>" +
                        " <body>  <ul>"
        );
        for (Customer customer : customers){
            resp.getWriter().print(
                    "<li>" + customer.getName()+
                            "(" + customer.getCity() + ") (" +
                            "<a href= 'editCustomer?id=" + customer.getId() + " '> Edit </a>)"
            );
        }

        resp.getWriter().print(
                     "</ul></body> </html>"
        );
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //update customer
        int customerId = 0;
        try {
            customerId = Integer.parseInt(req.getParameter("id"));
        }catch (NumberFormatException e){

        }
        Customer customer = getCustomer(customerId);
        if (customer != null){
            customer.setName(req.getParameter("name"));
            customer.setCity(req.getParameter("city"));
        }
        sendCustomerList(resp);
    }
}
