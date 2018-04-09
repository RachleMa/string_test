#include <iostream>
#include "mysrting.h"
using namespace std;
int main()
{
    //使用系统提供的string
    cout<<"string:"<<endl;
    string s;           //char *str = "";
    string s2("China"); //char *str = "China";
    //cout可以通过<<输出char *类型 但是通过<<输出string类型的类对象时需要重载<<运算符
    //c_str()可以通过string类型返回一个char *类型的字符串
    cout<<s.c_str();
    cout<<s2.c_str()<<endl;

    string *ps = new string("Chinese");
    cout<<(*ps).c_str()<<endl;
    cout<<endl;
    delete ps;

    cout<<"compare between up(system) and down(user defined)"<<endl<<endl;

    //使用自己添加的类 mysrting
    cout<<"mystrting:"<<endl;
    mysrting ms;
    mysrting ms2("China");
    cout<<ms.c_str();
    cout<<ms2.c_str()<<endl;
    cout<<endl;

    //析构器
    cout<<"descructor:"<<endl;
    mysrting *pms = new mysrting("Chinese");
    cout<<(*pms).c_str()<<endl;
    cout<<endl;
    delete pms;

    //拷贝构造器
    cout<<"copy constructor:"<<endl;
    mysrting ms3(ms2);
    cout<<ms3.c_str()<<endl;
    cout<<endl;

    //赋值运算符重载
    cout<<"operator = :"<<endl;
    mysrting ms4;
    ms4 = ms3;      //等价于ms4.operator =(ms3)
    cout<<ms4.c_str()<<endl;
    mysrting ms5;
    //ms4 = ms3 相当于 ms4.operator = (ms3)，此时this指针是指向ms4的，&another指向ms3
    ms5 = ms4 = ms3;//返回值为了实现连等操作
    ms5.operator = ( ms4.operator =(ms3) ); //从右往左执行
    cout<<ms5.c_str()<<endl;
    cout<<endl;

    //[]运算符重载
    cout<<"operator [] :"<<endl;
    mysrting ms6 = "Amreica";
    cout<<ms6[2]<<endl;
    ms6[2] = 'm';
    cout<<ms6.c_str()<<endl;

    mysrting ms7 = ms6;     //mysrting ms7(ms6); 两个发生的均是拷贝构造
    cout<<ms7.c_str()<<endl;
//    cout<<ms7._str<<endl;

    //+运算符重载
    cout<<"operator + :"<<endl;
    mysrting ms8 = ms2 + ms6;//mysrting ms8 = ms2.operator +(ms6);
    cout<<ms8.c_str()<<endl;
    //因为加号运算符重载返回的对象时const的，所以不能进行修改，但是返回的对象可以赋值给其他对象，
    //这里体现了const类型的普通变量可以赋值给非const类型的普通变量
    //即const int a = 5; int b = a; 因为b是普通变量不是引用或者指针，是无法间接修改a的
    ms2.operator +(ms6) = "Japan";
    return 0;
}

