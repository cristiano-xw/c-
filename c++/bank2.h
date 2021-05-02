#include<bits/stdc++.h>
using namespace std; 

class Account 
{
public:
	Account(double balance);
	void setBalance(double balance);
	double getBalance() const;
	virtual bool debit(double amount);
	virtual bool credit(double amount);

	virtual ~Account();
private:
	double balance;
};

Account::Account(double balance) 
{
	setBalance(balance);
}

Account::~Account() { }

void Account::setBalance(double balance) {
	if (balance >= 0)
		this->balance = balance;
	else {
		balance = 0;
		cout << "  非法的余额，设为0" << endl;
	}
}

double Account::getBalance() const {
	return balance;
}

bool Account::credit(double amount) {
	balance += amount;
	return true;
}

bool Account::debit(double amount) {
	if (balance < amount) {
		cout << "  Debit amount exceeded account balance" << endl;
		return false;
	} else {
		balance -= amount;
		return true;
	}
}


class CheckingAccount: public Account 
{
public:
	CheckingAccount(double balance, double transFee);
	bool credit(double amount);
	bool debit(double amount);
private:
	double transFee; // 每笔交易的费用
};

class SavingsAccount: public Account {
public:
	SavingsAccount(double balance, double interestRate);
	double calculateInterest();
private:
	double interestRate;
};

SavingsAccount::SavingsAccount(double balance, double interestRate) :
		Account(balance) {
	this->interestRate = interestRate;
}

double SavingsAccount::calculateInterest() {
	return getBalance() * interestRate / 100;
}



CheckingAccount::CheckingAccount(double balance, double transFee) : Account(balance) {
	this->transFee = transFee;
}

bool CheckingAccount::credit(double amount) {
	Account::credit(amount);
	if (getBalance() < transFee) {
		cout << "  Transaction fee exceeded account balance while crediting" << endl;
		Account::debit(amount);
		return false;
	} else
		return Account::debit(transFee);
}

bool CheckingAccount::debit(double amount) {
	if (Account::debit(amount)) {
		if (getBalance() < transFee) {
			cout << "  Transaction fee exceeded account balance while debiting" << endl;
			Account::credit(amount);
			return false;
		} else
			return Account::debit(transFee);
	}

	return false;
}












