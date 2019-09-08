package com.lowfree.clone;

/**
 * 程序克隆了 Employee 类的一个实例，然后调用两个更改器方法。raiseSalary 方法会改变 salary 域的值， 而 setHireDay 方法改变 hireDay 域的状
 * 态。这两个更改器方法都不会影响原来的对象， 因为 done 定义为建立一个深拷贝。
 */
public class CloneTest {
    public static void main(String[] args) {

            Employee original = new Employee("John Q.public", 5000);
            original.setHireDay(2000, 1 ,1);

        try {
            Employee copy = (Employee) original.clone();
            copy.raiseSalary(10);
            copy.setHireDay(2002,12,31);
            System.out.println("origin = " + original);
            System.out.println("copy = " + copy);


        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }


    }
}
