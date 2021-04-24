#include<bits/stdc++.h>
#include"park.h"
using namespace std;

int main() 
{
int N=0;
cout << "请输入停车位数量：";
cin >> N;// 输入停车位数量，此处输入2

Park* park = new Park(N);// 创建一个停车场对象
car car1("鲁B-12345","奥迪A6"); // 创建轿车对象
car1.enter(park); // car1进入停车场，分配停车位
Truck truck("鲁B-23456", 15); // 创建卡车对象
truck.enter(park); // truck进入停车场，分配车位
car1.leave(park); // car1离开停车场，缴纳停车费
bus bus1("鲁B-34567", 50); // 创建公交车对象
bus1.enter(park); // bus进入停车场，分配车位
/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
cout<<"显示"<<endl;
park->showInfo();

car car2("鲁B-45678","宝马320"); // 创建轿车对象
car2.enter(park); 
// car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配

bus1.leave(park); // bus离开停车场，缴纳停车费
truck.leave(park); // truck离开停车场，缴纳停车费
/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
park->showInfo();
return 0;
}