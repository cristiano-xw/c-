#include<bits/stdc++.h>
using namespace std;
class base0
{
	public:
		base0(int var):var0(var){}
		int var0;
		void fun0(){cout<<"member of base0 "<<var0<<endl;}
};

class base1:virtual public base0
{
	public:
		base1(int var):base0(var){}
		int var1;
};

class base2:virtual public base0
{
	public:
		base2(int var):base0(var){}
};

class derived:public base1,public base2
{
	public:
		derived(int var):base0(var),base1(var),base2(var){} 
		int var;
		void fun(){cout<<"member of derived"<<endl;}
};

int main()
{
	derived d(1);
	d.fun0();
	return 0;
}

