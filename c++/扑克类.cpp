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
    string colors[]={"����", "����", "�ݻ�", "����"};
    string numbers[]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<13;j++)
        {
            this->card.push_back(Card(colors[i], numbers[j]));
        }
    }
    this->card.push_back(Card("", "����"));
    this->card.push_back(Card("", "С��"));

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
    cout<<"��ʼ���˿��ƣ�"<<endl;
	Card card("����", "2");
	card.display();
    Card card2("����");
    card2.display();
    cout<<"�Ƚϴ�С��"<<endl;
    card2.battle(card);
    cout<<"��ʼ���˿��ƣ�"<<endl;
	Card card1("����","1");
	card1.display();
	Card card3("����", "2");
	card3.display();
	cout<<"�Ƚϴ�С��"<<endl;
	card3.battle(card);
	cout<<"�Ƚϴ�С��"<<endl;
    card.battle(card1);
    cout<<"��ʼ���˿������У�"<<endl;
    rcards cards;
	cards.display_all();
	cout<<"��ʼϴ�ƣ�"<<endl;
	cards.shufflePoker();
	cards.display_all();
	cout<<"ϴ�ƽ���"<<endl;
    cout<<"��ʼϴ�ƣ�"<<endl;
	cards.shufflePoker();
	cards.display_all();
	cout<<"ϴ�ƽ���"<<endl;
    return 0;
}



