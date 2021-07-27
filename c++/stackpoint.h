#include<iostream>
using namespace std;

template<typename type>
class stack
{
    private:
        enum{size=10};
        int stacksize;
        type * items; //定义一个指针
        int top; 
    public:
        explicit stack(int ss=size);
        stack(const stack & s);
        ~stack() {delete[] items;}  //   其实定义了指针数组，每个指针指向一个字符串
        bool isempty() {return top==0;}
        bool isfull() {return top==stacksize;}
        bool push(const type & item);
        stack & operator=(const stack & st);   
};

template <typename type>
stack<type>::stack(int s):stacksize(s),top(0)
{
    items=new type[stacksize];
}

