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
		
	 	card();//���г�ʼ�� �޲�������� 
		  
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
		int  getvalue();//ȡֵ���� 
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
            dp.push_back(card(colors[i], numbers[j]));//�������
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
    cout<<"��ʼ���˿������У�"<<endl;
   	card cards;
	cards.display_all(); 
	cout<<endl;
	
	cout<<"��ʼϴ�ƣ�"<<endl;
	cards.xipai();
	cards.display_all();
	cout<<"ϴ�ƽ���"<<endl;
	
	cout<<"�м����˲μ�����Ϸ"<<endl;
	cin>>n;
	int sum[11];//����Ǹ���
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
				cout<<"��"<<i<<"����ͽӮ��"<<endl; 
				break;
			}
			
			if(sum[i]>21)
			{
				flag=1;
				cout<<"���ź�������"<<endl; 
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
				cout<<"��"<<maxn<<"����ͽӮ��"<<endl; 
			}
		}
		
	} 
	
	
    return 0;
}



