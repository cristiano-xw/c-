#include<iostream>
#include"mytime3.h"
using namespace std;

int main()
{
	time planning;
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
	
	time dis;
	dis=fixing-coding;
	dis.show();
	return 0;
}
