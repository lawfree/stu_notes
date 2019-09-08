package com.lowfree;

//prepare a Person class
public class Person {
    private String name;
    int age;
    public  String address;

    // 4 kinds of constructor
    public  Person(){}

    private  Person(String name){
        this.name = name;
    }

    Person(String name , int age ){
        this.name = name;
        this.age = age;
    }

    public Person(String  name, int age ,String address){
        this.name = name;
        this.age = age;
        this.address = address;
    }


    public  void  show(){
        System.out.println("show - public ");
    }

    public  void method(String s){
        System.out.println("method - public" + s);
    }

    public String getString (String s , int i){
        return  s + "-----" + i;
    }

    private  void function(){
        System.out.println("function - private");
    }

    @Override
    public String toString() {
        return getClass() + "name:" + name + ",age: " + age + ",address:" +address ;
    }
}
