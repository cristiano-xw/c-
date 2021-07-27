//双向链表有两个指针域，分别指向前驱和后继
#include<iostream>
using namespace std;

enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量

template <class ElemType>
struct dblnode
{
    ElemType data;
    dblnode<ElemType>*back;
    dblnode<ElemType>*next; //分别为指向前驱和后继的指针域
    dblnode();
    dblnode(ElemType,dblnode<ElemType>*linkback=NULL,dblnode<ElemType>*linknext=NULL);
};

template<class ElemType>
dblnode<ElemType>::dblnode()
{
    next=NULL;
}

template<class ElemType>
dblnode<ElemType>::dblnode(ElemType,dblnode<ElemType>*linkback,dblnode<ElemType>*linknext)
{
    data=item;
    back=linkback;
    next=linknext;      
}  

template<class ElemType>
class simpledbllinklist
{
    protected:
        dblnode<ElemType>*head;
        dblnode<ElemType>*GetElemPtr(int position)const;
        void Init();

    public:
        simpledbllinklist();
        virtual~simpledbllinklist();
        int Length() const;
        bool Empty() const;
        void Clear() ;
        void Traverse(void(*visit)(const ElemType &))const;
        StatusCode GetElem(int position,ElemType & e) const;
        StatusCode SetElem(int position,ElemType & e);
        StatusCode Delete(int position,ElemType & e);
        StatusCode Insert(int position,const ElemType &e);
        //SimpleLinklist(const SimpleLinklist<ElemType>&copy);
       //SimpleLinklist<ElemType>&operator=(const SimpleLinklist<ElemType>&copy);


};

//对插入的算法进行更改
template<class ElemType>
StatusCode simpledbllinklist<ElemType>::Insert(int position,const ElemType & e)
{
    if(position<1||position>length()+1)
    {
        return RANGE_ERROR;
    }

    else
    {
        dblnode<ElemType>*tmppter,*nextptr,*newptr;
        tmppter=GetElemPtr(position-1);
        nextptr=tmppter->next;
        newptr=new dblnode<ElemType>(e,tmppter,nextptr);
        tmppter->next=newptr;
        nextptr->back=newptr;
        return SUCCESS;
    }
}


template<class ElemType>
StatusCode simpledbllinklist<ElemType>::Delete(int position,ElemType &e)
{
    if(position<1||position>length())
    {
        return RANGE_ERROR;
    }

    else
    {
        dblnode<ElemType>*tmpptr;
        tmpptr =GetElemPtr(position);
        tmppter->back->next=tmppter->next;
        tmppter->next->back=tmppter->back;
        e=tmppter->data;
        delete tmpptr;
        return SUCCESS;
    }
}