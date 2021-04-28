#include<iostream>
using namespace std;

template<typename T> void counts();
template<typename T> void report(T &);

template<typename TT>
class HasfriendT
{
    private:
        TT item;
        static int ct;  //次数
    public:
        HasfriendT(const TT & i):item(i){ct++;}
        ~HasfriendT(){ct--;}
        friend void counts<TT>();
        friend void report<>(HasfriendT<TT>&);
};

template<typename T>
int HasfriendT<T>::ct=0;

template<typename T>
void counts()
{
    cout<<"size: "<<sizeof(HasfriendT<T>)<<"; ";
    cout<<"counts: "<<HasfriendT<T>::ct<<endl;
}

template<typename T>
void report(T & hf)
{
    cout<<hf.item<<endl;
}

int main()
{
    counts<int>();
    counts<double>();
    HasfriendT<int>hfi1(10);
    HasfriendT<int>hfi2(10);
    HasfriendT<double>hfdb(10.5);
    report(hfi1);
    report(hfi2);
    report(hfdb);

    cout<<"int "<<endl;
    counts<int>();
    cout<<"double "<<endl;
    counts<double>();

    return 0;
}