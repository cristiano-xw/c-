#ifndef TABTENN0_H
#define	TABATEN0_H
#include<string> 
#include<iostream> 
using namespace std;

class tabletennisplayer
{
	private:
		string firstname;
		string lastname;
		bool hastable;
	public:
		tabletennisplayer(const string &fn="none", const string &ln="none", bool ht=false);
		void name() const;
		bool Hastable () const {return hastable;};
		void resettable (bool v) {hastable=v;};
};

tabletennisplayer::tabletennisplayer(const string &fn,const string &ln,bool ht):firstname(fn),lastname(ln),hastable(ht){}

void tabletennisplayer::name() const {
	cout<<lastname<<" "<<firstname;
}
#endif

