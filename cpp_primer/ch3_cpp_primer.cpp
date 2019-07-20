
#include <iostream>
#include <vector>

using namespace std;
using std::vector;


int main(){

    /*读取未知数量的string对象 */
    // string word ;
    // while (cin >> word)         //反复读取，直到到达文件末尾
    //     cout << word << endl;   //逐个输出单词，每个单词后面紧跟一个换行

    // string line;
    // /* 每次读入一整行，直到文件末尾 */
    // while (getline(cin , line))
    // {
    //     cout << line << endl;
    // }

    /*测试范围for */
    // string str("some string ");
    // //每行输出str中的一个字符
    // for(char c : str)
    //     cout << c << endl;
/********************************************/
//    vector<int> v2;	//空vector对象
//    for (int i = 0; i != 100; i++)
//            v2.push_back(i);

//    string word;
//    vector <string>  text ;    //空vector
//    while (cin >> word)
//        text.push_back(word);   //把word 添加到text后面
/********************************************/
//    vector<int> iv(10 , 0);
//    iv[1] = 1;
//    cout << iv[0] << iv[1] << endl;     //01

    /*用迭代器把string对象的第一个字母改成大写形式*/
//    string s("some string ");
//    if (s.begin() != s.end()){  //确保s非空
//        char it = s.begin();    //it 表示s的第一个字符
//        *it = toupper(*it);     //将当前字符改成大写形式
//    }
/***********************************************/
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
//    int *p = arr ;                  //p指向arr的第一个元素
//    int *e = &arr[10];
//    for(int *b = arr; b != e; ++b)
//        cout << *b << endl;
    vector<int> subarr(arr+2 , arr);        //.. 地址作为参数,,应该是有点问题的
    vector<int> subarr2(*(arr+2) , *(arr)); //0 0


    cout << subarr[0] << " " << subarr[1] <<endl;


    return 0;
}

