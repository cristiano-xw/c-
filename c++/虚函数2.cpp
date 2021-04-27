#include<bits/stdc++.h>
using namespace std;

class Base//创建基类
{
public:
    Base(int a) : ma(a){}
    //void Show() 
    virtual void Show()
    {
        cout<<"ma "<<ma<<endl;
    }
protected:
    int ma;
};
class Derive : public Base//派生类公有继承基类
{
public:
    Derive(int b) : mb(b) ,Base(b){}//指明基类的构造方式
    void Show()
    {
        cout<<"mb "<<mb<<endl;
    }
protected:
    int mb;
};
int main()
{
    Base* pb = new Derive(10);//基类指针指向派生类指针
    cout<<sizeof(Base)<<endl;//基类大小
    cout<<sizeof(Derive)<<endl;//派生类大小
    cout<<typeid(pb).name()<<endl;//pb指针的类型
    cout<<typeid(*pb).name()<<endl;//pb指向的数据类型
    pb->Show();
    delete pb;
    return 0;
}

