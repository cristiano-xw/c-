#include <iostream>
#include<cstring>
using namespace std;
using std::istream;
using std::ostream;

class String
{
private:
    char *str;                    //字符串首字符指针;
    int len;                      //记录字符串长度;
    //static int num_strings;       //记录构造的字符串数目;
    static const int CINLIM = 80; //限制输入字符个数;

public:
    String(const char *s);     //用户定义构造函数;
    String();                  //默认构造函数;
    String(const String &st);  //复制构造函数;
    ~String();                 //析构函数;
    int length() const { return len; }
    String &operator=(const String &st);
    String &operator=(const char *s);
    String operator+(const char *s); //重载'+'使得String类可以和const char *进行相加;
    char &operator[](int i);
    const char &operator[](int i) const;
    friend bool operator<(const String &st1, const String &st2);
    friend bool operator>(const String &st1, const String &st2);
    friend bool operator==(const String &st1, const String &st2);
    friend ostream &operator<<(ostream &os, const String &st);
    friend istream &operator>>(istream &is, String &st);
    friend String operator+(const char *s, const String &st);      //重载'+'使得const char *可以和String类进行相加;
    friend String operator+(const String &st1, const String &st2); //重载'+'使得String类可以相加;
    void stringlow();                                              //使得字符串字母转换成小写;
    void stringup();                                               //使得字符串字母转换成大写;
    unsigned has(const char s) const;                              //计算单个字符在字符串中出现的次数;
    static int HowMany();
};


/*int String::HowMany() 
{
    return num_strings;
}*/

String::String()
{
    len=1;
    str=new char[1];
    strcpy(str,"\0");
    //num_strings++;
}

String::String(const char *s)
{
    len=strlen(s);
    str=new char[len+1];
    strcpy(str,s);
   // num_strings++;
}

String::String(const String &st)
{
    len=st.len;
    str=new char[len+1];
    strcpy(str,st.str);
}

String::~ String()
{
    //num_strings--;
    delete[] str;      
}

String & String::operator=(const String &st) //对象给对象赋值。
{
    if(this==&st)
    {
        return*this; 
    }

    delete[] str;
    len=st.len;
    str=new char[len+1];
    strcpy(str,st.str);
    return * this; 
}

String &String::operator=(const char *s)  //对字符变量的构造
{
    delete[] str;
    len=strlen(s);
    str=new char [len+1];
    strcpy(str,s);
    return *this;
}

String String::operator+(const char *s)  //成员变量和字符串相加
{
    int length= len+strlen(s)+1;
    char * temp= new char [length];
    strcpy(temp,str);
    strcat(temp,s);
    return String(temp);  
}

char &String::operator[](int i)
{
    return str[i];
}

bool operator<(const String &st1, const String &st2)
{
    return(strcmp(st1.str,st2.str)<0);  
}

bool operator==(const String & st1,const String &st2)
{
    return(strcmp(st1.str,st2.str)==0);
}

bool operator>(const String & st1,const String &st2) //
{
    return(strcmp(st1.str,st2.str)>0);
}

//对输入和输出流的重载
istream &operator>>(istream &is, String &st)  
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is) 
    {
        st = temp;
    }
    while (is && is.get() != '\n')
        continue;
    return is;
}   

ostream &operator<<(ostream & os,const String &st)
{
    os<<st.str;
    return os;
}

String operator+(const char *s, const String &st)
{
    int length=strlen(s)+st.len;
    char * temp=new char[length+1];
    strcpy(temp,s);
    strcat(temp,st.str); 
    return String(temp);
}

String operator+(const String &st1,const String &st2)
{
    int length=st1.len+st2.len;
    char * temp =new char[length+1];
    strcpy(temp,st1.str);
    strcat(temp,st2.str);
    return String(temp);
}

void String::stringlow()
{
    for (int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void String::stringup()
{
    for(int i=0;i<len;i++)
    {
        str[i]=toupper(str[i]);
    }
}

unsigned String::has(const char s) const
{
    int t=0;
    for(int i=0;i<len;i++)
    {
        if(s==str[i])
        {
            t++;
        }
    }
    return t;
}