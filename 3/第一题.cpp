#include<bits/stdc++.h>
using namespace std;

class book
{
	private:
		string name;//����
		string auther;
		int price;//�۸� 
	
	public:
		
		int number;
		
		book()
		{
			auther="������"; name="�߼�����";  number=100;  price=99;
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
			cout<<"����:"<<name<<"  "<<"����:"<<auther<<"  "<<"�۸�:"<<price<<"  "<<"ʣ����:"<<number<<endl;
		}
		
		void borrow()
		{
			if(number>=1)
			{
			number--;
			cout<<"ʣ��ı���:"<<number<<endl;
			}
			else
			{
				cout<<"��Ҫ�����ˣ�û�ˣ�"<<endl;
			}
		}
		
		void restore()
		{
			++number;
			cout<<"ʣ��ı���"<<number<<endl; 
		}
};

int main()
{
	book shuji;
	shuji.display();
	 
	cout<<"����������";
	string a;string b;int c; int d;
	cin>>a;
	cout<<"����������";
	cin>>b;
	cout<<"����۸�ʣ����";
	cin>>c;
	cin>>d;
	book shu(a,b,c,d);
	shuji=shu;
	
	cout<<"������ָ��:";
	
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



