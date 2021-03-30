#include<bits/stdc++.h> 
using namespace std;
class Card
{
	public:
		string color;
		string point;
		Card(string color, string point);
		Card(string point);
		void display();
		void battle(Card card1);

};

class rcards
{
    public:
        vector<Card> card;
        rcards();
		void display_all();
        void shufflePoker();
};

Card::Card(string color, string point)
{
    this->color = color;
    this->point = point;
}

Card::Card(string point)
{
    this->color = "";
    this->point = point;
}


void Card::display()
{
	string s = this->color + this->point;
    cout<<s<<endl;
}


rcards::rcards()
{
    string colors[]={"黑心", "红心", "草花", "方块"};
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            this->card.push_back(Card(colors[i], numbers[j]));
        }
    }
    this->card.push_back(Card("", "大王"));
    this->card.push_back(Card("", "小王"));

}

void rcards::shufflePoker()
{
    srand((unsigned int)time(0));
	random_shuffle(this->card.begin(), this->card.end());
}

void rcards::display_all()
{
	for(int i=0;i<card.size();i++)
    {
        cout<<this->card[i].color;
		cout<<this->card[i].point + "\t";
    }
    cout<<endl;
}


int main()
{
    cout<<"初始化扑克牌："<<endl;
	Card card("黑心", "2");
	card.display();
    Card card2("大王");
    card2.display();
    cout<<"比较大小："<<endl;
    card2.battle(card);
    cout<<"初始化扑克牌："<<endl;
	Card card1("红心","1");
	card1.display();
	Card card3("黑心", "2");
	card3.display();
	cout<<"比较大小："<<endl;
	card3.battle(card);
	cout<<"比较大小："<<endl;
    card.battle(card1);
    cout<<"初始化扑克牌序列："<<endl;
    rcards cards;
	cards.display_all();
	cout<<"开始洗牌："<<endl;
	cards.shufflePoker();
	cards.display_all();
	cout<<"洗牌结束"<<endl;
    cout<<"开始洗牌："<<endl;
	cards.shufflePoker();
	cards.display_all();
	cout<<"洗牌结束"<<endl;
    return 0;
}



