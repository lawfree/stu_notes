package com.lowfree;

public class Student extends  Person {

    private  String major;

    /**
     * @param  name the student's name
     * @return
     */
    public  Student (String name , String  major){
        // pass n to superclass constructor
        super(name);
        this.major = major;
    }
    @Override
    public String getDescription() {
        return "a student majoring in " + major;
    }
}
