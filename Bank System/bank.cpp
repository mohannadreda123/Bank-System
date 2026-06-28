#include<iostream>
using namespace std;
class Bank
{
protected:
	string password;
	double balance = 0;
public:
	Bank(double balance, string pass)
	{
		if (balance >= 0)
		{
			this->balance += balance;
		}
		else
		{
			this->balance = 0;
		}
		if (pass.size() >= 8)
		{
			password = pass;
		}
	}
	bool checkpass(string pass)
	{
		if (password == pass)
		{
			return true;
		}
		return false;
	}
	double getbalance()
	{
		return balance;
	}
	bool Withdrawal(double cash)
	{
		if (cash <= balance)
		{
			balance -= cash;
			return true;
		}
		return false;
	}
	bool Deposit(double deposit)
	{
		if (deposit > 0)
		{
			balance += deposit;
			return true;
		}
		return false;
	}
};