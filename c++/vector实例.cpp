#include<iostream>
#include<vector>
using namespace std;

double average (const vector<double>&arr)
{
	double sum=0;
	for(int i=0;i<arr.size();i++)
	{
		sum+=arr[i];
	}
	return sum/arr.size();
}    

int main()
{
	int n=0;
	cout<<"n=";
	cin>>n;
	vector<double>arr(n);
	cout<<"please input"<<n<<"real times"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<"average="<<average(arr)<<endl;
	return 0;
}
