#include<iostream>
using namespace std;
//namespace VECTOR 
//{
    class Vector
    {
        public:
            enum Mode{RECT,POL};
        private:
            double x;
            double y;
            double mag;
            double ang;
            Mode mode;
            void set_mag();
            void set_ang();
            void set_x(); void set_y();
        public:
        void reset(double n1,double n2,Mode form=RECT);
        Vector();
        Vector(double n1,double n2,Mode form = RECT);
        ~Vector();
        double xval() const{return x;}
        double yval() const{return y;}
        double magval() const{return mag;}
        double angval() const{return ang;}
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &b)const;
        Vector operator-(const Vector &b)const;
        Vector operator-() const;
        Vector operator*(double n) const;

        friend Vector & operator*(double n,const Vector & a); 
        friend ostream & operator<<(ostream & os,const Vector &v);
    };


//};

#include<cmath>
using namespace std;

//namespace VECTOR
//{
     const double Rad_to_deg = 45.0 / atan(1.0);
    void Vector::set_mag()
    {
        mag=sqrt(x*x+y*y);
    }

    void Vector::set_ang()
    {
        if(x==0&&y==0)
        {
            ang=0;
        }
        else
        ang=atan2(y,x);
    }

    void Vector::set_x() //建立横坐标
    {
        x = mag * cos(ang);
    }

    void Vector::set_y() 
    {
        y = mag * sin(ang);
    }

    Vector::Vector()       //默认构造函数 初始化
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1,double n2,Mode form) //构造函数
    {
        mode=form;
        if(form==RECT)
        {
            x=n1; y=n2;
            set_mag();  
            set_ang(); 
        }

        else if(form = POL)
        {
            mag=n1; ang=n2/Rad_to_deg;
            set_x(); set_y();
        }
        else 
        {
            cout<<"incorrect command"<<endl;
        }
    }

    void Vector:: reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
         {
             x = n1;
             y = n2;
             set_mag();
             set_ang();
        }
        else if (form == POL)
        {
             mag = n1;
             ang = n2 / Rad_to_deg; 
             set_x();
             set_y();
        }
        else
        {
             cout << "Incorrect 3rd argument to Vector() -- ";
             cout << "vector set to 0\n";
             x = y = mag = ang = 0.0;
             mode = RECT;
        }
    }

    Vector::~Vector()
    {
    }

    void Vector::polar_mode()//建立极坐标系
    {
        mode=POL;
    }

    void Vector::rect_mode() //建立直角坐标
    {
        mode=RECT;
    }

    Vector Vector::operator+(const Vector & b) const
    {
       return Vector(x+b.x,y+b.y);      //利用构造函数改变
    }

    Vector Vector::operator-(const Vector & b)const
    {
        return Vector(x-b.x,y-b.y);  
    }

    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }

    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }  

    /*Vector operator*(double n, const Vector & a) 
    {
        return a * n;
    }  */

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
             os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
             os << "(m,a) = (" << v.mag << ", "
                 << v.ang * Rad_to_deg << ")";
        }
        else
             os << "Vector object mode is invalid";
        return os; 
    }    
//}