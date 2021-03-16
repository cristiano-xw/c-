#include<bits/stdc++.h>
using namespace std;
class date
{
	public:
		void setdate(int y,int m,int d)
		{
			year=y; month=m; day=d;
		}
		int isleapyear()//函数 
		{
			return (year%4==0&&year%100!=0)||(year%400==0);
		}
		void print()
		{
			cout<<year<<" "<<month<<" "<<day;
	    }
	    private:
	    	int year; int month; int day;
}; 

int main()
{
	date d1;
	//d1.setdate(2012,11,11);
	int x=0; int y=0; int z=0;
	cin>>x>>y>>z;
	d1.setdate(x,y,z);
	d1.print();
	cout<<endl;
	
	//cout<<d1.isleapyear()<<endl;
	if(d1.isleapyear()!=0)
	{
		cout<<"是闰年"; 
	}
	else
	{
		cout<<"不是";
	}
	return 0;
}
