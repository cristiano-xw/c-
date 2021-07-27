#include <iostream>
#include "name.h"

int main()
{
    using std::cout;
    using std::endl;

    cow temp1;
    cow temp2("Clover", "Computer", 30);
    cow temp3(temp2);

    cout << "Here are some cows:" << endl;
    cout << "The first:" << endl;
    temp1.showcow();
    cout << "The second:" << endl;
    temp2.showcow();
    cout << "The third:" << endl;
    temp3.showcow();
    temp1 = temp3;
    cout << "After assignment for temp1:" << endl;
    temp1.showcow();

    return 0;
}
