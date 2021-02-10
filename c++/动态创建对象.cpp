#include<iostream>
using namespace std;
class point
{
	public:
		point():x(0),y(0)
		{
			cout<<"default constructor called."<<endl;
		}
		point(int x,int y):x(x),y(y)
		{
			cout<<"constructor called."<<endl;
		}
		~point()
		{
			cout<<"destructor called."<<endl;
		}
		int getx()const {return x;}
		int gety()const {return y;}
		void move(int newx,int newy) 
		{
			x=newx; y=newy;
		}
	private:
		int x;int y;
};

int main()
{
	cout<<"step one:"<<endl;
	point*ptr1=new point;
	delete ptr1;
	
	cout<<"step two:"<<endl;
	ptr1=new point(1,2);
	delete ptr1;
	return 0;
}
