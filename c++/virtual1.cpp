#include<iostream>
using namespace std;

class Furniture
{                      // 声明公共基类
public:
	Furniture ( float w ) ;            
	void SetWeight( float w) ;         // 设置重量
	float GetWeight( );              // 访问重量
protected:
	float weight;                   // 重量
}; 

class Bed : virtual public Furniture
{                  // 将公共基类声明为虚基类
public:
	Bed ( float w ): Furniture( w ) {}    // 一级派生类构造函数
	void Sleep( void ) const;           // 睡觉		
};

class Sofa:  virtual public Furniture
{     // 在定义一级派生类时必须将公共基类声明为虚基类
public:
	Sofa ( float w ): Furniture( w ) {}   // 一级派生类构造函数，
	void WatchTV( void ) const;       // 看电视		
};

class SofaBed : public Sofa, public Bed {
public:	
	SofaBed ( float w ): Furniture(w), Sofa(w), Bed(w) {} 
        // 派生类构造函数的参数用来初始化3个基类的数据成员
	void FoldOut( void ) ;                           // 折叠
};
Furniture::Furniture ( float w ){ weight=w; }
void Furniture::SetWeight( float w)  {
	weight=w;
	cout<<"此家具重"<<weight<<"千克"<<endl;
}
float Furniture::GetWeight( ){	return weight;}

void Bed::Sleep( void ) const{	cout<<"开始睡觉。"<<endl;}
void Sofa::WatchTV( void ) const{cout<<"正在看电视。"<<endl;}
void SofaBed::FoldOut( void){	cout<<"可以折叠和打开。"<<endl;}

int main( ){
	SofaBed sb( 50.5 );
	sb.SetWeight( 51.9 );
	sb.WatchTV( );
	sb.FoldOut( );
	sb.Sleep( );
	return 0;
}


