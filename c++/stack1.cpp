#include <iostream>
using namespace std;
#include "stack3.h" 

int main()
{
    stack st;
    Item temp = 1000UL;
    st.push(temp);
    temp = 2000UL;
    st.push(temp);
    temp = 3000UL;
    st.push(temp);
    stack st1(st);
    stack st2;
    st2 = st1;
    cout << "Here are some stack contents:" << endl;
    cout << "stack st:" << endl;
    cout << st;
    cout << "stack st1:" << endl;
    cout << st1;
    cout << "stack st2:" << endl;
    cout << st2;
    cout << "Bye\n";

    return 0;
}
