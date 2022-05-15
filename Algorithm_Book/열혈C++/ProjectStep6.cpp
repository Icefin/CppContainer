//OOP Project Step #6
//Required Function
//Account클래스를 상속하는 클래스를 추가로 정의한다.
//Assumptions
//1. NormalAccount : 최소한의 이자를 지급하는 자율 입출금식 계좌
//->객체의 생성과정에서 이율정보를 등록할 수 있어야 한다.

//2. HighCreditAccount : 신용도가 높은 고객에게만 개설을 허용하는 높은 이율의 계좌
//->NormalAccount와 같이 객체 생성과정에서 기본 이율을 등록할 수 있다.
//->고객의 신용등급을 A, B, C로 나누고 계좌개설 시 이 정보를 등록한다.
//->A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.

//3. 모든 계좌에 대해 다음의 조건을 적용한다.
//->계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자를 계산하지 않는다.
//->계좌개설 후 별도로 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주한다.
//->이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다.

//4. Control Class에는 큰 변화가 없어야 한다.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int MAX_NAME_LEN = 10;
const int MAX_ACCOUNT_NUM = 100;

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };
enum { CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 2 };
enum { NORMAL_ACCOUNT = 1, HIGH_CREDIT_ACCOUNT };

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
	Account(Account& acc)
		:accID(acc.accID), balance(acc.balance)
	{
		this->name = new char[strlen(acc.name) + 1];
		strcpy(this->name, acc.name);
	}
	virtual ~Account()
	{
		delete[]name;
	}
	virtual void Deposit(int amount)
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
};

class NormalAccount : public Account {
private:
	int default_rate;
public:
	NormalAccount(int accID, const char* name, int balance, int rate)
		: Account(accID, name, balance), default_rate(rate)
	{}
	virtual void Deposit(int amount) override
	{
		int tot_amount = amount * (1 + (default_rate / 100.0));
		Account::Deposit(tot_amount);
	}
};

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

class AccountHandler {
private:
	Account* account[MAX_ACCOUNT_NUM];
	int accCnt = 0;

private:
	void MakeAccount()
	{
		int choice;
		cout << "[계좌종류선택]" << '\n';
		cout << "1. 보통예금계좌    2. 신용신뢰계좌" << '\n';
		cout << "선택 : "; cin >> choice;

		int accID, balance, rate; char name[MAX_NAME_LEN];
		switch (choice) {
		case NORMAL_ACCOUNT:
			cout << "[보통예금계좌 개설]" << '\n';
			cout << "계좌ID : "; cin >> accID;
			cout << "이 름 : "; cin >> name;
			cout << "입금액 : "; cin >> balance;
			cout << "이자율 : "; cin >> rate;
			account[accCnt++] = new NormalAccount(accID, name, balance, rate);
			break;
		case HIGH_CREDIT_ACCOUNT:
			cout << "[신용신뢰계좌 개설]" << '\n';
			cout << "계좌ID : "; cin >> accID;
			cout << "이 름 : "; cin >> name;
			cout << "입금액 : "; cin >> balance;
			cout << "이자율 : "; cin >> rate;
			int credit;
			cout << "신용등급(1toA, 2toB, 3toC) : "; cin >> credit;
			account[accCnt++] = new HighCreditAccount(accID, name, balance, rate, credit);
			break;
		}

		cout << "계좌개설 완료" << '\n' << '\n';
	}
	void Deposit()
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
	void Withdraw()
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
	void ShowAllAccount() const
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
public:
	AccountHandler() {}
	~AccountHandler()
	{
		for (int i = 0; i < accCnt; i++)
			delete account[i];
	}
	void PrintInfo() const
	{
		cout << "-----Menu-----" << '\n';
		cout << "1. 계좌개설" << '\n';
		cout << "2. 입  금" << '\n';
		cout << "3. 출  금" << '\n';
		cout << "4. 계좌정보 전체 출력" << '\n';
		cout << "5. 프로그램 종료" << '\n';
		cout << "선택 : ";
	}
	bool Process(int cmd)
	{
		switch (cmd) {
		case MAKE:
			MakeAccount();
			return true;
			break;
		case DEPOSIT:
			Deposit();
			return true;
			break;
		case WITHDRAW:
			Withdraw();
			return true;
			break;
		case SHOWALL:
			ShowAllAccount();
			return true;
			break;
		case EXIT:
			return false;
			break;
		}
	}
};


int main()
{
	bool run = true;
	int command;
	AccountHandler accHandler;

	while (run)
	{
		accHandler.PrintInfo();
		cin >> command; cout << '\n';
		run = accHandler.Process(command);
	}
}