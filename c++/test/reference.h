#include<iostream>//�����������
using namespace std;
int arr[10];
void test_11()//���õĵ�һ������ 
{
	cout<<"1�����õĵ�һ������"<<endl; 
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
    int a=10;//�ֲ�����
    return a;
}
//���ؾ�̬��������
int& fun02()
{
    static int a=20;
    cout << "static int a : " << a << endl;
    return a;
}
void test_12()//���õĵڶ������� 
{
	cout<<"���õĵڶ�������"<<endl; 
    //���ܷ��ؾֲ�����������
    int &ret01=fun01();
    //�����������ֵ��ô���뷵������
    fun02();
    fun02()=100;
    fun02();
}      
