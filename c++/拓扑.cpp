#include <bits/stdc++.h>
#define MAXN 50
using namespace std;
int n,m;
struct Node{
    int u;
    int val;
    Node(int u=0,int val=0):u(u),val(val){}
};

vector<int> vec[MAXN];
int ru[MAXN];int ru2[MAXN];
int sum;
int ans;
int k;
set<int> s1;

void make()
{  
    queue<int> q;
    
    for(int i=0; i<26; i++){
        if(ru2[i]==0&&s1.count(i)){
            q.push(i);
            cout<<char(i+'A');
        }
    }
    
    while(!q.empty())
	{      
        int u=q.front();
        q.pop();
        for(int i=0; i<vec[u].size(); i++){
            int v=vec[u][i];
            ru2[v]--;
            if(ru2[v]==0){
                q.push(v);
                cout<<char(v+'A');
            }
        }
    }
    
}

int have;

void topo()//判断函数 
{   
    queue<Node> q;
    for(int i=0; i<26; i++)//将字母转换为数字 
	{ 
        if(ru[i]==0&&s1.count(i))     //判断入度为0且只出现过一次  
		{
            q.push(Node(i,1));//进入队列 
            sum++;
        } 
    }
    //cout<<sum<<"ok";
    
    while(!q.empty())
	{
        int u=q.front().u;  
        int val=q.front().val;
        q.pop();
        for(int i=0; i<vec[u].size(); i++){
            int v=vec[u][i];
            ru[v]--;
            if(ru[v]==0)
			{
                sum++;//得到一个入度为0的点，自加 
                q.push(Node(v,val+1));
                ans=max(ans,val+1);
            }
        }
    }
    
    if(ans==n){
        printf("Sorted sequence determined after %d relations: ",k);
        make();
        cout<<".";
        exit(0);
    }
    
    if(sum!=have)
	{
        printf("Inconsistency found after %d relations.",k);
        exit(0);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        string s;
        cin>>s;
        k=i;
        vec[s[0]-'A'].push_back(s[2]-'A');
        s1.insert(s[0]-'A');
        s1.insert(s[2]-'A');
        have=s1.size();
        ru2[s[2]-'A']++;//增加入度 
        sum=0;
        ans=0;
        memcpy(ru,ru2,sizeof(ru2));//进行数据拷贝 
        topo();
    }
    
    printf("Sorted sequence cannot be determined.");//余下的情况即为不可判断 
    return 0;
}

