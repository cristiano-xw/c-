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
    sort(s+1,s+1+n); //��ֵ��С��������
    if(s[1]!=1)
    {cout<<-1<<endl;   return 0;}  
    
    sum=0;//sum�Ѿ����Դյ�Ǯ
    while(sum<x) 
    {  
        for(i=n;i>=1;i--)   
            if(s[i]<=sum+1)break; //����һ��,�ҿ��������ֵ��
        ans++;       //ѡ��ֵs[i]��Ӳ��
        sum+=s[i];  //�Ѿ��պõ�sum,�м���s[i]���շ�������
    }   
    
    printf("%d\n",ans);
    return 0;
}
