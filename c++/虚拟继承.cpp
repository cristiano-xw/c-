#include<bits/stdc++.h>
using namespace std;
class base0
{
	public:
		int var0;
		void fun0(){cout<<"member of base0"<<endl;}
};

class base1:virtual public base0
{
	public:
		int var1;
};

class base2:virtual public base0
{
	public:
		int var2;
};

class derived:public base1,public base2
{
	public:
		int var;
		void fun(){cout<<"member of derived"<<endl;}
};

int main()
{
	derived d;
	d.var0=2;
	d.fun0();
	return 0;
}
