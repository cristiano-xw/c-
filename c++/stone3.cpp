#include <iostream>
#include"stone3.h" 
using namespace std;
int main()
{
    double val;
    int i, count;
    Stonewt min, max;
    Stonewt temp(11.0,STONE); 
    Stonewt wt[6] = {Stonewt(285.7,STONE), Stonewt(21,8,STONE), Stonewt(12.0,STONE)};

    count = 0;
    for (i = 3; i < 6; i++)
    {
        cout << "Please enter an number for pounds: ";
        while (!(cin >> val))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Illegal input! Enter an number: ";
        }
        wt[i] = Stonewt(i + 1, val,STONE); //循环赋值; 
    }

    min = max = wt[0];
    for (i = 0; i < 6; i++)
    {
        if (wt[i] < min)
        {
            min = wt[i];
        }
        if (max < wt[i])
        {
            max = wt[i];
        }
        if (temp <= wt[i])
        {
            ++count;
        }
    }
    cout << "The minimum pounds are: " << min;
    cout << "The maximum pounds are: " << max;
    cout << "There are " << count << " elements more than 11 pounds." << endl;
    return 0;
}
