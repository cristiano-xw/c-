#include<bits/stdc++.h>
using namespace std;

class Base//��������
{
public:
    Base(int a) : ma(a){}
    //void Show() 
    virtual void Show()
    {
        cout<<"ma "<<ma<<endl;
    }
protected:
    int ma;
};
class Derive : public Base//�����๫�м̳л���
{
public:
    Derive(int b) : mb(b) ,Base(b){}//ָ������Ĺ��췽ʽ
    void Show()
    {
        cout<<"mb "<<mb<<endl;
    }
protected:
    int mb;
};
int main()
{
    Base* pb = new Derive(10);//����ָ��ָ��������ָ��
    cout<<sizeof(Base)<<endl;//�����С
    cout<<sizeof(Derive)<<endl;//�������С
    cout<<typeid(pb).name()<<endl;//pbָ�������
    cout<<typeid(*pb).name()<<endl;//pbָ�����������
    pb->Show();
    delete pb;
    return 0;
}

