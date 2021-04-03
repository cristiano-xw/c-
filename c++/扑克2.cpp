#include<bits/stdc++.h>
#include<vector>
using namespace std;
class card
{
	public:  
		string color;
		string point;
		card(string color, string point)  
		{
			this->color=color;
			this->point=point;
		}
		card(string point)
		{
			this->point=point;
		}
		void display();
};

void card::display()//输出牌 
{
	string s = this->color + this->point;
    cout<<s<<endl;
}

class rcards
{
    public:
        vector<card>dp;
        rcards();
		void display_all()
		{
			for(int i=0;i<dp.size();i++)
			{
				cout<<this->dp[i].color;
				cout<<this->dp[i].point;
				cout<<" ";
			}
		}
		void xipai();
};

rcards::rcards()
{
    string colors[]={"c", "d", "h", "s"};
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            this->dp.push_back(card(colors[i], numbers[j]));//创建组合 
        }
    }
    
    this->dp.push_back(card("", "大王"));
    this->dp.push_back(card("", "小王"));
};//读入牌 

void rcards::xipai() 
{
    srand((int)time(0));
	random_shuffle(this->dp.begin(),this->dp.end());  
};  

int main()
{
    cout<<"初始化扑克牌序列："<<endl;
    rcards cards;
	cards.display_all();
	cout<<endl;
	cout<<"开始洗牌："<<endl;
	cards.xipai();
	cards.display_all();
	cout<<"洗牌结束"<<endl;
    cout<<"开始洗牌"<<endl;
	cards.xipai();
	cards.display_all();
	cout<<"洗牌结束"<<endl;
    return 0;
}



