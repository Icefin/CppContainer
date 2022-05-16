#pragma once
class Account {
private:
	int accID;
	String name;
	int balance;
public:
	Account(int accID, const String name, int balance);
	Account(const Account& acc);
	virtual ~Account();

	Account& operator=(const Account& acc);
	virtual void Deposit(int amount);
	void Withdraw(int amount);
	int getID() const;
	String getName() const;
	int getBalance() const;
};