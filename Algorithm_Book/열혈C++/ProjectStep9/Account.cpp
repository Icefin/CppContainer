#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int accID, const String name, int balance)
	:accID(accID), name(name), balance(balance)
{

}
Account::Account(const Account& acc)
	:accID(acc.accID), name(acc.name), balance(acc.balance)
{

}
Account::~Account()
{

}

Account& Account::operator=(const Account& acc)
{
	accID = acc.accID;
	balance = acc.balance;
	name = acc.name;
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
String Account::getName() const
{
	return name;
}
int Account::getBalance() const
{
	return balance;
}