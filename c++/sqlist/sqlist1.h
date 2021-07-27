#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h> 
using namespace std;

enum StatusCode 
{SUCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量

template<class ElemType>
class SqList
{
    protected:
        int count; //元素个数
        int maxsize; //最大存储的元素个数
        ElemType * elems; //初始化元素的存储空间
        bool Full() const;
        void Init(int size); //初始化顺序表的空间

    public:
        SqList(int size);
        virtual ~SqList();
        int Length() const;
        bool Empty() const;
        void Clear();
        void Traverse(void (*visit)(ElemType &));
        StatusCode Getelem(int position,ElemType & e) const;
        StatusCode Setelem(int position,const ElemType & e);
        StatusCode Delete(int position,ElemType & e);
        StatusCode Insert(int position,const ElemType & e);
        SqList(const SqList<ElemType>&copy);
        SqList<ElemType>&operator=(const SqList<ElemType>&copy); //重载赋值运算符
};


template <class ElemType>
bool SqList<ElemType>::Full() const
{
    return count==maxsize;
}

template <class ElemType>
void SqList<ElemType>::Init(int size)
{
    maxsize=size;
    if(elems!=NULL) delete[] elems;
    elems=new ElemType[maxsize];
    count=0;  //分配区域
}

template<class ElemType>
SqList<ElemType>::SqList(int size)
{
    elsms=null;
    Init(size);
}

template <class ElemType>
SqList<ElemType>::~SqList()
{
    delete[] elems;
}

template <class ElemType>  
int SqList<ElemType>::Length() const
{
    return count;  //计算当前的长度
}

template<class ElemType>
bool SqList<ElemType>::Empty() const
{
    return count==0;
}

template<class ElemType>
void SqList<ElemType>::Clear()
{
    count=0;
}

template<class ElemType>
void SqList<ElemType>::Traverse(void(*visit)(ElemType &))
{
    for (int i=1;i<=Length();i++)
    {
        (*visit)(elems[i-1]); 
    }
}

template<class ElemType>
StatusCode SqList<ElemType>::Getelem(int position,ElemType & e) const 
{
    if(position<1||position>Length())
    {
        return NOT_PRESENT; //元素不存在
    }

    else
    {
        e=elems[position-1];
        return ENTRY_FOUND;
    }

}

template<class ElemType>
StatusCode SqList<ElemType>::Setelem(int position,const ElemType & e)  //插入操作
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }

    else 
    {
        elems[position-1]=e;   
        return SUCCESS; 
    }
} 

//插入操作
template<class ElemType>
StatusCode SqList<ElemType>::Insert(int position,const ElemType &e)
{
    int len=Length(); 
    ElemType tmp;
    if(Full())
    {
        return OVER_FLOW;
    }    

    else if(position<1||position>len+1)
    {
        return RANGE_ERROR;
    }

    else 
    {
        count++;
        for(int i=len;i>=position;i--)
        {
            GetElem(i,tmp);
            SetElem(i+1,tmp);  //从最后一个元素开始往后移动
        }

        SetElem(position,e);
        return SUCCESS;
    }
}


template<class ElemType>
StatusCode SqList<ElemType>::Delete(int position,ElemType &e)  
{
    int len=Length();
    ElemType tmp;

    if(position<1||position>=len)
    {
        return RANGE_ERROR;
    }

    else 
    {
        GetElem(position,e);  //提取除删除的元素
        for(int i=position+1;i<=len;i++)
        {
            GetElem(i,tmp);
            SetElem(i-1,tmp);
        }
        count--;
        return SUCCESS;
    }
}

template<class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>&copy)
{
    int copylength=copy.Length();
    ElemType e;
    elems=null;
    init(copy.maxsize);
    for(int i=1;i<=copylength;i++)
    {
        copy.Getelem(i,e);
        Insert(length()+1,e); 
    }
}

template<class ElemType>
SqList<ElemType>&SqList<ElemType>::operator=(const SqList<ElemType>&copy)
{
    if(&copy!=this)
    {
        int copylength=copy.Length();
        for(int i=1;i<=copylength;i++)
        {
            copy.Getelem(i,e);
            Insert(length()+1,e);
        }
    }
    return *this;
}


