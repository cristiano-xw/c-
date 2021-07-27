#include<iostream>
using namespace std;

class String
{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM=80;
    
    public:
        String (const char * s);//构造函数
        String();
        String (const String &); //复制构造函数
        ~String();
        int length() const {return len;} //在函数后面加const表示为只读函数

        String & operator=(const String &); //重载运算符进行赋值 
        String & operator=(const char*);
        char & operator[](int i); //使得可以直接引用数组的下标
        const char & operator[](int i) const;

        friend bool operator==(const String &st,const String &st1);
        friend bool operator>(const String &st1,const String &st2);
        friend bool operator<(const String &st1,const String &st2);
        friend ostream & operator << (ostream & os,const String & st);
        friend istream & operator >> (istream & is,String st);
        static int HowMany();
};

#include<cstring>
using namespace std;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len=strlen(s);
    str=new char[len+1]; //通过new分配内存
    strcpy(str,s);//直接拷贝复制
    num_strings++; //创建了多少个对象
}

String::String()
{
    len=4;
    str=new char[1];
    str[0]='\0';
    num_strings++;
}

String::String(const String &st) //复制构造函数
{
    num_strings++;
    len=st.len;
    str=new char [len+1];
    strcpy(str,st.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

String & String::operator=(const char * s)   //通过重载=来实现赋值
{
    delete [] str;   //先删除str原有的内容
    len=strlen(s);
    str=new char [len+1]; //多申请一个空间
    strcpy(str,s);
    return *this;  //返回一个String型
}

char & String::operator[](int i) //使用引用可以省去创建中间变量
{
    return str[i];
}

const char & String::operator[](int i) const
{
   return str[i];
}

bool operator<(const String &st1,const String &st2)
{
    return (strcmp(st1.str,st2.str)<0);     //返回
}

bool operator>(const String &st1,const String &st2)
{
    return st2.str<st1.str;   
}

bool operator==(const String &st1,const String &st2)
{
    return (strcmp(st1.str,st2.str)==0);
}

ostream &operator<<(ostream & os,const String &st)
{
    os<<st.str;
    return os; //返回输出流
}
//friend istream & operator >> (istream & is,String st);

istream & operator>>(istream & is, String st) //此处涉及到修改成员，不加const
{
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
    {
        st=temp;
    }
    while (is&&is.get()!='\n')
    continue;
    return is;
}
