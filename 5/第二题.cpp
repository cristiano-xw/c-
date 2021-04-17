#include<bits/stdc++.h> 
using namespace std;
class animal
{
private:
    int height;   
    int weight;   
    char sex;    
public:
    animal() {}
    animal(int h,int w,char s)
    {
    	height=h; weight=w; sex=s;
	}
	
	void show()
	{
		cout<<"height:"<<height<<endl;
    	cout<<"weight:"<<weight<<endl;
    	cout<<"sex:"<<sex<<endl;
	}
};
 
class water:virtual public animal   
{
private:
    int swimming_speed;   
public:
    water() {}
    water(int h,int w,char s,int speed):
    animal(h,w,s),swimming_speed(speed) {}
    
    void show()
    {
    	cout<<"swimming_speed:"<<swimming_speed<<endl;
	}
};
 
class land:virtual public animal
{
private:
    int running_speed;
public:
    land() {}
    land(int h,int w,char s,int r_s):
        animal(h,w,s),running_speed(r_s) {} 
    void show()
    {
    	cout<<"running_speed:"<<running_speed<<endl;
	}
};
 
class amp_animal:public land,public water
{
public:
    amp_animal() {}
    amp_animal(int h,int w,char s,int speed,int r_s):
    animal(h,w,s),water(h,w,s,speed),land(h,w,s,r_s) {}
    
    void show()
    {
    	animal::show();
    	water::show();
    	land::show();
	}
};
 
 

int main()
{
    amp_animal a1(50,20,'m',100,120);
    int a; int b; char c; int d ; int e;
    cin>>a>>b>>c>>d>>e;
    amp_animal a2(a,b,c,d,e); 
    
    a1.show();
    cout<<endl;
    a2.show();
    return 0;
}
