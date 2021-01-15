#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int b=99233;
	cout<<setiosflags(ios::showpos)<<b<<endl;//showpos产生正负号 
	cout<<hex<<b<<endl;
	cout<<setiosflags(ios::uppercase)<<b<<endl;//变为大写 
	cout<<setw(10)<<b<<','<<b<<endl;
	cout<<setfill('*')<<setw(10)<<b<<endl;
	cout <<b<<endl;
	return 0;
	
}
