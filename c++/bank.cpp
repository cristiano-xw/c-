#include<iostream>
#include<cstdlib>
#include<ctime>
#include"queue1.h"
using namespace std;
const int MIN_PER_HR=60;

bool newcustomer(double x)
{
    return (rand()*x/RAND_MAX<1);
}

int main()
{
    srand(time(0));
    cout<<"case study:"<<endl;
    cout<<"enter the maxium size of queue: ";
    int qs; cin>>qs; queue line(qs); //初始化队列的最大值

    cout<<"enter the number of simulation hours:";
    int hours; cin>>hours;
    long cyclelimit= MIN_PER_HR*hours;

    cout<<"enter the average number of customers per hour: ";
    double perhour; cin>>perhour; //读入平均每个小时有多少顾客
    double min_per_cust; //平均的两个顾客到来的时间差
    min_per_cust=MIN_PER_HR/perhour;

    Item temp;
    long turnaways=0; //计算被满队列劝退的人数
    long customers=0;
    long served=0; //已经进行了服务
    long sum_line=0;
    int wait_time=0;                                         
    long line_wait=0;

    for(int cycle=0;cycle<cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))//判断此时有无顾客进入
        {
            if(line.isfull())
            {
                turnaways++;
            }
            else 
            {
                customers++;
                temp.set(cycle); //读入到达时间即可
                line.enqueue(temp);//进入队列
            }
            if(wait_time<=0&&!line.isempty())
            {
                line.dequeue(temp);
                wait_time=temp.ptime(); //temp的时长即为等待时间
                line_wait+=cycle-temp.when();
                served++;
            }
        }
            if(wait_time>0)
            {
                wait_time--;
            }
            sum_line+=line.queuecount();
    }

    if(customers>0)
    {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"customers served: "<<served<<endl;
        cout<<"turnaways: "<<turnaways<<endl;
        cout<<"average queue size:";
        cout.precision(2);
        cout<<(double) sum_line/cyclelimit<<endl;
        cout<<"average waittime:";
        cout<<(double) line_wait/served<<" minutes"<<endl;
    }

    else 
        cout<<"no customers"<<endl;
        cout<<"done"<<endl;
        return 0;

}