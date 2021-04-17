#include<bits/stdc++.h>
using namespace std;
int n=0;
class card
{		
		public:  
		string color;
		string point;
		card();
		//void shuru();
		void display();//输出函数  
		int sum;//表示计数 
};

vector<card>dp;

void display()
{
	for(int i=0;i<dp.size();i++)
	{
		cout<<dp[i].color;
		cout<<dp[i].point;
		cout<<" ";
	}
}

void shuru() 
{
    string colors[]={"c", "d", "h", "s"};
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
           dp.push_back(card(colors[i], numbers[j])); 
        }
    }
};

void xipai() 
{
    srand((int)time(0));
	random_shuffle(dp.begin(),dp.end());  
};//洗牌

int main()
{
	card s[10];//创建对象数组
	cout<<"输入玩家数";
	cin>>n;
	int flag=0;//做游戏结束的标记哈
	shuru();
	xipai();
	display();
	//while(flag==0)
	//{
		
	//} 
	return 0;
	
}

