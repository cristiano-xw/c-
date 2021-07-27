#include<iostream>//对数组的引用
using namespace std;
int arr[10];
void test_11()//引用的第一个案例 
{
	cout<<"1）引用的第一个案例"<<endl; 
    int (&f)[10]=arr;
    for(int i=0;i<10;i++)
    {
        f[i]=i+10;
    }
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int & fun01()
{
    int a=10;//局部变量
    return a;
}
//返回静态变量引用
int& fun02()
{
    static int a=20;
    cout << "static int a : " << a << endl;
    return a;
}
void test_12()//引用的第二个案例 
{
	cout<<"引用的第二个案例"<<endl; 
    //不能返回局部变量的引用
    int &ret01=fun01();
    //如果函数做左值那么必须返回引用
    fun02();
    fun02()=100;
    fun02();
}      
