#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

class AccountHandler {
private:
	Account* account[MAX_ACCOUNT_NUM];
	int accCnt = 0;
private:
	void MakeAccount();
	void Deposit();
	void Withdraw();
	void ShowAllAccount() const;
public:
	AccountHandler();
	~AccountHandler();
	void PrintInfo() const;
	bool Process(int cmd);
};