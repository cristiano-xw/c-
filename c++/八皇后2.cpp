#include<bits/stdc++.h>
int a[100]; int b[100]; int c[100]; int d[100];//�ֱ��ʾһ��һ������б��
//a[]��ʾ��ÿһ�е��к� 
int total=0;//�ܹ��ķ�����;
int n=0; //�ӵ�1�е���n�� 
using namespace std;
 
void queen(int i=0)//��ʾ��ʱ�ǵ�i���ʺ�
{
	if(i>n) //���n���ʺ��ȫ������
	{                          
		if(total<=2)  //0 1 2   
		{
			int k=0;
			for(k=1;k<=n;k++)  //�ӵ�1�е���n��  
			{
				printf("%d ",a[k]);
			}
			printf("\n"); 
		}
		total++;
	} 
	
	if(i<=n) //��û����ɱ��� 
	{
		 int j=0;
		 for(j=1;j<=n;j++)//������һ�е�0��n-1��λ�� ���Ƿ�ռ��� 
		 {
		 	if(b[j]==0&&c[i+j]==0&&d[j-i]==0)//û�б�ռ���
			{  
			a[i]=j; b[j]=1; c[i+j]=1; d[j-i]=1; //��ʾռ��  
			queen(i+1);//Ѱ����һ���ʺ� 
			b[j]=0; c[i+j]=0; d[j-i]=0; //��ʾ����        
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
	queen(1);//�ӵ�һ���ʺ�ʼ
	printf("%d",total);
	return 0; 
}   


