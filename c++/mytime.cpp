#include<iostream>
using namespace std;

class time
{
	private:
		int hours;
		int minutes;
	public:
		time();
		time(int h,int m=0);
		void addmin(int m);
		void addhr(int h);
		void reset(int h=0,int m=0);
		time Sum(const time &t) const;
		void show() const;
};

time::time()
{
	hours=minutes=0;
}

time::time(int h,int m)
{
	hours=h;
	minutes=m;
}

void time::addmin(int m)
{
	minutes+=m;
	hours+=minutes/60;
	minutes%=60;
}

void time::addhr(int h)
{
	hours+=h;
}

void time::reset(int h,int m)
{
	hours=h;
	minutes=m;
}

time time::Sum(const time &t) const
{ 
	time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours;
} 

void time::show() const
{
	cout<<hours<<"hours; "<<minutes<<"minutes; ";
}
