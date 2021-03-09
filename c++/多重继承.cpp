#include<bits/stdc++.h>
using namespace std;
class base0
{
	public:
		int var0;
		void fun0(){cout<<"member of base0"<<endl;}
} ;

class base1:public base0
{
	public:
		int var1;
};

class base2:public base0
{
	public:
		int var2;	
};

class derived:public base1,public base2
{
	public:
		int var;
		void fun(){cout<<"constructing of derived"<<endl;}
};

int main()
{
	derived d;
    d.fun();
	d.base1::var0=2;
	d.base1::fun0();
	d.base2::fun0();
	return 0; 
}
