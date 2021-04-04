#include<bits/stdc++.h>
using namespace std;

class book
{
	private:
		string name;//书名
		string auther;
		int price;//价格 
	
	public:
		
		int number;
		
		book()
		{
			auther="杨欣威"; name="高级语言";  number=100;  price=99;
		}
		
		book(string a,string b,int c,int d)
		{
			name=a; auther=b; price=c; number=d;
		} 
		
		~book()
		{
			
		}
		
		void display()
		{
			cout<<"书名:"<<name<<"  "<<"作者:"<<auther<<"  "<<"价格:"<<price<<"  "<<"剩余量:"<<number<<endl;
		}
		
		void borrow()
		{
			if(number>=1)
			{
			number--;
			cout<<"剩余的本数:"<<number<<endl;
			}
			else
			{
				cout<<"不要借书了，没了！"<<endl;
			}
		}
		
		void restore()
		{
			++number;
			cout<<"剩余的本数"<<number<<endl; 
		}
};

int main()
{
	book shuji;
	shuji.display();
	 
	cout<<"请输入书名";
	string a;string b;int c; int d;
	cin>>a;
	cout<<"请输入作者";
	cin>>b;
	cout<<"输入价格，剩余量";
	cin>>c;
	cin>>d;
	book shu(a,b,c,d);
	shuji=shu;
	
	cout<<"请输入指令:";
	
	char ch;
	ch=getchar();
	
	while(ch!='e')
	{
		if(ch=='b')
		{
			shuji.borrow();
		}
		
		if(ch=='r')
		{
			shuji.restore();
		}
		
		if(ch=='s')
		{
			shuji.display();
		}
		
		if(ch=='e')
		{
			break;
		}
		ch=getchar();
	}
	
	
	
	return 0;
	
}



