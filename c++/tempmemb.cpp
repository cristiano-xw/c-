#include<iostream>
using namespace std;
template<typename T>

class beta
{
    private:     
        template <typename V>;//模板参数
        class hold //定义模板类
        {
            private:
                V val;
            public:
                hold(V v=0):val(v){}
                void show const {cout<<val<<endl;}
                V value() const{return val;}
        };  //类中类

    hold <T> q;
    hold <int> n;

    public:
        beta(T t,int i):q(t),n(i){}
        template<typename U>
        U blab(U u,T t){return (n.value()+q.value())*u/t;}
        void Show() const{q.show();n.show();}           
};

int main()
{
    beta<double>guy(3.5,3); //T为double类型
    cout<<"T was set to double\n";
    guy.Show();
    cout<<"V was set to int\n";
    cout<<guy.blab(10,2.3)<<endl;//10是int类型，所以计算结果会返回int

    cout<<"U was set to double"<<endl;
    cout<<guy.blab(10.0,2.3)<<endl;

    return 0;
}