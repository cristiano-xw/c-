#include<iostream>
#include<string>
#include<cstring>
#include<windows.h>
using namespace std;
class Building;
//��Ԫ��
class MyFriend{
public:
    //��Ԫ��Ա����
    void LookAtBedRoom(Building& building);
    void PlayInBedRoom(Building& building);
};
class Building{
    //ȫ�ֺ�������Ԫ
    friend void CleanBedRoom(Building& building);
#if 0
    //��Ա��������Ԫ
    friend void MyFriend::LookAtBedRoom(Building& building);
    friend void MyFriend::PlayInBedRoom(Building& building);
#else  
    //��Ԫ��
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
    cout << "�ҵ����Ѳι�" << building.mBedroom << endl;
}
void MyFriend::PlayInBedRoom(Building& building){
    cout << "�ҵ�������ˣ��" << building.mBedroom << endl;
}
 
//��Ԫȫ�ֺ���
void CleanBedRoom(Building& building){
    cout << "��Ԫȫ�ֺ�������" << building.mBedroom << endl;
}
 
Building::Building(){
    this->mSittingRoom = "����";
    this->mBedroom = "����";
}
void test_3()
{
	cout<<"3����Ԫ����"<<endl;
    Building building;
    MyFriend myfriend;
    CleanBedRoom(building);
    myfriend.LookAtBedRoom(building);
    myfriend.PlayInBedRoom(building);
}
