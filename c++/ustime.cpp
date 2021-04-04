#include<iostream>
#include"mytime.h"
using namespace std;
int main()
{
	time planning;
	time coding(2,40);
	time fixing(3,55);
	time total;
	
	cout<<"planning time =";
	planning.show();
	cout<<endl;
	
	cout<<"coding time=";
	coding.show();
	
	total=coding.Sum(fixing);
	cout<<"total time is ";
	total.show();
	cout<<endl;
	
	return 0;
}
