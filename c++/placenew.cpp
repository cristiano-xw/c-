#include<iostream>
#include<string>
#include<new>
using namespace std;

class test 
{
    private:
        string words;
        int number;
    public:
        test(const string & s="testing",int n=0)
        {
            words=s;
            number=n;
            cout<<words<<" "<<"constructed"<<endl;
        }
        ~test()
        {
            cout<<words<<" "<<"destroy"<<endl;
        }
        void show() const {cout<<words<<","<<number<<endl;}
};

int main()
{
    char * buffer = new char[512]; //创建一个512字节的缓存区

    test *pc1,*pc2;
    pc1=new(buffer) test;
    pc2=new test("okkk",20);

    cout<<"memory block addresses"<<endl<<"buffer:"<<(void*)buffer<<"   "<<"heap:"<<pc2<<endl;
    cout<<"memory contents"<<endl;
    cout<<pc1<<":";// 输出其初始地址
    pc1->show();
    cout<<pc2<<":";
    pc2->show();

    test *pc3,*pc4;
    pc3=new(buffer+sizeof(test)) test("better idea",6);// 多申请test个内存
    pc4=new test("heap2",10);

    cout<<"memory contents"<<endl;
    cout<<pc3<<":";
    pc3->show();
    cout<<pc4<<":";
    pc4->show();

    delete pc2; delete pc4;
    pc3->~test();
    pc1->~test();
    delete [] buffer;//释放内存空间
    cout<<"done";
    return 0;
    
}