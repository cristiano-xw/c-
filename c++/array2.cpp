#include<bits/stdc++.h>
#include"Array.h" 
using namespace std;

//纯虚函数是一个在基类中声明的虚函数，它在该基类中没有定义具体的操作内容
class shape //抽象基类
{
    public:
    virtual double getCircumference() = 0;  //通过成员函数求得边长
    virtual void show() = 0;
    bool operator>(shape & a);  //重载预算符
    virtual ~shape() {}  
};

bool shape::operator>(shape &a)
{
    return getCircumference()>a.getCircumference(); //比较周长
}

class circle: public shape
{
    private:
        double r;
        double PI = 3.1415926;
    public:
        circle(double a):r(a)
        {                
        }
        double getCircumference()
        {
            return 2* PI *r;
        }
        static shape * creatcricle()
        {
            cout<<"请输入半径"<<endl;
            double r=0; cin>>r;
            return new circle(r); 
        }

        void show()
        {
            cout<<"圆的半径为：";
            cout<<r;
            cout<<"  圆的周长为：";
            printf("%.2f\n",getCircumference());  
        }
}; 

class rectangle: public shape 
{
    private:
        double lenghth;
        double width;
    public:
        rectangle(double a, double b)
        {
            lenghth=a;
            width=b;
        }

        static shape * creatrectangle()
        {
            cout<<"请输入长"<<endl;
            double a=0; cin>>a;
            cout<<"请输入宽"<<endl;
            double b=0; cin>>b;
            return new rectangle(a,b);  
        }

        double getCircumference()
        {
            return 2*(lenghth+width);
        }

        void show()
        {
            cout<<"长方形的长："<<lenghth<<"  长方形的宽："<<width<<"长方形的周长：";
            printf("%.2f\n",getCircumference()); 
        }

};  

class rightTriangle: public shape 
{
public:
	rightTriangle(double edge1, double edge2) :
		edge1(edge1), edge2(edge2) 
        {}

	double getCircumference() 
    {
		return edge1 + edge2 + sqrt(edge1 * edge1 + edge2 * edge2);
	}

    static shape * creattriangle()
    {
        cout<<"请输入长直角边"<<endl;
        double a=0; cin>>a;
        cout<<"请输入短直角边"<<endl;
        double b=0; cin>>b;
        return new rightTriangle(a,b);    
    }
	void show() 
    {
		cout << "直角三角形，直角边" << edge1 << "，直角边" << edge2 << "，周长" ;
        printf("%.2f\n",getCircumference()); 
	} //抽象基类的纯虚函数必须要有替代

private:
	double edge1;
	double edge2;
}; 

void Sort(Array<shape *> &a, int index, shape * ptr)  //index显然是当前的大小-1
{// 将新创建的形状ptr插入到动态数组shapes中
	int size = a.getSize();
	int boundary = 0;

	for (; boundary < index; boundary++)  //给新插入的数组寻找位置
    {
		if (*ptr > *a[boundary])  
			break;
	}   //最后的数组需要从大到小进行排序

	for (int i = size - 1; i > boundary; i--)
    {
		a[i] =a[i-1];
    }

	a[boundary] = ptr;
}

int main()
{
    cout << "输入框架图案的编号，创建新的框架，键入-1输入结束" << endl
			<< "  1  圆形" << endl
			<< "  2  长方形" << endl
			<< "  3  直角三角形" << endl;

    int presize=2;
    Array<shape *>a(presize); //将元素个数赋值给size的同时，分配size个空间
    for(int i=0;i<presize;i++)
    {
        a[i]=NULL; //赋空值
    }

    int cnt=0;
    int choice=0;
    while(choice!=-1)
    {
        int flag=0;
        shape * ptr=NULL;
        cin>>choice;
        if(choice==1)
        {
            ptr=circle::creatcricle(); //非静态函数的引用必须要和特定对象相对 所以构造静态函数
            flag=1;
        }
        if(choice==2)
        {
            ptr=rectangle::creatrectangle();
            flag=1;
        }
        if(choice==3)
        {
            ptr=rightTriangle::creattriangle();
            flag=1;
        }
        if(flag==1)
        {
        Sort(a,cnt,ptr);
        cnt++;     //表示又插入了一个元素
        if(cnt>=presize)
        {
            presize++;
            a.resize(presize);
        }
        }
    }
    
    for(int i=0;i<cnt;i++)
    {
        a[i]->show();   
    }

    return 0;

}

