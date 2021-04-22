#include<bits/stdc++.h>
using namespace std;

typedef enum
{
	A=1,two, three, four, five, six, seven, eight,nine,ten,J,Q,K
}numtype;

typedef enum
{
	clubs,diamonds,hearts,spades
}shapetype;

struct Card
{
	numtype num; 
	shapetype shape; 
};
#define max_length 10  
 

class poker
{
public: 
		poker();	 
		virtual ~poker(){}; 
		void Game();	
private:
	Card PK[52]; 
	int startPosition; 
	Card gamers[8][21];
	int numcards[8];	 
	string name[8];	 
	int numgamer; 
	
	void Shuffle();	 
	
	int getscore(Card gamer[21],int n);	 
	
	void show(int num,bool hideFirstCard=false); 
	
	Card FirstCard()
	{
		return PK[startPosition++];
	} 
};

poker::poker()
{
	int nowPos=0; 
	
	char* str;
	
	for(int shapePos=0;shapePos<4;shapePos++)	//花色
	{
		for(int numPos=1;numPos<=13;numPos++)	//面值
		{
			PK[nowPos].shape=(shapetype)shapePos;	//花色
			PK[nowPos].num=(numtype)numPos;	//面值
			nowPos++;
		}
	}
	
	cout<<endl<<"请问有几个人参加游戏？";
	cin>>numgamer;
	
	startPosition=0; 
	int i=0; 
 
	for(i=0;i<=numgamer;i++) numcards[i]=0;
	name[0]="庄家";
	
	for(i=1;i<=numgamer;i++)    
	{
		cout<<"输入第"<<i<<"个玩家的姓名:";
		cin>>name[i];
	}
	cout<<"游戏开始"<<endl<<endl;
}

void poker::Shuffle()
{
	srand((unsigned)time(NULL));	
	for(int nowPos=51;nowPos>0;nowPos--)
	{
		int pos=rand()%(nowPos+1);	  
		Card temp;	
		temp=PK[pos];
		PK[pos]=PK[nowPos];
		PK[nowPos]=temp;
	}
}

int poker::getscore(Card gamer[21],int n) 
{
	int pos;
	int ans=0;
	for(pos=0;pos<n;pos++)	 
	{  
		if(gamer[pos].num==A) ans+=11;	 
		else if(gamer[pos].num>ten)ans+=10;	 
		else ans+=(int)gamer[pos].num;  
	}
	
	for(pos=0;ans>21&&pos<n;pos++)
	{
		if(gamer[pos].num==A) ans-=10;
	}
	return ans;
}

void poker::show(int num,bool hideFirstCard) 
{

	cout<<endl<<name[num]<<":";	 
	
	if(hideFirstCard)cout<<"<**你看不见庄家**>"; 
	else if(gamers[num][0].shape==clubs) cout<<"梅花";		
	else if(gamers[num][0].shape==diamonds) cout<<"方块";	
	else if(gamers[num][0].shape==hearts) cout<< "红桃";
	else if(gamers[num][0].shape==spades) cout<<"黑桃";	
	
	if(hideFirstCard)  cout<<"";
	else if(gamers[num][0].num==A) cout<<"A ";	//A表示A
	else if(gamers[num][0].num==J) cout<<"J ";
	else if(gamers[num][0].num==Q) cout<<"Q ";	
	else if(gamers[num][0].num==K) cout<<"K ";
	else cout<<(int)gamers[num][0].num;
	
	for(int i=1;i<numcards[num];i++)
	{
	if(gamers[num][i].shape==clubs) cout<<"梅花";		

	else if(gamers[num][i].shape==diamonds) cout<<"方块";	

		else if(gamers[num][i].shape==hearts) cout<< "红桃";	

		else if(gamers[num][i].shape==spades) cout<<"黑桃";

//输出面值
		if (gamers[num][i].num==A) cout<<"A";
		else if(gamers[num][i].num==J) cout<<"J";
		else if(gamers[num][i].num==Q) cout<<"Q";
		else if(gamers[num][i].num==K) cout<<"K";
		else cout<<(int)gamers[num][i].num;
	}
	
	if(!hideFirstCard)
		cout<<"   总分值"<<getscore(gamers[num],numcards[num]);
	cout<<endl;
	
	if(getscore(gamers[num],numcards[num])>21)
		cout<<endl<<name[num]<<"引爆(超过21点啦 ！ 结束啦)!"<<endl; 
}

void poker::Game()
{
	Shuffle();	 
	int i,j;
	 
	for(i=0;i<2;i++)
		gamers[0][numcards[0]++]=FirstCard();
		
	show(0,true);	
	
	for(i=1;i<=numgamer;i++)
	{
		for(j=0;j<2;j++)
		gamers[i][numcards[i]++]=FirstCard();
		show(i);
	}
	
	cout<<endl;
	for(i=1;i<=numgamer;i++)
	{
		char p;
		cout<<endl<<name[i]<<",你还想再要一张牌吗?如果要请输入1,不要请输入0:";
		cin>>p;
		
		while(p!='1' && p!='0')
		{
			cout<<"你的输入不正确，请重新输入。"<<endl;
			cout<<name[i]<<",你还想再要一张牌吗?如果要请输入1,不要请输入0:";
			cin>>p;
		}
		
		while (getscore(gamers[i],numcards[i])<=21&&p=='1')
		{
			gamers[i][numcards[i]++]=FirstCard();
			show(i);
			
			if(getscore(gamers[i],numcards[i])>21) break;
			cout<<endl<<name[i]<<",你想再要一张牌吗?如果要请输入1,不要请输入0:";
			cin>>p;
		}	
		
	}
	
	show(0);	 
 
	while(getscore(gamers[0],numcards[0])<=16)
	{
		gamers[0][numcards[0]++]=FirstCard();	//为庄家发1张牌
		show(0);	//显示庄家
	}
	cout<<endl;
 
	if(getscore(gamers[0],numcards[0])>21)
	{
		for(i=1;i<=numgamer;i++)
		{ 
			if(getscore(gamers[i],numcards[i])<=21)
				cout<<name[i]<<",恭喜你，庄家引爆，而你没有超过21点，你赢了！"<<endl; 
			else cout<<name[i]<<",唉,可惜超过21点了，打了平局！"<<endl; 
		}
	}
	
	else
	{ 
		for(i=1;i<=numgamer;i++)
		{ 
			if(getscore(gamers[i],numcards[i])<=21&&getscore(gamers[i],numcards[i])>getscore(gamers[0],numcards[0]))
			{ 
				cout<<name[i]<<",恭喜你，你最接近21点，你赢了!"<<endl;		
			}
			else if(getscore(gamers[i],numcards[i])==getscore(gamers[0],numcards[0]))
			{
				cout<<name[i]<<",唉，可惜了你与庄家总分相同，打了平局!"<<endl;
			}
			else
			{
				cout<<name[i]<<",对不起，你输了!（爆了或者庄家更接近21点）"<<endl;		
			}
		}
	}
}


int main()
{		
	poker newGame;	
	newGame.Game();
	cout<<endl<<endl<<"***************************************************";
	return 0;
}


