#include<iostream>
#include "sqlist.h"
using namespace std;


void reverse()
{
    int n; int e;
    sqstack<int> tmps;
    cout<<"输入一个整数";
    cin>>n;

    while(n<=0)
    {
        cout<<"整数不可以负数,重来"<<endl;
        cin>>n;
    }

    cout<<"输入"<<n<<"个整数"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>e;
        tmps.push(e);
    }


    cout<<"相反的方向输出"<<endl;
    while(!tmps.empty())
    {
        tmps.pop(e);
        cout<<e<<" ";
    }
}

int main()
{
    reverse();
    return 0;
}