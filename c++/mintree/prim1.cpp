#include<bits/stdc++.h>
using namespace std;

#define inf 999999999
#define maxn 5005
#define maxm 200005

struct edge
{
    int v;//表示终点
    int w;//表示边权
    int next; //即为同起点的上一条边
    //链式前向星建边是从后往前进行建边
}e[maxm*2];

int head[maxn];int dis[maxn];
int n; int m; int tot;int now=1;int ans=0;
int cnt=0;
bool vis[maxn]; //标记数组

void add(int u,int v,int w) //起点 终点 边权
{
    e[++cnt].v = v;
    e[cnt].w = w;
    e[cnt].next=head[u]; //上一条同起点边的编号
    head[u]=cnt; //更新以u为起点边的编号
}

int prim() //prim算法
{
    for(int i=2;i<=n;i++)
    {
        dis[i]=inf; //默认为最大
    }
    //准备从第一条边开始遍历
    for(int i=head[1];i;i=e[i].next)
    {
        dis[e[i].v]=min(dis[e[i].v],e[i].w);
    }

    while(++tot<n)
    {
        int minn=inf;
        vis[now]=1;
        //枚举每一个没有使用过的点 找出最小值作为新边
          
            for(int i=1;i<=n;i++)
            {    
                if(!vis[i]&&minn>dis[i])
                {
                    minn=dis[i];
                    now=i; //找出当前的最短边
                }
            }

        //找出此时最短边所对应的点
        ans+=minn; //加上这条边到所有边之和
        //枚举now的所有相连的边这些边都有相同的起点now，更新dis数组
        for(int i=head[now];i;i=e[i].next)
        {
            int v=e[i].v; //找到这些边的终点
            if(dis[v]>e[i].w&&!vis[v])
            {  
                dis[v]=e[i].w; //找到了一条到达该点的最短边
            }
        }
    }
    return ans;
}


int main()
{
    cin>>n>>m;
    for(int i=1,u,v,w;i<=m;++i)
    {
        cin>>u>>v>>w;
        add(u,v,w),add(v,u,w); //建立双向边
    }
   
    cout<<prim()<<endl;
    return 0;
}