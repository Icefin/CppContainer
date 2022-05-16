#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "AccountArray.h"

class AccountHandler {
private:
	AccountArray account;
	int accCnt;
private:
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccount() const;
public:
	~AccountHandler();
	void PrintInfo() const;
	bool Process(int cmd);
};