#include<bits/stdc++.h>
#include<vector>
using namespace std;
int t=0;
class card
{
	public:  
		string color;
		char point;
		vector<card>dp;
		card(string color, char point)  
		{
			this->color=color;
			this->point=point;
		}
		
	 	card();//进行初始化 无参数情况下 
		  
		void display_all()
		{
			for(int i=0;i<dp.size();i++)
			{
				cout<<dp[i].color;
				cout<<dp[i].point;
				cout<<" ";
			}
		}
		void xipai();
		int  getvalue();//取值函数 
};



card::card()
{
    string colors[]={"c", "d", "h", "s"};
    char numbers[]="A234567891JQK"; 
    //cout<<(int)numbers[2]<<"sqwdwq";
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            dp.push_back(card(colors[i], numbers[j]));//创建组合
        }
    }
};

void card::xipai() 
{
    srand((int)time(0));
	random_shuffle(dp.begin(),dp.end());  
};  

int card::getvalue()
{
	if((int)dp[t].point>=48&&(int)dp[t].point<=58)
	{
	int p=dp[t].point-'0';
	t++;
	return p;
	}
	t++;
	return 10;
}



int n=0;

int main()
{
    cout<<"初始化扑克牌序列："<<endl;
   	card cards;
	cards.display_all(); 
	cout<<endl;
	
	cout<<"开始洗牌："<<endl;
	cards.xipai();
	cards.display_all();
	cout<<"洗牌结束"<<endl;
	
	cout<<"有几个人参加了游戏"<<endl;
	cin>>n;
	int sum[11];//最多是个人
	for(int i=1;i<=n;i++)
	{
		sum[i]=0;
	}
	int flag=0;
	while(flag==0)
	{
		for(int i=1;i<=10;i++)
		{
			sum[i]+=cards.getvalue();
			if(sum[i]==21)
			{
				flag=1;
				cout<<"第"<<i<<"个赌徒赢了"<<endl; 
				break;
			}
			
			if(sum[i]>21)
			{
				flag=1;
				cout<<"很遗憾，爆了"<<endl; 
			}
			if(t>52)
			{
				int maxx=0;
				int maxn=0;
				for(int i=1;i<=n;i++)
				{
					if(sum[i]>maxx)
					{
						maxx=sum[i];
						maxn=i;
					}
				}
				flag=1;
				cout<<"第"<<maxn<<"个赌徒赢了"<<endl; 
			}
		}
		
	} 
	
	
    return 0;
}



