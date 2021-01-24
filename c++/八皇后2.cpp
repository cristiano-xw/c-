#include<bits/stdc++.h>
int a[100]; int b[100]; int c[100]; int d[100];//分别表示一列一行两个斜线
//a[]表示在每一行的列号 
int total=0;//总共的方案数;
int n=0; //从第1行到第n行 
using namespace std;
 
void queen(int i=0)//表示此时是第i个皇后
{
	if(i>n) //完成n个皇后的全部安排
	{                          
		if(total<=2)  //0 1 2   
		{
			int k=0;
			for(k=1;k<=n;k++)  //从第1行到第n行  
			{
				printf("%d ",a[k]);
			}
			printf("\n"); 
		}
		total++;
	} 
	
	if(i<=n) //还没有完成遍历 
	{
		 int j=0;
		 for(j=1;j<=n;j++)//遍历这一行的0到n-1的位置 看是否被占领过 
		 {
		 	if(b[j]==0&&c[i+j]==0&&d[j-i]==0)//没有被占领过
			{  
			a[i]=j; b[j]=1; c[i+j]=1; d[j-i]=1; //表示占领  
			queen(i+1);//寻找下一个皇后 
			b[j]=0; c[i+j]=0; d[j-i]=0; //表示回溯        
			} 
		 } 
	} 
} 

int main(void)
{  
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b)); 
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
	scanf("%d",&n);
	queen(1);//从第一个皇后开始
	printf("%d",total);
	return 0; 
}   


