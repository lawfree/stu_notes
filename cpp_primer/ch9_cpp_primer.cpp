#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main (){
    vector<int> a(3,0);
    vector<int> b (4,1);
    swap(a,b);
    cout << a[3]<< endl;    // 1



    return 0;
}

/*
一个容器就是有些特定类型对象的集合.顺序容器sequential container为程序员提供了控制元素存储和访问顺序的能力.这种顺序不依赖于元素的值,
而是与元素加入容器时的位置相对应.

9.1顺序容器概述
    下表列出了标准库中的顺序容器,所有顺序容器都提供了快速顺序访问元素的能力.但是这些容器在以下方面都有不同的性能折中:
        向容器添加或从容器中删除元素的代价
        非顺序访问容器中元素的代价
                                顺序容器类型
        vector          可变大小数组,支持随机快速随机访问.在尾部之外的位置插入或删除元素可能很慢
        deque           双端队列.支持快速随机访问,在头尾位置插入/删除速度很快
        list            双向链表.只支持双向顺序访问.在list中任何位置进行插入/删除操作速度都很快
        forward_list    单向链表.只支持单向顺序访问.在链表任何位置进行插入/删除操作速度很快
        array           固定大小数组.支持快速随机访问,不能添加或删除元素
        string          与vector相似的容器.但专门用于保存字符.随机访问快.在尾部插入/删除速度快
    确定使用哪种顺序容器
        通常,用vector,除非有很好的理由用其他的
9.2 容器库概览
    某些操作是所有容器类型都提供的.
    另外一些操作仅针对顺序容器,关联容器或无序容器
    还有一些操作只适用于一小部分容器
    对容器可以保存的元素类型的限制
        顺序容器可以保存几乎任何类型的元素.
迭代器
    与容器一样,迭代器有着公共接口:如果一个迭代器提供某个操作,那么所有提供相同操作的迭代器对这个操作的实现方式都是相同的.
    迭代器范围
        一个迭代器范围由一对迭代器表示,两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置.这两个迭代器通常被称为begin和end
        这种元素范围称为左闭合区间区间
        对构成范围的迭代器的要求
            如果满足如下条件,两个迭代器begin和end构成一个迭代器范:
                他们指向同一个容器中的元素,或者是容器最后一个元素之后的位置
                我们可以通过反复递增begin来达到end.换句话说,end不在begin之前
容器类型成员
begin和end成员
    begin和end操作生成指向容器中第一个元素和尾元素之后位置的迭代器.这两个迭代器最常见的用途是形成一个包含容器中所有元素的迭代器范围.
    begin和end有多个版本:带r的版本返回反向迭代器;以c开头的版本返回const迭代器
        //显式指定类型
        list<string>::iterator it5 = a.begin();
容器定义和初始化
    每个容器类型都定义了默认构造函数
    将一个容器初始化为另一个容器的拷贝
        为了创建一个容器为另一个容器的拷贝,两个容器的类型及其元素类型必须匹配.
        当将一个容器初始化为另一个容器的拷贝时,两个容器的容器类型和元素类型都必须相同
    与顺序容器大小相关的构造函数
        只有顺序容器的构造函数才接受大小参数,关联容器并不支持
    标准库array具有固定大小
        与内置数组一样,标准库array的大小也是类型的一部分.当定义一个array时,除了指定元素类型,还要指定容器大小:
            array<int , 42>     //保存42个int的数组
    赋值和swap
        赋值运算符将其左边容器中的全部元素替换为右边容器中元素的拷贝:
            c1 = c2;            //将c1的内容替换为c2中元素的拷贝
            c1 = {a , b , c};   //赋值后,c1大小为3
        第一个赋值运算后,左边容器将与右边容器相等.如果两个容器原来大小不同,赋值运算后两者的大小都与右边容器的原大小相同.第二个赋值运算后,c1的size变为3    
    使用swap
        swap操作交换两个相同类型容器的内容.调用swap之后,两个容器中的元素将会交换:
            vector<string> svec1(10);
            vector<string> svec2(24);
        调用swap后,svec1将包含24个string元素,svec2将包含10个string
关系运算符
    如果两个容器具有相同大小且所有元素都两两对应相等,则这两个容器相等;否则两个容器不等
    如果两个大小不等.但较小容器中每个元素都等于较大容器中的对应元素,则较小容器小于较大容器.
    如果两个容器都不是另一个容器的前缀子序列,则他们的比较结果取决于第一个不想等的元素的比较结果

9.3顺序容器操作
向顺序容器添加元素
    使用push_back
        容器元素是拷贝
        当我们用一个对象来初始化容器时,或将一个对象插入到容器中时,实际上放入到容器中的是对象值的一个拷贝,而不是对象本身.
        就像我们将一个对象传递给非引用参数一样,容器中的元素与提供值的对象之间没有任何关联.随后对容器中元素的任何改变都不会影响到原始对象.
    使用push_front
        除了push_back,list,forward_list和deque容器还支持名为push_front.此操作将元素插入到容器头部:
            list<int> ilist;
            //将元素添加到ilist开头
            for(size_t ix = 0；ix != 4 ； ++ix)
                ilist.push_front(ix);
        此循环将元素0 1 2 3添加到ilist头部.
    在容器的特定位置添加元素   
        insert成员提供了更一般的添加功能,它允许我们在容器中任意位置插入0个或多个元素.
        每个insert函数接受一个迭代器作为其第一个参数.迭代器指出了在容器中什么位置放置新元素.insert函数将元素插入到迭代器所指定的位置之前
            slist.insert(iter, "Hello!");           //将"Hello!"添加到iter之前的位置.
        将元素插入到vector,deque和string中的任何位置都是合法的.然而这样做可能很耗时
    插入范围内的元素
        除了第一个迭代器参数外,insert函数还可以接受更多的参数,这与容器构造焊素和类似.其中一个版本接受一个元素数目和一个值.
            sevec.insert(svec.end() , 10 , "Anna");
        这行代码将10个元素插到svec的末尾,并将所有元素都初始化为string "Anna".
        接受一对迭代器或一个初始化列表的insert版本将给定范围中的元素插入到指定位置之前:
    使用insert的返回值
        通过使用insert的返回值,可以在容器中一个特定位置反复插入元素:
            list<string> lst;
            auto iter = lst.begin();
            while(cin >> word)
                iter = lst.insert(iter,word);       //等价于调用push_front
        
        在循环之前,我们将iter初始化为lst.begin().第一次调用insert会将我们刚刚读入的string插入到iter所指的元素之前的位置.insert返回的迭代器恰好指向这个元素/
        我们将此迭代器赋予iter并重复循环,读取下一个单词.只要继续有单词读入,每步while循环就会将一个新元素插入到iter之前,并将iter改变为新加入元素的位置.
        此元素为首元素.因此每步循环将一个新元素插入到list首元素之前的位置.
    使用emplace操作
        新标准引入了三个新成员--emplace_front,emplace和emplace_back,这些操作构造而不是拷贝元素.这些操作分别对应push_front,insert和push_back,
        允许我们将元素放置在容器头部,一个指定位置之前或容器尾部.
        当调用push或insert成员函数时,我们将元素类型的对象传递给它们,这些对象被拷贝到容器中.而当我们调用一个emplace成员函数时,则是将参数传递给元素类型的构造函数.
        emplace成员使用这些参数在容器管理的内存空间中直接构造元素.
            //在c的末尾构造一个Sales_data对象
            //使用三个参数的Sales_data构造函数
            c.emplace_back("978-059124",25,15.99);
            //错误:没有接受三个参数的push_back版本
            c.push_back("978-059124",25,15.99);
            //正确:创建一个临时的Sales_data对象传递给push_back
            c.push_back则会创建一个局部临时对象,并将其压入容器中
        其中对emplace_back的调用和第二个push_back调用都会创建薪的Sale_data对象.在调用emplace_back时,会在容器管理的内存空间中直接创建对象.
        而调用push_back则会创建一个局部临时对象,并将其压入容器中.
            emplace函数的参数根据元素类型而变化,参数必须与元素类型的构造函数相匹配:
            //iter指向c中一个元素,其中保存了Sales_data元素
            c.emplace_back();   //使用Sales_data的默认构造函数
            c.emplace(iter,"999-99999");    //使用Sales_data(string)
            //使用Sales_data的接受一个ISBN,一个count和一个price的构造函数
            c.emplace_front("978-059124,25,15.99");
        emplace函数在容器中直接构造元素.传递给emplace函数的参数必须与元素类型的构造函数相匹配.
访问元素
                    在顺序容器中访问元素的操作  
    at和下标操作只适用与string,vector,deque和array,back不适用于forward_list
    c.back()        返回c中尾元素的引用,若c为空,函数行未定义
    c.front()       返回c中首元素的引用,若c为空,函数行为未定义
    c[n]            返回c中下标为n的元素的引用,n是一个无符号整数.若n >= c.size(),则函数行为未定义
    c.at[n]         返回下标为n的元素的引用.如果下标越界,则抛出一out_of_range异常
    对一个空容器调用front和back,就像使用一个越界的下标一样,是一种严重的程序设计错误.

    访问成员函数返回的是引用
        在容器中访问元素的成员函数(即,front,back,下标和at)返回的都是引用.如果容器是一个const对象,则返回的const的引用.
    下标操作和安全的随机访问提供快速随机访问的容器也都提供下标运算符.下标运算符接受一个下标参数,返回容器中该位置的元素的引用.
    给定下标必须"在范围内"(大于等于0,小于容器大小).
    如果我们希望确保下标合法,可以用at成员函数.at成员函数类似下标运算符,但如果下标越界,at会抛出一个out_of_range异常
        vector <string> svec ;          //空vector
        cout << svec[0];                //运行时错误:svec中没有元素
        cout << svec.at(0);             //抛出一个out_of_range异常
删除元素
    与添加元素的多种方式类似,容器也有多种删除元素的方式.
                        顺序容器的删除操作  
        forward_list 有特殊版本的erase
        forward_list 不支持pop_back;vector 和 string 不支持pop_front
        c.pop_back()        删除c中尾元素.若c为空,则函数未定义
        c.pop_front()       删除c中首元素.若c为空,则函数行为未定义.函数返回void
    pop_front 和 pop_back 成员函数
         pop_front和pop_back 成员函数分别删除首元素和尾元素.与vector和string不支持push_front一样,也不支持pop_front.
         类似forward_list不支持pop_back.与元素访问成员函数类似,不能对一个空容器执行弹出操作.
        
        这些操作返回void,如果需要弹出的元素的值,就必须在执行弹出操作之前保存它:
    从容器内部删除一个元素
        成员函数erase从容器中指定位置删除元素.我们可以删除由一个迭代器指定的单个元素,也可以删除由一对迭代器指定的范围内的所有元素.
        两种形式erase都返回指向删除的元素之后位置的迭代器.即,若j是i之后的元素,那么erase(i)将返回指向j的迭代器.
            例如下面删除一个list中所有奇数的元素:
                list<int> lst = {0,1,2,3,4,5,6,7,8,9};
                auto t = lst.begin();
                while(it != lst.end())
                    if (* it % 2)               //若元素为奇数
                        it = lst.erase(it);     //删除此元素
                    else
                        ++ it;
    删除多个元素
        接受一对迭代器的erase版本允许我们删除一个范围内的元素:
            //删除两个迭代器表示范围内的元素
            //返回指向最后一个被删元素之后位置的迭代器
            elem1 = slist.erase(elem1 , elem2); //调用后 ,elem1 == elem2
        迭代器elem1 指向我们要删除的第一个元素,elem2 指向我们要删除的最后一个元素之后的位置
        为了删除一个容器中的所有元素,我们既可以调用clear,也可以用begin和end获得的迭代器作为参数调用erase:
            slist.clear();                      //删除容器中所有元素
            slist.erase(slist.begin() , slist.end());       //等价调用
改变容器大小
    我们可以用resize来增大或减小容器,不适用与array
        c.resize(n)             调整c的大小为n个元素.若n < c.size() , 则多出来的元素被丢弃.若必须添加新元素,对新元素进行值初始化
        c.resize(n , t)         调整c的大小为n个元素.任何新添加的元素都初始化为t
9.5额外的string 操作
    除了顺序容器共同的操作外,string类型还提供了一些额外的操作.这些操作中的大部分要么是提供string类和C风格字符数组之间的相互转换,
    要么是增加了允许我们常用下标代替迭代器的版本.
构造string的其他方法
                        其他构造string方法
    n,len2和pos2都是无符号值
    string s(cp , n)            s是cp指向的数组中前n个字符的拷贝.此数组至少应该包含n个字符
    string s(s2 , pos2)         s是string s2 从下标 pos2 开始的拷贝
    string s(s2 , pos2 , len2)  s是string s2 从下标 pos2 开始len2个字符的拷贝.若pos2 > s2.size(),构造函数行为未定义.

    这些构造函数接受一个string或一个const char* 参数, 还接受(可选的)指定拷贝多少个字符的参数.当我们传递给它们的是一个string时,
    还可以给定一个下标来指出从哪里开始拷贝:
        const char *cp = "Hello World!!!";          //以空字符
        char noNull[] = {'H' , 'i'};                //不是以空字符结束
        string s1(cp);                              //拷贝cp中的字符直到遇到空字符；    s1 == "Hello World!!!"                 
        string s2(noNull , 2);                      //从noNull拷贝两个字符;s2 == "Hi"
        string s3(noNull);                          //未定义:noNull不是以空字符结束
        string s4(cp +６　，　５)；                   //从cp[6]开始拷贝5个字符;s4 == "World"
    substr操作
        返回一个string,它是原始string的一部分或全部的拷贝.可以传递给substr一个可选的开始位置和计数值:
            string s("hello world");
            string s2 = s.substr(0 , 5);            //s2 = hello
            string s3 = s.substr(6);                //s3 = world
            string s4 = s.substr(6 , 11);           //s4 = world
        s.substr(pos , n)           返回一个string,包含s中pos开始的n个字符的拷贝.pos的默认值为0.n的默认值为s.size() - pos, 即拷贝从pos开始的所有字符
改变string的其他方法
    除了迭代器的insert 和 erase 版本外, string 还提供了接受下标的版本.下标指出了开始删除的位置,或是insert给定值之前的位置
        s.insert(s.size() , 5 , '!');               //在s末尾插入5个感叹号
        s.erase(s.size() - 5 , 5 );                 //从s 删除最后5 个字符
    标准库 string 类型还提供了接受C风格字符数组的insert和assign版本.例如,我们可以将空字符结尾的字符数组insert到或assign给一个string:
        const char *cp = "Stately, plump Buck";     
        s.assign(cp , 7);                           //s == "Stately"
        s.insert(s.size(), cp + 7);                 //s == "Stately, plump Buck"
    此处我们首先通过调用assign替换s的内容.我们赋予s的是cp指向的地址开始的7个字符
    append 和 replace 函数
        string 类定义了两个额外的成员函数: append 和 replace, 这俩个函数可以改变string1的内容.append是在三头日国内末尾进行插入
string搜索操作
    find 函数完成最简单的搜索.它查找参数指定的字符串,若找到,则返回第一个匹配位置的下标,否则返回npos:
        string name("AnnaBelle");
        auto pos1 = name.find("Anna");              //pos1 == 0
    这段程序返回0 , 即子字符串在AnnaBelle中第一次出现的下标.
                    string 搜索操作
        s.find(args)                    查找s中args第一次出现的位置
        s.rfind(args)                   查找s中args最后一次出现的位置
        s.find_first_of(args)           在s中查找args中任何一个字符
        s.find_first_not_of(args)       在s中查找第一个不在args中的字符

        args必须是以下形式之一
        c,pos                           从s中位置pos开始查找字符c.pos默认为0
        s2,pos                          从s中位置pos开始查找字符串s2.pos默认为0
compare函数
    除了关系运算符外,标准库string 类型还提供了一组compare函数,这些函数与C标准库的strcmp相似
    compare有6个版本,根据我们是要比较俩个string还是一个string与一个字符串数组,参数各有不同
                    s.compare的几种参数
        s2                              比较s和s2
        pos1 , n1 , s2                  将s中从pos1开始的n1个字符与s2进行比较
        pos1 , s2 , pos2, n2            将s中从pos1开始的n1个字符与s2中从pos2开始的n2个字符进行比较奥
        cp                              比较s与cp指向的以空
        pos1,n1,cp                      将s中从pos1开始的n1个字符与cp指向的以空字符结尾的字符串数组进行比较
数值转换
        int i = 42 ;
        string s = to_string(i);        //将整数i转换为字符表示形式
        double d = stod(s);             //将字符串s转换为浮点数
    要转换为数值的string中第一个非空白字符必须是数值中可能出现的字符:
        string s2 = "pi = 3.14";
        //转换s中以数字开始的第一个子串,结果d = 3.14
        d = stod (s2.substr(s2.find_first_of("+-.0123456789")));
    在这个stod调用中,我们调用了find_find_of来获得s中第一个可能是数值的一部分的字符的位置.
                        string 和数值之间的转换
        to_string(val)          一组重载函数,返回数值val的string表示.val可以是任何算术类型.对每个浮点类型和int或更大的整型,都有相应版本的to_string.
        stoi(s,p,b)             返回s的起始子串(表示整数内容)的数值,返回值类型分别是int,long,,,b表示转换所用的基数,默认为10.p是size_t指针,用来保存
                                s中第一个非数值字符的下标,即,函数不保存下标返回s的起始子串的数值,返回值类型分别是float,double
9.6容器适配器
    除了顺序容器,标准库还定义了三个顺序容器适配器: stack queue 和 priority_queue .
    本质上适配器接受一种已有的容器类型,使其行为看起来像一种不同的类型.
    定义一个适配器
        每个适配器都定义两个构造函数:默认构造函数创建一个空对象,接受一个容器的构造函数拷贝该容器来初始化适配器.例如,假定deq是一个deque<int>,我们可以用deq来初始化
        一个新的stack
            stack<int> stk(deq);            //从deq拷贝元素到stk
        默认情况,stack和queue是基于deque实现的,priority_queue是在vector之上实现的.我们可以在创建一个适配器时将一个命名的顺序容器作为第二个类型参数,来重载默认容器
            //在vector上实现的空栈
            stack<string , vector<string>> str_stk;
    栈适配器
        stack类型定义在stack头文件中.
            stack<int> intStack;            //空栈
            // 填满栈
            for(size_t ix = 0 ；ix != 10 ；++ ix)
                intStack.push(ix);          //intStack保存0到9十个数
            while(!intStack.empty()){
                intStack.pop();             //弹出栈顶.
            }        
 */