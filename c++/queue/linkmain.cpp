#include<iostream>
//#include"linkqueue.h"
#include"sqqueue.h" 
using namespace std;

template<class ElemType>
void show(const ElemType &e)
{
    cout<<e<<" ";
}

int main()
{
    char select = '0';
    //linkqueue<double> qa,qb;
    sqqueue<double>qa(20),qb(10);
    double x;

    while(select!='6')
    {
        cout << endl << "1. 生成队列.";
        cout << endl << "2. 显示队列.";
        cout << endl << "3. 入队列.";
        cout << endl << "4. 出队列.";
        cout << endl << "5. 取队列头.";
		cout << endl << "6. 退出";
		cout << endl << "选择功能(1~6):";
		cin >> select;

        switch(select)
        {
            case '1':
				cout << endl << "输入e(e = 0时退出)";
				cin >> x;
				while (x != 0)
				{
					qa.inqueue(x);
					cin >> x;
				}
				break;
            case '2':
			    qb = qa;
				cout << endl;
			    qb.traverse(show<double>);
				break;
            case '3':
                cout<<endl<<"输入元素值:";
                cin>>x;
                qa.inqueue(x);
                break;
            case '4':
                qa.outqueue(x);
                cout<<endl<<"队头的元素:"<<x<<"."<<endl;
                break;
            case '5':
                qa.gethead(x);
                cout<<endl<<"队头"<<x<<"."<<endl;

            case '6':
                break;
        }
    }
    return 0;
}



