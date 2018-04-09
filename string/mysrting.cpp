#include "mysrting.h"
#include "string.h"
#include "iostream"
using namespace std;
mysrting::mysrting(const char *s)
{
    if(s == NULL)
    {
        _str = new char[1];
        *_str = '\0';
    }
    else
    {
        int len = strlen(s);
        _str = new char[len+1];
        strcpy(_str,s);
    }
}
char * mysrting::c_str()
{
    return _str;
}
mysrting::~mysrting()
{
    delete []_str;
}
mysrting::mysrting(const mysrting &another)
{
    _str = new char[strlen(another._str+1)];
    strcpy(_str,another._str);
    cout<<"copy constructor:"<<endl;
}
mysrting & mysrting::operator=(const mysrting &another)
{
    if(this == &another)            //判断是否是自赋值，如果是直接返回
        return *this;
    delete []this->_str;            //如果不是，则先把自己的内存释放掉，然后new一个和别人相等的空间
    int len = strlen(another._str); //然后在拷贝过来就可以了
    this->_str = new char[len+1];
    strcpy(this->_str,another._str);
    return *this;
}
const mysrting mysrting::operator+(const mysrting &another)
{
    int len = strlen(this->_str) + strlen(another._str);
    mysrting str;
    delete []str._str;
    str._str = new char[len+1];
    memset(str._str,0,len+1);
    strcat(str._str,this->_str);
    strcat(str._str,another._str);
    return str;
}
bool mysrting::operator==(const mysrting &another)
{
    if(strcmp(this->_str,another._str) == 0)
        return true;
    else
        return false;
}
bool mysrting::operator>(const mysrting &another)
{
    if(strcmp(this->_str,another._str) > 0)
        return true;
    else
        return false;
}
bool mysrting::operator<(const mysrting &another)
{
    if(strcmp(this->_str,another._str) < 0)
        return true;
    else
        return false;
}
char & mysrting::operator[](int idx)
{
    return this->_str[idx]; //return _str[idx];
}
char mysrting::at(int idx)
{
    return this->_str[idx];
}











