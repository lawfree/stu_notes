package com.lowfree;

public class TestObject {
    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}

/**
 可以使用 Object 类型的变量引用任何类型的对象：
 Object obj = new EmployeeC'Harry Hacker", 35000);

 当然， Object 类型的变量只能用于作为各种值的通用持有者。要想对其中的内容进行具体的操作， 还需要清楚对象的原始类型， 并进行相应的类型转换：
 Employee e = (Employee) obj ;

equals 方法
 Object 类中的 equals 方法用于检测一个对象是否等于另外一个对象。在 Object 类中，这
 个方法将判断两个对象是否具有相同的引用。如果两个对象具有相同的引用， 它们一定是相等的。

 然而，对于多数类来说，这种判断并没有什么意义。例如， 采用这种方式比较两个 PrintStream 对象是否相等就完全没有意义。
 然而，经常需要检测两个对象状态的相等性，如果两个对象的状态相等， 就认为这两个对象是相等的。
 */
