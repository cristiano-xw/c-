#include<iostream.h>
#include<stdlib.h>
#include"utility.h"
#include"wait.h"

class Game{
private:
	float player;             //一局中玩家的总点数
	float cpu;                //一局中计算机的总点数
	int win;                  //玩家赢的次数
	int lose;                 //玩家输的次数
	int draw;                 //平局次数
	int playerturns;          //一局中玩家牌数
	int cputurns;             //一局中庄家牌数
	int money;                //玩家的当前有的赌资
	int bet;                  //一局中玩家下注值总和
	int  i;                   //每次的下注值
public:
	Game();
	int h(float);             //测试是否为高级玩家
	int GetMon();             //返回总本金数
	int Check();              //检查是否还可下注
    int playerhit();          //玩家再要一张牌	
	void reset();             //重新开始一局
	void cpuhit();            //庄家再要一张牌
	void deal();              //为玩家和计算机各发两张牌
	void BET();               //下注
	void print();             //打出最后的输赢平局数及最后有的赌资
	void results();           //找出最后的结果，输赢
};
                             
void replay(char &ans);       //允许重复游戏
void rules();                 //游戏规则介绍

int main()
{
	char ans;
	system("cls");            //执行系统命令 ,清屏
	rules();
	cout<<"\t\t\t你要开始吗？（y/n）";
	cin>>ans;
	if((ans == 'y')||(ans=='Y')) //查看是否要开始游戏
	{
		cout<<"\t\t\t";	
	}
	else
	{
		return(0);
	}
	Game game;    //定义一个对象
	do{
		system("cls");           //清屏
		if(game.GetMon()<=0) //查看是否有赌金
		{
	    	cout<<"您没有赌本了！"<<endl; 
			return 0;
		}
		game.reset();//开始新的一局
        game.BET(); //下赌注
     	game.deal(); //发牌程序，为计算机和玩家各发两张牌
		cout<<"\t\t\t继续要牌吗？（Y/N）"; //询问是否要牌
		game.playerhit();        //给玩家发一张牌
		game.cpuhit();           //  给计算机发一张牌
		cout<<endl;
		cout<<endl;
        game.results(); //判断输赢
		game.print();
		replay(ans);
	}while((ans=='y')||(ans=='Y'));
	
	cout<<endl;
	cout<<"\t\t\t\t";
	return 0;
}


void rules()        //规则介绍
{
	cout<<"\t\t 欢迎进入游戏!"<<endl;
    cout<<"\t\t 规则介绍："<<endl;
	cout<<"\t\t1:您最多可以要五张牌；"<<endl;
	cout<<"\t\t2:超过十点的牌算半点；"<<endl;
	cout<<"\t\t3:总的牌面超过21点则爆了；"<<endl;
	cout<<"\t\t4:赢家可以得到双倍的赌注；"<<endl;
	cout<<"\t\t5:拿牌之后您可以增加赌注"<<endl;
	cout<<"\t\t\t";
}


void Game::BET()                    //找出他们要下注多少;
{  
	cout<<"\t\t\t您有：$"<<money<<endl;
	cout<<"\t\t\t 您下注多少？ ";
    cin>>i;
	   if(Check())
	   { bet+=i;
	   money=money-i;}
	   else{
		   cout<<"您没有足够的钱";
		   BET();                      // 下注
	   }

	   
}
void Game::results()                                 //判断输赢
{
	cout<<"\t\t\t计算机总的牌面是："<<cpu<<endl; 
	cout<<"\t\t\t您总的牌面是："<<player<<endl;
	cout<<endl;
	if(cpu==player)
	{
		cout<<"\t\t\t平局。"<<endl;
		draw++;    
	}
	else
	{
		if(cpu>player)
		{
			cout<<"\t\t\t您输了。"<<endl;
			lose++;
		}
		else
		{
			cout<<"\n\t\t\t您赢了。";
		    money=money+(bet*2);
        	win++;	
		}
	}
}


void Game::print()
{
	cout<<"\n\t\t\t\t赢的次数 :"<<win<<endl;
	cout<<"\t\t\t\t输的次数 :"<<lose<<endl;
	cout<<"\t\t\t\t平局次数 :"<<draw<<endl;
	cout<<"\t\t\t\t您的赌本 :"<<money<<endl;
}

