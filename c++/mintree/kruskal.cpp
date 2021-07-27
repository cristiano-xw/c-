#include<bits/stdc++.h>
using namespace std;


struct Edge
{
	int u; //起点
    int v; //终点
    int w; //边权
}edge[200005];


int fa[5005],n,m,ans,eu,ev,cnt;

bool cmp(Edge a,Edge b)
{
    return a.w<b.w;   //快排边权从小排到大
}


int find(int x)
{
    while(x!=fa[x]) x=fa[x]=fa[fa[x]];
    return x;
}

//并查集循环实现模板，及路径压缩，不懂并查集的同学可以戳一戳代码上方的“并查集详解”
void kruskal()
{
    sort(edge,edge+m,cmp);
    //将边的权值排序
    for(int i=0;i<m;i++)
    {
        eu=find(edge[i].u), ev=find(edge[i].v);
        if(eu==ev)
        {
            continue;
        }
        //若出现两个点已经联通了，则说明这一条边不需要了
        ans+=edge[i].w;
        //将此边权计入答案
        fa[ev]=eu;
        //将eu、ev合并
        if(++cnt==n-1)
        {
            break;
        }
        //循环结束条件，及边数为点数减一时
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    //初始化并查集

    for(int i=0;i<m;i++)
    {
        cin>>edge[i].u; 
        cin>>edge[i].v;
        cin>>edge[i].w;
    }

    kruskal();
    cout<<ans;
    return 0;
}