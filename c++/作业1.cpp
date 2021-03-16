#include<bits/stdc++.h>
using namespace std;
int mapp[20][20];
 
int main()
{
	int m=0; 
	cin>>m; 
	 
	int sum=0;
	
	for(int i=m;i>=0;i--)
	{
		sum+=i;
	}
	//cout<<sum<<endl;
	
    int cnt=0;//定义层数
	int k=0;
	
	while(k<sum)
	{   
	    
		for(int j=1+cnt;j<=m-2*cnt;j++)//横向循环 
		{
			mapp[1+cnt][j]=++k;
			//k=k+1;
			if(k>=sum) break;
		}
		if(k>=sum) break;
		//cout<<k<<endl;
		
		for(int i=2+cnt;i<=m-2*cnt;i++)
		{
			mapp[i][m+1-cnt-i]=++k;  
			if(k>=sum) break;
		} 
		if(k>=sum) break;
		
		for(int i=m-2*cnt-1;i>=1+cnt+1;i--)
		{  
			mapp[i][1+cnt]=++k;
			if(k>=sum) break;
		}
		if(k>=sum) break;
		cnt=cnt+1;
		
		//cout<<k<<endl;
	}
	
	//cout<<mapp[1][5]<<endl;
	//cout<<mapp[1][1]<<endl;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m+1-i;j++)
		{
			cout<<mapp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
	
}
