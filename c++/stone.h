#include<iostream>
using namespace std;
class stonewt
{
    private:
        enum{lbs_per_stn=14};//枚举
        int stone;  
        double pds_left;
        double pounds;
    public:
        stonewt(double lbs);
        stonewt(int stn,double lbs);
        stonewt();
        ~stonewt();
        void show_lbs() const;
        void show_stn() const;
};

stonewt::stonewt(double lbs)  
{
    stone=int (lbs)/lbs_per_stn;  //表示进制转换
    pds_left=int(lbs)%lbs_per_stn+lbs-int(lbs);//表示剩下的
    pounds=lbs;
}

stonewt::stonewt(int stn,double lbs)
{
    stone=stn;
    pds_left=lbs;
    pounds=stn*lbs_per_stn+lbs;
}

stonewt::stonewt()
{
    stone=pounds=pds_left=0;
}

stonewt::~stonewt()
{
}

void stonewt::show_stn() const
{
    cout<<stone<<"stone, "<<pds_left<<"pounds\n ";
}

void stonewt::show_lbs() const
{
    cout<<pounds<<"pounds\n ";
}

