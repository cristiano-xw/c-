/*����һ����Ա��Person�����ݳ�Ա������š��������Ա𡢼�ͥסַ����ϵ�绰���Ա���char��ʵ�֣�
��f����ʾŮ�ԣ���m����ʾ���ԣ�������string���͡���Ա����������(1)���ñ��;(2)��������;(3)�����Ա�(4)���ü�ͥסַ��
(5)������ϵ�绰��(6)���캯����(7)���һ����Ա��ȫ��������Ϣ��*/
#include<bits/stdc++.h>
using namespace std;

class person
{
	private:
		string num;//��� 
		string name;//����
		char gender;//�Ա�
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
			cout<<"���: "<<num<<endl;
			cout<<"����: "<<name<<endl;
			cout<<"�Ա�: "<<gender<<endl;
			cout<<"��ͥ��ַ: "<<address<<endl;
			cout<<"��ϵ�绰: "<<phone<<endl; 
			 
		}
};

/*����һ������ѧ������Student��ΪPerson�๫���������������������ݳ�Ա������ѧ������Ӣ�����������ſγɼ���
���ſγɼ�Ϊ���͡�ע��̳����ı�ų�Ա�ڴ˴���������ѧ�š������ĳ�Ա����������
(1)������ѧ�������������������ſγɼ�������ԭ��Ϊvoid setScore(char tag, int score);
��tag��ֵ�ֱ�Ϊ��m������p������e���͡�c��ʱ���ֱ�������ѧ������Ӣ�����������ſγɼ���
(2)���캯����(3)���һ��ѧ����ȫ����Ϣ��
ע���ڴ˺����е��û����������Ա��ȫ��������Ϣ�ĺ���*/

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
			cout<<"��  ѧ: "<<math<<endl;
			cout<<"��  ��: "<<physics<<endl;
			cout<<"Ӣ  ��: "<<English<<endl;
			cout<<"�������:"<<cpp<<endl;
			 
		}
};

/*����һ��������ʦ����Teacher��ΪPerson�๫������������
���������ݳ�Ա������ְ�ơ����ʣ�ְ��Ϊstring���ͣ�����Ϊdouble�ͣ���
ע��̳����ı���ڴ˴�������Ϊ���š������ĳ�Ա����������(1)����ְ�ƣ�(2)���ù��ʣ�(3)���캯����
(4)���һ����ʦ��ȫ��������Ϣ��ע���ڴ˺����е��û����������Ա��ȫ��������Ϣ�ĺ�����*/

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
			cout<<"ְ  ��: "<<title<<endl;
			cout<<"��  ��: "<<wages<<endl; 
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
	s.setnum(a); s.setname(b); s.setgender(c); s.setaddress(d); s.setphone(e);//���������Ϣ
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
	t.setnum(a); t.setname(b); t.setgender(c); t.setaddress(d); t.setphone(e);//���������Ϣ
	t.settitle(w); t.setwages(m);
	t.show();
	cout<<endl;
	cin>>m;
	t.changewages(m);
	t.show();
	cout<<endl;
	
	
	return 0;
	
	
}









