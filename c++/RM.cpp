#include<bits/stdc++.h>
#define for1n(i,n) for(int i=1;i<=n;i++)
using namespace std;
struct point{
    double x,y;
}; 

double dis_qu(point xx,point yy)
{
    return sqrt((xx.x-yy.x)*(xx.x-yy.x)+(xx.y-yy.y)*(xx.y-yy.y));
}

int n;
double ans=1e6;
point a[30];
bool b[30];
double dis[30][30];

void dfs(int x,int poi,double sum)
{
    if(x==n+1) //找到了最后一个点
    {      
        ans=min(ans,sum);
        return;
    }
    if(sum>ans) //如果大于结果，那就回溯吧
        return;
    for1n(i,n)
    {
        if(!b[i])
        {
            b[i]=1;
            dfs(x+1,i,sum+dis[poi][i]);
            b[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    for1n(i,n)
        cin>>a[i].x>>a[i].y;
    for1n(i,n)
        for1n(j,n)
            dis[i][j]=dis_qu(a[i],a[j]);
    dfs(1,0,0);
   	printf("%.2lf",ans);
}
