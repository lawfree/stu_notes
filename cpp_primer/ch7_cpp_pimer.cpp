#include <iostream>
#include <vector>

using namespace std;
using std::vector;
class Sales_data {
    friend Sales_data add (const Sales_data&, const Sales_data&);
    friend ostream &print(ostream&, const Sales_data&);
    friend istream &read (istream&, Sales_data&);
public:    
    //新增的构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s){ }
    Sales_data(const std::string &s , unsigned n , double p):
        bookNo(s) , units_sold(n) , revenue(p*n){ }
    Sales_data(std :: istream &);       

    //成员:关于Sales_data对象的操作
    string isbn() const {return bookNo; }

    Sales_data& combine (const Sales_data&);
private:
    double avg_price() const;
    //定义在类内部的函数是隐式的inline函数

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// struct Sales_data 
// {
//     //新增的构造函数
//     Sales_data() = default;
//     Sales_data(const std::string &s) : bookNo(s){ }
//     Sales_data(const std::string &s , unsigned n , double p):
//         bookNo(s) , units_sold(n) , revenue(p*n){ }
//     Sales_data(std :: istream &);       

//     //成员:关于Sales_data对象的操作
//     string isbn() const {return bookNo; }
//     Sales_data& combine (const Sales_data&);
//     double avg_price() const;
//     //定义在类内部的函数是隐式的inline函数

//     string bookNo;
//     unsigned units_sold = 0;
//     double revenue = 0.0;
// };
// Sales_data 的非成员接口函数


Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;   //把rhs的成员加到this对象成员上
    revenue += rhs.revenue;
    return *this;                   //返回调用该函数的对象
}
double Sales_data::avg_price() const {
    if(units_sold)  return revenue / units_sold;
    else    return 0;    
}

//输入的交易信息包括ISBN,售出总数和售出价格
istream &read (istream &is,Sales_data &item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price ; 
    item.revenue = price * item.units_sold;
    return is;
}
ostream &print(ostream &os, const Sales_data &item){
    os  << item.isbn() << " " << item.units_sold << " "
        << item.revenue << " " << item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs , const Sales_data &rhs){
    Sales_data sum = lhs;       //把lhs的数据成员拷贝给sum
    sum.combine(rhs);           //把rhs的数据成员加到sum中
    return sum;
}

Sales_data::Sales_data(std::istream &is){
    read (is , *this);  //read 函数作用是从is中读取一条交易信息后存入this对象中
}

