#include<bits/stdc++.h>
using namespace std;

enum StatusCode 
{SUCCESS,FAIL,UNDER_FLOW,OVER_FLOW,RANGE_ERROR,DUPLICATE_ERROR,NOT_PRESENT,ENTRY_INSERTED,ENTRY_FOUND,VISITED,UNVISITED};
//枚举状态变量

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
class SimpleLinklist
{
    protected:
        node<ElemType>*head;  //构造头节点

        mutable int curposition;
        mutable node<ElemType> * curptr;
        int count;

        node<ElemType>*GetElemptr(int position)const;
        void Init();

    public:
        SimpleLinklist();
        virtual~SimpleLinklist();
        int Length() const;
        void show() const; //自定义的显示函数
        bool Empty() const;
        void Clear();
        void Traverse(void (*visit)(const ElemType &))const;
        StatusCode GetElem(int position,ElemType & e) const;
        StatusCode SetElem(int position,ElemType & e);
        StatusCode Delete(int position,ElemType & e);
        StatusCode Insert(int position,const ElemType &e);
        SimpleLinklist(const SimpleLinklist<ElemType>&copy);
        SimpleLinklist<ElemType>&operator=(const SimpleLinklist<ElemType>&copy);

};

template<class ElemType>
node<ElemType>*SimpleLinklist<ElemType>::GetElemptr(int position) const
//返回指向第position个节点的指针
{
    if(curposition>position)
    {
        curposition=0;
        curptr=head; //过了，从头开始吧
    }
    for(;curposition<position;curposition++)
    curptr=curptr->next;

    return curptr;

}

template<class ElemType>
void SimpleLinklist<ElemType>::Init()
{
    head=new node<ElemType>;
    curptr=head;
    curposition=0;
    count=0; //初始化数据成员
}

template<class ElemType>
SimpleLinklist<ElemType>::SimpleLinklist()
{
    Init();
}

template<class ElemType>
SimpleLinklist<ElemType>::~SimpleLinklist()
{
    Clear();
    delete head; //删除头节点
}

template<class ElemType>
int SimpleLinklist<ElemType>::Length()const
{
    return count; //返回计数就可了
}

template<class ElemType>
void SimpleLinklist<ElemType>::show()const
{
    for(node<ElemType>*tmpptr=head->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        cout<<tmpptr->data<<endl;   
    }
}



template<class ElemType>
bool SimpleLinklist<ElemType>::Empty()const
{
    return head->next==NULL; //判断这个链表是否为空
}

template<class ElemType> 
void SimpleLinklist<ElemType>::Clear()
{
    ElemType tmpElem;
    while(Length()>0)
    {
        Delete(1,tmpElem); 
    }
}

template<class ElemType>
void SimpleLinklist<ElemType>::Traverse(void (*visit)(const ElemType &)) const
{
    for(node<ElemType>*tmpptr=head->next;tmpptr!=NULL;tmpptr=tmpptr->next)
    {
        //用指针指向每一个元素
        (*visit)(tmpptr->data);
    }

}

template<class ElemType>
StatusCode SimpleLinklist<ElemType>::GetElem(int position,ElemType &e) const 
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }
    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemptr(position);
        e=tmpptr->data;
        return ENTRY_FOUND;
    }
}

//将第position个位置的元素赋值为e
template<class ElemType>
StatusCode SimpleLinklist<ElemType>::SetElem(int position,ElemType &e)
{
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }
    else 
    {
      node<ElemType>*tmpptr;
      tmpptr=GetElemptr(position);
      tmpptr->data=e;
      return SUCCESS;  
    }
}

template<class ElemType>
StatusCode SimpleLinklist<ElemType>::Insert(int position,const ElemType &e)
//在第position个位置前面插入
{
    if(position<1||position>Length()+1)
    {
        return RANGE_ERROR;
    }
    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemptr(position-1);
        node<ElemType>*newptr;
        newptr=new node<ElemType>(e,tmpptr->next); //生成新的节点
        tmpptr->next=newptr;

        curposition=position;
        curptr=newptr;
        count++;
        return SUCCESS;
    }
}

template<class ElemType>
StatusCode SimpleLinklist<ElemType>::Delete(int position,ElemType &e)
{
    //删除position个位置的元素，并且用e返回值
    if(position<1||position>Length())
    {
        return RANGE_ERROR;
    }

    else 
    {
        node<ElemType>*tmpptr;
        tmpptr=GetElemptr(position-1);
        node<ElemType>*nextptr=tmpptr->next;
        tmpptr->next=nextptr->next; //删除节点的操作
        e=nextptr->data;
        if(position==Length())
        {
            curposition=0;
            curptr=head;
        }

        else 
        {  
           curposition=position;
           curptr=tmpptr->next; 
        }

        count--;
        delete nextptr;
        return SUCCESS;
    }
}

template<class ElemType>
SimpleLinklist<ElemType>::SimpleLinklist(const SimpleLinklist<ElemType>&copy)
{
    int copylength=copy.Length(); //长度
    ElemType e;
    Init(); //构造一个头节点
    for(int i=1;i<=copylength;i++)
    {
        copy.Getelem(i,e);
        Insert(Length()+1,e); 
    }
}





