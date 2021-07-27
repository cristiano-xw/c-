//循环链表 最后一个节点会指向头节点
#include<iostream>
using namespace std;

enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};


template <class ElemType>
struct node
{
    ElemType data; //数据域
    node<ElemType> * next; //指针域

    node();
    node(ElemType item,node<ElemType>*link=NULL);

};

template<class ElemType>
node<ElemType>::node()
{
    next=NULL; //默认构造函数 下一个节点为空
}

template<class ElemType>
node<ElemType>::node(ElemType item,node<ElemType>*link)
{
    data=item; //数据域
    next=link; //指针域
}


template<class ElemType>
class simplecirclelinklist
{
    protected:
        node<ElemType>*head;
        node<ElemType>*GetElemPtr(int position)const;
        void Init();
    public:
        simplecirclelinklist();
        virtual~simplecirclelinklist(); 
        int Length() const;
        bool Empty() const;
        void Clear();
        void Traverse(void (*visit)(const ElemType &))const;
        StatusCode GetElem(int position,ElemType &e) const;
        StatusCode SetElem(int position,const ElemType & e);
        StatusCode Delete(int position,ElemType & e);
        StatusCode Insert(int position,const ElemType & e);

        //SimpleLinklist(const SimpleLinklist<ElemType>&copy);
        //SimpleLinklist<ElemType>&operator=(const SimpleLinklist<ElemType>&copy);

};


template <class ElemType>
node<ElemType>*simplecirclelinklist<ElemType>::GetElemPtr(int position)const 
{
    if(position==0)
    {
        return head;
    }
    node<ElemType>*tmpptr=head->next;
    int curposition=1;
    while(tmpptr!=head&&curposition<position)
    {
        tmpptr=tmpptr->next;
        curposition++;
    }

    if(tmpptr!=head&&curposition==position)
    {
        return tmpptr;
    }

    else
    {
        return NULL;
    }
}


template<class ElemType>
void simplecirclelinklist<ElemType>::Init()
{
    head=new node<ElemType>;
    head->next=head; 
}

template <class ElemType>
simplecirclelinklist<ElemType>::simplecirclelinklist()
{
    Init();
}

template <class ElemType>
simplecirclelinklist<ElemType>::~simplecirclelinklist()
{
    Clear();
    delete head;
}

template<class ElemType>
int simplecirclelinklist<ElemType>::Length()const 
{
    int count=0;
    for(node<ElemType>*tmpptr=head->next;tmpptr!=head;tmpptr=tmpptr->next)
    {
        count++;
    }
    return count;
}

template <class ElemType>
bool simplecirclelinklist<ElemType>::Empty()const 
{
    return head->next=head;
}

template <class ElemType>
void simplecirclelinklist<ElemType>::Traverse(void(*visit)(const ElemType &)) const 
{
    for(node<ElemType>*tmpptr=head->next;tmpptr!=head;tmpptr=tmpptr->next)
    {
        (*visit)(tmpptr->data);
    }
}

template <class ElemType>
StatusCode simplecirclelinklist<ElemType>::GetElem(int position,ElemType &e)const 
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }    
    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemPtr(position);
        e=tmpptr->data;
        return ENTRY_FOUND;
    }

}

template<class ElemType> 
void simplecirclelinklist<ElemType>::Clear()
{
    ElemType tmpElem;
    while(Length()>0)
    {
        Delete(1,tmpElem); 
    }
}


template <class ElemType>
StatusCode simplecirclelinklist<ElemType>::SetElem(int position,const ElemType &e)
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }

    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemPtr(position);
        tmpptr->data=e;
        return SUCCESS;
    }
}

template <class ElemType>
StatusCode simplecirclelinklist<ElemType>::Insert(int position,const ElemType &e)
{
    if(position<1||position>Length()+1)
    {
        return RANGE_ERROR;
    }

    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemPtr(position-1);
        node<ElemType>*newptr;
        newptr=new node<ElemType>(e,tmpptr->next);
        tmpptr->next=newptr;
        return SUCCESS;
    }
}


template <class ElemType>
StatusCode simplecirclelinklist<ElemType>::Delete(int position,ElemType & e)
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }

    else
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemPtr(position-1);
        node<ElemType>*nextptr=tmpptr->next;
        tmpptr->next=nextptr->next;
        e=nextptr->data;
        delete nextptr;
        return SUCCESS;
    }
}