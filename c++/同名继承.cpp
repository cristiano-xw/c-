#include<bits/stdc++.h>
using namespace std;
class base1
{
	public:
		int var;
		void fun(){cout<<"member of base1 "<<var<<endl;}
};

class base2
{
	public:
		int var;
		void fun(){cout<<"member of base2 "<<var<<endl;}
};

class derived:public base1,public base2
{
	public:
		int var;
		void fun(){cout<<"member of base3 "<<var<<endl;}
};

int main()
{
	derived d;//派生类的对象
	derived*p=&d;
	
	d.var=1;
	d.fun();
	
	d.base1::var=2;
	d.base1::fun();
	
	p->base2::var=3;
	p->base2::fun();
	
	return 0; 
}
