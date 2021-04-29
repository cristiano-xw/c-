
#include <iostream>

namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode{ RECT, POL };

    private:
        double x;
        double y;
        Mode mode;
        double set_mag() const;             //修改了原来设置矢量长度的函数;
        double set_ang() const;             //修改了原来设置矢量角度的函数;
        void set_x(double mag, double ang); //修改了原来设置矢量x坐标的函数;
        void set_y(double mag, double ang); //修改了原来设置矢量y坐标的函数;

    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return set_mag(); }
        double angval() const { return set_ang(); }
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &b) const;
        Vector operator-(const Vector &b) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector &a);
        friend std::ostream &operator<<(std::ostream &os, const Vector &v);
    };
}

#include <cmath>
using std::atan;
using std::atan2;
using std::cos;
using std::cout;
using std::sin;
using std::sqrt;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);

    double Vector::set_mag() const
    {
        return sqrt(x * x + y * y); //计算向量的长度;
    }

    double Vector::set_ang() const
    {
        if (x == 0.0 && y == 0.0)
        {
            return 0.0; //若是向量的x坐标和y坐标为0则角度也为0;
        }
        else
        {
            return atan2(y, x); //否则计算向量的角度并返回至调用对象;
        }
    }

    void Vector::set_x(double mag, double ang)
    {
        x = mag * cos(ang);
        return;
    }

    void Vector::set_y(double mag, double ang)
    {
        y = mag * sin(ang);
        return;
    }

    Vector::Vector()
    {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg); //使用修改的设置x坐标的函数来更新x坐标值;
            set_y(n1, n2 / Rad_to_deg); //使用修改的设置y坐标的函数来更新y坐标值;
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        }
        else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg); //同上一个函数说明;
            set_y(n1, n2 / Rad_to_deg); //同上一个函数说明;
        }
        else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
        return;
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()
    {
        mode = POL;
        return;
    }

    void Vector::rect_mode()
    {
        mode = RECT;
        return;
    }

    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    Vector operator*(double n, const Vector &a)
    {
        return a * n;
    }

    std::ostream &operator<<(std::ostream &os, const Vector &v)
    {
        if (v.mode == Vector::RECT)
        {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        }
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.magval() << ", ";
            os << v.angval() * Rad_to_deg << ")";
        }
        else
        {
            os << "Vector object mode is invalid";
        }
        return os;
    }
}
