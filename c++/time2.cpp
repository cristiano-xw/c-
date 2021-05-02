#include<iostream>
using namespace std;

class time 
{
    private:
        int hours;
        int minutes;
    public:
       time();
        time(int h,int m=0);
        void addmin(int m);
        void addhr(int h);
        void reset(int h=0,int m=0);
        friend time operator+(const time &a, const time &b); //'+'运算符的友元函数原型;
        friend time operator-(const time &a, const time &b);
        friend time operator*(const time &t,double m);
        //友元函数和类函数的区别在于，友元函数需要定义两个变量哈哈哈哈    
        friend std::ostream &operator<<(std::ostream &os, const time &t);
};

time::time()
{
    hours=minutes=0;
}

time::time(int h,int m)
{
    hours=h;
    minutes=m;
}

void time::addmin(int m)
{
    minutes+=m;
    hours+=minutes/60;
    minutes%60;
}

void time::addhr(int h)
{
    hours+=h;
}

void time::reset(int h,int m )
{
    hours=h; minutes=m;
}

time operator+(const time &a, const time &b) //友元函数实现的'+'运算符重载;
{
    time sum;
    sum.minutes = a.minutes + b.minutes;
    sum.hours = a.hours + b.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

time operator-(const time &a, const time &b) //友元函数实现的'-'运算符重载;
{
    time diff;
    int tot1, tot2;
    tot1 = a.minutes + 60 * a.hours;
    tot2 = b.minutes + 60 * b.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

time operator*(const time&a , double t)
{
    time diff;
    diff.minutes=a.minutes*t;
    diff.hours+=a.minutes/60;
    diff.minutes=a.minutes%60;
    return diff;        //友元函数不可以直接改变私有成员
}

ostream &operator<<(ostream &os, const time &t) 
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}

int main()
{
    using std::cout;
    using std::endl;
    time aida(3, 35);
    time tosca(2, 48);
    time temp;

    cout << "Aida and Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca;
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17;
    cout << "Aida * 1.17: " << temp << endl;
    //cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

    return 0;
}
