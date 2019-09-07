public class EqualsTest {
    public static void main(String[] args) {
        Employee alice1 = new Employee("Alice Adams" , 75000, 1987, 12 , 15);
        Employee alice2 = alice1;
        Employee alice3 = new Employee ("Alice Adams", 75000, 1987, 12, 15);
        Employee bob = new Employee("Bob Brandson" , 50000, 1989, 10, 1);

        System.out.println("alice1 == alice2: " + (alice1 == alice2));
        System.out.println("alice1 == alice3: " + (alice1 == alice3));
        System.out.println("alice1.equals(alice3): " + alice1.equals(alice3));

        System.out.println(alice1.getName().equals(alice3.getName()));         //true
        System.out.println( alice1.getName() == alice3.getName()) ;            //true
        System.out.println( alice1.getSalary() == alice3.getSalary());         //true
        System.out.println( alice1.getHireDay().equals(alice3.getSalary()));   //false




        System.out .println("alice1.equals(bob): " + alice1.equals(bob));
        System.out.println(" bob.toStringO：" + bob);

        Manager carl = new Manager("Carl Cracker" , 80000 , 1987 , 12, 15);
        Manager boss = new Manager("Carl Cracker",80000 , 1987, 12 , 15);
        boss. setBonus(5000);
        System.out.println("boss .toStringO：" + boss);
        System.out.println("carl .equals(boss): " + carl .equals(boss));
        System.out.println("alice1.hashCode(): " + alice1.hashCode());
        System.out.println("alice2.hashCode(): " + alice2.hashCode());
        System.out.println("alice3 .hashCode(): " + alice3 .hashCode());
        System.out.println("bob.hashCode()： " + bob.hashCode());
        System.out.println("carl .hashCode() : " + carl .hashCode());

    }
}
/**
 alice1 == alice2: true
 alice1 == alice3: false
 alice1.equals(alice3): true
 true
 true
 true
 false
 alice1.equals(bob): false
 bob.toStringO：Employee[ name = Bob Brandson ,salary = 50000.0,hireDay =1989-10-01]
 boss .toStringO：Manager[ name = Carl Cracker ,salary = 80000.0,hireDay =1987-12-15][bonus = 5000.0】
 carl .equals(boss): false
 alice1.hashCode(): -808853550
 alice2.hashCode(): -808853550
 alice3 .hashCode(): -808853550
 bob.hashCode()： -624019882
 carl .hashCode() : -341762419

 */


/**
 java.lang.Object 1.0
     •Class getClass( )
         返回包含对象信息的类对象。稍后会看到 Java 提供了类运行时的描述， 它的内容被封装在 Class 类中。
    •boolean equals(Object otherObject )
         比较两个对象是否相等， 如果两个对象指向同一块存储区域方法返回 true ;
        否则方法返回 false。在自定义的类中， 应该覆盖这个方法。
    •String toString( )
        返冋描述该对象值的字符串。在自定义的类中， 应该覆盖这个方法。

 java.lang.Class 1.0
    •String getName( )
        返回这个类的名字。
    •Class getSuperclass( )
        以Class对象的形式返回这个类的超类信息。
 */