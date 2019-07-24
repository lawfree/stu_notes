
#include <iostream>
#include <vector>

using namespace std;
using std::vector;


int main(){
//    char ch;        cout<<sizeof (ch);  //1
//    int i;          cout<<sizeof(i);    //4
//    long l;         cout<<sizeof(l);    //4
//    double d;       cout<<sizeof(d);    //8
    int i = 0,b = 0;
    ++i,--b;
    cout << i <<" "<<b;
}

/*
4.1基础
    左值和右值
       当一个对象被用作右值的时候,用的是对象的值(内容);
       当对象被用作左值的时候,用的是对象的身份(在内存中的位置)

4.7条件运算符
    嵌套条件运算符
        允许在条件运算符内部嵌套另外一个条件运算符.也就是说,条件表达式可以作为另外一个条件运算符comd和expr
        finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";
    在输出表达式中使用条件运算符
        cout << ( (grade < 60 ) ? "fail" : "pass" );    //输出pass或者fail
        cout << (grade < 60) ? "fail" : "pass";         //输出1或者0!
        cout << grade < 60 ? "fail" : "pass";           //错误:试图比较cout 和 60
4.8 位运算符
    强烈建议仅将位运算符用于处理无符号类型
    左移运算符 << 在右侧插入值为0的二进制位
    右移运算符 >> 依赖于其左侧运算对象的类型:
        如果该运算符对象是无符号类型,在左侧插入值为0的二进制为
        如果该运算对象是带符号类型,在左侧插入符号为副本或值为0的二进制位
     位求反运算符~
        char类型的运算对象首先提升成int类型,提升时运算对象原来的位保持不变,往高位添0即可
        首先将bits提升成int类型,增加24个高位0,随后将提升后的值按位求反.
    位与,位或,异或运算符
        在两个运算对象上逐位执行相应的逻辑操作
4.10逗号运算符
    含有两个运算对象,按照从左向右的顺序依次求值.
    首先对左侧表达式求值,然后将求值结果丢弃掉.逗号运算符真正的结果是右侧表达式的值.
4.11类型转换
    何时发生隐式类型转换
    显式转换

5.6 try语句块和异常处理
    throw表达式
        throw表达式包含关键字throw和紧随其后的一个表达式,其中表达式的类型就是抛出的异常类型
        表达式的类型就是抛出的异常类型.throw表达式后面通常紧跟一个分号
            // throw runtime_error (" ,...");
    try 语句块
        try{
            program-statements
        } catch (exception - declaration){
            handler-statement
        } catch (exception - declaration){
            handler-statement
        }// ...

6.3.3 返回数组指针
    *func(int i)[10]        表示解引用func的调用将得到一个大小是10的数组
    int (*func(int i))[10]  表示数组中的元素是int类型
6.4 函数重载
    如果同一作用域内的几个函数名字相同,我们称为重载函数
    接受的形参类型不同,但是执行的操作类似.当调用这些函数时,编译器会根据传递的实参类型推断想要的是哪个函数
    重载和const形参
        一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来
            record lookup (phone);
            record lookup (const phone);    //重复声明
        另一方面,如果形参是某种类型的指针或引用,则通过区分其指向的是常量对象还是非常量对象可以实现函数重载
        此时,const是低层的
            //对于接受引用或指针的函数来说,对象是常量还是非常量对应的形参不同
            //定义了4个独立的重载函数
            record lookup (Account&)        //函数作用与Account的引用
            record lookup (const Account&)  //新函数,作用于常量引用
6.5.2内联函数和constexpr函数
    内联函数可避免函数调用的开销
        一般来说,内联机制用于优化规模较小,流程直接,频繁调用的函数.很多编译器都不支持内联递归函数
        把内联函数和constexpr函数放在头文件内
6.5.3调试帮助
    assert预处理宏
        assert(expr);
        首先对expr求值,如果表达式为假,assert输出信息并终止程序执行,如果表达式为真,assert什么也不做
    NDEBUG预处理变量
            $ CC -D NDEBUG main.c # use /D with the Microsoft compiler
        这条命令作用等价于在main.c文件一开始写#define NDEBUG
            __func__    存放当前调试的函数的名字
            __LINE__    存放当前行号的整型字面值
            __TIME__    存放文件编译时间的字符串字面值
            __DATE__
6.7 函数指针
    函数指针指向的是函数而非对象，和其他指针一样，函数指针指向某种特定类型。函数类型由它的返回类型和形参类型共同决定，与函数名无关
        //比较两个string对象的长度
        bool lengthCompare(const string &, const string &);
    该函数的类型是bool(const string &, const string &)。想声明一个可以指向该函数的指针，只需要用指针替换函数名即可：
        //pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool类型
        bool (*pf)(const string &,const string &);  //未初始化
    pf前面有个*,因此pf是指针;右侧是形参列表,表示pf指向的是函数;再观察左侧,发现函数的返回类型是bool值.因此.pf就是一个指向函数的指针,
    其中该函数的参数是两个const string 的引用,返回值bool类型
    *pf两端的括号必不可少,如果不写括号,则pf是一个返回值为bool指针的函数:
        //声明一个名为pf的函数,该函数返回bool*
        bool *pf(const string...);

    使用函数指针
        当我们把函数名作为一个值来使用时,该函数自动地转换为指针.
        pf = lengthCompare;     //pf指向名为lengthCompare的函数
        pf = &lengthConmpare;   //等价的赋值语句:取地址符号是可选的

        此外,还可以直接使用指向函数的指针调用该函数,无需提前解引用指针:
        bool b1 = pf("hello" , "goodbye");      //调用lengthCompare函数
        bool b2 = (*pf)("hello" , "goodbye");   //一个等价的调用
        bool b3 = lengthCompare(...)            //另一个等价调用
    重载函数的指针
        当使用重载函数时,上下文必须清晰界定到底应该选用哪个函数.
    函数指针形参
        和数组类似,虽然不能定义函数类型的形参,但是形参可以是指向函数的指针.此时形参看起来是函数类型,实际上是当成指针使用:
            //第三个形参是函数类型,它会自动地转换成指向函数的指针
            void useBigger(const string &s1 , const string &s2,
                            bool pf(const string &, const string &));
            //等价声明:显式地将形参定义成指向函数的指针
            void useBigger(const string &s1 , const string &s2,
                            bool (*pf)(const string &, const string &));                                        
            //直接把函数当做实参使用,它会自动转换为指针
            useBigger (s1 , s2 , lengthCompare);                
    返回指向函数的指针
        和数组类似,虽然不能返回一个函数,但是能返回指向函数类型的指针.然而,我们必须把返回类型写成指针形式,编译器不会自动地将函数返回类型当成对应指针类型处理













*/
