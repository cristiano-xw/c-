#include<iostream>
#include"table1.h"
using namespace std;
int main()
{
    cout<<"input firstname,lastname,hastable";
    player player1("yang","xinwei",1);
    player player2("wang","haoli",0);

    player1.name();
    player2.name();

    if(player1.hastable())
    {
        cout<<"has a table"<<endl;
    }
    else
    {
        cout<<"do not have a table"<<endl;
    }

    return 0;


}
