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
	
	int m=0; //��ʾ�Ѿ�������Ԫ��
	int le=1; int ri=1; //�ֱ��ʾ����ָ�� 
	
	while(a.size()+m<n) 
	{
		long long minn=2*0x3f3f3f3f;
		int len=c-a.size(); 
		le=ri;//��ָ��ָ��û�ж���ĵ�һ����
		for(int i=le;i<le+len&&i<=n;i++)   
		{
			if(s[i]<minn)
			{
				ri=i;
				minn=s[i];
			}
			//��¼��Сֵ����λ�� 
		}

		if(a.empty()==1||a.top()>=minn) 
		{
		 
			for(int i=le;i<=ri;i++) //��ȡ����Сֵ���� 
			{
				a.push(s[i]);   	
			}
			++ri;//��ָ����� 
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
