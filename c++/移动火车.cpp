#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int main(void)
{   
    int n=0;
    int a[1111]={};
    cin>>n;
    int i=0;
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
	}
	
	 
	int v=0;//ÒÆ¶¯´ÎÊý
	int j=0;
	
	for(j=0;j<n;j++)
	{
		for(i=0;i<n-1;i++)
		{ 
			if(a[i]>a[i+1])
			{
				swap(a[i],a[i+1]);
				v++;
				continue;
			}
			if(a[i]<a[i+1])
			{
				continue;
			}
		}
	}
	
	cout<<v;
	
	
	return 0;
}
