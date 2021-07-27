#include<bits/stdc++.h>
using namespace std;

struct point
{
    double x; double y;
}; //建立点

double distan(point xx,point yy)
{
    return sqrt((xx.x-yy.x)*(xx.x-yy.x)+(xx.y-yy.y)*(xx.y-yy.y));
}

int n;
double ans=1e6;
point a[30];
bool b[30]; double dis[30][30];
//b相当于是标记数组
void dfs(int x,int poi,double sum)
{
    if(x==n+1)
    {
        ans=min(ans,sum);
        return;
    }
    if(sum>ans)
        return;
    for(int i=1;i<=n;i++)
    {
        if(!b[i]) //这个点没有出发过
        {
            b[i]=1;
            dfs(x+1,i,sum+dis[poi][i]);//跟换出发点对每一个点进行遍历
            b[i]=0;
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dis[i][j]=distan(a[i],a[j]);
        }
    }
    dfs(1,0,0);
    printf("%.2f",ans);
    return 0;

}