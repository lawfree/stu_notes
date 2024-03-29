#include <iostream>

using namespace std;

int main (){


}

/*
动态内存

全局对象在程序启动时分配,在程序结束时销毁.对于局部自动对象,当我们进入其定义所在的程序时被创建,在离开时被销毁.
除了自动和static对象外,C++还支持动态分配对象.动态分配的对象与他们在哪里创建是无关的,只有当显示地被释放,这些对象才被销毁
为了更安全地使用动态对象,标准库定义了两个智能指针类型来管理动态分配的对象.当一个对象应该被释放时,指向它的智能指针可以确保自动地释放它.

我们的程序目前为止只使用过静态内存或栈内存.
    静态内存用来保存局部static对象,类static数据成员以及定义在任何函数之外的变量.        分配在静态或栈内存中的对象由编译器自动创建和销毁 
    栈内存用来保存定义在函数内的非static对象.                                      对于栈对象,仅在其定义的程序块运行时才存在.     
    
    除了静态内存和栈内存,每个程序还拥有一个内存池.这部分内存被称为自由空间或堆.程序用堆来存储动态分配的对象--即,那些在程序运行时分配的对象.
    动态对象的生存周期由程序来控制,即当动态对象不再使用时,我们的代码必须显式地销毁它们.

12.1 动态内存与智能指针
    C++中动态内存的管理是通过一对运算符来完成: 
        new,在动态内存中为对象分配空间并返回一个指向该对象的指针,我们可以选择对对象进行初始化;
        delete,接受一个动态对象的指针,销毁该对象,并释放与之关联的内存
    为了更容易(也更安全)地使用动态内存,新的标准库提供了两种智能指针(smart pointer)类型来管理动态对象.
    只能指针的行为类似常规指针,区别是他负责自动释放所指向啊的对象.新标准库提供的这两种只能指针的区别管理底层指针的方式:
        shared_ptr 允许多个指针指向同一个对象; unique_ptr 则"独占"所有的对象
    weak_ptr伴随类,它是一种弱引用,指向shared_ptr所管理的对象.
12.1.1 shared_ptr 类    
    类似vector,智能指针也是模板.因此,当我们创建一个智能指针时,必须提供额外的信息 -- 指针可以指向的类型. 
        shared_ptr<string>  p1;         //shared_ptr 可以指向string
        shared_ptr<list<int> > p2;
    智能指针使用方式与普通指针类似.解引用一个智能指针返回他所指向的对象.
        //如果p1不空,检查它是否指向一个空string
        if(p1 && p1 -> empty())
            *p1 = "h1";     //如果p1指向一个空string,解引用p1,将一个新值赋予string
                    shared_ptr 和 unique_ptr都支持的操作
        shared_ptr<T> sp       空智能指针,可以指向类型为T的对象
        unique_ptr<T> up
        p                       将p用作一个条件判断,若p指向一个对象,则为true
        *p                      解引用p,获得其指向的对象
        p->mem                  等价于(*p).mem
        p.get()                 返回p中保存的指针
        swap(p,q)               交换p和q中的指针
        p.swap(q)

    make_shared 函数
        最安全的分配和使用动态内存的方法是调用一个名为make_shared的标准库函数.此函数在动态内存中分配一个对象并初始化它,返回指向此对象的shared_ptr.
        与智能指针一样,make_shared 也定义在头文件memory中        
            //指向一个值为42的int的shared_ptr
            shared_ptr<int> p3 = make_shared<int>(42);
    shared_ptr的拷贝和赋值
        当进行拷贝或赋值操作时,每个shared_ptr都会记录有多少个其他shared_ptr指向相同的对象:
            auto p = make_shared<int>(42);      //p指向的对象只有一个引用者
            auto q(p);      //p和q指向相同对象,此对象有两个引用者
        我们可以认为每个shared_ptr 都有一个关联的计数器,通常称其为引用计数.无论何时我们拷贝一个shared_ptr,计数器都会递增.
        一旦一个shared_ptr 离开其作用域,计数器就会递减.计数器变为0,就会自动释放自己所管理的对象:

直接管理内存
    两个运算符来分配和释放动态内存.运算符new分配内存,delete释放new分配的内存.
    使用new动态分配和初始化对象
        在自由空间分配的内存是无名的,因此new无法为其分配的对象命名,而是返回一个指向该对象的指针:
            int *pi = new int;      //pi 指向一个动态分配的,未初始化的无名对象
        此new表达式在自由空间构造一个int型对象,并返回指向该对象的指针.
        默认情况下,动态分配的对象是默认初始化的,这意味着内置类型或组合类型的值将是未定义的,而类类型对象将用默认构造函数进行初始化:
            string *ps = new string;    //初始化空string
        我们可以使用直接初始化方式来初始化一个动态分配的对象.我们可以使用传统的构造翻上,新标准下,也可以使用列表初始化(花括号)
            int *pi = new int(1024);
            string *ps = new string(10, '9');
            vector<int> *pv = new vector<int>{0,1,2}
        也可以对动态分配的对象进行值初始化,只需在类型名之后跟一对空括号:
            string *ps1 = new string;       //默认初始化为空string
            string *ps = new string();      //值初始化为空string
            int *pi1 = new int;             //默认初始化; *pi1 的值未定义
            int *pi2 = new int();           //值初始化为0; *pi2为0
        对于定义了自己的构造函数的类类型(如string),要求值初始化是无意义的;不管采用什么形式,对象都会通过默认构造函数来初始化.
        但对于内置类型,两种形式的差别就很大了;值初始化的内置对象有良好定义的值.而默认初始化的对象的值则是未定义的.
        类似的,对于类中那些依赖于编译器合成的默认构造函数的内置类型成员,如果它们未在类内被初始化,那么他们的值也是未定义的
            出于与变量初始化相同的原因,对动态分配的对象进行初始化通常是好主意
        
        

        

 */