int main(){

}
/*
本章主要关注数据抽象的重要性.其能帮助我们将对象的具体实现与对象所能执行的操作分离开来.
类的基本思想是数据抽象(data abstraction)分离的编程(以及设计)技术.类的接口包括用户所能执行的操作;
类的实现则包括类的数据成员,负责接口实现的函数体以及定义类所需的各种私有函数

7.1 定义抽象数据类型
设计Sale_data类
    Sales_data 的接口应该包含以下操作:
     一个isbn成员函数,用于返回对象的ISBN编号
     一个combine成员函数,用于将一个Sales_data对象加到另一个对象上
     一个名add的函数,执行两个Sales_data对象的加法
     一个print函数,将Sales_data对象的值输出到ostream
    定义成员函数
        所有的成员都必须在类的内部声明,但是成员函数体可以定义在类内部也可以定义在类外.
        对于Sales_data类来说,isbn函数定义在了类内,而combine 和 avg_price定义在了类外.
        首先介绍isbn函数,其参数列表为空,返回值是一个string对象:
            string isbn() const { return bookNo; }
        块里面只有一条return语句,用于返回Sales_data对象的bookNo数据成员.它是如何获得bookNo成员所依赖的对象的?
    引人 this
        当我们调用成员函数时,实际上是在替某个对象调用它.如果isbn指向Sales_data的成员,则它隐式地指向调用该函数的对象的成员
        比如total.isbn(),隐式返回total.bookNo
        成员函数通过一个名为this的额外的隐式参数来访问调用它的那个对象.当我们调用一个成员函数时,用请求该函数的对象地址初始化位this
            total.isbn()
        编译器负责把total的地址传递给isbn的隐式形参this,可以等价地认为编译器将该调用重写为:
            Sales_data:: isbn(&total)        //伪代码
        其中,调用Sales_data的isbn成员时传入了total的地址
        在成员函数内部,可以直接使用调用该函数的对象的成员,而无须通过成员访问运算符来做到这一点,因为this正是指向这个对象.
        任何对类成员的直接访问都被看作this的隐式引用,此时当isbn使用bookNo时,隐式使用了this指向的成员,就像我们写 this->bookNo
        this的目的总是指向"这个"对象,所以this是一个常量指针    
    引入const成员函数
        默认情况下,this的类型是指向类类型非常量版本的常量指针.例如Sales_data成员函数中,this的类型是Sales_data *const .
        尽管this是隐式的,但仍然需要满足初始化规则,意味着不能把this绑定到一个常量对象上.也使得我们不能在一个常量对象上调用普通的成员函数
        如果isbn是个普通函数并且this是一个普通的指针参数,则我们应该把this声明长const Sales_data *const.
        毕竟在isbn的函数体内部不会改变this所指的对象,所以把this设置为指向常量的指针有助于提高函数灵活性

        然而this是隐式故不会出现在参数列表.C++是允许把const关键字放在成员函数的参数列表之后,
        此时,紧跟在参数列表后面的const表示this是一个指向常量的指针.
        像这样使用const的成员函数被称作 常量成员函数const member function
            //可以向下成下面这种形式,伪代码,下面代码非法,因为不能显式定义自己的this
            //谨记此处的this是一个指向常量的指针,因为isbn是一个常量成员
            string Sales_data::isbn(const Sales_data *const this){return this -> isbn ;}
        常量对象,常量对象的引用或指针都只能调用常量成员函数
    类作用域和成员函数
        isbn中用到的名字其实就是定义在Sales_data内部的数据成员.
        即使bookNo定义在isbn之后,isbn也还是能够使用bookNo(编译器分两步处理类:首先编译成员的声明,然后才轮到成员函数体)
    在类的外部定义成员函数
        当在类的外部定义函数时,成员函数的定义必须与它的声明匹配.如果成员被声明成常量成员函数,则它的定义也必须在参数列表后明确指定cosnt
        同时,类外部定义的成员的名字必须包含它所属的类名:
            double Sales_data::avg_price() const {
                if(units_sold)  return revenue / units_sold;
                else    return 0;    
            }
    定义一个返回this对象的函数
        函数combine的设计初衷类似于复合赋值运算符+=,调用该函数的对象代表是赋值运算符左侧的运算对象,右侧运算对象则通过显示的实参传入函数:
        当我们的交易处理程序调用如下的函数时,
            total.combine(trans);           // 更新变量total当前的值
        total的地址被绑定到隐式的this参数上,而rhs绑定到了trans上.因此,当combine执行下面语句
            units_sold += rhs.units_sold;   //把rhs的成员添加到this对象的成员中
        我们无需使用隐式的this指针访问函数调用者的某个具体成员,而是需要把调用函数的对象当成一个整体来访问:
            return * this;                  //返回调用该函数的对象
        return 语句解引用this 指针以获得执行该函数的对象,也即是说,上面的这个调用返回total的引用.
    定义类相关的非成员函数
        类的作者常常需要定义一些辅助函数,比如add,read,print等.这些本身实际上并不属于类本身.
        定义非成员函数的方式与定义其他函数一样,通常把函数的声明和定义分离开.
        如果函数在概念上属于类但是不定义在类中,则它一般应与类声明在同个头文件内,\.

        一般来说,如果非成员函数是类接口的组成部分,则这些函数的声明应该与类在同一个头文件内
    定义read 和 print 函数
        read 函数从给定流中将数据读到给定的对象里,print函数则负责将给定对象的内容打印到给定流中.
        还有两点重要的:
        1. read 和 print 分别接受一个各自IO类型的引用作为其参数,这是因为IO类属于不能被拷贝的类型,因此只能通过引用来传递它们
            而且因为读取和写入操作会修改流的内容,所以两个函数接受的都是普通引用,而非对常量的引用.
        2. print函数不负责换行,一般,执行输出任务的函数应该尽量减少对空格的控制,以确保用代码决定是否换行.
    定义add函数
        接受两个Sales_data对象作为其参数,返回值是一个新的Sales_data,用于表示前两个对象的和:
        函数体中定义了一个新的Sales_data对象并将其命名为sum,用于存放两笔交易和,我们用lhs的副本来初始化sum.
        默认情况下,拷贝类的对象其实拷贝的是对象的数据成员.在拷贝完成后,sum的bookNo等和lhs一致.
        接下来调用combine函数,将rhs的units_sold和revenue添加给sum.最后返回sum副本.
7.1.4构造函数
    类通过一个或几个特殊成员函数来控制其对象的初始化过程,这些函数称为构造函数 construtor
    构造函数和其他函数不一样的是.其没有返回类型;除此之外类似于其他的函数,构造函数也有一个参数列表和一个函数体.
    不同的构造函数之间必须在参数数量或参数类型上有所区别.
    构造函数不能被声明成const
    合成的默认构造函数
        我们的Sale_data类并未写构造函数,但之前使用了Sales_data.
            Sales_data total;       //保存当前和结果的变量
            Sales_data trans;       //保存下一条交易数据的变量
        如果类没有显式地定义constructor,那么编译器就会为我们隐式地定义一个默认construtor
        编译器创建的构造函数又被称为合成的默认构造函数.按如下规则初始化类的数据成员:
            如果存在类内的初始值,用它来初始化成员
            否则,默认初始化该成员
    某些类不能依赖合成的默认构造函数
        有些情况必须定义它自己的默认construtor,原因:
        1.只有在发现类不包含任何construtor的情况下才会帮我们生成一个默认的构造函数.一旦我们定义了一些其他的构造函数,类将没有了默认构造函数
        2.合成的默认构造函数可能执行错误的操作.
            如果类含有内置类型或复合类型的成员,则只有当这些成员全部都被赋予了类内的初始值时,这个类才适合于使用合成的默认构造函数.
        3.有时编译器不能位某些类合成默认的构造函数.例如类中包含一个其他类类型的成员且这个成员的类型无默认构造函数
    定义Sales_data的构造函数
        4个不同的构造函数:
            一个istream& , 从中读取一条信息
            一个const string&, 表示ISBN编号; 一个unsigned,表示售出的图书数量,以及一个double,表示图书售出价格
            一个const string &,表示ISBN;编译器将赋予其他成员默认值
            一个空参数列表(即默认构造函数).
    = default 的含义
        我们希望这个函数的作用完全等同于之前使用的合成默认构造函数.
        C++11中,如果我们需要默认的行为,那么可以通过在参数列表后写上 = default 来要求编译器构造函数.
        如果 = default 在类的内部,则默认构造函数是内联的;如果它在类的外部,则该成员默认情况是不内联的.

        上面的默认构造函数之所以对Sales_data有效,是因为我们为内置类型的数据成员提供了初始值.
        如果你的编译器不支持类初始值,那么构造函数就应该使用构造函数初始化值列表来初始化类的每个成员
    构造函数初始值列表
            Sales_data(const std::string &s):bookNo(s){}
            Sales_data(const std::string &s , unsigned n , double p):
                bookNo(s) , units_sold(n) , revenue(p*n){ }                 
        这两个定义中出现了新的部分,即冒号以及冒号和花括号之间的代码,其中花括号定义了(空的)函数体.我们把新出现的部分称为 构造函数初始值列表
        含有三个参数的构造函数分别使用它的前两个参数初始化成员bookNo和units_sold,revenue的初始值则通过将售出图书总数和每本书单价相乘得到
        只有一个string类型参数的构造函数使用这个string对象初始化bookNo,对于units_sold和revenue没有显示地初始化..他将以合成默认构造函数方式
            //与上面那个构造函数相同
            Sales_data(const std :: string &s):bookNo(s), units_sold(0),revenue(0){ }
        上面两个构造函数中函数体都是空的.这是因为这些构造函数的唯一目的就是为数据成员赋初始值    
    在类外部定义构造函数
        与其他构造函数不同,以istream为参数的构造函数需要执行一些实际操作.在他的函数体内,调用了read函数以给数据成员赋初值
        构造函数没有返回类型,所以定义从指定的函数名开始.

        这个构造函数没有构造函数初始值列表.尽管构造函数初始值列表是空的,但是由于执行了构造函数体,所以对象成员仍然能被初始化
拷贝,赋值和析构
    除了定义类的对象如何初始化之外,类还需要控制拷贝,赋值和销毁对象时发生的行为.
    对象在几种情况下会被拷贝,如初始化,如我们初始化变量以及以值的方式传递或返回一个对象等.
    当我们使用了赋值运算符时会发生对象的赋值操作.
    当对象不再存在时执行销毁操作,比如一个局部对象会在创建它的块结束时被销毁,当vector对象销毁时存储在其中的对象也会被销毁.
    当我们不主动定义这些操作,编译器替我们合成它们.如"
    某些类不能依赖于合成的版本
        尽管编译器能替我们合成拷贝,赋值.销毁操作,但是对于某些类来说合成版本不能正常工作.

7.2 访问控制与封装
    目前我们已经为类定义了接口,但并无任何机制强制用户使用这些接口,用户可以直达Sales_data并控制它的具体细节.
    在C++中我们使用访问说明符号access specific 加强类的封装性:
        定义在public说明符之后的成员在整个程序内可被访问,public成员定义类的接口
        定义在private说明符之后的成员可以被类的成员函数访问,但是不能被使用该类的代码访问,private部分隐藏(封装)了类的实现细节
            class Sales_data {
            public:
                //新增的构造函数
                Sales_data() = default;
                Sales_data(const std::string &s) : bookNo(s){ }
                Sales_data(const std::string &s , unsigned n , double p):
                    bookNo(s) , units_sold(n) , revenue(p*n){ }
                Sales_data(std :: istream &);       

                //成员:关于Sales_data对象的操作
                string isbn() const {return bookNo; }
                Sales_data& combine (const Sales_data&);
                double avg_price() const;
                //定义在类内部的函数是隐式的inline函数
            private:
                string bookNo;
                unsigned units_sold = 0;
                double revenue = 0.0;
            };
    作为接口的一部分,构造函数和部分成员函数紧跟在public说明符之后;而数据成员和作为实现部分的函数则跟在private说明符后面          
    而数据成员和作为实现部分的函数则在private说明符后面
    使用class或struct关键字
        唯一的区别是,struct和class默认访问权限不太一样
        类可以在它的第一个访问说明符之前定义成员,对这种成员的访问权限依赖于类定义方式
        我们希望定义的类的所有成员是public时,用struct;反之希望成员是private,使用class
友元
    友元函数可以访问类的 private 和 protected 成员。
    既然Sales_data 的数据成员是private的,我们的read,print和add函数就无法正常编译,因为尽管这几个函数函数是类的接口的一部分,但它们不是类成员
    类可以允许其他类或者函数访问它的非公有函数,方法是令其他类或函数成为它的友元.
    如果类想把一个函数作为它的友元,只需要增加一条friend关键字开始的函数声明语句:
    友元声明只能出现在类定义的内部,但是在类内出现的具体位置不限.友元不是类的成员也不受它所在区域访问控制级别的约束.
    一般来说,最好在类定义开始或结束前的位置集中声明友元.

    封装的益处
        确保用户代码不会无意间破坏封装对象的状态.
        被封装的类的具体实现细节可以随时改变,而无须调整用户级别的代码
    一些编译器允许在尚无友元函数的初始声明的情况下就调用它.不过最好是提供一个独立的函数声明.
    一个友元例子
        #include <iostream>
        using namespace std;
        
        class Box{
            double width;
        public:
            friend void printWidth( Box box );
            void setWidth( double wid );
        };
        // 成员函数定义
        void Box::setWidth( double wid ){
            width = wid;
        }
        // 请注意：printWidth() 不是任何类的成员函数
        void printWidth( Box box ){
        // 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 
            cout << "Width of box : " << box.width <<endl;
        }  
        // 程序的主函数
        int main( ){
            Box box;
            // 使用成员函数设置宽度
            box.setWidth(10.0);    
            // 使用友元函数输出宽度
            printWidth( box );    
            return 0;
        }

7.3类的其他特性 介绍Sales_data没有体现出来的一些类特性.包括:类的成员,类的成员的类初始值,可变数据成员,内联成员函数,成员函数返回*this
类成员再探
        class Screen
        {
        public:
            typedef string::size_type pos;    
            Screen() = default;         

            //cursor被其类内初始化为0
            Screen(pos ht, pos wd , char c): height(ht), width(wd),contents(ht * wd , c){}
            
            char get() const                            //读取光标处的字符       
            { return contents [cursor]; }               //隐式内联

            inline char get (pos ht ,  pos wd) const;   //显式内联
            Screen &move (pos r , pos c);               //能在之后被设为内联
        private:

            pos cursor = 0;
            pos height = 0 , width = 0;
            std::string contents;
        };    
    需要指出的是第二个构造函数(接受三个参数)位cursor成员隐式地使用了类的初始值.如果类中不存在cursor初始值,就需要向其他成员显式初始化cursor

    我们无需在声明和定义的地方同时说明inline,但是其实是合法的.不过最好只在类外部定义说明inline.
    和我们在头文件中定义inline函数的原因一样,inline成员函数也应该与相应的类定义在同一个头文件中

    类数据成员的的初始值
        在定义好Screen类之后,我们将定义一个窗口管理类并用它表示显示器上的一组Screen.
        这个类将包含一个Screen类型的vector,每个元素表示一个特定的Screen.默认情况我们希望Window_mgr类开始时总有一个默认初始化的Screen.
        在C++11新标准中,最好的方式就是把这个默认值声明成一个类内部初始值
            class Window_mgr{
            private:
                //这个Window_mgr追踪的Screen
                //默认情况下,一个Window_mgr包含一个标准尺寸的空白Screen
                std::vector<Screen> screens{ Screen(24, 80, ' ') };

            };            
        当我们初始化类类型的成员时,需要构造函数传递一个符合成员类型的实参.
        类内初始值必须使用=的初始化形式(初始化Screen的数据成员时所用的)或者花括号括起来的直接初始化形式
返回*this的成员函数
    接下来我们继续添加一些函数,它们负责设置光标所在位置的字符或者其他任一给定位置的字符:
        inline Screen &Screen::set(char c){
            contents[cursor] = c;                       //设置当前光标所在位置的新值
            return *this;
        }
        inline Screen &Screen::set(pos r , pos col , char ch){
            contents[r * width + col] = ch ; 
            return *this;
        }
    和move操作一样,我们的set成员的返回值是调用set对象的引用.返回引用的函数是左值的,意味着这些函数返回的是对象本身而非对象副本
    如果我们把一系列这样操作连接在一条表达式的话:
        //把光标移动到一个指定的位置,然后设置该位置的字符值
        myScreen.move(4,0).set('#');
    这些操作将在同一个对象上执行.等价于
        myScreen.move(4,0);
        myScreen,set('#');

    假如当初我们定义的返回类型不是引用,则move的返回值将是*this的副本,因此调用set只能改变临时副本,而不能改变myScreen的值.
    从const成员函数返回 *this 
        接下来添加个名为disply的操作,其负责打印Screen的内容.我们希望这个函数和move以及set出现在同一序列中,因此类似于move和set,
        display也应该返回 执行它的对象的引用    
        一个const成员函数如果以引用的形式返回*this,那么它的返回类型将是常量引用.
    基于const的重载
        通过区分成员函数是否是const的,我们可对其进行重载,其原因与我们之前根据指针参数是否指向const而重载的原因差不多.
        因为非常量版本的函数对于常量对象是不可用的,所以我们只能在一个常量对象上调用const成员函数.
        另外,虽然可以在非常量对象上调用常量版本或非常量版本,但显然此时非常量版本是一个更好的匹配.
        
        在下面的例子中,我们将定义个名为do_display的私有成员,由它负责打印Screen的实际工作.所有的display操作都将调用这个函数,然后返回执行操作的对象
            


*/  
