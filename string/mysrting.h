#ifndef MYSRTING_H
#define MYSRTING_H
#include <iostream>
class mysrting
{
public:
    mysrting(const char *s = NULL);
    ~mysrting();
    //1.赋值运算符重载返回引用是用来实现连等操作，返回引用还可以实现更改操作
    //2.拷贝构造器还有其他运算符重载中传参中传引用是为了减少内存的占用，类型为const是为了防止修改，传参中加了const
    //则another对象只能调用const修饰的成员函数，但是可以访问类中的const成员和非const成员，譬如在拷贝构造器中
    //another._str与another.c_str()，虽然两者都可以返回char *的成员，但是第二个是非const成员函数，不可以调用
    mysrting(const mysrting &another);
    mysrting & operator=(const mysrting &another);
    // 加号运算符重载返回值为const，则返回的对象不能更改 参照main.cpp中的实例
    const mysrting operator+(const mysrting &another);
    bool operator==(const mysrting &another);
    bool operator>(const mysrting &another);
    bool operator<(const mysrting &another);
    char & operator[](int idx);
    char at(int idx);
    char * c_str();
private:
    char *_str;
};

#endif // MYSRTING_H
