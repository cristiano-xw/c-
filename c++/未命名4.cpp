#include<iostream>  
#include<cstdio>  
#include<algorithm>  
using namespace std; 
const int Maxn=1005;  
int n,x,s[Maxn],ans; 
int main()
{  
    int i,j,sum;
    cin>>x>>n;  
    for(i=1;i<=n;i++)cin>>s[i]; 
    sort(s+1,s+1+n); //面值从小到大排序
    if(s[1]!=1)
    {cout<<-1<<endl;   return 0;}  
    
    sum=0;//sum已经可以凑的钱
    while(sum<x) 
    {  
        for(i=n;i>=1;i--)   
            if(s[i]<=sum+1)break; //凑下一个,找可用最大面值的
        ans++;       //选面值s[i]的硬币
        sum+=s[i];  //已经凑好的sum,中间间隔s[i]个凑法做过了
    }   
    
    printf("%d\n",ans);
    return 0;
}
