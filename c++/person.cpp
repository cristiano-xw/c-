#include<iostream>
using namespace std;

class person
{
    private:
        string name;
        int  age;
    public:
        person(string a,int b)
        {
            name=a; 
            if(b>0&&b<100)
            {
            age=b;
            }
        }
        string getname()
        {
            return name;
        }
        int getage()
        {
            return age;
        }
        void setage(int a)
        {
            if(a>0&&a<100)
            {
                age=a;            
            }
        }

        void setname(string a)
        {
            name=a;
        }

        friend ostream & operator<<( ostream & os,const person & a)
        {
            cout<<a.age<<"  "<<a.name<<endl;
        }
};

class cube
{
     private:
        double a;double b;double c;
     public:
         cube(double x,double y,double z):a(x),b(y),c(z){}

        double  count()
        {
            return a*b*c;
        }

        bool equal(cube &a,cube & b)
        {
            if(a.count()==b.count())
            {
                return true;
            }
            return false;
        }


};


bool equal(cube &a,cube & b)
        {
            if(a.count()==b.count())
            {
                return true;
            }
            return false;
        }


class advcircle
{
    private:
    int x; int y;
    int r;

    public:
      advcircle(double a,double b,double c )
      {
          x=a;y=b;r=c;
      }
     //friend void temp(point & a,advcircle & b);
};

class point
{
    private:
        double x; double y;
    public:
        point(int a,int b)
        {
            x=a;y=b;
        }
    double getx()
    {
        return x;
    }

    double gety()
    {
        return y;
    }  
    //friend void temp(point & a,advcircle & b);
};


int main()
{
    point p1(1,2);
    advcircle p2(1,2,3);
    //cout<<p1.getx()<<endl;
    
    return 0;
}
