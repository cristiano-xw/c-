#include<iostream>
using namespace std;

template<typename T>
class Hasfriend
{
    private:
        T item;
        static int ct;
    public:
        Hasfriend(const T & i):item(i){ct++;}//构造特定类型的数据次数增加
        ~Hasfriend(){ct--;}
        friend void counts();   //定义友元函数，但是没指定类型
        friend void reports(Hasfriend<T>&);  //指定了类型
};

template<typename T>
int Hasfriend<T>::ct=0;//分别表示int和double出现的次数

void counts()
{
    cout<<"int count: "<<Hasfriend<int>::ct<<"; ";
    cout<<"double count: "<<Hasfriend<double>::ct<<"; "<<endl;
}

void reports(Hasfriend<int> &hf)
{
    cout<<"Hasfriend<int>: "<<hf.item<<endl;
}

void reports(Hasfriend<double> &hf)
{
    cout<<"Hasfriend<double> "<<hf.item<<endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();
    Hasfriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();
    Hasfriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    Hasfriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts(); 
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    // std::cin.get();
    return 0; 
}
