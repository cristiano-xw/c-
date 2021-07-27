#include<iostream>
using namespace std;

typedef unsigned long Item;
class stack
{
    private:
        enum{MAX=10};
        Item * pitems;  
        int size; //栈的大小
        int top; //栈顶
    public:
        stack();
        //stack(int n=MAX); 
        stack(const stack & st); //利用已有的栈初始化，复制构造函数
        ~stack();
        bool isempty() const;
        bool isfull() const;
        bool push(const Item & item);
        bool pop(Item & item);
        stack & operator=(const stack & st);
        friend ostream & operator<<(ostream & os,const stack &st);
};

stack::stack()
{
    top=0;
    size=10;
    pitems = new Item[size];
}


/*stack::stack(int n)
{
    if(n>MAX)
    {
        cout<<"the size of the stack is exceed limit"<<endl;
        size=MAX;
    }

    if(n<MAX)
    {
        cout<<"please input a bigger size"<<endl;
        size=MAX;
    }

    if(n==MAX)
    {
        size=MAX;
    }

    pitems=new Item[size]; //new申请空间
    top=0;
}*/


stack::stack(const stack & st)
{
    size=st.size;
    top=st.top;
    for(int i=0;i<top;i++)
    {
        pitems[i]=st.pitems[i];
    }
}//相当于对其进行复制构造

stack::~stack()
{
    delete[] pitems;
}

bool stack::isempty() const
{
    return top==0;
}

bool stack::isfull() const
{
    return top==MAX;
}

bool stack::push(const Item & item)
{
    if(top<MAX)
    {              
        pitems[top++]=item;   //使用右自增     
        return true;
    }

    else 
    {
        return false;
    }
}

bool stack::pop(Item & item)
{
    if(top>0)  
    {
        item=pitems[--top];
        return true; 
    }
    else
    {
        return false;
    }
}

stack & stack::operator=(const stack & st)
{
    if(this==&st) 
    {
        return *this;
    }

    delete[] pitems;
    size=st.size;
    top=st.top;
    pitems = new Item[size];
    for(int i=0;i<top;i++) //最后的top并没有保留元素
    {         
        pitems[i]=st.pitems[i];
    }
    return *this;
}


ostream & operator<<(ostream & os,const stack &st)
{
    for(int i=st.top-1;i>=0;i--)
    {
       os<<st.pitems[i]<<" ";  
    }
    cout<<endl;
    return os;  
}     
