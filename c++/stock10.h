#include<string>
using namespace std;

class stock
{
	private:
		string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() {total_val=shares*share_val;}
	public:
		stock();//Ĭ�� 
		stock(const string &co,long n=0,double pr=0.0);//���캯��
		~stock();
		void buy(long sum,double price);
		void sell(long sum,double price);
		void update(double price);
		void show(); 
};
