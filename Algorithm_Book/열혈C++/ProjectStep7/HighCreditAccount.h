#pragma once
#include "BankingCommonDecl.h"
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int credit_level;
public:
	HighCreditAccount(int accID, const char* name, int balance, int rate, int credit)
		: NormalAccount(accID, name, balance, rate)
	{
		switch (credit)
		{
		case 1:
			credit_level = CREDIT_A;
			break;
		case 2:
			credit_level = CREDIT_B;
			break;
		case 3:
			credit_level = CREDIT_C;
			break;
		default:
			credit_level = CREDIT_A;
			break;
		}
	}
	virtual void Deposit(int amount) override
	{
		NormalAccount::Deposit(amount);
		Account::Deposit(amount * (credit_level / 100.0));
	}
};