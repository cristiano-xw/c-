#include<bits/stdc++.h> 
using namespace std;

const int COLOR=4;
const int NUM=13;
string RANKS[] = {"A", "2", "3", "4", "5", "6", "7","8", "9", "10", "J", "Q", "K"};
string SUITS[] = {"c", "d", "h", "s"};

class Card{
public:
	string rank;
	string suit;
	bool bFaceUp;
	Card(){
		bFaceUp=true;
	}
	Card(string strrank,string strsuit,bool FaceUp){
		rank=strrank;
		suit=strsuit;
		bFaceUp=FaceUp;
	}
	void Print(){
		//cout<<"Suit="<<suit<<";Rank="<<rank<<"  ";
		if (bFaceUp)
			cout<<rank<<suit<<endl;
		else
			cout<<"**"<<endl;
	}
};

class Hand{
public:
	vector<Card> cards; 
	Hand(){}
	void Clear(){
		if (!cards.empty())
			cards.clear();
	}
	void Show()
	{
		for(int i=0;i<cards.size();i++)
			cards.at(i).Print();
	}
	int Value(){
	
			//A可以作为11，也可作为1点，当它与<10点的牌配对时，=11点，否则，=1点
		int iRet=0;//分数累加器； 
		string str="";
		int iCountA=0;//‘A’累加器； 
		for(int i=0;i<cards.size();i++){
			if(cards.at(i).rank!="A" && cards.at(i).rank!="J" && cards.at(i).rank!="Q" && cards.at(i).rank!="K")
				iRet+=stoi(cards.at(i).rank);//stoi函数为<sting>中string转换为int; 
			else if (cards.at(i).rank=="J" || cards.at(i).rank=="Q" || cards.at(i).rank=="K")
				iRet+=10;
			else{
			
				iRet+=11;
				iCountA++;
			}
		}
		//查看A，必要时将A当成1点；
		while (iRet>21){
			if (iCountA>0){
				iRet-=10;
				iCountA--;
			}
			if (iCountA==0)
				break;
		}
		return iRet;
	}
};


class Deck:public Hand
{
private:
	Card tempcards[NUM*COLOR];
public:
	
	//vector<Card> cards;
	Deck(){
		int k=0;
		for(int i=0;i<COLOR;i++){
			for(int j=0;j<NUM;j++){
				tempcards[k].rank=RANKS[j];
				tempcards[k].suit=SUITS[i];
				k++;
			}
		}

	}
	void Shuffle(){
		//随机产生一个0~51的数，以它为下标与cards[i]交换，i从0循环到51；
		srand((int)time(0));
		int j=0;
		//swap
		for (int i=0;i<COLOR*NUM;i++){
			j=rand()%(COLOR*NUM);
			Card temp(tempcards[i]);
			tempcards[i]=tempcards[j];
			tempcards[j]=temp;
			//cout<<"-----------"<<endl;
		}
		for(int k=0;k<NUM*COLOR;k++){
			cards.push_back(tempcards[k]); 
		}
	}
	
	void Give(Hand &hand){//将数组中下标为0的 扑克牌给hand; 
		if (!cards.empty())
		{
			Card FirstCard=cards.at(0);
			hand.cards.push_back(FirstCard);    
			cards.erase(cards.begin());
		}
	}
	
	
};


int main(){
	Deck deck;
	deck.Shuffle();
	deck.Show();
	Hand me;
	cout<<"----------"<<endl;
	deck.Give(me);
	deck.Give(me);
	deck.Give(me);
	deck.Show();
	cout<<"---------"<<endl;
	cout<<"me:"<<endl;
	me.Show();
	int point=me.Value();
	cout<<point<<endl;
}

