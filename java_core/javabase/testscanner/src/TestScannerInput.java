import java.io.IOException;
import java.nio.file.Paths;
import java.util.*;

/**
 * This program demonstrates console input
 */

public class TestScannerInput {
    public  static void main(String[] args){
        //testScannerInput();
        testArray();

    }
    public  static  void  testScannerInput(){
        Scanner scanner = new Scanner(System.in);       //new a Scanner constructed with System.in

        //get first input
        System.out.println("what's your name?");
        String name = scanner.nextLine();

        //get second input
        System.out.println("How old are you?");
        int age = scanner .nextInt();

        //display output on console
        System.out.println("your name is = " + name + "   your age is = " + age );
        //System.out.printf("Hello, %s. Next year, you'll be $d", name, age);
    }

    public static void readFileByScanner(String  filename){
        try {
            Scanner scanner = new Scanner(Paths.get("/home/lowfree/doc/idea_workspace/javabase/testscanner/" + filename),"UTH-8");
            scanner.nextLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        // TODO
    }
    public  static void testArray(){
        int a[] = new int[]{1, 4, 3,2};
        System.out.println(a.length);       //4

        /* try foreach */
        for (int element : a)
            System.out.println(element + 1);

        /* transform am array to string*/
        String str_a =  Arrays.toString(a);
        System.out.println(str_a);

        /* copy array */
        int copy_a[] = a;                               // 两个变量将引用同一个数组
        int copy_a2[] = Arrays.copyOf(a,a.length);      //Arrays类的copyOf方法,将一个数组中所有值拷贝一个新的数组中去.

        copy_a[0] = 0;
        System.out.println( "change in copy_a, now a[0] = " + a[0]);    //0
        copy_a2[0] = - 1;
        System.out.println( "change in copy_a2, now a[0] = " + a[0]);    //0
        System.out.println( "change in copy_a2, now copy_a2[0] = " + copy_a2[0]);    //0


        /* sort array */
        Arrays.sort(a);
        System.out.println(str_a);  //[1, 4, 3, 2]
        str_a = Arrays.toString(a);
        System.out.println(str_a);  //[0, 2, 3, 4]


        /* 不规则 arrays */
        int[][] odds  = new int[10][];
        for (int i = 0 ; i <  10 ; i ++ ) {
            odds[i] = new int [i + 1];
        }

    }

}
/**
java.util.Scanner
    Scanner (InputStream in)    //用给定的输人流创建一个 Scanner 对象。
    String nextLine( )          //读取输入的下一行内容。
    String next( )              //读取输入的下一个单词（以空格作为分隔符。)
    int nextInt( )
    double nextDouble( )        //读取并转换下一个表示整数或浮点数的字符序列。
    boolean hasNext( )          //检测输人中是否还有其他单词。
    boolean hasNextInt( )
    boolean hasNextDouble( )    //检测是否还有表示整数或浮点数的下一个字符序列。Scanner (InputStream in)
*/

/**
 java.util.Scanner 5.0
     •Scanner(File f)
         构造一个从给定文件读取数据的 Scanner。
     Scanner(String data)
         构造一个从给定字符串读取数据的 Scanner。
 java.io.PrintWriter 1.1
     • PrintWriter(String fileName)
        构造一个将数据写入文件的 PrintWriter。文件名由参数指定。
 java.nio.file.Paths 7
     • static Path get(String pathname)
       根据给定的路径名构造一个 Path。
 */


/**
 java,util.Arrays 1.2
    •static String toString(type[]a)
         返回包含 a 中数据元素的字符串， 这些数据元素被放在括号内， 并用逗号分隔。
         参数： a 类型为 int、long、short、 char、 byte、boolean、float 或 double 的数组
 。
     • static type copyOf(type[]a, int length)
     • static type copyOfRange(type[]a , int start, int end)
         返回与 a 类型相同的一个数组， 其长度为 length 或者 end-start， 数组元素为 a 的值。
         参数：  a 类型为 int、 long、 short、 char、 byte、boolean、 float 或 double 的数组。
                start 起始下标（包含这个值）0
                end 终止下标（不包含这个值）。这个值可能大于 a.length。 在这种情况下，结果为 0 或 false。
                length 拷卩!的数据元素长度c 如果 length 值大于 a.length， 结果为 0 或 false ;
                        否则， 数组中只有前面 length 个数据元素的拷 W 值。

    static void sort(type [ ] a)
        采用优化的快速排序算法对数组进行排序。
        参数：a 类型为 int、long、short、char、byte、boolean、float 或 double 的数组。

     •static int binarySearch(type[]a , type v)
     • static int binarySearch(type[]a, int start, int end, type v) 6
        采用二分搜索算法查找值 v。如果查找成功， 则返回相应的下标值； 否则， 返回一个
        负数值 。r -r-1 是为保持 a 有序 v 应插入的位置。
        参数 a 类型为 int、 long、 short、 char、 byte、 boolean float 或 double 的有序数组。
            start 起始下标（包含这个值）。
            end 终止下标（不包含这个值。)
            v 同 a 的数据元素类型相同的值。

     • static void fi11(type[]a , type v)
        将数组的所有数据元素值设置为 V。
        参数 a 类型为 int、 long、short、 char、byte、boolean float 或 double 的数组。
            v 与 a 数据元素类型相同的一个值。

    • static boolean equals(type[] a, type[] b)
        如果两个数组大小相同， 并且下标相同的元素都对应相等， 返回 true。
        参数 a、 b 类型为 int、long、short、char、byte、boolean、float 或 double 的两个数组。


 */


/**
 C++ 注释： 在 C++ 中， Java 声明
     doublet][] balances = new double[10][6]; // Java
     不同于
     double balances [10] [6]; // C++
     也不同于
     double (*balances)[6] = new double[10] [6]; // C++
     而是分配了一个包含 10 个指针的数组：
     double** balances = new double* [10]; // C++
     然后， 指针数组的每一个元素被填充了一个包含 6 个数字的数组：
     for (i = 0; i < 10; i++)
     balances[i] = new double [6] ;
     庆幸的是， 当创建 new double[10][6] 时， 这个循环将自动地执行，:， 当需要不规则的
     数组时， 只能单独地创建行数组。

*/