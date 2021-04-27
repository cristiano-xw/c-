#include<iostream>
using namespace std;

class acount
{
	public:
	int id; 
	string name;
	float balance;
	void deposit(float amount);
	void withdraw(float amount);
	void exit();
	acount()
	{
		
	}
	acount(int x,float b)
	{
		id=x;
		money=b;
	}
	float money;
};

void acount::withdraw(float x)
{
	money=money-x;
}

void acount::deposit(float x)
{
	money=money+x;
}

void acount::exit()
{
	cout<<"bye"<<endl;
}

int main()
{
	acount a[5];
	for(int i=1;i<=5;i++)
	{
		a[i].id=i+100;
		a[i].money=100;
	}
	
	
	while(1)
	{
	cout<<"输入一个id"<<endl;
	int x=0;
	cin>>x;
	while(x<=100||x>=106)
	{
		cout<<"重输"<<endl;
		cin>>x;
	}
	int i=0;
	
	while(i!=4)
	{
	 
	if(101<=x<=105)
	{
		cout<<"enter an id "<<x<<endl;
		cout<<"main menu"<<endl;
		cout<<"1 check banlance"<<endl;
		cout<<"2 withdraw"<<endl;
		cout<<"3 deposit "<<endl;
		cout<<"4 exit "<<endl;
		cin>>i;
	} 
	
	if(i==1)
	{
		cout<<"余额 "<<a[x-100].money<<endl;
	}
	
	if(i==2)
	{
		cout<<"取多少"<<endl;
		float n=0;
		cin>>n;
		if(a[x-100].money>=n)
		{
			a[x-100].money-=n;
		}
		else
		cout<<"error"<<endl; 
	}
	
	if(i==3)
	{
		cout<<"存多少"<<endl;
		float n=0;
		cin>>n;
		a[x-100].money+=n;
	}
	
	if(i==4)
	{
		cout<<"bye"<<endl; 
	}
	}
	
	}
	return 0;
	
}



