#include<iostream>
using namespace std;

enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量

const int DEFAULT_SIZE=10;
template<class ElemType>
class sqstack
{
    protected:
        int count; //元素个数
        int maxsize; //最大元素个数
        ElemType * elems; //分配存储空间

        bool full() const;
        void init(int size);

    public:
        sqstack(int size=DEFAULT_SIZE);
        virtual~sqstack();
        int length() const;
        bool empty() const;
        void clear();
        void traverse(void (*visit)(const ElemType &)) const;
        StatusCode push(const ElemType &e); //进入
        StatusCode top(ElemType & e) const; //顶端
        StatusCode pop(ElemType & e); //弹出
        sqstack(const sqstack<ElemType>&copy); //复制构造
        sqstack<ElemType>&operator=(const sqstack<ElemType>&copy); 
};

template<class ElemType>
bool sqstack<ElemType>::full() const
{
    return count==maxsize;
}

template<class ElemType>
void sqstack<ElemType>::init(int size)
{
    maxsize=size; //初始化栈的长度
    if(elems!=NULL) delete []elems;
    elems=new ElemType[maxsize];
    count=0;
}

template<class ElemType>
sqstack<ElemType>::sqstack(int size)
{
    elems=NULL;
    init(size);
}

template<class ElemType>
sqstack<ElemType>::~sqstack()
{
    delete[] elems; //释放空间
}

template<class ElemType>
int sqstack<ElemType>::length()const
{
    return count;
}

template<class ElemType>
bool sqstack<ElemType>::empty() const
{
    return count==0;
}

template<class ElemType>
void sqstack<ElemType>::clear()
{
    count=0;
}

template<class ElemType>
void sqstack<ElemType>::traverse(void (*visit)(const ElemType &))const
{
    for(int i=1;i<=length();i++)
    {
        (*visit)(elems[i-1]);
    }
}

template<class ElemType>
StatusCode sqstack<ElemType>::push(const ElemType &e)
{
    if(full())
    {
        return OVER_FLOW;
    }

    else
    {
        elems[count++]=e; //压入后再加
        return SUCCESS;
    }
}

template<class ElemType>
StatusCode sqstack<ElemType>::top(ElemType& e)const
{
    if(empty ())
    {
        return UNDER_FLOW;
    }

    else 
    {
        e=elems[count-1];
        return SUCCESS;
    }
}

template<class ElemType>
StatusCode sqstack<ElemType>::pop(ElemType& e)
{
    if(empty())
    {
        return UNDER_FLOW;
    }

    else 
    {
        e=elems[count-1];
        count--;
        return SUCCESS;
    }
}

template<class ElemType>
sqstack<ElemType>::sqstack(const sqstack<ElemType>&copy)  //拷贝构造函数
{
    elems=NULL;
    init(copy.maxsize);
    count=copy.count;
    for(int i=1;i<=length();i++)
    {
        elems[i-1]=copy.elems[i-1];
    }
}

template<class ElemType>
sqstack<ElemType>&sqstack<ElemType>::operator=(const sqstack<ElemType>&copy)
{
    if(&copy!=this)
    {
        init(copy.maxsize);
        count=copy.count; 
        for(int i=1;i<=length();i++)
        {
            elems[i-1]=copy.elems[i-1];
        }
    }
    return *this;
}











