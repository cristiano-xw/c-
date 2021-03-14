#include<bits/stdc++.h>
#include<set>
#include<queue>
using namespace std;
int ru[50]; int ru1[50];int ru2[50]; //分别记录入度的数组
int n=0; int m=0;int cnt=0;//表示次数 
int sum=0; int ans=0;int siz=0;
struct node
{
	int num; int time;//分别表示序号和一共出现的次数
	node(int num=0, int time=0) :num(num),time(time){};  
}; 

vector<int> vec[50];
set<int>stl;

void output()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	{
		if(ru1[i]==0&&stl.count(i))
		{
			q.push(i);
			cout<<char(i+'A');//输出字母 
		}
	}
	
	while(q.empty()==0)
	{
		int k=q.front();
		q.pop();
		for(int i=0;i<vec[k].size();i++)
		{
			int v=vec[k][i];
			ru1[v]--;
			if(ru1[v]==0)
			{
				q.push(v);
				cout<<char(v+'A');
			}
		}	 
	}
	
	
}


void tuopu()//判断数组 
{
	queue<node>q;
	for(int i=0;i<26;i++)//寻找入度为0的点 
	{
		if(ru[i]==0&&stl.count(i))
		{
			q.push(node(i,1));
			sum++;
			//cout<<sum<<"pio ";
		}             
	}
	//cout<<sum<<"ok";
	while(q.empty()==0)
	{
		int k=q.front().num;
		int t=q.front().time;
		q.pop();//弹出
		for(int i=0;i<vec[k].size();i++)//遍历vector 
		{
			int v=vec[k][i];
			ru[v]--;//减少入度 
			if(ru[v]==0)//入度减少为0
			{
				sum++;
				q.push(node(v,t+1));
				ans=max(ans,t+1);
			} 
		} 
	}
	
	if(ans==n)
	{
		 printf("Sorted sequence determined after %d relations: ",cnt);
		 output();
		 printf(".");
		 exit(0);
	}
	
	if(sum!=siz)
	{ 
	    //cout<<sum<<"  ";
		printf("Inconsistency found after %d relations.",cnt);
		exit(0);
	}
}



int main()
{ 
    memset(ru,0,sizeof(ru));
    memset(ru1,0,sizeof(ru1));
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{ 
		string s;
		cin>>s;
		cnt=i;
		vec[s[0]-'A'].push_back(s[2]-'A');
		stl.insert(s[0]-'A');
		stl.insert(s[2]-'A');
		ru2[s[2]-'A']++;//增加入度 
		siz=stl.size();
		//cout<<siz<<"   ";
		sum=0; ans=0;
		memcpy(ru1,ru2,sizeof(ru2));  //将ru数组进行拷贝 
		memcpy(ru,ru2,sizeof(ru2));
		
		tuopu();
	}
	 printf("Sorted sequence cannot be determined.");//余下的情况即为不可判断 
	
	return 0;
}
