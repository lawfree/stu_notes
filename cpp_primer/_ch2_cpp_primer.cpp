#include<iostream>

using namespace std;


int main(){

    // unsigned u = 10 , u2 = 42 ; 
    // std :: cout << u2 - u << std :: endl;   //32
    // std :: cout << u - u2 << std :: endl;   //big positive

    // int i = 10 , i2 = 42 ;
    // cout << i2 - i << endl; //32
    // cout << i - i2 << endl; //-32
    // cout << i - u << endl;  //0
    // cout << u - i << endl;  //0

    // int local_int ;     cout << local_int << endl;  // 0
    // string local_str;   cout << local_str << endl;  // " "
/*******************************/
    // int i =10 ;
    // int &refi = i; cout << refi <<endl; //10
    // int &refi2 = refi ; 

    // i++;    cout << refi << endl;   //11
    // i++;    cout << refi2 << endl;  //12

    // refi++; cout << i << endl;      //13   作用在引用上，对i本身也有影响
 /******************************/   
    /* const */
    const int ci = 1024;
    const int ci2 = 1025;
    //int &r1 = ci;         //error: binding ‘const int’ to reference of type ‘int&’ discards qualifiers
    const int &r1 = ci;     //ok
    //r1 = ci2;               // error: assignment of read-only reference ‘r1’

    int i = 42;
    int &r3 = i ; 
    const int &cr4 = i;         //cr4 也绑定对象i，但是不允许通过cr4修改i的值
    r3 = 0 ;                // now ， i = 0
    //cr4  = 0 ;             //error: assignment of read-only reference ‘cr4’
 /******************************/   


    return 0 ;
}
/*
p39 2.2 
术语： 何为对象？
    通常情况下，对象是指一块能存储数据并具有某种类型的内存空间
    本书遵循大多数人的习惯用法，认为对象是具有某种数据类型的内存空间。我们使用对象这个词时，
    不严格区分是类还是内置类型，也不区分是否命名或是否只读。

初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值，而赋值的含义是把对象当前值擦除，而以一个新值代替
 
为了支持分离式编译，C++语言将声明和定义区分。
    声明使得名字为程序员所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。
    定义负责创建与名字关联的实体。
变量声明规定了变量的类型和名字，这一点和定义与之相同。但除此之外，定义还申请存储空间，也可能会位变量附一个初始值。
如果想声明一个变量而非定义它，就在变量名前添加关键字extern，而且不要显示地初始化变量：
    extern int i；  //声明i而非定义 i
    int j ；        //声明并定义 j
在函数题内部，如果试图初始化一个由extern关键字标记的变量，将引发错误。
 */

