#include<iostream>
using namespace std;

template<typename T>
class myfriend
{
    private:
        T item;
    public:
        myfriend(const T &i): item(i){}  
        template<typename C,typename D>friend void show2(C &,D &);
};

template<typename C,typename D> void show2(C & c,D &d) //指定类型的混用
{
    cout<<c.item<<"  "<<d.item<<endl;
}

int main()
{
    myfriend<int>hfi1(10);
    myfriend<int>hfi2(20);
    show2(hfi1,hfi2);
    return 0;
}
