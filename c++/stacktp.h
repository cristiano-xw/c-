//使用类模板构造一个栈
template <class type>
class stack
{
private:
    enum{MAX=10};
    type items[MAX];
    int top;
public:
    stack();
    bool isempty();
    bool isfull();
    bool push(const type & item);
    bool pop(type & item);
};

template <class type>
stack<type>::stack()//构造函数
{
    top=0;
}

template <class type>
bool stack<type>::isempty()
{
    return top==0;//判断是否为空栈
}

template <class type>
bool stack<type>::isfull()
{
    return top==MAX;
}

template <class type>
bool stack<type>::push(const type & item)
{
    if(top<MAX)
    {
        items[top++]=item;
        return true;
    }
    else 
    return false;
}//入栈指令

template <class type>
bool stack<type>::pop(type & item)
{
    if(top>0)
    {
        item=items[--top];//将栈顶的元素弹出
        return true;
    }
    else 
    return false;
}

