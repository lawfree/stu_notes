#include <iostream>

using namespace std;

int main (){


}

/*
8.1 IO类
    为了支持这些不同种类的io处理操作,在istream和ostream之外,标准库还定义了其他一些io类型.
    iostream定义了用于读写溜的基本类型,fsream定义读写命名文件的类型,sstream定义了读写内存string对象的类型
    io类型间的关系
        本届剩下部分所介绍的标准库流特性都可以无差别地应用与普通流,文件流和string流,以及char或宽字符溜版本
io对象无拷贝或赋值
    ofstream out, out2;         //不能对流对象赋值
    out1 = out2;                //不能初始化ofstream参数
    out2 = print(out2);         //错误:不能拷贝流对象

    由于不能拷贝io对象,因此我们也不能将形参或返回类型设置为流类型.
    进行io操作的函数通常以引用方式传递和返回流.读写一个io对象会改变其状态,因此传递和返回的引用不能是const的
条件状态
    io操作一个与生俱来的问题是可能发生错误.下面是一个io错误的例子:
        int ival;
        cin >> ival;
    如果我们在标准输入上键入Boo,读操作就会失败.代码中的输入运算符期待读取个int,但得到一个字符B,这样cin进入错误状态.
    类似的,如果我们输入一个文件结束标识,cin也会进入错误状态.
    
    一个流一旦发生错误,其上后续的io操作都会失败.只有当一个流处于无错状态时,才可以从它读取数据,向它写入数据.
    由于流可能处于错误状态,因此代码通常应该在使用一个流之前检查它是否处于良好状态.确定一个流对象的状态的最简单方法是将其当作一个条件来用:
        whille(cin >> word)
            // ok : 读操作成功
    while循环检查 >> 表达式返回的流状态.如果输入操作成功,流保持有效状态,则条件为真.
    查询流状态
    将流作为条件使用,只能告诉流是否有效,而无法告诉我们具体发生了什么
    io库定义了一个与机器无关的iostate类型,它提供了表达流状态的完整功能.
    管理流状态
    流对象的rastate成员返回一个iostate值,对应的当前状态.setstate操作将给定条件位置位,表示发生了对应错误.clear成员是一个重载的成员
管理输出缓冲
    每个输出流都管理一个缓冲区,用来保存程序读写的数据.
        os << "please enter a value: ";
    文本串可能立即打印出来,但也有可能被操作系统保存在缓冲区中,随后再打印.有了缓冲机制,操作系统就可以将程序的多个输出操作组合成单一的系统级写操作.
    由于设备的写操作可能很耗时,允许操作系统将多个输出操作组合为单一的设备写操作可以带来很大性能的提升.
    刷新输出缓冲区
        endl,它完成换行并刷新缓冲区的工作.io库还有俩个类似的操作符:
            flush和ends.flush刷新缓冲区,但不输出任何额外的字符;ends向缓冲区插入一个空字符,然后刷新缓冲区:
                cout << "hi" << endl;       //输出hi和一个换行,然后刷新缓冲区
                cout << "hi" << flush;      //输出hi,然后刷新缓冲区,不附加任何额外的字符
                cout << "hi" << ends;       //输出hi和一个空字符,然后刷新缓冲区
8.2文件输入输出
    头文件fstream定义了三个类型来支持文件io:
        airstream从一个给定文件读取数据,ofstream向一个给定文件写入数据,以及fstream可以读写给定文件.
        这些类型提供的操作与我们之前已经使用过的对象cin和cout的操作一样.特别是我们可以用IO运算符(<< >>)来读写文件,
        可以用getline从一个ifstream读取数据.
        除了继承自iostream类型的行为之外,fstream中定义的类型还增加了一些新成员来管理与流关联的文件.
                            fstream特有操作
        fstream fstrm;      创建一个未绑定的文件流,fstream是头文件fstream中定义的一个类型
        fstream fstrm(s);   创建一个fstream,并打开名为s的头文件.s可以是string类型,或只想要个C风格字符串的指针.
                            这些构早函数都是explict的.默认的文件模式mode依赖与fstream的类型
        fstream fstrm(s,mode);
        fstrm.open(s)       打开名为s的文件,并将文件与fstrm绑定.s可以是一个string或一个指向C风格字符串的指针.
                            默认的文件mode依赖与fstream的类型.
        fstrem.close()      关闭与fstrm绑定的文件.返回void
        fstrm.is_open()     返回一个bool值,指出与fstrm关联的文件是否成功打开尚未关闭
使用文件流对象
    创建文件流对象时,我们可以提供文件名.如果提供了一个文件名,则open会自动被调用:
        ifstream in(ifile);     //构造一个ifstream并打开给定文件
        ofstream out;           //输出文件流未关联到任何文件
    成员函数open和close
        如果我们定义了一个空文件流对象,可以随后调用open来将它与文件关联起来:
            ifstream in(ifile); //构筑一个ifstream并打开给定文件
            ofstream out ;      //输出文件流未与任何文件关联
            out.open(ifile +　＂．copy＂);  //打开指定文件
        如果调用open失败,failbit会被置位.因为调用open可能失败,进行open是否成功的检测通常是个好习惯:
            if(out)     //检查open是否成功
                        //open成功,我们可以使用文件
        为了将文件流关联到另外一个文件,必须首先关闭已经关联的文件.一旦文件成功关闭,我们可以打开新的文件:
            in.close();         //关闭文件
            in.open(ifile + "2");
    自动构造和析构
        每个循环步input都会离开作用域,因此会被销毁
        当一个input是while的局部变量,他在每个循环步中都要创建和销毁一次.当一个fstream对象离开其他作用域时,与之的会自动关闭
        当一个fstram对象被销毁时,close会自动被调用.
文件模式
    每个流都有一个关联的文件模式,用来指出如何使用文件.
                文件模式
        in          以读的方式打开
        out         以写方式打开
        app         每次写操作前均定位到文件末尾
        ate         打开文件后立即定位到文件末尾
        trunc       截断文件
        binary      以二进制方式进行IO
    用一个文件名初始化流来隐式打开文件也可以.指定文件模式有如下限制:
        只可以对ofstream或fstream对象设定out模式
        只可以对ifstream或fstream对象设定in模式
        只有当out也被设定时才可设定trunc模式
    以out模式打开文件会丢弃已有数据
        阻止一个ofstream清空给定文件内容的方法是同时指定app模式:
            //为了保留文件内容,我们必须显式指定app模式
            ofstream app("file2" , ofstream::app);      //隐含为输出模式
            ofstream app2("file2" , ofstream::out | ofstream::app);
    每次调用open时都会确定文件模式
        对于一个给定流,每当打开文件时,都可以改变其文件模式
            ofstream out;   //未指定文件打开模式
            out.open("scratchpad"); //模式隐含设置为输出和截断
            out.close();
            out.open("precious" , ofstream::app);       //模式为输出和追加
            out.close();
        在每次打开文件时,都要设置文件模式,可能是显示地设置,也可能是隐式地设置.当程序未指定模式时,就使用默认值

 */