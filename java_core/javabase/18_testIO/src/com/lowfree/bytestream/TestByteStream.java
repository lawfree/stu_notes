package com.lowfree.bytestream;

import org.junit.jupiter.api.Test;

import java.io.*;

public class TestByteStream {

    @Test
    public void readFromFile() {
        String path = "/home/lowfree/doc/idea_workspace/javabase/18_testIO/test1.txt";
        FileInputStream inputStream = null;
        BufferedInputStream bufferedInputStream = null;
        try {
             inputStream = new FileInputStream(path);
            bufferedInputStream = new BufferedInputStream(inputStream);

            byte[] b =  new byte[1024];
            int hasread = 0;
            while ( (hasread = bufferedInputStream.read(b) )> 0){
                System.out.println(new String(b,0, hasread));
            }
            inputStream.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    /* 需求：往一个文本文件中写入一句话："hello,IO".
     *
     * 分析：
     *      A：这个最好用字符流实现，这里用字节流
     *      B：由于我是想往文件中写一句话，所以我们用字节输出流
     * 通过上面的分析后我们知道要使用OutputStream
     * 但是通过查看API，我们发现该流对象是一个抽象类，不能实例化
     * 所以我们要找一个具体的子类，这个时候很简单,实际上，我们是要往文件中写东西
     * 文件单词：File
     * 然后用的是字节流，连起来就是FileOutputStream
     * 注意：每种基类的子类都是以父类名作为后缀名
     *
     * 查看FileOutputStream构造方法
     *      FileOutputStream(File file)
     *      FileOutputStream(String name)
     */
    @Test
    public  void  writeToFile(){
        String path = "/home/lowfree/doc/idea_workspace/javabase/18_testIO/test1.txt";
        try {
            FileOutputStream fos = new FileOutputStream(path , true);
            /*
             * 创建字节输出流对象做了几件事情
             * 1：调用系统功能去创建文件
             * 2：创建fos对象
             * 3：把fos对象指向这个文件
             */
            fos.write("hello ,FileOutPutStream\n".getBytes());
            fos.write(97);//97----底层是二进制数组----通过记事本打开-----找97对应的字符值----a

            //public void write (byte[] b):写一个字节流数组
            byte[] bys={97,98,99,100,101};
            fos.write( "\n".getBytes());
            fos.write(bys);
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Test
    public  void copyFile(){
        String src_path =   "/home/lowfree/doc/idea_workspace/javabase/18_testIO/test1.txt";
        String des_path =   "/home/lowfree/doc/idea_workspace/javabase/18_testIO/test2.txt";

        try {
            FileInputStream fis = new FileInputStream(src_path) ;
            FileOutputStream fos = new FileOutputStream(des_path);

//            int by = 0;
//            while ( (by = fis.read()) != -1 ){
//                fos.write(by);
//            }

            byte[] bys  = new byte[1024];
            int len = 0;
            while ( (len = fis.read()) != -1){
                fos. write(bys , 0 , len);
            }

            fis.close();
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }



}


