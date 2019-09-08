package com.lowfree;

/*
 * 反射:就是通过class文件对象,去使用该文件的成员变量,构造方法
 *
 * 通过class对象去干其他事儿,首先就必须得到class文件独享,其实也就是得到Class类的对象
 * (Class类:
 *      成员变量    Filed
 *      构造方法    Constructor
 *      成员方法    Method)
 *
 * 获取class对象的方式有三种:
 *  A:Object类的getClass()方法
 *  B:数据类型的静态属性class
 *  C:Class类中的静态方法
 *      public static Class<?> forName(String className)
 *
 * 一般选用哪一个?
 *      A:自己玩   任选一种,第二种比较方便
 *      B:开发    第三种
 *                  为什么?因为第三种是一个字符串,而不是一个具体类名,这样我们就可以把这样的字符串配置到配置文件中
 */

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Objects;

public class ReflectionDemo {
    public static void main(String[] args) throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InstantiationException, InvocationTargetException, NoSuchFieldException {
        //getClassObjectDemo();
        //getConstructorDemo();
        //getMemberValueDemo();
        getMemberMethod();

    }
    public  static  void  getClassObjectDemo() throws  ClassNotFoundException{
        //method1 :  Object 类的getClass()方法
        //先获得一个示例对象的引用p
        Person p = new Person();
        Class c = p.getClass();

        Person p2 = new Person();
        Class c2 = p.getClass();

        System.out.println(p == p2);    // false//由于示例化了两个对象,c和c2分别指向两个不同的对象,这点很好理解
        System.out.println(c == c2);    // true//注意这里实际上获得的同一个class对象(字节码对象)`

        //method2 : 类型名称.class
        Class c3 = Person.class;
        //int.class;
        //String.class;
        System.out.println( int.class);     //int


        // method3 : class.forName(类型权限名)
        //ClassNotFoundException
        //com.lowfree.Person
        Class c4 = Class.forName("com.lowfree.Person");
        System.out.println(c == c4);        //true
    }

    public  static  void getConstructorDemo() throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        //获得字节码对象
        Class c = Class.forName("com.lowfree.Person");

        //获取构造方法(组)
        //1.使用getConstructors[] 获得所有公共方法
        //public Constructor[] getConstructors{}
        //2.使用getDeclaredConstructors{}获得所有构造方法
        //public Constructor[] getDeclaredConstructors{}

        Constructor[] cons = c.getDeclaredConstructors();
        for (Constructor con : cons) {
            //System.out.println(con.getName());        //com.lowfree.Person
            System.out.println(con);
        }

        //获取单个构造方法
        //pub Constructor<T> getConstructor(Class<?> ...parameterTypes)
        //参数表示的是: 你要获取的构造方法的构造参数个数及数据类型的class字节码对象.比如:
        Constructor con = c.getConstructor();
        // 使用此 Constructor 对象表示的构造方法来创建该构造方法的声明类的新实例，并用指定的初始化参数初始化该实例。
        Object obj = con.newInstance();
        System.out.println(obj);
        //class com.lowfree.Personname:null,age: 0,address:null


        //Constructor con2 = c.getConstructor(String.class);   getConstructor z只能拿到公共的
        Constructor con2 = c.getConstructor(String.class, int.class , String.class);
        Object obj2 = con2.newInstance("lowfree",22, "chengdu");
        System.out.println(obj2);


        //想拿private 或者包权限的,用getDeclare
        //Object obj3 = c.getDeclaredConstructor(String.class).newInstance("lowfree");
        /* xception in thread "main" java.lang.IllegalAccessException: Class com.lowfree.ReflectionDemo can not access a member of class com.lowfree.Person with modifiers "private"
	at sun.reflect.Reflection.ensureMemberAccess(Reflection.java:102) */

        Constructor con3 = c.getDeclaredConstructor(String.class);
        con3.setAccessible(true);
        Object obj3 = con3.newInstance("Lowfree");


        System.out.println(obj3);
    }

    public static  void  getMemberValueDemo() throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException, NoSuchFieldException {
        Class c = Class.forName("com.lowfree.Person");

        Object obj = c.getConstructor(String.class, int.class , String.class).newInstance("Lowfree",22,"chengdu");
        System.out.println(obj);

        // 获取所有成员变量
        // Field[] fields = c.getFields();还是只能获取公共的
        // Field[] fields = c.getDeclaredFields();
        // for (Field field : fields) {
        // System.out.println(field);


        Field[] fields = c.getDeclaredFields();
        for (Field field : fields)
            System.out.println(field);

        //获取单个的成员变量并赋值
        Field addressField = c.getField("address");
        //public void set(Object obj, Object value)
        //将制定对象变量上此Field对象表示的字段设置为新值
        addressField.set(obj,"shanghai");
        System.out.println(obj);

        //获取private的name字段
        Field nameField = c.getDeclaredField("name");

        nameField.setAccessible(true);
        nameField.set(obj , "bob");
        System.out.println(obj);

        //获取age并对其赋值
        Field ageFiled = c.getDeclaredField("age");
        ageFiled.setAccessible(true);
        ageFiled.set(obj , 23);
        System.out.println(obj);
    }

    public  static void getMemberMethod() throws ClassNotFoundException, NoSuchMethodException, IllegalAccessException, InvocationTargetException, InstantiationException {
        Class c = Class.forName("com.lowfree.Person");

        Object obj = c.getDeclaredConstructor(String.class, int.class, String.class).newInstance("lowfree",22, "chengdu");

        /*
        以前我们这么用:
        Person p = new Person(); p. show();
         */

        //获取单个方法并使用
        //public void show()
        //public Method getMethod(String name , Class<?> ... parameterTypes)
        //第一个参数表示方法名,第二个表示方法的class类型
        Method m1 = c.getMethod("show");

        // public Object invoke(Object obj, Object... args
        // 返回值是Object,第一个数据表示对象是谁,第二个表示调用该方法的实际参数
        m1.invoke(obj );        // 调用obj对象的1 方法

        Method m2 = c.getDeclaredMethod("method", String.class);
        m2 .invoke(obj , "hello");

        Method m3 = c.getDeclaredMethod("getString", String.class, int.class);
        //Object objString = m3.invoke(obj);
        String s =  (String)m3.invoke(obj, "hello", 100 );
        System.out.println(s);

        //private method
        Method m4  = c.getDeclaredMethod("function");
        m4.setAccessible(true);
        m4.invoke(obj);
    }
}
