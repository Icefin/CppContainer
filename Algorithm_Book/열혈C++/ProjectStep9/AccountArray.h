#pragma once
#include "BankingCommonDecl.h"
#include "Account.h"

typedef Account* ACCOUNT_PTR;

class AccountArray {
private :
	ACCOUNT_PTR* account;
	int arrCnt;

public:
	AccountArray(int size = MAX_ACCOUNT_NUM);
	~AccountArray();
	ACCOUNT_PTR& operator[] (int idx);
	ACCOUNT_PTR operator[] (int idx) const;
	int GetArrCnt() const;

};