#include<iostream>
using namespace std;
class Base1
{
public:
	Base1( void )	{  cout <<"class Base1"<<endl;}
};
class Base2
{           
public:
	Base2( void )	{    cout <<"class Base2"<<endl;}
};
class Level1 :virtual  public Base2, virtual public Base1  
{// 定义派生类Level1,指定Base1为虚基类
public:
	Level1 ( void ){    cout <<"class Level1"<<endl;	}
};
class Level2 : virtual public Base2, virtual public Base1{  //同上
public:
	Level2 ( void ) {cout << "class Level2" <<endl;}
};

class Leaf : public Level1, public Level2
{ //同上
public:
	Leaf ( void ){	cout << "class Leaf" <<endl;	}
};


int main( void )
{
	Leaf obj;  // 创建一个派生类Leaf的对象
	return 0; //调用过的函数不会再调用第二次
}
