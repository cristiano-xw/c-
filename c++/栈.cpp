#include<iostream>
#include<cctype>
#include"stack2.h"     
using namespace std;

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
