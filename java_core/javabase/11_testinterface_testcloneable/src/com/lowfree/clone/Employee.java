package com.lowfree.clone;

import java.util.Date;
import java.util.GregorianCalendar;

public class Employee  implements  Cloneable {
    private String name;
    private double salary;
    private Date hireDay;

    public Employee(String name, double salary) {
        this.name = name;
        this.salary = salary;
        hireDay = new Date();
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {

        //call Object.clone()
        Employee cloned = (Employee) super.clone();
        //Employee cloned = (Employee) this.clone();  this is wrong

        //clone mutable fields
        cloned.hireDay = (Date) hireDay.clone();

        return cloned;
    }

    /**
     *
     * @param year
     * @param month
     * @param day
     */
    public void setHireDay(int year , int month , int day) {
        Date newHireDay = new GregorianCalendar(year , month - 1, day).getTime();

        //Example of instance field mutation
        hireDay.setTime(newHireDay.getTime());
    }

    public void raiseSalary(double byPercent){
        double raise = salary * byPercent / 100;
        salary += raise;
    }

    @Override
    public String toString() {
        return "Employee[name=" + name + ",salary=" + salary + ",hireDay: " + hireDay +"]";
    }
}