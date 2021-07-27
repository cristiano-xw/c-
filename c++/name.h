#include<iostream>
#include<cstring>
using namespace std;

class cow
{
    private:
    char name[20];  //名字，定义为字符串
    char *hobby;
    double weight;  //

    public:
    cow();
    cow(const char * nm,const char * ho,double wt);
    cow(const cow & c);
    ~cow();
    cow & operator=(const cow & c);     //在类里面重载预算符 
    void showcow() const;
};

cow::cow()
{
    strcpy(name,"\0");
    hobby=new char[1];  //new申请空间使得析构函数可以释放
    hobby[0]='\0';
    weight=0.0;
}

cow::cow(const char * nm,const char *ho,double wt)
{
    strncpy(name,nm,20);
    name[19]='\0';
    hobby=new char[strlen(ho)+1];  //多申请一个空间
    strcpy(hobby,ho);
    weight=wt; 

}

cow::cow(const cow & c)   //复制构造函数
{
    strcpy(name,c.name);
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
}

cow::~cow()
{
    delete[] hobby;  //在析构的时候释放空间
}

cow &cow::operator=(const cow & c)
{
    if(this == &c)
    {
        return *this;
    }

    delete[] hobby;
    strcpy(name,c.name);
    hobby=new char[strlen(c.hobby)+1];
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this;
}

void cow::showcow() const
{
    std::cout << "Cow name: " << name << std::endl;
    std::cout << "Cow hobby: " << hobby << std::endl;
    std::cout << "Cow weight: " << weight << "\n\n";
    return;
}




