#include<iostream>
using namespace std;
class Widget
{
	int i[10];
public:
	Widget(){cout<<"*";}
	~Widget(){cout<<"~";} 
	
	void* operator new(size_t sz)
	{
		cout<<"Widget::new: "<<sz<<"bytes"<<endl;
		return ::new char[sz];
	}
	
	void operator delete(void* p)
	{
		cout<<"Widget::delete "<<endl;
		::delete []p;
	}
	
	void *operator new[](size_t sz)
	{
		cout<<"Widget::new[]: "<<sz<<"bytes"<<endl;
		return ::new char[sz];
	}
	
	void operator delete[](void *p)
	{
		cout<<"Widget::delete[] "<<endl;
		::delete []p;
	}
};

int main( )
{
	cout<<"(1-1) new Widget"<<endl;
	Widget *w=new Widget;
	cout<<"\n(1-2) delete Widget"<<endl;
	delete w;
	

	cout<<"\n(2-1)new Widget[25]"<<endl;
	Widget *const wa=new Widget[25];
	cout<<"\n(2-2)delete []Widget"<<endl;
	delete []wa;
	
	
	return 0;
}
