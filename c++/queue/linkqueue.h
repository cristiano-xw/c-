#include<iostream>
using namespace std;

enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量


template <class ElemType>
struct Node
{
    ElemType data;  //数据域
    Node<ElemType>*next; //下一个节点的指针域

    Node();
    Node(const ElemType &e,Node<ElemType>*link=NULL)    ;                                
};

template <class ElemType>
Node<ElemType>::Node()
{
    next=NULL;
}

template <class ElemType>
Node<ElemType>::Node(const ElemType &e,Node<ElemType>*link)
{
    //构造一个数据成分e和指针成分为link的节点
    data=e;
    next=link;
}


template<class ElemType>
class linkqueue
{
    protected:
        Node<ElemType>*front,*rear; //队头队尾指针
        void init();
    
    public:
        linkqueue();
        virtual ~linkqueue(); 
        int length() const; //长度
        bool empty() const;
        void clear() ;
        void traverse(void (*visit)(const ElemType &)) const;
        StatusCode outqueue(ElemType &e); //出队
        StatusCode gethead(ElemType &e) const; 
        StatusCode inqueue(const ElemType &e); //入队
        linkqueue (const linkqueue<ElemType>&copy);
        linkqueue<ElemType>&operator =(const linkqueue<ElemType>&copy);
};

template<class ElemType>
void linkqueue<ElemType>::init() //初始化生成队列
{
    rear=front=new Node<ElemType>;
}

template<class ElemType>
linkqueue<ElemType>::linkqueue()
{
    init();
}

template<class ElemType>
linkqueue<ElemType>::~linkqueue()
{
    clear();
}

//需要明确的是，这样建立队列的队头并不是front而是front->next
template<class ElemType>
int linkqueue<ElemType>::length()const
{
    int count=0;
    for(Node<ElemType>*tmpptr=front->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        count++;
    }
    return count;
}


template<class ElemType>
bool linkqueue<ElemType>::empty() const
{
    return rear==front;
}

template<class ElemType>
void linkqueue<ElemType>::clear()
{
    ElemType tmp;
    while(length()>0)
    {
        outqueue(tmp);
    }
}

template<class ElemType>
void linkqueue<ElemType>::traverse(void(*visit)(const ElemType &)) const
{
    for(Node<ElemType>*tmpptr=front->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        (*visit) (tmpptr->data);
    }
}

template<class ElemType>
StatusCode linkqueue<ElemType>::outqueue(ElemType &e)
{
    if(!empty())
    {
        Node<ElemType>*tmpptr=front->next;
        e=tmpptr->data; //取出队首的数据
        front->next=tmpptr->next;     //改变队首
        if(rear==tmpptr)
        {
            rear=front;
        }
        delete tmpptr;
        return SUCCESS;
    }

    else 
    {
        return UNDER_FLOW;
    }
}

template<class ElemType>
StatusCode linkqueue<ElemType>::gethead(ElemType &e) const 
{
    if(!empty())
    {
        Node<ElemType>*tmpptr=front->next;
        e=tmpptr->data;
        return SUCCESS;
    }

    else 
    {
        return UNDER_FLOW;
    }
}

template<class ElemType>
StatusCode linkqueue<ElemType>::inqueue(const ElemType &e)  //插入队尾
{
    Node<ElemType>*tmpptr=new Node<ElemType>(e);
    rear->next=tmpptr;
    rear=tmpptr;
    return SUCCESS;
}

template<class ElemType>
linkqueue<ElemType>::linkqueue(const linkqueue<ElemType>&copy)
{
    init();
    for(Node<ElemType>*tmpptr=copy.front->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        inqueue(tmpptr->data);
    }
}

template<class ElemType>
linkqueue<ElemType>&linkqueue<ElemType>::operator=(const linkqueue<ElemType>&copy)
{
    if(&copy!=this)
    {
        clear();
    

    for(Node<ElemType>*tmpptr=copy.front->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        inqueue(tmpptr->data);
    }
    }
    return *this;
}