/*
2.3 复合类型
    复合类型是指基于其他类型定义的类型。本章介绍其中两种：引用 和 指针
    一条声明语句由一个基本数据类型和紧随其后的一个声明符declarator列表组成。每个声明符命名了一个变量并指定变量为与基本数据类型有关的某种类型
    目前，所接触的声明语句中，声明符其实就是变量名，此时变量的类型也就是声明的基本数据类型。

引用
    引用为对象起了另外一个名字，引用类型引用refers to另外一种类型。
    通过将声明符写成 &d 的形式来定义引用类型，其中 d 是声明的变量名：
        int ival = 1024；
        int &refVal = ival；    //refVal 指向ival （是ival 的另一个名字）
    一般在初始化变量时，初始值会被拷贝到新建的对象中。然而定义引用时，程序把引用和它的初始值绑定bind到一起，而不是将初始值拷贝给引用。
    一旦初始化完成，引用将和它的初始值对象一直绑定在一起，因为无法令引用重新绑定到另一个对象，因此引用必须初始化。

    引用并非对象，相反的，它只是为一个已经存在的对象所起的另外一个名字。

    int &refVal4 = 10 ；    //错误：引用类型的初始值必须是一个对象

指针
    某些符号有多重含义
        int i = 42 ；
        int &r = i ;    //紧跟类型名出现，因此是声明的一部分，r是一个引用
        int *p ;        //紧跟类型名出现，因此是声明的一部分，p是一个指针
        p = &i ;        //出现在表达式中，是一个取地址符
        *p = i ;        //出现在表达式中，是一个解引用符号
        int &r2 = *p;   //&是声明的一部分，*是以解引用符号

指向指针的引用
    引用本身不是一个对象，因此不能定义指向引用的指针。但是指针是对象，所以存在对指针的引用：
        int i = 42;
        int * p;        //p是一个int型指针
        int *&r = p ;   //r是一个对指针p的引用

        r = &i;         //r引用了一个指针，因此给r赋值&i 就是令p指向i
        *r = 0 ;        //解引用r得到i，也是p指向的对象，将i的值改为0
    从右往左阅读有助于弄清楚它的真正含义

2.4 const限定符
    默认状态下，const对象仅在文件内有效
        当以编译时初始化的方式定义一个const对象时，就如对bufSize的定义一样：
            const int bufSize = 512 
        编译器将在编译过程中把用到该变量的地方都替换成为对应的值。
        有时有这样一种const变量，它的初始值不是一个常量表达式，但又确实有必要在文件间共享。
        我们想，只在一个文件中定义const，而在其他多个文件中声明并使用它。
            解决的办法：对于const变量不管是声明还是定义都添加extern关键字，这样只需定义一次就ok了
 
const的引用
    可以把引用绑定到const对象上，就像绑定到其他对象上一样。与普通不同的是，对常量的引用不能被用作修改它所绑定的对象：
        const int ci = 1024；
        const int &r1 = ci;     //正确：引用及其对应的对象都是常量
        r1 = 42 ；              //错误： r1是对常量的引用
        int &r2 = ci            //错误：试图让一个非常量引用指向一个常量对象
    术语：常量引用是对const的引用
        对const的引用 简称为 常量引用
        不允许随便改变引用所绑定的对象，所以这层意思上理解所有的引用又都算常量
    
指针和const
    指向常量的指针不能用于改变其所指对象的值，要想存放常量对象的地址，只能使用指向常量的指针：
        const double pi = 3.14 ;   // pi is a const value,其值不能变
        double* ptr = &pi;         // c错误： ptr是一个普通指针
        const double *cptr = &pi ; //正确：cptr可以指向一个double常量
        *cptr = 42 ;               //错误：不能给*cptr赋值
    和常量引用一样，指向常量的指针也没有规定其所指的对象必须是一个常量，
    所谓指向常量的指针仅仅要求不能通过该指针改变对象的值，而没有规定那个对象的值不能通过其他途径改变

    const指针
        指针是对象而引用不是，因此允许把指针本身定为常量。常量指针必须初始化，而且初始化一旦完成，则它的值（地址）就不能变了
        把*放在const之前说明指针是个常量    
                int errNumb = 0 ;
                int *const curErr = &errNumb ;  //curErr将一直指向errNumb
                const double pi = 3.14150926；
                const double *const pip = &pi；  //pip是一个指向常量对象的常量指针

constexpr和常量表达式
    常量表达式是指值不会改变并且在编译过程就能得到计算结果的表达式。
    显然，字面值属于常量表达式，用常量表达式初始化的const对象也是常量表达式。
    constexpr变量
        声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化：

2.5处理类型
2.5.1 类型别名
    别名声明来定义类型的别名：
        using SI = Sales_item； //SI是Sales_item的同义词
    指针，常量和类型别名
        typedef char *pstring;
        const pstring cstr = 0  //cstr是指向char的常量指针
        const char *cstr = 0 ;  //是对const pstring的错误理解
        const pstring *ps；     //ps 是一个指针，他的对象是指向char的常量指针

2.5.2
    auto类型说明符，用它能让编译器替我们去分析表达式所属的类型。

2.5.3 decltype 类型指示符
    有时会遇到这种情况：希望从表达式的类型推断出要定义的变量类型，但是不想用该表达式的值初始化变量。
    decltype。其作用是选择并返回操作数的数据类型。此过程中，编译器分析表达式并得到它的类型，却不实际计算表达式的值
        decltype(f()) sum = x;  //sum的类型就是函数f的返回类型

*/