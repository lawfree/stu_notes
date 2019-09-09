package com.lowfree.innerclass;

import java.awt.*;
import java.awt.event.ActionListener;
import  java.awt.event.*;
import java.util.Date;
import javax.swing.*;
import  javax.swing.Timer;

public class InnerClassTest {
    public static void main(String[] args) {
        TalkingClock clock = new TalkingClock(1000, true);
        clock.start();

        //keep program running until user select OK
        JOptionPane.showMessageDialog(null, "Quit program?");
        System.exit(0);
    }
}

/**
 * A clock prints the time in regular intervals,
 */
class TalkingClock{

    private int interval;
    private  boolean beep;

    /**
     * Constructs a talking clock
     * @param interval the interval between messages(in milliseconds)
     * @parm beep  true if the clock should beep
     */
    public  TalkingClock(int interval , boolean beep){
        this .interval = interval;
        this.beep = beep;
    }

    /**
     * starts the clock
     */
    public void start(){
        ActionListener listener = new TimerPrinter();
        Timer t = new Timer(interval ,listener) ;
        t.start();
    }

    public class TimerPrinter implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent e) {
            System.out.println("At the tome , the time is " + new Date());
            if (beep) Toolkit.getDefaultToolkit().beep();
        }
    }
}