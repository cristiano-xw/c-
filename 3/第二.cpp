#include<bits/stdc++.h>
using namespace std;

class student
{
	public:
		int number;
		int score;
		string name;
		int total;
};

bool cmp(student a,student b)
{
	if(a.score!=b.score)
	{
		return a.score>b.score;
	}
	return a.number>b.number;
}

int main()
{
	student a[10];
	for(int i=1;i<=4;i++)
	{
		printf("������%dλѧ������Ϣ ѧ�ţ�����������\n",i);
		cin>>a[i].number>>a[i].score>>a[i].name;
	}
	
	sort(a+1,a+5,cmp);
	for(int i=1;i<=4;i++)
	{
		printf("����%d",i);
		cout<<endl;
		cout<<a[i].number<<" "<<a[i].score<<"  "<<a[i].name<<endl;
	}
	return 0;
}
