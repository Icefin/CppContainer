#pragma once
class Account {
private:
	int accID;
	char* name;
	int balance;
public:
	Account(int accID, const char* name, int balance);
	Account(const Account& acc);
	virtual ~Account();

	Account& operator=(const Account& acc);
	virtual void Deposit(int amount);
	void Withdraw(int amount);
	int getID() const;
	char* getName() const;
	int getBalance() const;
};