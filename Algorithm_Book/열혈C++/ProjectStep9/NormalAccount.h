#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

class NormalAccount : public Account {
private:
	int default_rate;
public:
	NormalAccount(int accID, String name, int balance, int rate)
		: Account(accID, name, balance), default_rate(rate)
	{}
	virtual void Deposit(int amount) override
	{
		int tot_amount = amount * (1 + (default_rate / 100.0));
		Account::Deposit(tot_amount);
	}
};