Game::Game()               //成员数据的初始化
{
	player=0;
	cpu=0;
	win=0;
	lose=0;
	draw=0;
	playerturns=0;
	cputurns=0;
	money=100;
	bet=0;
	cout<<"\t\t\t您的赌本有： $100"<<endl;  
}


int Game::GetMon()
{
	return money;
}

void Game::reset()
{
	player=0;
	cpu=0;
	playerturns=0;
	cputurns=0;
	bet=0;
}
int Game::h(float card)           //高级玩家的判断
{
	cout<<"\n\n\n验证您是否为高级玩家，请输入密码"<<endl;
	int superman;
	cin>>superman;
	if(superman==666666)
	{
		cout<<"密码正确"<<endl;
		cout<<"下张牌的点数是："<<card<<"。要吗?（Y/N）";
		char ans;
		cin>>ans;
		if((ans=='y')||(ans=='Y')) 
		return 1;
		else return 0;
	}
	else cout<<"对不起，密码错误!";
	return -1;
}


int Game::Check()            // 判断下注值是否小于拥有的赌资
{
	if(i<=money) return 1;
    else return 0;
}

void Game::cpuhit()        //给计算机发一张牌
{
	float card;
	card=random(13,1);    //在1和13之间取一个随机数赋给card
	if(card>=10)
	{
		card=0.5;
	}
	if(cpu+card>21) return;
	cout<<"计算机要一张牌。"<<endl;
	cputurns++;
	cpu+=card;
	if(cputurns<6) cpuhit();
}


void Game::deal()                    //为计算机和玩家各发两张牌
{
	float playercard1,playercard2,cpucard1,cpucard2;
	playerturns=2;
	cputurns=2;
	playercard1=random(13,1);
	cout<<"\n\n\t\t\t发牌"<<endl;
	wait(350);
	playercard2=random(13,1);
	wait(150);
	cpucard1=random(13,1);
	wait(350);
	cpucard2=random(13,1);
	if(playercard1>=10)
	{
		playercard1=0.5;
	}
	if(playercard2>=10)
	{
		playercard2=0.5;
	}
	if(cpucard1>=10)
	{
		cpucard1=0.5;
	}
	if(cpucard2>=10)
	{
		cpucard2=0.5;
	}
	player=playercard1+playercard2;
	cpu=cpucard1+cpucard2;
	cout<<"\t\t\t您的牌面是："<<player<<endl;
	cout<<"["<<playercard1<<"]";
	cout<<"["<<playercard2<<"]";
	cout<<endl;
	cout<<"\t\t\t计算机其中一张牌的点数是 "<<cpucard1<<endl;
	cout<<endl;
	cout<<"[*] "<<" ["<<cpucard1<<"]";
}    

int Game::playerhit()
{   int  passwords;
	float card;
	card=random(13,1);
	if(card>=10)
	{
		card=0.5;
	}
	char ans;
	cin>>ans;
	if((ans=='h')||(ans=='H'))
	{
		if(h(card)==0) return 0;
	}
	else{
		if((ans!='y')&(ans!='Y'))
			return 0;
	}
	playerturns++; 
	if(playerturns>5) //判断玩家能否要牌
	{
		cout<<"\t\t\t对不起，您最多能要五张牌!"<<endl;
		return 0;
	}
	else{   cout<<" 验证您是否为高级玩家(y/n) ";
	        cin>>ans;
			if(ans=='y'||ans=='Y')
			{  cout<<"请输入密码:"<<endl;//启动超级玩家
        	   cin>>passwords;//输入密码

		       if(passwords==666666)
			   {  card=random(13,1);
		        cout<<"下张牌是:"<<card<<endl;
				cout<<"要不要(y/n)";
				cin>>ans;
				if(ans=='y'||ans=='Y')
				{
			      player=player+card;
				  
				}  
	
			   }
              else  cout<<"对不起，您的密码错误";
			       
			}
			 else
				player=player+card;
				cout<<"\t\t\t下张的牌的点数是 ："<<card<<endl;
				cout<<"\t\t\t您的总牌面是："<<player<<endl;
				if (player>21)
				{lose++;
				return 0;}
				BET();
		}
	cout<<"\t\t\t您是否再要一张牌？（Y/N）"; //询问是否要牌
	playerhit();
	return 1;
}

void replay(char &ans)
{
	cout<<"\n\t\t\t您想继续玩吗(Y/N)？";
	cin>>ans;
}

