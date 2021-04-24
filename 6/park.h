#include<bits/stdc++.h>
using namespace std;
class Automobile;

class Park    
{
public:
    Park(int a);//表示剩余的车位 
    void parkAllote(Automobile* a);
    void feeTake(Automobile* a,int f);
    void showInfo();//显示结果的构造函数 
    ~Park();

    private:
    Automobile** space;//指针数组分配 
    int income=0;	//表示停车场的收入 
    int n;
    int cnt=0;
};

Park::Park(int a)
{
    n=a;
    space = new Automobile * [n]; 
    for (int i = 0; i < n; i++)
    {
        space[i] = NULL;
    }
    income = 0;
    cnt = 0;
}

class Automobile
{
	public:
		Automobile()
		{
		}
		void enter(Park* park);//表示进入 
    	//virtual void leave(Park* a);//表示出去 
		Automobile(string a)  
		{
			number=a;
		}
		string getnumber()	//旨在输出车牌 
		{
			return number;
		}
		
	private:
		string number;	//表示车牌 
};

class Truck :public Automobile
{
	public:          
		Truck(string a,double b):Automobile(a)//利用形参传递实参 
		{
			weight=b;              
		}
		virtual void leave(Park*a);
		
	private:
		double weight;
};

class car:public Automobile
{
	public:
		car(string a,string b):Automobile(a)
		{
			brand=b;
		}
		virtual void leave(Park*a);
	private:
		string brand;
};

class bus:public Automobile
{
	public:
		bus(string a,int b):Automobile(a)
		{
			people=b;
		}
		virtual void leave(Park*a);
	private:
		int people;
};

void Park::parkAllote(Automobile*a)		//分配车位 
{
	int i=0;
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(space[i]==NULL)
		{
			space[i]=a;
			cnt++;
			cout<<a->getnumber()<<",进入停车场，分配车位。"<<endl;
			flag=1;
			break;
		}
	}
	
	if(flag==0) 
	{
		cout<<"无法为"<<a->getnumber()<<"分配车位"<<endl; 
	}
} 

void Park::feeTake(Automobile*a,int f)//收费函数 
{
	for(int i=0;i<n;i++)
	{
		if(space[i] == a)
		{   
			space[i] = nullptr;	//传递一个空指针 
			cnt--;//多出来一个车位
			income+=f;
			break; 
		}
		
	}
	cout<<a->getnumber()<<"离开了停车场,缴纳费用" <<f<<"元"<<endl;
}


void Park::showInfo()
{
	cout<<"停车场停放了，"<<cnt<<"辆汽车"<<",";
	
	for (int i = 0; i < n; i++)//显示车牌号 
    {
        if (space[i] != nullptr)
        {
            cout<<space[i]->getnumber()<<",";
        }
    }
    cout<<"总共收入"<<income<<"元停车费"<<endl;    
}

void Automobile::enter(Park* park)
{
    park->parkAllote(this);//对其分配车位 
} 

void Truck::leave(Park* park)//卡车离开 
{
    park->feeTake(this,3);
}

void car::leave(Park* park)
{
    park->feeTake(this, 1);
}

void bus::leave(Park* park)
{
    park->feeTake(this, 2);
}

Park::~Park()
{
	delete[] space;
}










