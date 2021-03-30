#include<bits/stdc++.h>
#include<stack>					
using namespace std;
stack<long long>a;
long long s[10005];    
int main()
{
	int n=0; int c=0;
	cin>>n>>c;    
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	
	int m=0; //表示已经弹出的元素
	int le=1; int ri=1; //分别表示两个指针 
	
	while(a.size()+m<n) 
	{
		long long minn=2*0x3f3f3f3f;
		int len=c-a.size(); 
		le=ri;//将指针指向没有读入的第一个数
		for(int i=le;i<le+len&&i<=n;i++)   
		{
			if(s[i]<minn)
			{
				ri=i;
				minn=s[i];
			}
			//记录最小值所在位置 
		}

		if(a.empty()==1||a.top()>=minn) 
		{
		 
			for(int i=le;i<=ri;i++) //读取到最小值即可 
			{
				a.push(s[i]);   	
			}
			++ri;//将指针后移 
		}
		
		else
		{
		ri=le;
		}
		
		cout<<a.top()<<" ";
		m++;
		a.pop();
	}
	
	while(a.empty()==0)
	{
		cout<<a.top()<<" ";
		a.pop();
	}  
	return 0;
}
