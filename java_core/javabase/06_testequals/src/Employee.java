import java.time.*;
import java.util.Objects;

public class Employee {
    private String name;
    private  double salary;
    private  LocalDate hireDay;

    public  Employee( String name, double salary , int year, int month, int day){
        this.name =  name ;
        this.salary = salary;
        hireDay = LocalDate.of(year, month , day);
    }

    public String getName() {
        return name;
    }

    public double getSalary() {
        return salary;
    }

    public LocalDate getHireDay() {
        return hireDay;
    }

    public void raiseSalary(double byPercent){
        double raise = salary * byPercent / 100;
        salary += raise;
    }

    @Override
    public boolean equals(Object obj) {
        //return super.equals(obj);

        //a quick test to see if the objects are identical
        if ( this == obj) return  true;

        //must return false if the explicit parameter is null
        if (obj == null) return  false;

        //if the classes don't match , they can't be equal
        if(getClass() != obj.getClass()) return  false;

        //now we know obj is a non-null Employee
        Employee other =  (Employee) obj;

        //test whether the fields have identical values
        return  Objects.equals(name, other.name) && salary == other.salary && Objects.equals(hireDay, other.hireDay);
    }

    @Override
    public int hashCode() {
        //return super.hashCode();

        return  Objects.hash(name , salary , hireDay);

    }
}
