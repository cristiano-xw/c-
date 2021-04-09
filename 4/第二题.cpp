#include<bits/stdc++.h>
using namespace std;

class RECT
{
	protected:
		double x,y;
	public:
		RECT(double x1,double y1)
		{
			x=x1;
			y=y1;
		}
		
		virtual double area()
		{
			return x*y;
		}
		
		double peri()
		{
			return 2*(x+y);
		}
		
		virtual int isSquare()
		{
			if(x==y) return 1;
			else return 0;
		}
};

class CUB:public RECT
{
	private:
		double height;
	
	public:
		CUB(double h,double &x1,double &y1) : RECT(x1,y1)
		{
			height=h;
		}
		double area()//�������� 
		{
			return RECT::area()*2+RECT::peri()*height;
		}
		
		double volume()
		{
			return RECT::area()*height;
		}
		
		int isSquare()
		{
			if(x==y&&x==height)
			{
				return 1;
			}
			return 0;
		}
		
};

int main()
{
	double a=0; double b=0; double c=0;
	cout<<"����������Ҫ�ĳ����"<<endl;
	cin>>a>>b>>c;
	
	CUB cu(a,b,c);
	RECT*re=&cu;
	
	cout<<"����������"<<endl;
	cout<<re->area()<<" "<<cu.volume()<<endl;
	
	if(re->isSquare()==1)
	cout<<"������"<<endl;
	else
	cout<<"������"<<endl; 
	return 0;
}
