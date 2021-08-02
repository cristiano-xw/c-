#include<iostream>
#include"linklist1.h"
using namespace std;

struct polyitem
{
    double coef; //系数
    int expn;   //指数
    polyitem();
    polyitem(double sf,int en);
};

polyitem::polyitem()
{
    expn=-1;
}

polyitem::polyitem(double cf,int en)
{
    coef=cf;
    expn=en;
}

class polynomial
{
    protected:
        SimpleLinklist<polyitem>polylist;
    
    public:
        polynomial(){};
        ~polynomial(){};
        int Length() const; //多项式的系数
        bool IsZero() const; //判断多项式是否为0
        void SetZero(); //将多项式置位0
        void Display();
        void InsItem(const polyitem &p) ;
        polynomial operator+(const polynomial &p) const;
        polynomial operator-(const polynomial &p) const;
        polynomial operator*(const polynomial &p) const;

};

//多项式相加的算法
polynomial polynomial::operator+(const polynomial &p)const
{
    SimpleLinklist<polyitem>la=polylist;
    SimpleLinklist<polyitem>lb=p.polylist;
    SimpleLinklist<polyitem>lc;
    int apos=1; int bpos=1;
    polyitem aitem,bitem;
    StatusCode aStatus, bStatus;
    aStatus=la.GetElem(apos,aitem);
    bStatus=lb.GetElem(bpos,bitem);

    while(aStatus==ENTRY_FOUND&&bStatus==ENTRY_FOUND)
    {
        if(aitem.expn<bitem.expn) //la中项的指数系数较小
        {
            lc.Insert(lc.Length()+1,aitem);
            aStatus=la.GetElem(++apos,aitem);
        }
        else if(aitem.expn>bitem.expn)
        {
            lc.Insert(lc.Length()+1,bitem);
            bStatus=lb.GetElem(++bpos,bitem);
        }
        else 
        {
            polyitem sumItem(aitem.coef+bitem.coef,aitem.expn);
            if(sumItem.coef!=0)
            lc.Insert(lc.Length()+1,sumItem);
            aStatus=la.GetElem(++apos,aitem);
            bStatus=lb.GetElem(++bpos,bitem);
        }
    }

    while(aStatus==ENTRY_FOUND)
    {
        lc.Insert(lc.Length()+1,aitem);
        aStatus=la.GetElem(++apos,aitem);
    }

    while(bStatus==ENTRY_FOUND)
    {
        lc.Insert(lc.Length()+1,bitem);
        bStatus=lb.GetElem(++bpos,bitem);
    }

    polynomial fs;
    fs.polylist=lc;
    return fs;
}

polynomial polynomial::operator*(const polynomial &p) const
{
    SimpleLinklist<polyitem>la=polylist;
    SimpleLinklist<polyitem>lb=p.polylist;
    SimpleLinklist<polyitem>lc;
    polynomial f;
    int apos=1; int bpos=1;
    polyitem aitem,bitem,citem;
    StatusCode aStatus,bStatus;

    aStatus=la.GetElem(apos,aitem);
    while(aStatus==ENTRY_FOUND)
    {
        bpos=1;
        bStatus=lb.GetElem(bpos,bitem);
        while(bStatus==ENTRY_FOUND)
        {
            citem.coef=aitem.coef*bitem.coef;
            citem.expn=aitem.expn+bitem.expn;

            lc.Clear();
            lc.Insert(lc.Length()+1,citem); //相当于lc只保留当前这一项
            polynomial fc(lc);
            f=f+fc;
            bStatus=lb.GetElem(++bpos,bItem);
        }
        aStatus=lb.GetElem(++apos,aitem);
    }
    return f;
}

