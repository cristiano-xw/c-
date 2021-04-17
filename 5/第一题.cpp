/*定义一个人员类Person，数据成员包括编号、姓名、性别、家庭住址、联系电话。性别用char型实现，
’f’表示女性，’m’表示男性，其它用string类型。成员函数包括：(1)设置编号;(2)设置姓名;(3)设置性别；(4)设置家庭住址；
(5)设置联系电话；(6)构造函数；(7)输出一个人员的全部描述信息。*/
#include<bits/stdc++.h>
using namespace std;

class person
{
	private:
		string num;//编号 
		string name;//姓名
		char gender;//性别
		string address;
		string phone;
	public:
		person()
		{
			
		}
		void setnum(string a)
		{
			num=a;
		}
		void setname(string a)
		{
			name=a;
		}
		void setgender(char a)
		{
			if(a=='f')
			{
				gender='f';
			}
			else
			{
				gender='m';
			}
		}
		void setaddress(string a)
		{
			address=a;
		}
		void setphone(string a)
		{
			phone=a;
		}
		void changephone(string a)
		{
			phone=a;
		}
		
		void show()
		{
			cout<<"编号: "<<num<<endl;
			cout<<"姓名: "<<name<<endl;
			cout<<"性别: "<<gender<<endl;
			cout<<"家庭地址: "<<address<<endl;
			cout<<"联系电话: "<<phone<<endl; 
			 
		}
};

/*定义一个描述学生的类Student，为Person类公有派生而来。新增的数据成员包括数学、物理、英语、程序设计四门课成绩，
各门课成绩为整型。注意继承来的编号成员在此处的意义是学号。新增的成员函数包括：
(1)设置数学、物理、外语、程序设计四门课成绩，函数原型为void setScore(char tag, int score);
当tag的值分别为’m’、’p’、’e’和’c’时，分别设置数学、物理、英语、程序设计四门课成绩。
(2)构造函数；(3)输出一个学生的全部信息，
注意在此函数中调用基类中输出人员的全部描述信息的函数*/

class student:public person
{
	private:
		int math; int physics;
		int English; int cpp;
	
	public:
		void setscore(int a,int b,int c,int d)
		{
			math=a; physics=b; English=c; cpp=d;
		}
		
		void changescore(char tag,int score)
		{
			if(tag=='m')
			{
				math=score;
			}
			
			if(tag=='p')
			{
				physics=score;
			}
			if(tag=='e')
			{
				English=score;
			}
			if(tag=='c')
			{
				cpp=score;
			}
		}
		
		void show()
		{
			person::show();
			cout<<"数  学: "<<math<<endl;
			cout<<"物  理: "<<physics<<endl;
			cout<<"英  语: "<<English<<endl;
			cout<<"程序设计:"<<cpp<<endl;
			 
		}
};

/*定义一个描述教师的类Teacher，为Person类公有派生而来。
新增的数据成员包括：职称、工资（职称为string类型，工资为double型），
注意继承来的编号在此处的意义为工号。新增的成员函数包括：(1)设置职称；(2)设置工资；(3)构造函数；
(4)输出一个教师的全部描述信息，注意在此函数中调用基类中输出人员的全部描述信息的函数。*/

class teacher:public person
{
	private:
		string title;
		double wages;
		
	public:
		void settitle(string a)
		{
			title=a;
		}
		
		void setwages(double a)
		{
			wages=a;
		}
		teacher()
		{
		};
		
		void changewages(double a)
		{
			wages=a;
		}
		
		void show()
		{
			person::show();
			cout<<"职  称: "<<title<<endl;
			cout<<"工  资: "<<wages<<endl; 
		}
};

int main()
{
	person p;
	string a; string b;
	cin>>a; cin>>b; 
	char c; cin>>c;
	string d; string e;
	cin>>d>>e;
	
	p.setnum(a);p.setname(b); p.setgender(c);p.setaddress(d);p.setphone(e);
	p.show();
	cout<<endl;
	
	cin>>e;
	p.setphone(e);
	p.show();
	cout<<endl;
	
	student s;
	cin>>a>>b;
	cin>>c;
	cin>>d>>e;
	s.setnum(a); s.setname(b); s.setgender(c); s.setaddress(d); s.setphone(e);//读入基本信息
	int a1; int b1; int c1; int d1;
	cin>>a1>>b1>>c1>>d1;
	s.setscore(a1,b1,c1,d1); 
	s.show();
	cout<<endl;
	char n1;
	cin>>n1;
	int n2;
	cin>>n2;
	s.changescore(n1,n2);
	s.show();
	cout<<endl;
	
	teacher t;
	cin>>a>>b;
	cin>>c;
	cin>>d>>e;
	string w; double m;
	cin>>w>>m;
	t.setnum(a); t.setname(b); t.setgender(c); t.setaddress(d); t.setphone(e);//读入基本信息
	t.settitle(w); t.setwages(m);
	t.show();
	cout<<endl;
	cin>>m;
	t.changewages(m);
	t.show();
	cout<<endl;
	
	
	return 0;
	
	
}









