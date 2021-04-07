#include<iostream>
#include"stone.h"
using namespace std;
void display(const stonewt&st,int n) 
{
    for(int i=0;i<n;i++)
    {
        cout<<"wow! ";
        st.show_stn();
    }
}

int main()
{
    stonewt incognito=275;
    stonewt wolfe(285.7);
    stonewt taft(21,8);

    cout<<"the celebrity weighed ";
    incognito.show_stn();

    cout<<"the detective weighed ";
    wolfe.show_stn();

    cout<<"the president weighted ";
    taft.show_lbs();
    return 0;
}


