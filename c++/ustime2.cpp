#include<iostream>
#include"mytime2.h"
using namespace std;

int main()
{
	time planning();
	//planning(2,89);	
	time coding(2,40);
	time fixing(5,55);
	time total;
	
	cout<<"planning time = ";
	planning.show();
	cout<<endl;
	
	cout<<"coding time = ";
	coding.show();
	cout<<endl;
	
	total=coding+fixing;//在这个地方重载了运算符 
	cout<<"coding + fixing =";
	total.show();
	cout<<endl;
	
	time morefixing(3,28);
	cout<<"more fixing time =";
	morefixing.show();
	cout<<endl;
	
	total=morefixing+total;
	total.show();
	cout<<endl; 
}
