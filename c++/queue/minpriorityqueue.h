//最小优先队列
//先是最小的值出去
#include<iostream>
#include"linkqueue.h"
using namespace std;

template<class ElemType>
class minqueue:public linkqueue<ElemType>
{
    public:
        StatusCode inqueue(const ElemType &e);
        //重载了入队顺序
};

template<class ElemType>
StatusCode minqueue<ElemType>::inqueue(const ElemType& e)
{
    Node<ElemType>*curptr=linkqueue<ElemType>::front->next;
    Node<ElemType>*curptrpre=linkqueue<ElemType>::front; //前驱的空节点

    while(curptr!=NULL&&curptr->data<=e)
    {
        curptrpre=curptr;
        curptr=curptr->next;
    }
    //按顺序大小，小的数被挤到前面去 ,优先出队
    Node<ElemType>*tmpptr=new Node<ElemType>(e,curptr);
    curptr->next=tmpptr; 

    if(curpreptr==linkqueue<ElemType>::rear)
    {
        linkqueue<ElemType>::rear=tmpptr;
    }
    return SUCCESS;
}


//其实任何队列的本质都是一样的，从队尾进入，从队首离开

