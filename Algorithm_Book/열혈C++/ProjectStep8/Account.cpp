#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accID, const char* name, int balance)
	:accID(accID), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
Account::Account(const Account& acc)
	:accID(acc.accID), balance(acc.balance)
{
	this->name = new char[strlen(acc.name) + 1];
	strcpy(this->name, acc.name);
}
Account::~Account()
{
	delete[]name;
}

Account& Account::operator=(const Account& acc)
{
	accID = acc.accID;
	balance = acc.balance;

	delete[]name;
	name = new char[strlen(acc.name) + 1];
	strcpy(name, acc.name);
	return *this;
}
void Account::Deposit(int amount)
{
	balance += amount;
}
void Account::Withdraw(int amount)
{
	balance -= amount;
}
int Account::getID() const
{
	return accID;
}
char* Account::getName() const
{
	return name;
}
int Account::getBalance() const
{
	return balance;
}