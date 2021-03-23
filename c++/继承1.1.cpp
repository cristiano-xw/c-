#include<bits/stdc++.h>
#include"tabtenn0.h"
using namespace std;
int main()
{
	tabletennisplayer player1("chuck","blizzard",true);
	tabletennisplayer player2("tara","boomdea",false);
	player1.name();
	if(player1.Hastable())
	{
		cout<<":has a table.\n";
	}
	else 
		cout<<": hasn't a table\n";
	
	player2.name();
	if(player2.Hastable())
	{
		cout<<":has a table.\n";
	}
	else
	{
		cout<<": hasn't a table\n";
	}
	return 0;
}

