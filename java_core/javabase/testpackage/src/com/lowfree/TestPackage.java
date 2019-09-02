package com.lowfree;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

class Employee{

    private String name = "";   //instance field initiation
    private double salary;
    private LocalDate hireDay;

//    public  Employee(){
//
//    }

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

class Manager extends Employee{
    private  double  bonus ;

    public  Manager(String name, double salary , int year, int month , int day){
        super(name , salary, year , month , day);   //调用超类 Employee 中含有 n、s、year month 和 day 参数的构造器
        bonus = 0;
    }

    public   void  setBonus(double bonus){
        this.bonus = bonus;
    }

    @Override
    public double getSalary() {
        //return super.getSalary();    this means use parent's method
        double baseSalary = super.getSalary();
        return  baseSalary  + bonus;

    }
}


public class TestPackage {
    public static void main(String[] args) {
        Manager boss = new Manager("Carl Cracker" , 80000,987, 12 , 15);
        boss.setBonus(5000) ;
        Employee staff_1 = new Employee("Harry Hacker",50000, 1989, 10, 1);
        Employee staff_2 = new Employee("Tony Tester", 40000, 1990, 3, 15);


        List<Employee> li_em = new ArrayList<Employee>();
        li_em.add(boss);
        li_em.add(staff_1);
        li_em.add(staff_2);

    }
}

/**
 一个类可以使用所属包中的所有类， 以及其他包中的公有类（ public class。)

 我们可以采用两种方式访问另一个包中的公有类。
     第一种方式是在每个类名之前添加完整的包名。
     可以使用 import 语句导人一个特定的类或者整个包。

 import java.*.* 导入以 java 为前缀的所有包。在大多数情况下， 只导入所需的包， 并不必过多地理睬它们。
 但在发生命名冲突的时候，就不能不注意包的名字了。例如，java.util 和 java.sql 包都有日期（ Date) 类。如果在程
 序中导入了这两个包：
    import java.util .*;
    import java.sql .*;
 在程序使用 Date 类的时候， 就会出现一个编译错误：
    Date today; // Error java.util .Date or java.sql .Date?
 此时编译器无法确定程序使用的是哪一个 Date 类。可以采用增加一个特定的 import 语句来解决这个问题：
    import java.util .*;
    import java.sql .*;
    import java.util .Date;
 如果这两个 Date 类都需要使用，又该怎么办呢？ 答案是，在每个类名的前面加上完整的包名。
    java.util .Date deadline = new java.util .Date();
    java.sql .Date today = new java.sql .Date(...);
 在包中定位类是编译器 （ compiler) 的工作。类文件中的字节码肯定使用完整的包名来引用其他类。

 */


/**
 关键字 this 有两个用途： 一是引用隐式参数，二是调用该类其他的构造器 ，
 同样，super 关键字也有两个用途：一是调用超类的方法，二是调用超类的构造器。

 在调用构造器的时候，这两个关键字的使用方式很相似。调用构造器的语句只能作为另
 一个构造器的第一条语句出现。构造参数既可以传递给本类（ this) 的其他构造器，也可
 以传递给超类（super ) 的构造器。

 */

/**

 •只能在继承层次内进行类型转换。
 •在将超类转换成子类之前，应该使用 instanceof进行检查。

 x instanceof C
 不会产生异常， 只是返回 false。之所以这样处理是因为 null 没有引用任何对象， 当
 然也不会引用 C 类型的对象。
 实际上，通过类型转换调整对象的类型并不是一种好的做法。在我们列举的示例中， 大
 多数情况并不需要将 Employee 对象转换成 Manager 对象， 两个类的对象都能够正确地调用
 getSalary 方法，这是因为实现多态性的动态绑定机制能够自动地找到相应的方法。
 只有在使用 Manager 中特有的方法时才需要进行类型转换， 例如， setBonus 方法o 如果
 鉴于某种原因，发现需要通过 Employee 对象调用 setBomis 方法， 那么就应该检查一下超类
 的设计是否合理。重新设计一下超类，并添加 setBonus
 *
 法才是正确的选择。请记住，只要
 没有捕获 ClassCastException 异常，程序就会终止执行。 在一般情况下，应该尽量少用类型
 转换和 instanceof 运算符。

 */

/**

 Manager* boss = dynamic_ca.st<Manager*>(staff[1]); // C++
 if (boss != NULL) . . .
 而在 Java 中， 需要将 instanceof 运算符和类型转换组合起来使用:
 if (staff[1] instanceof Manager){
 Manager boss = (Manager) staff[1];
    ...
 }
 */