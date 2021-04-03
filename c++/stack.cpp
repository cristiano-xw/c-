#include"stack.h"
#include<iostream>
#include<cctype>
using namespace std;

stack::stack()
{
	top=0;
}

bool stack::isempty() const
{
	return top==0;   //判断是否是空栈 
}

bool stack::isfull() const
{
	return top==MAX;//判断是否满栈 
}

bool stack::push(const Item &item)
{
	if(top<MAX)
	{
		items[top++]=item;
		return true;
	}
	
	else 
		return false;
} 

bool stack::pop(Item & item)
{
	if(top>0)
	{
		item=items[--top];
		return true;
	}
	else
		return false;
}

int main()
{
	stack st;
	char ch;
	unsigned long po;
	cout<<"please enter A to add a purchase order,\n"<<"p to process a PO ,or Q to quit.\n";
	
	while(cin>>ch&&toupper(ch)!='Q')  //转化小写字母位大写
	{
		while(cin.get()!='\n')
		{
			continue;
		}
		
		switch(ch)
		{
			case 'A'://增加 
			case 'a': 
				cout<<"enter a po number to add:";
				cin>>po;
				if(st.isfull()) 
				{
					cout<<"stack already full\n";
				}
				else 
					st.push(po);
					break;
			
			case 'p':
			case'P': 
				if(st.isempty())
				{
					cout<<"stack already empty\n";
				}
				else 
				{
					st.pop(po);
					cout<<"po# "<<po<<" popped\n";
				}
				break;
		}
		cout<<"please enter A to add a purchase order\n"
		<<"p to process a PO, or Q to quit.\n";
	} 
	cout<<"Bye"<<endl;
	return 0;
}
