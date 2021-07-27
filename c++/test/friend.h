#include<iostream>
#include<string>
#include<cstring>
#include<windows.h>
using namespace std;
class Building;
//友元类
class MyFriend{
public:
    //友元成员函数
    void LookAtBedRoom(Building& building);
    void PlayInBedRoom(Building& building);
};
class Building{
    //全局函数做友元
    friend void CleanBedRoom(Building& building);
#if 0
    //成员函数做友元
    friend void MyFriend::LookAtBedRoom(Building& building);
    friend void MyFriend::PlayInBedRoom(Building& building);
#else  
    //友元类
    friend class MyFriend;
#endif
public:
    Building();
public:
    string mSittingRoom;
private:
    string mBedroom;
};
 
void MyFriend::LookAtBedRoom(Building& building){
    cout << "我的朋友参观" << building.mBedroom << endl;
}
void MyFriend::PlayInBedRoom(Building& building){
    cout << "我的朋友玩耍在" << building.mBedroom << endl;
}
 
//友元全局函数
void CleanBedRoom(Building& building){
    cout << "友元全局函数访问" << building.mBedroom << endl;
}
 
Building::Building(){
    this->mSittingRoom = "客厅";
    this->mBedroom = "卧室";
}
void test_3()
{
	cout<<"3）友元案例"<<endl;
    Building building;
    MyFriend myfriend;
    CleanBedRoom(building);
    myfriend.LookAtBedRoom(building);
    myfriend.PlayInBedRoom(building);
}
