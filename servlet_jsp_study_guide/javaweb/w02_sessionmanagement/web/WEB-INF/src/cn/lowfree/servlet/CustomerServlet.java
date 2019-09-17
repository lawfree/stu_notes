package cn.lowfree.servlet;

import cn.lowfree.entity.Customer;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import java.util.*;

@WebServlet(name = "Customer")
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
}
