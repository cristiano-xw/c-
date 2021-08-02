#include<iostream>
using namespace std;
enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量

//为了解决假溢出，我们需要建立一个循环队列
//从逻辑上首尾连接，成为一个环
template<class ElemType>
class sqqueue
{
    protected:
        int front; int rear; //其实front和rear也只是位置的计量
        int maxsize;
        ElemType * elem; //元素的存储空间

        bool full() const;
        void init() ;

    public:
        sqqueue(int size=10);
        virtual ~sqqueue();
        int length() const;
        bool empty() const;
        void clear();
        void traverse(void (*visit)(const ElemType &)) const;
        StatusCode outqueue(ElemType &e);
        StatusCode gethead(ElemType &e) const;
        StatusCode inqueue(const ElemType &e);
        sqqueue(const sqqueue<ElemType>&copy);
        sqqueue<ElemType>&operator=(const sqqueue<ElemType>&copy);
};

//约定队头在队尾的下一个位置，那么这个队列就是满的
template<class ElemType>
bool sqqueue<ElemType>::full() const
{
    return length() == maxsize-1; 
}

template<class ElemType>
void sqqueue<ElemType>::init()
{
    rear=front=0;
}

template<class ElemType>
sqqueue<ElemType>::sqqueue(int size)
{
    maxsize=size;
    elem=new ElemType[maxsize]; //分配空间
    init(); 
}

template<class ElemType>
sqqueue<ElemType>::~sqqueue()
{
    delete []elem;
}

template<class ElemType>
int sqqueue<ElemType>::length() const
{
    return(rear-front+maxsize)%maxsize; //rear-front是位置差，但是不一定大于0
}

template<class ElemType>
bool sqqueue<ElemType>::empty() const
{
    return rear==front;
}

template<class ElemType>
void sqqueue<ElemType>::clear()
{
    rear=front=0;
}

template<class ElemType>
void sqqueue<ElemType>::traverse(void(*visit)(const ElemType &)) const  
{
    for(int curposition=front;curposition!=rear;curposition=(curposition+1)%maxsize)
    {
        (*visit)(elem[curposition]);
    }
}

template<class ElemType>
StatusCode sqqueue<ElemType>::outqueue(ElemType &e) //队列先进先出，删除头元素
{
    if(!empty())
    {
        e=elem[front];
        front=(front+1)%maxsize;
        return SUCCESS;
    }

    else
    {
        return UNDER_FLOW;
    }
}

template<class ElemType>
StatusCode sqqueue<ElemType>::gethead(ElemType &e) const 
{
    if(!empty())
    {
        e=elem[front];
        return SUCCESS;
    }

    else
    {
        return UNDER_FLOW;
    }
}

template<class ElemType>
StatusCode sqqueue<ElemType>::inqueue(const ElemType &e)
{
    if(full())
    {
        return OVER_FLOW;
    }
    else
    {
        elem[rear]=e;
        rear=(rear+1)%maxsize;
        return SUCCESS;
    }

}

template<class ElemType>
sqqueue<ElemType>::sqqueue(const sqqueue<ElemType>&copy)
{
    front=copy.front;
    rear=copy.rear;
    for(int i=front;i!=rear;i=(i+1)%maxsize)
    {
        elem[i]=copy.elem[i]; 
    }
}

template<class ElemType>
sqqueue<ElemType>&sqqueue<ElemType>::operator=(const sqqueue<ElemType>&copy)
{
    if(&copy!=this)
    {
        front=copy.front;
        rear=copy.rear;
        for(int i=front;i!=rear;i=(i+1)%maxsize)
        {
        elem[i]=copy.elem[i]; 
        }
    }
    return *this;
}


