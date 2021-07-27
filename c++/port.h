#include<iostream>
#include<cstring>
using namespace std;

class port
{
    private:
        char * brand;
        char style[20];
        int bottles;
    public:
        port(const char* br ="none",const char* st="none",int b=0);
        port(const port & p);
        virtual ~port(){delete[] brand;}
        port & operator=(const port & p);
        port & operator+(int b);
        port & operator-(int b);
        int bottlecount() const {return bottles;}
        virtual void show() const;
        friend ostream & operator<<(ostream & os,const port & p);
};

port::port(const char* br ="none",const char* st="none",int b=0) 
{
    brand=new char[strlen(br)+1];  //指针指向一个数组
    strcpy(brand,br);    
    strncpy(style,st,20);     
    bottles=b;
}

port::port(const port & p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}

port &port::operator=(const port &p)
{
    if(this==&p)
    {
        return *this;   //返回this指针所指 
    }

    delete[] brand;
    brand= new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}

port &port::operator+(int b)
{
    bottles+=b;
    return *this;
}

port &port::operator-(int b)
{
    if(bottles>=b)
    {
    bottles-=b;
    return *this;
    }
    else 
    {
        cout<<"error"<<endl;
        return *this;
    }
}

void port::show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
    return;
}

ostream & operator<<(ostream & os,const port & p)
{
    os<<p.brand<<"   "<<p.style<<"  "<<p.bottles;
    return os;
}



class VintagePort : public port
{
private:
    char *nickname;
    int year;

public:
    VintagePort();
    VintagePort(const char *br, int b, const char *nn, int y);
    VintagePort(const VintagePort &vp);
    ~VintagePort() { delete[] nickname; }
    VintagePort &operator=(const VintagePort &vp);
    void Show() const;
    friend ostream &operator<<(ostream &os, const VintagePort &vp);
};

#include <cstring>
VintagePort::VintagePort() : port("none", "vintage", 0) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[1];
    nickname[0] = '\0';
    year = 0;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : port(br, "vintage", b) //成员列表初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(nn) + 1]; //构造了一个数组
    std::strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : port(vp) //调用基类复制构造函数初始化派生类的基类对象数据;
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
    {
        return *this;
    }
    delete[] nickname;
    port::operator=(vp); //调用基类赋值运算符修改派生类的基类数据成员;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    port::show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
    return;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const port &)vp; //强制类型转换调用Port基类的重载输出流运算符方法;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}

