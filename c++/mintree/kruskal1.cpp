//kruskal算法的最小生成树
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int u; 
    int v;
    int w;
}edge[200005]; 

int fa[5005]; //并查集找父亲
int n=0; int m=0; int ans=0; int cnt=0;

bool cmp(Edge a,Edge b)
{
    return a.w<b.w; //按照边权进行排序，边权小的点在前面
}

int find(int x)
{
    while(x!=fa[x]) //并查集寻找父节点
    {
        x=fa[x]=fa[fa[x]]; //并查集直接找到祖先
    }
    return x; //找到x的祖先
}

int fa1; int fa2; //分别寻找两个父亲

void kruskal()
{
    sort(edge,edge+m,cmp);
    for(int i=0;i<m;i++)
    {
        fa1=find(edge[i].u);
        fa2=find(edge[i].v); //判断这两个点是否联通了 

        if(fa1==fa2)
        {
            continue;// 已经联通了，没有必要再加边了
        }
        ans+=edge[i].w; //将这条边的边权计入
        fa[fa1]=fa2; //将祖先进行合并

        if(++cnt==n-1)
        {
            break;
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }

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