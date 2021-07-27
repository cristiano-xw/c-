#include<bits/stdc++.h>
using namespace std;

struct cmp
{
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

int main()
{
    int a[100005];
    int l[100005];
    int i=1;

    char c=0;
    while(1)
    {
        char c=0;
        scanf("%d",&a[i]);
        i++;
        c=getchar();
        if(c=='\n')
        {
            break;
        }
    }
    
    int n=i-1; //一共有n个数
    int ans=1; //默认只可以有一个数
    l[1]=a[1];

    for(int i=2;i<=n;i++)
    {
        if(l[ans]>=a[i])  //如果前一个数大于等于后一个数，更新大小并且继续检索
        {
            ans++;
            l[ans]=a[i];
        }

        else 
        {
            int k=upper_bound(l+1,l+ans+1,a[i],cmp())-l;  //返回第一个小于a[i]的位置
			l[k]=a[i];  
        }
    }

    cout<<"结果是"<<ans<<endl;
    return 0;
}