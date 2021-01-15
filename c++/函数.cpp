#include<iostream>
using namespace std;
int stone(int n); 
int main(void)
{
	int n;
	cout<<"enter the weight of stone"<<endl;
	cin>>n;
	int pounds=stone(n);
	cout<<pounds<<endl;
	return 0;
}
int stone(int n)
{
	return n*3;
}
