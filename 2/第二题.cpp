#include<bits/stdc++.h>
#define ISYEAP(x) x%100!=0&&x%4==0||x%400==0?1:0
using namespace std;
int son[5001][13][32];	//保留预处理的天数
int dayofmonth[13][2] = 
{
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};		

struct Date {
	int Day;
	int Month;
	int Year;
	void nextDay() 
	{ 
		Day++;
		if (Day > dayofmonth[Month][ISYEAP(Year)]) {
			Day = 1;
			Month++;
			if (Month > 12) {
				Month = 1;
				Year++;
			}
		}
	}
};

class date
{
	private:
		int day; int month; int year;
	public:
		date(int year=1990,int month=1,int day=1)
		{
		}
		
		void setyear(int a)
		{
			year=a;
		}
		int getyear()
		{
			return year;
		}
		void setmonth(int b)
		{
			month=b;
			if(month>12)
			month=1;
		}
		int getmonth()
		{
			return month;
		}
		int setday(int c)
		{
			day=c;
			if(day>dayofmonth[month][ISYEAP(year)])
			{
				day=1;
			}
		}
		int getday()
		{
			return day;
		}
		int printfullyear()
		{
			cout<<"日期的完整输出"<<" "<<year<<"-"<<month<<"-"<<day<<endl;
		}
		int printstandardyear()
		{
			int d=year%100;
			if(d==0) cout<<"标准输出"<<" "<<"00"<<"-"<<month<<"-"<<day<<endl;
			if(d>=1&&d<=9) cout<<"标准输出"<<" "<<"0"<<d<<"-"<<month<<"-"<<day<<endl; 
			if(d>=10) cout<<"标准输出"<<" "<<d<<"-"<<month<<"-"<<day<<endl;
		}
		
		int fullyearsto(int a,int b,int c)
		{
			if(b>month&&b==month&&c>day)
			{
				cout<<"白活了"<<a-year<<"年"<<endl;
			}
			else 
			cout<<"白活了"<<a-year-1<<"年"<<endl;
		}
		
		int daysto(int a,int b,int c)
		{
			if(a>year||a==year&&b>month||a==year&&b==month&&c>day)
			cout<<"傻活了";
			printf("%d", son[a][b][c] - son[year][month][day] );
			printf("天\n");
			printf("祖国比我早诞生");
			printf("%d",son[year][month][day]-son[1949][10][1]);
			printf("天\n");
		}
		
};

 
int main()
{
	int a=0; int b=0; int c=0;
	cout<<"请输入你的生日 年月日"<<endl;
	cin>>a>>b>>c;
	Date tmp;
	int cnt = 0;		//天数计数
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	
	while (tmp.Year != 5001) 
	{  
		son[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.nextDay();
		cnt++;
	}
	
	date birthdate;
	birthdate.setyear(a); birthdate.setmonth(b);birthdate.setday(c);
	birthdate.printfullyear(); birthdate.printstandardyear();
	cout<<"输入日期";
	cin>>a>>b>>c;
	birthdate.fullyearsto(a,b,c);
	birthdate.daysto(a,b,c);
	
	
	return 0;
	 
}
