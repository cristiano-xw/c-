#include<iostream>
using namespace std;

int getmax(int a,int b)
{
	return (a>b)? a:b;
}

char getmax(char a,char b)
{
	return (a>b)? a:b;
}

int main()
{
	double c=0;
	c=getmax(100,199.8); 
	cout<<c;
	return 0;
}
