#include<iostream>
#include"stock10.h"
using namespace std;

stock::stock()//默认构造 
{
	cout<<"default constructor called"<<endl;
	company="no name";
	shares=0;
	share_val=0.0;
	total_val=0.0;	
} 

stock::stock(const string &co,long n=0,double pr=0.0)//构造函数
{
	cout<<"constructing using"<<co<<" called"<<endl;
	company=co;
	if(n<0)
	{
		cout<<"numbers of shares can not be negative"<<endl;
		shares=0;
	}
	else shars=n;
	share_val=pr;
	set_tot;
}

stock::~stock()
{
	cout<<"ending......"<<endl;
}

void stock::buy(long num,double price)
{
	if(num<0)
	{
		cout<<"transaction is absorted.\n";
	}
	else
	{
		shares+=num;
		share_val=price;
		set_tot();
	}
}


