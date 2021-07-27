#include<iostream>
#include<new>//bad_alloc definition
using namespace std;
class Widget
{
	int i[10];
public:
	Widget(){cout<<"Widget()::Widget()";}
	~Widget(){cout<<"Widget()::~Widget()";}
	void* operator new(size_t sz) throw(bad_alloc)
	{
		cout<<"Widget::new: "<<sz<<"bytes"<<endl;
		throw bad_alloc();
		return ::new char[sz];
	}
	void operator delete(void* p)
	{
		cout<<"Widget::delete "<<endl;
		::delete []p;
	}
 
};
int main( )
{	
	Widget *w=0;
	try
	{
		w=new Widget;
	}
	catch(bad_alloc)
	{
		cerr<<"Bad_alloc Eception!"<<endl;
		return 0;
	}
	delete w;
	return 0;
}
