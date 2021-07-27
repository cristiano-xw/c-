#include<bits/stdc++.h>
#include"linklist1.h"
using namespace std;
//合并成为新的链表

template<class ElemType>
void MergeList(const SimpleLinklist<ElemType>&la, const SimpleLinklist<ElemType>&lb,  SimpleLinklist<ElemType>&lc)

{
    ElemType aitem; ElemType bitem;
    int alength=la.Length(); int blength=lb.Length();
    int aposition=1; int bposition=1;
    //cout<<alength<<endl; cout<<blength<<endl;

    lc.Clear();
    while(aposition<=alength&&bposition<=blength)
    {
        la.GetElem(aposition,aitem);
        lb.GetElem(bposition,bitem);
        if(aitem<bitem)
        {
            lc.Insert(lc.Length()+1,aitem);
            aposition++;
        }        

        else
        {
            lc.Insert(lc.Length()+1,bitem);
            bposition++;
        }
    }

    while(aposition<=alength)
    {
        la.GetElem(aposition,aitem);
        lc.Insert(lc.Length()+1,aitem);
        aposition++;
    }

    while(bposition<=blength)
    {
        lb.GetElem(bposition,bitem);
        lc.Insert(lc.Length()+1,bitem);
        bposition++;
    }


}


int main()
{
    SimpleLinklist<int> la1;
    la1.Insert(1,1);
    la1.Insert(2,2);
    la1.Insert(3,3);
    la1.Insert(4,4);

    SimpleLinklist<int> lb1;
    lb1.Insert(1,2);
    lb1.Insert(2,4);
    lb1.Insert(3,6);
    lb1.Insert(4,8);


    //cout<<la.Length()<<endl;
    SimpleLinklist<int> lc1;

    MergeList(la1,lb1,lc1);

    lc1.show();

    return 0;

}