/*
3.2标准库类型string
3.2.1定义和初始化string对象
    一些初始化string对象的常用方式：
        string s1;              //默认初始化，s1是一个空字符串
        string s2 = s1；        //s2是s1的副本
        string s3 = ”hiya“；    //s3是该字符串字面值的副本
        string s4(5, 'c');      //内容是ccccc
    直接初始化和拷贝初始化
        如果使用等号初始化一个变量，实际上执行的是拷贝初始化，编译器把等号右侧的初始值拷贝到新创建的对象中去。
        如果不使用等号，则执行的是直接初始化

3.2.2string对象上的操作
    os << s             将s写到输出流os当中，返回os
    is >> s             从is中读取字符串赋给s，字符串以空白分隔，返回is
    getline(is,s)       从is中读取一行赋给s，返回false
    s.size()            返回s中的字符的个数
    s[n]                返回s中第n个字符的引用，位置n从0记
    s1 + s2             返回s1 与 s2 连接
    s1 = s2             用s2的副本代替s1中原来的字符
    s1 == s2            如果s1和s2所含的字符完全一样，则他们相等；
    <,<=,>,>=           利用字符在字典中的顺序进行比较，且对字母的大小写敏感

    string对象会自动忽略开头的空白，并从第一个真正的字符开始读，直到遇见下一处空白为止。
    string对象的此类操作也是返回运算符左侧的运算对象作为其结果。
        string s1，s2；
        cin >> s1 >> s2;

    读取未知数量的string对象
    使用getline读取一整行
        有时我们希望能在最终得到的字符串中保留输入时的空白符，使用getline函数代替原来的>>运算符。
        getline函数的参数是一个输入流和一个string对象，

    比较string对象
        string类定义了几种用于比较字符串的运算符，这些运算符逐一比较string对象中的字符，并且对大小写敏感

    位string对象赋值
        在设计标准库类型时都力求在易用性上向内置类型看齐。string允许把一个对象的值赋给另外一个对象

    字面值和string对象相加
        标准库允许把字符字面值和字符串字面值转换成string对象
        当把string对象和字符字面值混在一条语句中使用时，必须确保每个加法运算符的两侧运算对象至少一个是string：
            string s4 = s1 + ”, "；                   //正确: 把一个string对象和一个字面值相加
            string s5 = “hello” + “ ，”               //错误：两个运算对象都不是string
            string s7 = “hello” + “， ” + s2；        //错误：不能把字面值直接相加
            string s6 = （s1+“， ”） +　“ world ”；    //正确

3.2.3 处理string对象中的字符
    cctype头文件中定义了一组标准库函数处理这部分工作

    处理每个字符？使用基于范围的for语句
        这种语句遍历给定序列中的每个元素并对序列中的每个值执行某种操作：
            for (declaration : expression)
                statement
        expression 部分是一个对象，用于表示一个序列。declaration负责定义一个变量，该变量将被访问序列中的基础元素
        每次迭代，declaration部分的变量会被初始化为expression部分的下一个元素值

    只处理一部分字符
        两种方式：使用下标，使用迭代器


3.3 标准库类型 vector
    标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有与之对应的索引，索引用于访问对象。
    因为vector容纳着对象，所以它也常常被称作为容器container

    模板本身不是类或函数，相反可以将模板看作为编译器生成类或函数编写的一份说明
    编译器根据模板创建类或函数的过程称为 实例化instantiation，当使用模板时，需要指出编译器把类或函数实例化成何种类型

    对于类模板，我们通过提供一些额外信息来指定模板到底实例化成什么样的类，需要提供哪些信息由模板决定。
    提供信息的方式：在模板名字后面跟一对尖括号，在括号内放上信息

        vector<int> ivec;                //ivec保存int类型的对象
        vector<Sales_item> Sales_vec;    //保存Sales_item类型的对象
        vector<vector<string>> file;     //该向量的元素是vector对象
    vector能容纳绝大多数类型的对象作为其元素，但是引用不是对象，所以不存在包含引用的vector。
    初始化vector对象的方法
        vector<T> v1                //默认初始化，v1不含任何元素
        vector<T> v2(v1)            //v2包含有v1所有元素的副本
        vector<T> v2 = v1
        vector<T> v3(n , val)       //v3包含了n个重复的元素，每个元素的值都是val
        vector<T> v4(n)
        vector<T> v5{a,b,c...}
        vector<T> v5 = {a,b,c...}

        vector<int> ivec3 = ivec;    //把ivec的元素拷贝给ivec3

    值初始化
        vector<int> v1(10);       //10个元素，每个初始化为0
        vector<int> v2{10};       //1个元素，这个元素值位10

3.3.2 向vector对象中添加元素
    直接初始化的方式适用于三种情况：
        初始值已知且数量较少，初始值是另一个vector对象的副本，所有元素的初始值都一样
    更常见是：创建一个vector对象并不知道实际所需的元素个数，值也无法确定
    push_back向其中添加元素。push_back负责把一个值当成vector对象的尾元素push到vector的尾端

3.3.3 其他vector操作
    除了push_back,还有其他操作
    访问vector对象中元素的方法和string对象中字符串差不多.例如,可以使用范围for语句处理vector对象中所有元素
        for (auto &i : v)   //对v中的每个元素
    empty检查vector对象是否包含元素然后返回一个布尔值;
    size则返回vector对象中元素的个数,返回类型是vector定义的size_type类型
        vector<int> :: size_type    //正确
        vector :: size_type         //错误
    不能用下标形式添加元素
        vector<int> ivec ;  //空vector对象
        for ( decltype(ivec.size()) ix = 0 ; ix != 10 ; ++ix)
            ivec[ix] = ix ;     // error:ivec 不包含任何元素

3.4迭代器介绍
    现在知道可以用下标运算符来访问string对象的字符或vector的元素,
    还有另一种更通用的机制也可以实现该目的:    迭代器 iterator
    所有的标准库容器都可以使用迭代器,但是只有其中少数几种才同时支持下标运算符

3.4.1使用迭代器
    获取迭代器不是使用取地址符,有迭代器的类型同时拥有返回迭代器的成员
    比如,这些类型都拥有begin和end成员,其中begin负责返回指向第一个元素的迭代器
        //由编译器决定b和e的类型
        //b表示v的第一个元素,e表示v尾元素的下一位置
        auto b = v.begin() , e = v. end(); //b和e类型同
    如果容器为空,则begin和end返回的是同一个迭代器,都是尾后迭代器
    迭代器运算符
        *iter           返回迭代器iter所指元素的引用
        iter -> mem     解引用iter并获取该元素的名为men的成员,等价于(*iter).men
        ++iter          令iter指容器的下一个元素
        --iter
        iter1 == iter2  判断俩个迭代器是否相等,如果两个迭代器指示的是同一个元素或者
                        它们是同一个容器的尾后迭代器,则相等
    将迭代器从一个元素移动到另外一个元素
        使用++运算符来从一个元素移动到下一个元素
        因为end返回的迭代器并不实际指示某个元素,所以不能对其进行递增或解引用的操作
        将一个单词改写成大写形式,现在利用迭代器及其递增运算符可以实现相同的功能:
            for (auto it = s.begin(); it != s.end() && !isspace(*it) ; ++it)
                *it = toupper(*it);     //将当前字符改成大写形式
        循环首先用s.begin的返回值来初始化it,意味着it指示的是s中的第一个字符
     迭代器类型
        vector <int> :: iterator it ;       //it能读写vector<int>的元素
        string:: iterator it2;              //it2能读写string对象中的字符
        vector<int>::const_iterator it3;    //it4只能读字符,不能写
    结合解引用和成员访问操作
        解引用迭代器可获得迭代器所指的对象,如果该对象的类型恰好是类,就有可能希望进一步访问它的成员
        例如,对于一个由字符串组成的vector对象来说,要想检查其元素是否为空,令it是该vector对象的迭代器,
        只需检查字符串是否为空就ok了
            (*it).empty()
            *it.empty()         //试图访问it的名为empty的成员,但it是个迭代器
         上面第二个表达式的含义是从名为it的对象中寻找其empty,显然it是一个迭代器..么有那个成员叫empty
         ->运算符把解引用和成员访问两个操作结合在一起,及it->mem和(*it).mem表达意思相同
    迭代器的算术运算
        下面代码得到一个迭代器,它指向某vector对象中间位置的元素:
            auto mid = vi.begin() + vi.size() / 2;
            if( it < mid )  //处理vi前半部分的元素

3.5数组
    显式初始化数组元素
        string a4[3] = {"hi" , "bye"};  //等价于 a4[] = {"hi","bye",""}
    字符数组的特殊性
        char a1[] = {'c' , '+' , '+'};  //列表初始化,没有空字符
        char a2[] = {'c','+','+' ,'\0'};//列表初始化,含有显式空字符
        char a3[] = "c++";              //自动添加表示字符串结束的空字符
        const char a4[6] = "Daniel";    //错误:没有空间可放空字符!
    不允许拷贝和赋值
        不能将数组的内容拷贝给其他数组作为其初始值,也不能用数组为其他数组赋值
    理解复杂的数组声明
        int *arr[10];           //arr是含有10个整型指针的数组
        int &refs[10] =...      //error:不存在引用的数组
        int (*parr)[10]= &arr;  //parr指向一个含有10个整数的数组
        int (&rarr)[10]=arr;    //rarr引用一个含有10个整数的数组
    理解数组声明的含义,最好是从数组的名字开始安照由内向外的顺序阅读
指针和数组
    string nums[] = {"aa","bb","cc"};   //数组二点元素是string对象
    string *p = &nums[0];               //p指向nums的第一个元素\
    string *p2 = nums;                  //等价于上面这个
    指针也是迭代器
        int arr[] = {0,1,2,3,4,5,6,7,8,9};
        int *p = arr ;                  //p指向arr的第一个元素
        int *e = &arr[10];
        for(int *b = arr; b != e; ++b)
            cout << *b << endl;
    标准库函数begin 和 end
        c++11新标准引入了两个名为begin和end的函数.这两个函数与容器中的两个同名成员功能类似
        不过数组毕竟不是类类型,因此这两个函数不是成员函数,正确的使用因素是将数组作为其参数
            int ia[] = {1,2,3};
            int *beg = begin(ia);   int *last = end(ia);
3.5.4 C风格的字符串
    字符串字面值是一种通用结构的实例,这种结构即是C++由C继承而来的C风格字符串
    c风格字符串不是一种类型,而是为表达和使用字符串而形成的一种约定俗成的写法.
    按此习惯书写的字符串存放在字符数组中并以空字符结束('\0')
    c标准库String函数
        cstring 是c语言头文件String.h的c++版本
            strlen(p)
            strcmp(p1,p2)
            strcat(p1,p2)       //将p2附加到p1后,返回p1
            strcpy(p1,p2)       //将p2拷贝给p1,返回p1
        传入此类函数的指针必须指向以空字符作为结束的数组
            char ca[] = {'c','+','+'};  //不以空字符结束
            cout << strlen(ca) << endl; //error
3.5.5 与旧代码的接口
    混用string对象和C风格字符串
        任何出现字符串字面值的地方都可以用以字符结束的字符数组来替代:
            允许使用以空字符结束的字符数组来初始化string对象或为string赋值
            string对象的加法运算中允许使用以空字符结束的字符数组作为其中一个运算对象
    使用数组初始化vector对象
        不允许用一个vector对象初始化数组.相反,允许使用数组来初始化vector对象.
            int int_arr[] = {0, 1,2,3};
            vector<int> ivec(begin(int_arr), end(int_arr));
            vector<int> subvec(int_arr+1, int_arr+5)

3.6多维数组
    多维数组初始化
        int ia[3][4] = {{0},{4},{8}};          //显式地初始化每行的首元素
        int ib[3][4] = {0,3,6,9};             //初始化第一行4个,其他元素被初始化为0










*/
