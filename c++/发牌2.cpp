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
	
	for(int shapePos=0;shapePos<4;shapePos++)	//��ɫ
	{
		for(int numPos=1;numPos<=13;numPos++)	//��ֵ
		{
			PK[nowPos].shape=(shapetype)shapePos;	//��ɫ
			PK[nowPos].num=(numtype)numPos;	//��ֵ
			nowPos++;
		}
	}
	
	cout<<endl<<"�����м����˲μ���Ϸ��";
	cin>>numgamer;
	
	startPosition=0; 
	int i=0; 
 
	for(i=0;i<=numgamer;i++) numcards[i]=0;
	name[0]="ׯ��";
	
	for(i=1;i<=numgamer;i++)    
	{
		cout<<"�����"<<i<<"����ҵ�����:";
		cin>>name[i];
	}
	cout<<"��Ϸ��ʼ"<<endl<<endl;
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
	
	if(hideFirstCard)cout<<"<**�㿴����ׯ��**>"; 
	else if(gamers[num][0].shape==clubs) cout<<"÷��";		
	else if(gamers[num][0].shape==diamonds) cout<<"����";	
	else if(gamers[num][0].shape==hearts) cout<< "����";
	else if(gamers[num][0].shape==spades) cout<<"����";	
	
	if(hideFirstCard)  cout<<"";
	else if(gamers[num][0].num==A) cout<<"A ";	//A��ʾA
	else if(gamers[num][0].num==J) cout<<"J ";
	else if(gamers[num][0].num==Q) cout<<"Q ";	
	else if(gamers[num][0].num==K) cout<<"K ";
	else cout<<(int)gamers[num][0].num;
	
	for(int i=1;i<numcards[num];i++)
	{
	if(gamers[num][i].shape==clubs) cout<<"÷��";		

	else if(gamers[num][i].shape==diamonds) cout<<"����";	

		else if(gamers[num][i].shape==hearts) cout<< "����";	

		else if(gamers[num][i].shape==spades) cout<<"����";

//�����ֵ
		if (gamers[num][i].num==A) cout<<"A";
		else if(gamers[num][i].num==J) cout<<"J";
		else if(gamers[num][i].num==Q) cout<<"Q";
		else if(gamers[num][i].num==K) cout<<"K";
		else cout<<(int)gamers[num][i].num;
	}
	
	if(!hideFirstCard)
		cout<<"   �ܷ�ֵ"<<getscore(gamers[num],numcards[num]);
	cout<<endl;
	
	if(getscore(gamers[num],numcards[num])>21)
		cout<<endl<<name[num]<<"����(����21���� �� ������)!"<<endl; 
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
		cout<<endl<<name[i]<<",�㻹����Ҫһ������?���Ҫ������1,��Ҫ������0:";
		cin>>p;
		
		while(p!='1' && p!='0')
		{
			cout<<"������벻��ȷ�����������롣"<<endl;
			cout<<name[i]<<",�㻹����Ҫһ������?���Ҫ������1,��Ҫ������0:";
			cin>>p;
		}
		
		while (getscore(gamers[i],numcards[i])<=21&&p=='1')
		{
			gamers[i][numcards[i]++]=FirstCard();
			show(i);
			
			if(getscore(gamers[i],numcards[i])>21) break;
			cout<<endl<<name[i]<<",������Ҫһ������?���Ҫ������1,��Ҫ������0:";
			cin>>p;
		}	
		
	}
	
	show(0);	 
 
	while(getscore(gamers[0],numcards[0])<=16)
	{
		gamers[0][numcards[0]++]=FirstCard();	//Ϊׯ�ҷ�1����
		show(0);	//��ʾׯ��
	}
	cout<<endl;
 
	if(getscore(gamers[0],numcards[0])>21)
	{
		for(i=1;i<=numgamer;i++)
		{ 
			if(getscore(gamers[i],numcards[i])<=21)
				cout<<name[i]<<",��ϲ�㣬ׯ������������û�г���21�㣬��Ӯ�ˣ�"<<endl; 
			else cout<<name[i]<<",��,��ϧ����21���ˣ�����ƽ�֣�"<<endl; 
		}
	}
	
	else
	{ 
		for(i=1;i<=numgamer;i++)
		{ 
			if(getscore(gamers[i],numcards[i])<=21&&getscore(gamers[i],numcards[i])>getscore(gamers[0],numcards[0]))
			{ 
				cout<<name[i]<<",��ϲ�㣬����ӽ�21�㣬��Ӯ��!"<<endl;		
			}
			else if(getscore(gamers[i],numcards[i])==getscore(gamers[0],numcards[0]))
			{
				cout<<name[i]<<",������ϧ������ׯ���ܷ���ͬ������ƽ��!"<<endl;
			}
			else
			{
				cout<<name[i]<<",�Բ���������!�����˻���ׯ�Ҹ��ӽ�21�㣩"<<endl;		
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


