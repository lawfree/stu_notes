#include <iostream>
#include <vector>

using namespace std;

class Screen
{
public:
    typedef string::size_type pos;    
    Screen() = default;         

    //cursor�������ڳ�ʼ��Ϊ0
    Screen(pos ht, pos wd , char c): height(ht), width(wd),contents(ht * wd , c){}
    
    char get() const                            //��ȡ��괦���ַ�       
    { return contents [cursor]; }               //��ʽ����

    inline char get (pos ht ,  pos wd) const;   //��ʽ����
    Screen &move (pos r , pos c);               //����֮����Ϊ����

    Screen &set (char);
    Screen &set (pos, pos , char);

    //���ݶ����Ƿ���const������display����
    //Screen &display(std::ostream )

private:

     pos cursor = 0;
     pos height = 0 , width = 0;
     std::string contents;
}; 

inline Screen &Screen::move (pos r , pos c){
    pos row = r * width;                        //�����е�λ��
    cursor = row + c ;                          //�����ڽ�����ƶ���ָ������
    return * this ;                             //���ض���
}

char Screen::get(pos r , pos c)const {           //������ڲ�������inline
    pos row = r * width ;                       //�����е�λ��
    return contents[row + c];                   //���ظ����е��ַ�
}
inline Screen &Screen::set(char c){
    contents[cursor] = c;                       //���õ�ǰ�������λ�õ���ֵ
    return *this;
}
inline Screen &Screen::set(pos r , pos col , char ch){
    contents[r * width + col] = ch ; 
    return *this;
}


class Window_mgr{
private:
    //���Window_mgr׷�ٵ�Screen
    //Ĭ�������,һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
    std::vector<Screen> screens{ Screen(24, 80, ' ') };

};