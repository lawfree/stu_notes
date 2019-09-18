package cn.lowfree.servlet;

import cn.lowfree.entity.ShoppingItem;
import cn.lowfree.entity.cn.lowfree.entity.Product;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.NumberFormat;
import java.util.*;

@WebServlet (name = "ShoppingCartServlet" , urlPatterns =
        {"/products", "/viewProductDetails" , "/addToCart" , "/viewCart"   }
)
public class ShoppingCartServlet extends HttpServlet {
    private  static  final  String CART_ATTRIBUTE = "cart";

    private List<Product> products = new ArrayList<Product>();
    private NumberFormat currencyFormat = NumberFormat.getCurrencyInstance(Locale.US);

    @Override
    public void init() throws ServletException {
        products.add(new Product(1,"HDTV", "Low-cost from renowned TV" , 159.85F));
        products.add(new Product(2,"BluRay Player", "High quality style" , 99.95F));
        products.add(new Product(3,"BluRay System", "speaker hifi system iPod player" , 129.95F));
        products.add(new Product(4,"IPod Player", "can play multiple formats" , 39.95F));
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String uri = req.getRequestURI();
        if (uri.endsWith("/products")){
            sendProductList(resp);
        }else if (uri.endsWith("/viewProductDetails")){
            sendProductDetails(req ,resp);
        }else if (uri.endsWith("/viewCart")){
            showCart(req, resp);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //add to cart
        int productId = 0;
        int quantity = 0;
        try {
            productId = Integer.parseInt(
                    req.getParameter("id")
            );
            quantity = Integer.parseInt(
                    req.getParameter("quantity")
            );
        }catch (NumberFormatException e){
        }

        Product product = getProduct(productId);
        if(product != null && quantity > 0){
            ShoppingItem shoppingItem = new ShoppingItem(product, quantity);
            HttpSession session = req.getSession();
            List<ShoppingItem> cart = (List<ShoppingItem>) session.getAttribute(CART_ATTRIBUTE);
            if (cart == null){
                cart = new ArrayList<ShoppingItem>();
                session.setAttribute(CART_ATTRIBUTE , cart);
            }
            cart.add(shoppingItem);
        }
        sendProductList(resp);
    }

    private void sendProductList(HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html");

        resp.getWriter().print(
                "<html> <head> " +
                        "<title> Products </title>"+
                        " </head>" +
                        " <body>  <ul>"
        );
        for (Product product : products){
            resp.getWriter().print(
                    "<li>"+ product.getName() + "(" + currencyFormat.format(product.getPrice()) + ") (" + "<a href = 'viewProductDetails?id="  + product.getId() + "  '> Details </a> )"
            );
        }
        resp.getWriter().print(
                "</ul>" +
                        "<a href = 'viewCart'> View Cart</a> " +
                        "</body> </html>"
        );
    }
    private  Product getProduct(int productId){
        for (Product product : products){
            if(product.getId() == productId)
              return product;
        }
        return  null;
    }

    private void sendProductDetails(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html");
        int productId = 0;
        try {
            productId = Integer.parseInt(req.getParameter("id"));
        }catch (NumberFormatException e){

        }
        Product product = getProduct(productId);

        if (product != null){
            resp.getWriter().print(
                    "<html>" +
                            "<head><title>  Product Details  </title></head>" +
                            "<body>" +
                            "<h1> Edit Customer </h1><br>" +
                            "<hr/>" +
                            "<form name = 'form_1' action='addToCart'  method = 'post'>"  +

                            "<input type= 'hidden' name ='id' value='" + productId + "' />" +
                            "<table>" +
                            "<tr>" +
                                "<td>" + "Name:" +" <input type='text' name ='name'   value = '" + product.getName() +  "' />  </td>" +
                                "<td>" + "Description:" +" <input type='text' name ='description'   value = '" + product.getDescription()  +  "' />  </td>" +
                                "<td>" + "Quantity:" +" <input type='text' name ='quantity'   />  </td>" +

                            "</tr>"+
                                "<input type ='submit'  name ='submit'  value = 'update' />" +
                            "<tr>" +
                                "<hr/><a href= 'customer'>Product List </a>" +
                            "</tr>" +
                            "</table>" +


                            "</body>" +
                            "</html>  "
            );
        }else {
            resp.getWriter().print("No Product found");

        }
    }

    private void showCart(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        resp.setContentType("text/html");
        PrintWriter writer = resp.getWriter();

        writer.print(
                "<html>" +
                        "<head><title>  Shopping Cart  </title></head>" +
                        "<body>" +
                        "<h1> Shopping Cart </h1><br>" +
                        "<a href= 'products'>  Products List </a>"
        );

        HttpSession session = req.getSession();
        List<ShoppingItem> cart = (List<ShoppingItem>) session.getAttribute(CART_ATTRIBUTE);

        if (cart != null){
            writer.print(
                    "<table>" +
                            "<tr>" +
                            "<td style= 'width:150px'>" + "Quantity:" +"  </td>" +
                            "<td style= 'width:150px'>" + "Product:" +"  </td>"  +
                            "<td style= 'width:150px'>" + "price:" +"  </td>" +
                            "<td > Amount </td>" +
                            "</tr>"
            );
            double total = 0.0;
            for (ShoppingItem shoppingItem : cart){
                Product product = shoppingItem.getProduct();
                int quantity = shoppingItem.getQuantity();
                double subtotal = product.getPrice() * quantity;
                if (quantity != 0){
                    writer.print(
                            "<tr>" +
                            "<td style= 'width:150px'>"  + quantity  +"  </td>" +
                            "<td style= 'width:150px'>"  + product.getName()  +"  </td>"  +
                            "<td style= 'width:150px'>" +  currencyFormat.format(product.getPrice())  +"  </td>" +
                            "<td style= 'width:150px'>" +  currencyFormat.format(subtotal)  +"  </td>" +
                            "</tr>"
                    );
                    total += subtotal;
                }
            }
            writer.print(
                        "<tr>" +
                                "<td colspan='4'"    +" style ='text-align:right' > " +
                                "Total:" +
                                 currencyFormat.format(total) +
                                "</td>" +
                         "</tr>" +
                    "</table>" +
               "</body>" +
                "</html>  "
            );

        }
    }




}
