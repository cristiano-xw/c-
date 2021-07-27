
#include <iostream>

typedef unsigned long Item;

class stack
{
private:
    enum {MAX = 10};
    Item *pitems;
    int size;
    int top;

public:
    stack(int n = MAX);
    stack(const stack &st);
    ~stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    stack &operator=(const stack &st);
    friend std::ostream &operator<<(std::ostream &os, const stack &st);
    //重载'<<'运算符查看复制构造函数和赋值运算符是否编写正确;
};

stack::stack(int n)
{
    top = 0;
    if (n > MAX) //长度大于MAX时的情况;
    {
        std::cout << "The length of stack can't exceed 10.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else if (n < 0) //长度小于0的情况;
    {
        std::cout << "The length of stack can't less than 0.\n";
        std::cout << "So initialize the length to 10.\n";
        size = MAX;
    }
    else
    {
        size = n;
    }
    pitems = new Item[size];
}

stack::stack(const stack &st)
{
    size = st.size;
    top = st.top;
    pitems = new Item[size]; //动态数组;
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
}

stack::~stack()
{
    delete[] pitems; //释放动态数组内存;
}

bool stack::isempty() const
{
    return top == 0;
}

bool stack::isfull() const
{
    return top == MAX;
}

bool stack::push(const Item &item)
{
    if (top < MAX)
    {
        pitems[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}

bool stack::pop(Item &item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
    {
        return false;
    }
}

stack &stack::operator=(const stack &st)
{
    if (this == &st)
    {
        return *this;
    }
    delete[] pitems;
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
    {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const stack &st)
{
    for (int i = st.top - 1; i >= 0; i--) //栈顶到栈底打印元素;
    {
        os << st.pitems[i] << std::endl;
    }
    return os;
}
