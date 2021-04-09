#include<bits/stdc++.h>
using namespace std;
int b[20]={0,1,-3,-1,3,2,4,-4,5,-5,-2};//´Ó1¿ªÊ¼ 

class ARR
{
	private:
		int n; int a[100];
	public:
		void add(int b[],int size)
		{
			for(int i=1;i<=size;i++)
			{
				a[i]=b[i];
			}
		}
		
		void change()
		{
			int i=1; int j=10;
			while(j>i) 
			{
				while(a[i]<0)
				{
					i++;
				}
				
				while(a[j]>=0)
				{
					j--;
				}
				swap(a[i],a[j]);
				i++; j--;
			} 
		}
		
		void show()
		{
			for(int i=1;i<=10;i++)
			{
				cout<<a[i]<<" "; 
			}
		}
};

int main()
{
	ARR p;
	for(int i=1;i<=10;i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	p.add(b,10);
	p.change();
	p.show();
	return 0;
}
