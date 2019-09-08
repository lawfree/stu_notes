package com.lowfree;

import java.util.Arrays;

public class EmployeeSortTest {
    public static void main(String[] args) {
        Employee[] staff = new Employee[3];

        staff[0] = new Employee ("Harry Hacker" , 35000) ;
        staff[1] = new Employee ("Carl Cracker" , 75000);
        staff[2] = new Employee ("Tony Tester" , 38000) ;

        Arrays.sort(staff);

        for(Employee e : staff)
            System.out.println("name = " + e.getName() + " , salary = " + e.getSalary());
    }
}


/*
java.lang.Comparable<T> 1.0
• int compareTo(T other)
    用这个对象与 other 进行比较。如果这个对象小于 other 则返回负值； 如果相等则返回0；否则返回正值。

java.util.Arrays 1.2
static void sort( Object[] a )
    使用 mergesort 算法对数组 a 中的元素进行排序。要求数组中的元素必须属于实现了Comparable 接口的类， 并且元素之间必须是可比较的。

java.lang.Integer 1.0
• static int comparednt x , int y) 7
    如果 x < y 返回一个负整数；如果 x 和 y 相等，则返回 0; 否则返回一个负整数。

java.lang.Double 1.0
•static int compare(double x , double y) 1.4
    如果 x < y 返回一个负数；如果 x 和 y 相等则返回 0; 否则返回一个负数

*/