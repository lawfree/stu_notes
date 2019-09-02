//import  java.time.*;

import com.sun.org.apache.xpath.internal.objects.XString;

import java.time.LocalDate; //alt + Enter
import java.util.Random;

/**
 * This program tests Employee class
 */



class Employee{

    private String name = "";   //instance field initiation
    private double salary;
    private LocalDate hireDay;




    public  Employee(String n , double s, int year, int  month  , int day){
        name = n ;
        salary = s;
        hireDay = LocalDate.of(year, month , day);
    }


    public  String getName(){
        return  name;
    }
    public  double getSalary(){
        return salary;
    }

    public LocalDate getHireDay() {
        return hireDay;
    }
    public  void  raiseSalary(double byPercent){
        double raise = salary * byPercent / 100;
        salary += raise;
    }
}


public class TestObjectClass_1 {
    public static  void  main(String[] args){
        //fill th staff array with three Employee objects
        Employee[] staff = new Employee[3];

        staff[0] = new Employee("Carl Cracker", 75000, 1987,12,15);
        staff[1] = new Employee("Harry Hacker", 50000, 1989,10,1);
        staff[2] = new Employee("Tony Tester", 40000, 1990,3,15);

        //raise everyone's salary by 5%
        for(Employee e : staff)
            e.raiseSalary(10);

        //print out information about all Employee objects
        for (Employee e : staff)
            System.out.println("name = " + e.getName()
                            +  ",salary = " + e.getSalary()
                            +  ",hireDay =" + e.getHireDay());
    }
}



/**
Data birthday = new Date();    //将对象放在一个变量里面

 在对象与对象与对象变量之间存在一个重要的区别.
 Date deadline;     //deadline doesn't refer to any object
 定义了一个对象变量deadline,他可以引用Date类型的对象.
 但是要认识到deadline不是一个对象,实际上也没有引用对象.
 此时,不能将任何Date方法应用与这个变量上.

 首先要初始化变量deadline,有两个选择.当然可以用新构造的对象初始化这个变量:
    deadline = new Date() ;
 也可以让这个变量引用一个已经存在的对象:
    deadline = birthday;
 现在这两个变量引用同一个对象.

 一定认识到:一个对象变量并没有实际包含一个对象,而仅仅引用一个对象.
 在Java中,任何对象变量的值都是对存储在另个地方的一个对象的引用.new操作符的返回值也是一个引用.

 Date deadline = new Date();
 有两个部分。表达式 new Date() 构造了一个 Date 类型的对象， 并且它的值是对新创建对象的引用。这个引用存储在变量 deadline 中。
 可以显式地将对象变量设置为 null 表明这个对象变量目前没有引用任何对象。
 deadline = null;

 如果将一个方法应用于一个值为 null 的对象上，那么就会产生运行时错误。
 birthday = null;
 String s = birthday.toStringQ; // runtime error!
 局部变量不会自动地初始化为 null，而必须通过调用 new 或将它们设置为 null 进行初始化。
 */

/**

 C++ 注释：很多人错误地认为 Java 对象变量与 C++ 的引用类似。然而，在 C++ 中没有
 空引用， 并且引用不能被赋值。可以将 Java 的对象变量看作 C++ 的对象指针。例如，
    Date birthday; // Java
 实际上，等同于
    Date* birthday; // C++
 一旦理解了这一点， 一切问题就迎刃而解了。 当然，一个 Date* 指针只能通过调用
 new 进行初始化。就这一点而言，OH■
 与 Java 的语法几乎是一样的
    Date* birthday = new Date(); // C++
 如果把一个变量的值賦给另一个变量， 两个变量就指向同一个日期，即它们是同一
 个对象的指针。 在 Java 中的 null 引用对应 C++ 中的 NULL 指针。
 所有的 Java 对象都存储在堆中。 当一个对象包含另一个对象变量时， 这个变量依然
 包含着指向另一个堆对象的指针。
 在 C++ 中， 指针十分令人头疼， 并常常导致程序错误。稍不小心就会创建一个错误
 的指针，或者造成内存溢出。在 Java 语言中，这些问题都不复存在。 如果使用一个没有
 初始化的指针， 运行系统将会产生一个运行时错误， 而不是生成一个随机的结果， 同时，
 不必担心内存管理问题，垃圾收集器将会处理相关的事宜。
 C++ 确实做了很大的努力， 它通过拷贝型构造器和复制操作符来实现对象的自动拷
 贝。 例如，
 一个链表（ linked list) 拷贝的结果将会得到一个新链表， 其内容与原始链表
 相同， 但却是一组独立的链接。这使得将同样的拷贝行为内置在类中成为可能。在 Java
 中，必须使用 clone 方法获得对象的完整拷贝 „

 */

/**
 在这个示例程序中包含两个类：Employee类和带有 public 访问修饰符的 EmployeeTest类。
 EmployeeTest 类包含了 main 方法，其中使用了前面介绍的指令。

 源文件名是 EmployeeTest.java，这是因为文件名必须与 public 类的名字相匹配。在一个
 源文件中， 只能有一个公有类，但可以有任意数目的非公有类。

 接下来，当编译这段源代码的时候，
    编译器将在目录下创建两个类文件：TestObjectClass_1.class
                               Employee.class
 将程序中包含 main方法的类名提供给字节码解释器， 以便启动这个程序：
        java TestObjectClass_1
 字节码解释器开始运行 EmployeeTest 类的 main方法中的代码。在这段代码中，先后构
 造了三个新 Employee 对象， 并显7K它们的状态。


 */