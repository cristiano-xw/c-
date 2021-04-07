#include<iostream>
#include"stringbad.h"
using namespace std;

void callme1(stringbad &rsb)
{
    cout<<"string passed by reference:\n";
    cout<<"\""<<rsb<<"\"\n";
}

void callme2(stringbad sb)
{
    cout<<"string passed by value:\n";
    cout<<"\""<<sb<<"\"\n";
}

int main()
{
    using std::endl;
    {
        cout<<"starting an inner block.\n";
        stringbad headline1("celery stalks at midnight");
        stringbad headline2("lettuce prey");
       
       cout<<"1"<<headline1<<endl;
       cout<<"2"<<headline2<<endl;

       


    }
}