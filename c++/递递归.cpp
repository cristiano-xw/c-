#include<iostream>
using namespace std;
const int len=66;
const int divs=6;

int main(void)
{
	char ruler[len];
	int i=0;
	for(i=1;i<len-2;i++)
	{
		ruler[i]=' ';
	}
	ruler[len-1]='\0';
	int max=len-2; int min=0;
	ruler[min]=ruler[max]='|';
	cout<<ruler<<endl; 
	return 0;
}


