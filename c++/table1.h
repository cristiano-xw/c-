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
};

player::player(const string &fn,const string &ln,bool ht): firstname(fn),lastname(ln), Hastable(ht){}

void player::name() const
{
    cout<<lastname<<","<<firstname<<endl;
}