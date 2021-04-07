#include<iostream>
#include<cstring>
#include"table2.h"
using namespace std;

int main()
{
    player player1("yang","xinwei",0);  
    rplayer rplayer2(1212,player1);
    cout<<"name:";
    rplayer2.name();
    cout<<";rating: "<<rplayer2.Rating()<<endl;
    return 0;
}