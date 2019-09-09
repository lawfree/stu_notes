package com.lowfree01;

import org.junit.jupiter.api.Test;

import java.util.Comparator;
import java.util.function.Consumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;

public class TestLambda {
    @Test
    public  void  test1(){
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                System.out.println("线程启动了.。");
            }
        };
        runnable.run();
    }

    /**
     语法格式一: 无参数,无返回值
        () -> System.out.println("线程启动了");
     */
    @Test
    public  void  test2(){
        //“->”左边只有一个小括号，表示无参数，右边是Lambda体(就相当于实现了匿名内部类里面的方法了，(即就是一个可用的接口实现类了。))
        Runnable runnable = ()-> System.out.println("线程启动了 --- lambda");
        runnable .run();
    }


    /**
     语法格式二: 一个参数,无返回值
          (x) -> System.out.println("线程启动了" + x) ;
     */
    @Test
    public void test3(){
        //这个e表示所实现的接口的方法的参数
        Consumer<String> consumer = e -> System.out.println("lambda" + e);
        consumer.accept("adfadafa");
    }

    /**
     语法格式三：若只有一个参数，小括号可以省略不写 x -> System.out.println(x)</font(第二种方式的一种简化吧)
     语法格式四：有两个以上的参数，有返回值，并且 Lambda 体中有多条语句
     */
    @Test
    public void test4 (){
        Comparator<Integer> comparator = new Comparator<Integer>() {
            @Override
            public int compare(Integer x, Integer y) {
                return  Integer.compare(x , y);
            }
        };

        //Lambda 有多条语句,要用大括号括起来
        Comparator<Integer> com = (x , y) -> {
            System.out.println("函数式接口");
            return Integer.compare(x , y);
        };

        int compare0 = comparator.compare(100 , 101);
        int compare = com.compare(100 , 244);
        System.out.println(compare0  + "  " + compare) ;

    }

    /**
     语法格式五：若 Lambda 体中只有一条语句， return 和 大括号都可以省略不写 即：Comparator com = (x, y) -> Integer.compare(x, y);
     语法格式六：Lambda 表达式的参数列表的数据类型可以省略不写，因为JVM编译器通过上下文推断出，数据类型，即“类型推断”(Integer x, Integer y) -> Integer.compare(x, y);
     */

    /**
     到这儿，相信大家也看出来规律了，这个Lambda表达式，好像离不开接口咦.......你还真说对了，这个Lambda表达式，是需要函数式接口的支持的，那么什么是函数式接口呢？
     函数式接口 ，即只包含一个抽象方法的接口，称为函数式接口。
     你可以通过 Lambda 表达式来创建该接口的对象。（若 Lambda 表达式抛出一个受检异常，那么该异常需要在目标接口的抽象方法上进行声明）。
     我们可以在任意函数式接口上使用 @FunctionalInterface 注解，这样做可以检查它是否是一个函数式接口，同时 javadoc 也会包含一条声明，说明这个接口是一个函数式接口。像上面的Consumer接口就是一个函数式接口。
     */


    /**
     Java 内置的四大函数式接口分别为

     函数式接口      参数类型        返回类型        用途
     Consumer<T>     T               void        对类型为T的对象应用操作,包含方法: void accept(T t)
     Supplier<T>     无               T          返回类型为T的对象,包含方法: T get();
     Function<T>     T                R          对类型为T的对象应用操作,并返回结果.结果是R类型的对象.包含方法 R apply(T t)
     Predicate<T>    T                boolean    确定类型为T的对象是否满足某约束
     */
    @Test
    public  void test6(){
        String str_test = "123456";

        Supplier<String> supplier0 = new Supplier<String>() {
            @Override
            public String get() {
                return  str_test.substring(0,2);
            }
        };

        Supplier<String> supplier = ( ) ->str_test.substring(0,2);
        System.out.println(supplier.get());

    }

    @Test
    public  void test7(){
        String  str_test = "123456";

        Function<String , String >  function0 = new Function<String, String>() {
            @Override
            public String apply(String s) {
                return  str_test + s;
            }
        };

        Function<String  , String > function =  (x) -> str_test + x;
        System.out.println(function.apply(str_test));
    }

    @Test
    public  void test8(){
        Predicate<String> predicate = (x) -> x.length() > 5;
        System.out.println(predicate.test("123456"));
        System.out.println(predicate.test("123"));
    }

}
