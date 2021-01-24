#include<bits/stdc++.h>
using namespace std;

class examinfo
{
	private:
		string name;
		enum {Grade,Pass,Percentage}mode;
		union
		{
			char grade;
			bool pass;
			int percent;
		};
		
	public:
	examinfo(string name,char grade):
		name(name),mode(Grade),grade(grade){}
	examinfo(string name,bool pass):
		name(name),mode(Pass),pass(pass){}
	examinfo(string name,int percent):
		name(name),mode(Percentage),percent(percent){ }
		
	void show();
};

void examinfo::show()
{
	cout<<name<<":";
	switch(mode)
	{
		case Grade:cout<<grade; break;
		case Pass:cout<<(pass?"PASS":"FAIL");break;
		case Percentage:cout<<percent;break; 
	}
	cout<<endl;
}


int main(void)
{
	examinfo course1("English",'B');
	examinfo course2("Calculus",true);
	examinfo course3("C++ programing",85);
	
	course1.show();
	course2.show();
	course3.show();
	return 0;
}
		

