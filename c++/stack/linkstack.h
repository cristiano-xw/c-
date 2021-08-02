#include<iostream>
using namespace std;

template <class ElemType>
struct Node
{
    ElemType data;
    Node<ElemType>*next;

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
class linkstack
{
    protected:
        Node<ElemType>*top;
        int count;

    public:
        linkstack();
        virtual ~linkstack();
        int length() const;
        bool empty() const;
        void clear();
        void traverse(void (*visit)(const ElemType &))const;
        bool push(const ElemType &e);
        bool Top(ElemType &e)const;
        bool pop(ElemType &e);
        bool pop();
        linkstack(const linkstack<ElemType>&source);
        linkstack<ElemType>&operator=(const linkstack<ElemType>&source);

};

template <class ElemType>
linkstack<ElemType>::linkstack()
{
    top=NULL;
    count=0;
}

template <class ElemType>
linkstack<ElemType>::~linkstack()
{
    clear();
}

template <class ElemType>
int linkstack<ElemType>::length() const
{
    return count;
}

template <class ElemType>
bool linkstack<ElemType>::empty() const
{
    return count==0;    
}

template <class ElemType>
void linkstack<ElemType>::clear()
{
    while(!empty())
    {
        pop();
    }
}

template <class ElemType>
void linkstack<ElemType>::traverse(void (*visit)(const ElemType &))const
{
    Node<ElemType>*temptr;  //建立指针方便分配空间
    linkstack<ElemType> tems;
    for(temptr =top;temptr !=NULL;temptr=temptr->next)
    {
        //自上而下遍历
        tems.push(temptr->data);
    }

    for(temptr=tems.top;temptr!=NULL;temptr=temptr->next)
    {
        (*visit)(temptr->data);
    }
}

template<class ElemType>
bool linkstack<ElemType>::push(const ElemType &e)
{
    Node<ElemType>*newtop=new Node<ElemType>(e,top);
    if(newtop=NULL)
    {
        return false;
    }
    else
    {
        top=newtop; //更改节点指向的上一个节点
        count++;
        return true;

    }
}

template <class ElemType>
bool linkstack<ElemType>::Top(ElemType &e)const 
{
    if(empty())
    {
        return false;
    }
    else
    {
        e=top->data;
        return true;
    }
}

template <class ElemType>
bool linkstack<ElemType>::pop(ElemType &e)
{
    if(empty())
    {
        return false; //栈空
    }
    else
    {
        Node<ElemType>*oldtop=top;
        e=oldtop->data;
        top=oldtop->next;
        delete oldtop;
        count--; //节点总数减一
        return true;
    }
}

template <class ElemType>
bool linkstack<ElemType>::pop()
{
    if(empty())
    {
        return false;
    }
    else
    {
        Node<ElemType>*oldtop=top;
        top=oldtop->next;
        delete oldtop;
        count--;
        return true;
    }

}

template <class ElemType>
linkstack<ElemType>::linkstack(const linkstack<ElemType> & source)
{
    if(source.empty())
    {
        top=NULL;
        count=0;
    }
    else
    {
        top = new Node<ElemType>(source.top->data);
        count=source.count;
        Node<ElemType>*buttomptr=top;
        for(Node<ElemType>*temptr=source.top->next;temptr!=NULL;temptr=temptr->next)
        {
            buttomptr->next = new Node<ElemType>(temptr->data);			// 向栈底追加元素
            buttomptr=buttomptr->next;
        }
    }
}

template<class ElemType>
linkstack<ElemType>&linkstack<ElemType>::operator=(const linkstack<ElemType>&source)
{
    if(&source!=this)
    {
        if (source.Empty())
		{	// source为空
			top = NULL;													// 构造栈顶指针
			count = 0;													// 初始化元素个数
		}

        else 
		{	// source非空,复制栈
			clear();													// 清空当前栈
			top = new Node<ElemType>(source.top->data);					// 生成当前栈项
			count = source.count;										// 栈元素个数
			Node<ElemType> *buttomPtr = top;							// 当前栈底指针
			for (Node<ElemType> *temPtr = source.top->next; temPtr != NULL; temPtr = temPtr->next)
			{	// 用temPtr依次指向其余元素
				buttomPtr->next = new Node<ElemType>(temPtr->data);		// 向栈底追加元素	
				buttomPtr = buttomPtr->next;							// buttomPtr指向新栈底
			}
		}
    }
    return *this;
}


