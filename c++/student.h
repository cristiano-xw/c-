#include<bits/stdc++.h>
using namespace std;

class student:private string ,private valarray<double> 
{
    private:
        typedef std::valarray<double> ArryDb;
        ostream & arr_out(ostream& os) const;
    public:
        student(): string("null"),ArryDb(){} //直接使用类名来构造函数 
        explicit student(const string &s): string(s),ArryDb(){}
        explicit student(int n) :string("null"),ArryDb(n){} 
        student(const string &s,int n):string(s),ArryDb(n){}
        student(const string &s,const ArryDb &a):string(s),ArryDb(a){}
        student(const char*str,const double *pd,int n):string(str),ArryDb(pd,n){}
        ~student(){}
        double average() const;
        const string &Name() const;
        double &operator[] (int i) ;
        double operator[] (int i) const;

        friend std::istream & operator>>(std::istream & is ,student &stu); 
        friend std::istream & getline(std::istream & is,student &stu);
        friend std::ostream & operator<<(std::ostream & os,student & stu);

};

double student::average() const
{
    if(ArryDb::size()>0)
    return ArryDb::sum()/ArryDb::size();
    else
    return 0;
}

const string & student::Name() const
{
    return (const string &)*this;
} 

double & student::operator[](int i)
{
    return ArryDb::operator[](i);
}

ostream & student::arr_out(ostream & os) const
{
    int i=0;
    int lim=ArryDb::size();
    if(lim>0)
    {
        for(i=0;i<lim;i++)
        {
            os<<ArryDb::operator[](i)<<" ";
            if(i%5==4)
            os<<endl;
        }
        if(i % 5 != 0)
        os<<endl;
    }
    else 
        os<<"empty array";
        return os;
}

istream & operator>>(istream & is,student & stu)  
{
    is>>(string &)stu;
    return is;
} 

istream & getline(istream & is ,student & stu)
{
   getline(is,(string &)stu);
   return is; 
}

ostream & operator<<(ostream & os, student &stu)
{
    os<<"ArryDb for"<<(const string &)stu<<":\n";
    stu.arr_out(os); 
    return os;
}
