
#include <iostream>
using namespace std;
class complex
{
private:
    double real;      //复数的实数部分;
    double imaginary; //复数的虚数部分;

public:
    complex();                                                               //默认构造函数;
    complex(double rl, double im);                                           //用户定义构造函数;
    ~complex();                                                              //析构函数;
    complex operator+(const complex &co) const;                              //重载'+'运算符;
    complex operator-(const complex &co) const;                              //重载'-'运算符;
    complex operator*(const complex &co) const;                              //重载'*'运算符;
    complex operator*(double n) const;                                       //重载'*'运算符可以与实数相乘;
    complex operator~() const;                                               //重载'~'共轭运算符;
    friend complex operator*(double n, const complex &co) { return co * n; } //友元函数重载'*'运算符使实数可以与对象相乘;
    friend std::istream &operator>>(std::istream &is, complex &co);          //重载'>>'运算符可以从不同的流中读取信息;
    friend std::ostream &operator<<(std::ostream &os, const complex &co);    //重载'<<'运算符可以发送消息到不同的流中;
};


complex::complex()
{
    real = imaginary = 0.0;
}

complex::complex(double rl, double im)
{
    real = rl;
    imaginary = im;
}

complex::~complex()
{
}

complex complex::operator+(const complex &co) const
{
    return complex(real + co.real, imaginary + co.imaginary); //使用用户定义构造函数构造新对象(+)并返回给调用对象;
}

complex complex::operator-(const complex &co) const
{
    return complex(real - co.real, imaginary - co.imaginary); //使用用户定义构造函数构造新对象(-)并返回给调用对象;
}

complex complex::operator*(const complex &co) const
{
    return complex(real * co.real - imaginary * co.imaginary,
                   real * co.imaginary + imaginary * co.real); //使用用户定义构造函数构造新对象(*)并返回给调用对象;
}

complex complex::operator*(double n) const
{
    return complex(n * real, n * imaginary); //使用用户定义构造函数构造新对象(*)并返回给调用对象;
}

complex complex::operator~() const
{
    return complex(real, -imaginary); //使用用户定义构造函数构造新对象(~)并返回给调用对象;
}

std::istream &operator>>(std::istream &is, complex &co)
{
    std::cout << "real: ";
    if (is >> co.real) //若实数部分读取失败则虚数部分不读取;
    {
        std::cout << "imaginary: ";
        is >> co.imaginary;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const complex &co)
{
    os << "(" << co.real << "," << co.imaginary << "i)"; 
    return os;
}


int main()
{
    complex a(3.0, 4.0);
    complex c;

    cout << "Enter a complex number (q to quit):\n";
    while (cin >> c)
    {
        cout << "c is " << c << '\n';
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";

    return 0;
}
