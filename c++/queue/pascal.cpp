#include<iostream>
#include"linkqueue.h"
using namespace std;

void pascal(int n)
{
    linkqueue<int>q; //生成队列
    int s; int t;
    q.inqueue(1); q.inqueue(1); //存放首行的两个1
    cout<<1<<" "<<1;
    for(int i=2;i<=n;i++)
    {
        cout<<endl;
        q.inqueue(1);//每一行的行首插入1
        cout<<1<<" ";
        q.outqueue(s); //首先取出i-1行第一个元素的值
        for(int j=2;j<=i;j++) //第i行有i+1个元素
        {  
            q.outqueue(t);
            q.inqueue(s+t); //对应的元素是 上面两个相邻元素的和
            cout<<s+t<<" ";
            s=t; //不断更新s的值
        }  
        q.inqueue(1);
        cout<<1;  //最后一个元素一定是1 
    }
    cout<<endl;
}

int main()
{
    pascal(5);
    return 0;
}