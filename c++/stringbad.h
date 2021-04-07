#include<iostream>
#include<cstring>
using namespace std;

class stringbad
{
    private:
        char *str;
        int len;
        static int num_strings;
    public:
        stringbad(const char *s);
        stringbad();
        ~stringbad();

        friend ostream & operator<<(ostream & os,const stringbad &st);
        //友元函数创建
};

stringbad::stringbad(const char *s)//构造函数，直接传递指针
{
    len=strlen(s);//求出长度
    str=new char[len +1];
    strcpy(str,s);
    num_strings++;
    cout<<num_strings<<":\""<<str<<"\"object created\n";
}

stringbad::stringbad()
{
    len=4;
    str=new char[4];
    strcpy(str,"c++");
    num_strings++;
    cout<<num_strings<<":\""<<str<<"\"object created\n";
}

stringbad::~stringbad()
{
    cout<<"\""<<str<<"\"object deleted,";
    --num_strings;
    cout<<num_strings<<" left\n";
    delete[] str;
}

ostream & operator<<(ostream & os,const stringbad &st)
{
    os<<st.str;
    return os;
}
