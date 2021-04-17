#include <iostream>
 
using namespace std;
class animal
{
protected:
    int height;  //身高或体长
    int weight;  //体重
    char sex;   //性别
public:
    animal() {}
    animal(int h,int w,char s):
        height(h),weight(w),sex(s) {}
};
 
class aqu_animal:virtual public animal  //水生动物
{
protected:
    int swimming_speed;  //游泳速度
public:
    aqu_animal() {}
    aqu_animal(int h,int w,char s,int s_p):
        animal(h,w,s),swimming_speed(s_p) {}
};
 
class ter_animal:virtual public animal
{
protected:
    int running_speed;
public:
    ter_animal() {}
    ter_animal(int h,int w,char s,int r_s):
        animal(h,w,s),running_speed(r_s) {}
};
 
class amp_animal:public ter_animal,public aqu_animal
{
public:
    amp_animal() {}
    amp_animal(int h,int w,char s,int s_p,int r_s):
        animal(h,w,s),aqu_animal(h,w,s,s_p),ter_animal(h,w,s,r_s) {}
    void input();
    void show();
private:
};
 
void amp_animal::input()
{
    cin>>height>>weight>>sex>>swimming_speed>>running_speed;
}
 
void amp_animal::show()
{
    cout<<"height:"<<height<<endl;
    cout<<"weight:"<<weight<<endl;
    cout<<"sex:"<<sex<<endl;
    cout<<"swimming_speed:"<<swimming_speed<<endl;
    cout<<"running_speed:"<<running_speed<<endl;
}
int main()
{
    amp_animal a1(50,20,'m',100,120);
    amp_animal a2;
    a2.input();
    a1.show();
    cout<<endl;
    a2.show();
    return 0;
}
