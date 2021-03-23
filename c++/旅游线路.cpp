#include<bits/stdc++.h>
using namespace std;
int a[111][20022];
int main()
{
	int m=0; int n=0;
	int ans=0; int sum=0;
	//每两个点之间都是林荫街
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	} 
	
	for(int i=1;i<=n;i++)//一列一列的走
	{
		int d=-111111111;
		for(int j=1;j<=m;j++)
		{
			d=max(a[j][i],d);//找到每一列的最大值 
		}
			if(d<0)
			{
				ans=max(ans,sum);//记忆化记住当前的最大值，防止损失
				if(sum+d>0) sum+=d;
				else sum=0;//放弃前面的路 
			}
			if(d>0)
			{
			sum+=d;	
			} 
	} 
	
	ans=max(ans,sum);
	cout<<ans;
	return 0;
}
