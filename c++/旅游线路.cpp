#include<bits/stdc++.h>
using namespace std;
int a[111][20022];
int main()
{
	int m=0; int n=0;
	int ans=0; int sum=0;
	//ÿ������֮�䶼�������
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	} 
	
	for(int i=1;i<=n;i++)//һ��һ�е���
	{
		int d=-111111111;
		for(int j=1;j<=m;j++)
		{
			d=max(a[j][i],d);//�ҵ�ÿһ�е����ֵ 
		}
			if(d<0)
			{
				ans=max(ans,sum);//���仯��ס��ǰ�����ֵ����ֹ��ʧ
				if(sum+d>0) sum+=d;
				else sum=0;//����ǰ���· 
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
