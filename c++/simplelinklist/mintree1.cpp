#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct node
{
    int to,d; //终点和距离
    node(int a,int b)
    {
        to=a,d=b;
    }
};

ll ans;
vector<node>v[50010];
bool vis[50010];

void dfs(int s,ll dis) //对图的每一条边进行遍历
{//dfs只能遍历一次
    vis[s]=1; //标记到达了
    int size=v[s].size();
    
    if(size==1&&vis[v[s][0].to])
    {
        ans=max(ans,dis);
        return ;
    }

    for(int i=0;i<size;i++)
    if(!vis[v[s][i].to])    //对每一条还没有访问的边进行遍历
    {
    dfs(v[s][i].to,v[s][i].d+dis);
    } 
}

int main()
{
    int n,x,a,b,c;
    ll sum=0;
    cin>>n>>x;

    for(int i=1;i<n;i++) 
    {
        scanf("%d%d%d",&a,&b,&c); //无向图建边，两个节点和一条边
        v[a].push_back(node(b,c)); //vector建边 建立相邻的边
        v[b].push_back(node(a,c));
        sum+=c;
    }

    dfs(x,0); //从节点开始
    printf("%lld\n",2*sum-ans);
    return 0;
}