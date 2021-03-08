#include<iostream>
using namespace std;

class base1
{
	public:
		void display () const{cout<<"base1::display()"<<endl;}
};
class base2:public base1
{
	public:
		void display() const{cout<<"base2::display()"<<endl;}
};
class derived:public base2
{
	public:
		void display() const{cout<<"derived::display()"<<endl;}
};

void fun(base1*ptr)
{
	ptr->display();
}

int main()
{
	base1 x;
	base2 y;
	derived z;
	fun(&x); fun(&y); fun(&z);
	return 0;
}
