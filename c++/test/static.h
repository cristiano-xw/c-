#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class PPerson{
public:
    //��ͨ��Ա�������Է���static��non-static��Ա����
    void changeParam1(int param){
        mParam = param;
        sNum = param;
    }
    //��̬��Ա����ֻ�ܷ���static��Ա����
    static void changeParam2(int param){
        //mParam = param; //�޷�����
        sNum = param;
    }
private:
    static void changeParam3(int param){
        //mParam = param; //�޷�����
        sNum = param;
    }
public:
    int mParam;
    static int sNum;
};
//��̬��Ա���������ʼ��
int PPerson::sNum = 0;
 
void test_4()
{
    cout<<"4����̬��Ա�İ���"<<endl;
    //1. ����ֱ�ӵ���
    PPerson::changeParam2(100);
 
    //2. ͨ���������
    PPerson p;
    p.changeParam2(200);
 
    //3. ��̬��Ա����Ҳ�з���Ȩ��
    //Person::changeParam3(100); //�����޷�����˽�о�̬��Ա����
}
