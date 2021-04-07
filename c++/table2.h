#include<iostream>
#include<cstring>
using namespace std;

class player
{
    private:
        string firstname;
        string lastname;
        bool Hastable;
    public:
        player(const string & fn="none", const string & ln ="none",bool ht =0);
        void name() const;
        bool hastable() const {return Hastable;};
        void resettable(bool v){Hastable=v;};
};//基类函数

class rplayer:public player 
{
    private:
        int rating;//派生类参数
    public:
        rplayer(int r=0,const string & fn="none", const string & ln ="none",bool ht =0);
        rplayer(int r,const player &tp);
        int Rating() const {return rating;};
        void resetrating(int r) {rating=r;}
};

player::player(const string &fn,const string &ln,bool ht): firstname(fn),lastname(ln), Hastable(ht){}

void player::name() const
{
    cout<<lastname<<","<<firstname<<endl;
}

rplayer::rplayer(int r,const string & fn, const string & ln ,bool ht):player(fn,ln,ht)
{
   rating=r;
}
//不可以二次赋值

rplayer::rplayer(int r,const player &tp):player(tp),rating(r)
{
}

