#include<bits/stdc++.h>
#include"linklist1.h"
using namespace std;

template<class ElemType>
void Reverse(SimpleLinklist<ElemType>&la)
{
    ElemType aitem; ElemType bitem;
    for(int position=1;position<=la.Length()/2;position++)
    {
        la.GetElem(position, aitem);
        la.GetElem(la.Length()-position+1,bitem);

        la.SetElem(position,bitem);
        la.SetElem(la.Length()-position+1,aitem);
    }
}


int main()
{
    SimpleLinklist<int> la1;
    la1.Insert(1,1);
    la1.Insert(2,2);
    la1.Insert(3,3);
    la1.Insert(4,4);

    Reverse(la1);
    la1.show();
    return 0;
}