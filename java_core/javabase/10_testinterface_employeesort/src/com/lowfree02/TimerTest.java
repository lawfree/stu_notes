package com.lowfree02;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

class TimerPrinter implements ActionListener{

    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("At the tome ,the time is " + (new Date()) .toString() );
    }
}

public class TimerTest {
    public static void main(String[] args) {
        ActionListener listener  = new TimerPrinter();

        //construct a timer  that calls the listener
        //once every 10 seconds
        Timer t = new Timer(1000, listener);
        t.start();
        JOptionPane.showMessageDialog(null , "quit program");
        System.exit(0);
    }
}

/*
javax.swing.JOptionPane 1.2
• static void showMessageDialog(Component parent, Object message)
显示一个包含一条消息和 OK 按钮的对话框。这个对话框将位于其 parent 组件的中央。如果 parent 为 mill , 对话框将显示在屏幕的中央，，

 javax.swing.Timer 1.2
• Timer(int interval , ActionListener listener)
构造一个定时器， 每隔 interval 毫秒通告 listener—次，
• void start()
启动定时器一旦启动成功， 定时器将调用监听器的 actionPerformed。
• void stop()
停止定时器。一旦停止成功， 定时器将不再调用监听器的 actionPerformed、

java.awt.Toolkit 1.0
• static Toolkit getDefaultToolkit()
获得默认的工具箱。 T.具箱包含有关 GUI 环境的信息。
• void beep()
发出一声铃响。

*/
