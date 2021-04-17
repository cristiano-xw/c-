#include<bits/stdc++.h>
using namespace std;

class student
{
    private:
        typedef std::valarray<double> ArryDb;//stl神器维护
        string name; 
        ArryDb scores;
        ostream & arr_out(ostream& os) const;
    public:
        student(): name("null"),scores(){}  //默认构造函数
        explicit student(const string &s): name(s),scores(){}
        explicit student(int n) :name("null"),scores(n){}//防止隐式转换
        student(const string &s,int n):name(s),scores(n){}
        student(const string &s,const ArryDb &a):name(s),scores(a){}
        student(const char*str,const double *pd,int n):name(str),scores(pd,n){}
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
    if(scores.size()>0)
    return scores.sum()/scores.size();
    else
    return 0;
}

const string & student::Name() const
{
    return name; //读取名字
} 

double & student::operator[](int i)
{
    return scores[i];
}

ostream & student::arr_out(ostream & os) const
{
    int i;
    int lim=scores.size();
    if(lim>0)
    {
        for(int i=0;i<lim;i++)
        {
            os<<scores[i]<<" ";
            if(i%5==4)
            os<<endl;
        }
        if(i%5!=0)
        os<<endl;
    }
    else 
        os<<"empty array";
        return os;
}

istream & operator>>(istream & is,student & stu)  
{
    is >> stu.name;
    return is;
} 

istream & getline(istream & is ,student & stu)
{
   getline(is,stu.name);
   return is; 
}

ostream & operator<<(ostream & os, student &stu)
{
    os<<"scores for"<<stu.name<<":\n";
    stu.arr_out(os); 
    return os;
}
