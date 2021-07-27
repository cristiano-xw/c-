#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Person{
public:
    Person(char* name,int age){
        pName = (char*)malloc(strlen(name) + 1);
        strcpy(pName,name);
        mAge = age;
    }
    //���ӿ������캯��
    Person(const Person& person){
        pName = (char*)malloc(strlen(person.pName) + 1);
        strcpy(pName, person.pName);
        mAge = person.mAge;
    }
    ~Person(){
        if (pName != NULL){
            free(pName);
        }
    }
    void show()
    {
    	cout<<"name is "<<this->pName;
    	cout<<"age is "<<this->mAge;
	}
private:
    char* pName;
    int mAge;
};
int main()
{
	cout<<"2������İ���"<<endl;
    Person p1("Edward",30);
    //�ö���p1��ʼ������p2,����c++�ṩ��Ĭ�Ͽ������캯��
    Person p2 = p1;
    p2.show();
    cout<<endl;
}
