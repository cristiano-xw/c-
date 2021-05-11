#include<iostream>
using namespace std;

class complex
{
    private:
        double real;
        double imag;//定义实部和虚部
    public:
        complex(){}
        complex(double a,double b)
        {
            real=a; imag=b;//构造函数
        } //自定义

        ~complex(){}

        complex operator+(const complex &st) const;     //重载运算符
        complex operator-(const complex &st) const;
        complex operator*(const complex &st) const;   //这个是复数和复数的乘法
        complex operator*(const double a) const; //最前面的complex就是返回类型 
        //这样写的默认是一个对象和一个double类型的数相乘，顺序不可以变
        complex operator~() const;  

        friend istream &operator>>(std::istream &is, complex &co);
        friend std::ostream &operator<<(std::ostream &os, const complex &co);
        //改变输入输出流，使得函数可以以不同的方式读取参数
};

complex complex::operator+(const complex &st) const
{
    return complex(real+st.real,imag+st.imag);
}

complex complex::operator-(const complex &st) const
{
    return complex(real-st.real,imag-st.imag);
}

complex complex::operator*(const complex &st) const
{
    return complex(real*st.real-imag*st.imag,real*st.imag+imag*st.real);
}

complex complex::operator*(double a) const 
{
    return  complex(a*real,a*imag); 
}

istream &operator>>(istream & is,complex &st)
{
    cout<<"real:";
    if(is>>st.real)
    {
        cout<<"imag:";
        is>>st.imag;
    }
    return is;
}

complex complex::operator~() const
{
    return complex(real, -imag); //使用用户定义构造函数构造新对象(~)并返回给调用对象;
}
//friend ostream &operator<<(std::ostream &is, complex &co);

std::ostream &operator<<(std::ostream &os, const complex &co) 
{
    os << "(" << co.real << "," << co.imag << "i)"; 
    return os;
}

