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
    //增加拷贝构造函数
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
	cout<<"2）深拷贝的案例"<<endl;
    Person p1("Edward",30);
    //用对象p1初始化对象p2,调用c++提供的默认拷贝构造函数
    Person p2 = p1;
    p2.show();
    cout<<endl;
}
