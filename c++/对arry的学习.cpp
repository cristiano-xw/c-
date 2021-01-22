#include<iostream>
#include<array>
#include<string>
using namespace std;
const int seasons=4;
const arry<string,seasons>sname={"spring","summer","fall","winter"};//arry盛放string类型
 
void fill(array<double,seasons>*pa);
void show(array<double,seasons>da);
int main(void)
{   
    arry<double,seasons>expenses;//盛放double类型 
    fill(&expenses);
    show(expenses);
	return 0;
}

void fill(arry<double,seasons>*pa)
{
	int =0;
	for(i=0;i<seasons;i++)
	{
		cout <<"enter"<<sname[i]<<"expenses";
		cin>>(*pa)[i];
	}
}

void show(arry<double,seasons>da)
{
	double total=0.0;
	cout<<"\nexpenses\n";
	for(i=0;i<seasons;i++)
	{
		cout<<sname[i]<<":$"<<da[i]<<endl;
		total+=da[i];
	}
	cout<<"total expenses:$"<<total<<endl;
}





