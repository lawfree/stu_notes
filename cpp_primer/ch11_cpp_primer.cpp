#include <iostream>

using namespace std;

int main (){


}

/*
关联容器

关联容器支持高效的关键字查找和访问.两个主要的关联容器类型map和set
标准库提供8个关联容器三个维度:
    (1)或者是set,或者是map
    (2)或者要求不重复的关键字,或者允许重复的关键字
    (3)按顺序保存元素,或无序保存
11.2 关联容器概述
定义关联容器
    定义一个map时,必须既指明关键字又指明类型:而定义个set时,只需指明关键字类型,因为set中没有值.每个关联容器都定义了一个默认构造函数,他创建一个指定类型的空容器.
    也可以将关联容器初始化为另一个同类容器的拷贝.
        map<string, size_t> word_count;         //空容器
        //列表初始化
        set<string> eclude = {"...", "...", ...};
        //三个元素; authors将姓映射成名
        map<string, string> authors = {{"...","..."}, {... , ...}, {}};
    初始化一个map时,必须提供关键字类型和值类型.
    初始化multimap或multiset
        一个map或set中的关键字必须是唯一的,即,对于一个给定的关键字,只能有一个元素的关键字等于它.容器multimap和multiset没有此限制,允许多个元素有相同的关键字.
pair 类型
    在介绍关联容器操作之前,我们了借名为pair的标准库类型,它定义在头文件utility中
    一个pair保存两个数据成员.类似容器,pair是一个用来生成特定类型的模板.当创建一个pair时,我们必须提供两个类型名,pair的数据成员将具有对应的类型.
                            pair上的操作
    pair<T1, T2> P;                     P是一个pair,两个类型分别为T1和T2的成员都进行了值初始化
    pair<T1, T2> p(v1, v2)              p是一个成员类型为T1和T2的pair,first和second分别用v1和v2进行初始化
    air<T1, T2> p = {v1, v2}            等价于上面那个
    make_pair(v1, v2)                   返回一个用v1和v2初始化的pair.pair的类型从v1和v2的类型推断出来
    p.first                             

    创建pair对象的函数
        想象一个函数需要返回一个pair.
            pair<string, int>
            process(vector<string> &v){
                //处理v
                if(!v.empty())
                    return {v.back(), v.back().size()};     //列表初始化
                else
                    return pair<string, int>();             //隐式构造返回值
            }
    在较早的c++版本中,不允许用话括号包围的初始化器来返回pair这种类型的对象,必须显示构造返回值:
        if(!v.empty())
            return pair<string, int>(v.back(), v.back().size());
11.3关联容器操作
关联容器迭代器
    当解引用一个关联容器迭代器时,我们会得到一个类型为容器的value_type的值的引用.对map而言,value_type是一个pair类型,其first成员保存const关键字,second保存值:
        //获取指向word_count 中一个元素的迭代器
        auto map_it = word_count.begin();
        // *map_it 是指向一个pair<const string, size_t>对象的引用
        count << map_it->first;

    一个map的value_type是一个pair,我们可以改变pair的值,但不能改变关键字成员的值.
    set的迭代器是const的
        虽然set类型同时定义了iterator和const_iterator类型,但两种类型都允许只读访问set中的元素.与不能改变一个map元素的关键字一样,set关键字也是const
        可以用一个set迭代器来读取元素的值,但不能修改:
            set<int> iset = {0,1,2,3,4,5,6,7,8,9};
            set<int>::iterator set_it = iset.begin();
    遍历关联容器
        map和set类型都支持begin和end操作.我们可以同这些函数获取迭代器,然后用迭代器来遍历容器.
            //获得一个指向首元素的迭代器
            auto map_it = word_count.cbegin();
            //比较当前迭代器和尾后迭代器
            while(map_it != word_count.cend()){
                //解引用迭代器,打印关键字-值对
                cout << map_it->first << "occures" << map_it->second << "times" << endl;
                ++ map_it ;     //递增迭代器,移动到下一元素
            }
添加元素
    关联容器的insert成员向容器中添加一个元素或一个元素范围.由于map和set包含不重复的关键字,因此插入一个已存在的元素对容器没任何影响:
        vector<int> ivec = {2,4,6,8,2,4,6,8};               //ivec有8个元素
        set<int> set2;                                      //空集合
        set2.insert(ivec.cbegin(), ivec.cend());            //set2有4个元素
    向map中添加元素
        对一个map进行insert操作时,必须记住元素类型是pair.通常,对于想要插入的数据,并没有一个现成的pair对象.可以在insert的参数列表中创建一个pair:
            //向word_count 插入word的4种方法
            word_count.insert({word,1});
            word_count.insert(make_pair(word,1);
            word_count.insert(pair<string, size_t>(word, 1));
            word_count.insert( map<string, size_t>::value_type(word, 1));
        

                 


    
 */