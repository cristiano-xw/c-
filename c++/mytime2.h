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
		time operator+(const time &t) const;
		void show() const;
};

time::time()
{
	hours=minutes=0;//��������漰���������Ĺ��죬��һ��Ҫдһ�����캯������ʼ�� 
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

time time::operator+(const time &t) const
{
	time sum;
	sum.minutes=minutes+t.minutes;
	sum.hours=hours+t.hours+sum.minutes/60;
	sum.minutes%=60;
	return sum;
}

void time::show() const
{
	cout<<hours<<"hours; "<<minutes<<"minutes; ";
}
