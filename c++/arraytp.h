#include<bits/stdc++.h>

template<class T,int n>
class arraytp
{
    private:
        T ar[n];    //T是类型名称，n是数组大小
    public:
        arraytp(){};
        explicit arraytp(const T &v);
        virtual T & operator[] (int i);
        virtual T operator[] (int i) const;
};

template<class T,int n>
arraytp<T,n>::arraytp(const T &v)
{
    for(int i=0;i<n;i++)
    {
        ar[i]=v;
    }
}

template<class T,int n>
T & arraytp<T,n>::operator[](int i)
{
    if(i<0||i>=n)
    {
        cout<<"error:"<<i<<"is out of range\n";
        exit(0);
    }
    return ar[i];
}

template<class T,int n>
T arraytp<T,n>::operator[](int i) const 
{
    if(i<0||i>n)
    {
        cout<<"error:"<<i<<"is out of limit";
        exit(0);
    }
    return ar[i];
}
