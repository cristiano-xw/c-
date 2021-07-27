//vector这个数据结构的测试
#include<iostream>
#include<vector>
#include<bits/stdc++.h>  
using namespace std;

void test12()
{
    int a[10]={1,2,5,3,4,6};
    vector<int> v(a,a+6);
    cout<<"vector 容量"<<" "<<v.capacity()<<endl;
    cout<<"vector 大小"<<" "<<v.size()<<endl;
    cout<<"初始化数据"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    sort(v.begin(),v.end());
    cout<<"排序过后的顺序"<<" ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    cout<<"改变大小"<<endl;
    v.resize(10);
    cout<<"大小"<<v.size()<<endl;

    cout<<"第一个数据"<<" ";
    cout<<v.front()<<endl;
    cout<<"最后一个数据"<<" ";
    cout<<v.back()<<endl;

    cout<<"删除操作 删除两个数据"<<endl;
    v.erase(v.begin()+1,v.begin()+3);
    cout<<"改变后的大小"<<" "<<v.size()<<endl;

    cout<<"清空"<<" ";
    v.clear();
    cout<<"大小"<<v.size();

}