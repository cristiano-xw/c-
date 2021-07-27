//循环链表求解约瑟夫问题
#include<iostream>
#include"circlelinklist2.h"
using namespace std;

void josephus(int n,int m)
{
    simplecirclelinklist<int> la;
    int position=0;
    int out=0; int winner=0;
    for(int i=1;i<=n;i++)
    {
        la.Insert(i,i); //进行位置的插入操作
    }

    cout<<"出列者:";
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            position++;
            if(position>la.Length())
            {
                position=1;
            }
        }
        la.Delete(position--,out);
        cout<<out<<" ";
    }

    la.GetElem(1,winner);
    cout<<"优胜者:"<<winner<<endl;
}

int main()
{
    josephus(8,3);
    return 0;
}

