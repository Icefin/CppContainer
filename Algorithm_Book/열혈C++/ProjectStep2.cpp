//OOP Project Step #2
//Required Function
//Account struct -> Account class
//Assumptions
//Account class는 멤버변수로 char형 포인터를 가지고 있다.
//객체 포인터 배열로 객체를 저장한다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void PrintInfo() {
	cout << "-----Menu-----" << '\n';
	cout << "1. 계좌개설" << '\n';
	cout << "2. 입  금" << '\n';
	cout << "3. 출  금" << '\n';
	cout << "4. 계좌정보 전체 출력" << '\n';
	cout << "5. 프로그램 종료" << '\n';
	cout << "선택 : ";
}

void MakeAccount();
void AccDeposit();
void AccWithdraw();
void ShowAllAccount();

class Account {
private:
	int accID;
	char* name;
	int balance;
public:
	Account(int accID, const char* name, int balance)
		:accID(accID), balance(balance)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void Deposit(int amount)
	{
		balance += amount;
	}
	void Withdraw(int amount)
	{
		balance -= amount;
	}
	int getID() const
	{
		return accID;
	}
	char* getName() const
	{
		return name;
	}
	int getBalance() const
	{
		return balance;
	}
	~Account()
	{
		delete[]name;
	}

};

Account* account[100];
int accNum = 0;

int accCnt = 0;

int main()
{
	int command;
	while (true)
	{
		PrintInfo();
		cin >> command; cout << '\n';

		switch (command) {
		case 1:
			MakeAccount();
			break;
		case 2:
			AccDeposit();
			break;
		case 3:
			AccWithdraw();
			break;
		case 4:
			ShowAllAccount();
			break;
		case 5:
			return 0;
			break;
		}
	}
}

void MakeAccount()
{
	cout << "[계좌개설]" << '\n';
	int accID;
	cout << "계좌ID : "; cin >> accID;
	char name[10];
	cout << "이 름 : "; cin >> name;
	int balance;
	cout << "입금액 : "; cin >> balance;

	account[accCnt++] = new Account(accID, name, balance);
	cout << "계좌개설 완료" << '\n' << '\n';
}

void AccDeposit()
{
	cout << "[입   금]" << '\n';
	int accID;
	cout << "계좌 ID : "; cin >> accID;
	int amount;
	cout << "입금액 : "; cin >> amount;

	for (int i = 0; i < accCnt; i++)
	{
		if (account[i]->getID() == accID)
		{
			account[i]->Deposit(amount);
			cout << "입금완료" << '\n' << '\n';
			return;
		}
	}

	cout << "잘못된 ID 입니다." << '\n' << '\n';
}

void AccWithdraw()
{
	cout << "[출   금]" << '\n';
	int accID;
	cout << "계좌 ID : "; cin >> accID;
	int amount;
	cout << "출금액 : "; cin >> amount;

	for (int i = 0; i < accCnt; i++)
	{
		if (account[i]->getID() == accID)
		{
			if (account[i]->getBalance() < amount)
			{
				cout << "잔액이 부족합니다." << '\n' << '\n';
				return;
			}
			account[i]->Withdraw(amount);
			cout << "출금완료" << '\n' << '\n';
			return;
		}
	}

	cout << "잘못된 ID 입니다." << '\n' << '\n';
}

void ShowAllAccount()
{
	cout << "[계좌정보 전체 출력]" << '\n';
	if (accCnt == 0)
	{
		cout << "생성된 계좌정보가 없습니다." << '\n' << '\n';
		return;
	}

	for (int i = 0; i < accCnt; i++)
	{
		cout << "계좌 ID : " << account[i]->getID() << '\n';
		cout << "이 름 : " << account[i]->getName() << '\n';
		cout << "잔 액 : " << account[i]->getBalance() << '\n' << '\n';
	}
}