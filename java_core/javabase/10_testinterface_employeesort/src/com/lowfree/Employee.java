package com.lowfree;

public class Employee implements  Comparable {

    private  String name;
    private  double salary;

    public  Employee(String name , double salary){
        this.name = name;
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public  void raiseSalary(double byPercent){
        double raise = salary * byPercent / 100;
        salary += raise;
    }

    @Override
    public int compareTo(Object other) {
        if (getClass() != other.getClass()) throw new ClassCastException();

        return  Double.compare(salary , ((Employee) other).salary );
    }
}
