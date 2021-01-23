#include<iostream>
using namespace std;
class clock
{
	public:
		void settime(int newh = 0,int newm=0,int news=0);
		void showtime();
	private:
	int hour ,minute,second; 
};

void clock::settime(int newh,int newm,int news)
{
	hour=newh;minute=newm;second=news;
}

void clock::showtime()
{
	cout<<hour<<":"<<minute<<":"<<second;
} 

int main()
{
	 clock myclock;
	 myclock.settime(8,30,30);
	 myclock.showtime();
	 return 0;
}
