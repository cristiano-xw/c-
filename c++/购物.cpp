#include<bits/stdc++.h>
using namespace std;
int s[1111];
int main()
{
	int n=0; int x=0;
	cin>>x>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	sort(s+1,s+n+1);//��Ǯ��������
	if(s[1]!=1) 
	{
		cout<<"-1";
		return 0;
	}
	
	int sum=1;//��һ��Ǯ��ʼ�� 
	int ans=0;
	int i=0;
	
	while(sum<x)
	{
		for(i=n;i>=1;i--)
		{
			if(s[i]<=sum)
			{
				break;
			}
		}
		ans++;
		sum+=s[i];//sum��ֵ���ϵ�ǰ��ֵ 
	}
	
	cout<<ans;
	return 0;
}

