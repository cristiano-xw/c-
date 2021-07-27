#include<iostream>
#include"sqlist1.h"
//两个集合求差集的情况



template<class ElemType>
void Difference(const SqList<ElemType>&la,const SqList<ElemType>&lb,const SqList<ElemType>&lc)
{
    ElemType aitem,bitem;
    lc.Clear();
    for(int i=1;i<=a.Length();i++)
    {
        la.GetItem(i,aitem);
        bool isexist=0;
        for(int i=1;i<=b.Length();i++)
        {
            lb.GetItem(i,bitem);
            if(aitem==bitem)
            {
                isexist=true;
                break;
            }
        }

        if(!isexist)
        {
            lc.Insert(lc.Length()+1,aitem);
        }
    }
}