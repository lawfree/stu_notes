#include <iostream>
#include <vector>

using namespace std;

class Screen
{
    //Windouw_mgr 的成员可以访问Screen类的私有部分
    friend class Window_mgr;
public:
    typedef string::size_type pos;    
    Screen() = default;         

    //cursor被其类内初始化为0
    Screen(pos ht, pos wd , char c): height(ht), width(wd),contents(ht * wd , c){}
    
    char get() const                            //读取光标处的字符       
    { return contents [cursor]; }               //隐式内联

    inline char get (pos ht ,  pos wd) const;   //显式内联
    Screen &move (pos r , pos c);               //能在之后被设为内联

    Screen &set (char);
    Screen &set (pos, pos , char);

    //根据对象是否是const重载了display函数
    Screen &display(std::ostream &os)
        { do_display(os); return *this; }
    const Screen &display(std :: ostream &os) const
        { do_display(os); return *this; }         
private:

     pos cursor = 0;
     pos height = 0 , width = 0;
     std::string contents;

    //该函数负责显示Screen的内容
    void do_display(std::ostream &os) const {os << contents;}
}; 

inline Screen &Screen::move (pos r , pos c){
    pos row = r * width;                        //计算行的位置
    cursor = row + c ;                          //在行内将光标移动到指定的列
    return * this ;                             //返回对象
}

char Screen::get(pos r , pos c)const {           //在类的内部声明成inline
    pos row = r * width ;                       //计算行的位置
    return contents[row + c];                   //返回给定列的字符
}
inline Screen &Screen::set(char c){
    contents[cursor] = c;                       //设置当前光标所在位置的新值
    return *this;
}
inline Screen &Screen::set(pos r , pos col , char ch){
    contents[r * width + col] = ch ; 
    return *this;
}


class Window_mgr{
public :
    //Window_mgr被指定为Screen的友元,因此我们可以将Window_mgr的clear成员写成如下的形式:
    //窗口中每个屏幕的编号
    using ScreenIndex = std :: vector<Screen> :: size_type;
    //按照编号将指定的Screen重置位空白
    void clear (ScreenIndex);

private:
    //这个Window_mgr追踪的Screen
    //默认情况下,一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{ Screen(24, 80, ' ') };

};

void Window_mgr::clear(ScreenIndex i){
    // s是一个Screen的引用,指向我们想要清空的那个屏幕
    Screen &s = screens[i];
    //将那个选定的Screen重置位空白
    s.contents = string(s.height * s.width, ' ');
}