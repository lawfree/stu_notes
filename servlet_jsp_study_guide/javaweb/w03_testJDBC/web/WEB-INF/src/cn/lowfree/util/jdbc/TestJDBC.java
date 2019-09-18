package cn.lowfree.util.jdbc;

import org.junit.jupiter.api.Test;

import java.sql.*;


public class TestJDBC {

    @Test
    void  test1(){
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");     //Class.forName是把这个类加载到JVM中，加载的时候，就会执行其中的静态初始化块，完成驱动的初始化的相关工作。
            System.out.println("registered success!");
            /*
                这里需要提供：数据库所处于的ip:127.0.0.1 (这里是本机，如果连接其他电脑上的数据库，请改变该ip)
                             数据库的端口号： 3306 （mysql专用端口号）
                             数据库名称 exam（根据你自己数据库中的名称填写）
                             编码方式 UTF-8
                             账号 root
                             密码 admin
             */
            Connection connection = DriverManager.getConnection("jdbc:mysql://localhost/myfirstdb_company?useSSL=FALSE&serverTimezone=UTC","root","124816");

            String sql1 = "insert into employee" +
                    " (employeeId, name,position,age,department,salary) values" +
                    " (null, 'Lily', 'secretary','21','market',50000);";

            String sql2 = "select * from employee";


            ResultSet resultSet =  connection.createStatement().executeQuery(sql2);
            while (resultSet.next()){
                for (int i = 1 ; i <= 6 ; i ++){
                    System.out.println(  resultSet.getString(i) + "\t");
                }
                System.out.println();
            }


        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
        }


    }

}
