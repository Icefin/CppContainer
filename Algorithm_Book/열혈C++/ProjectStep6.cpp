//OOP Project Step #6
//Required Function
//AccountŬ������ ����ϴ� Ŭ������ �߰��� �����Ѵ�.
//Assumptions
//1. NormalAccount : �ּ����� ���ڸ� �����ϴ� ���� ����ݽ� ����
//->��ü�� ������������ ���������� ����� �� �־�� �Ѵ�.

//2. HighCreditAccount : �ſ뵵�� ���� �����Ը� ������ ����ϴ� ���� ������ ����
//->NormalAccount�� ���� ��ü ������������ �⺻ ������ ����� �� �ִ�.
//->���� �ſ����� A, B, C�� ������ ���°��� �� �� ������ ����Ѵ�.
//->A, B, C ��޺��� ���� �⺻������ 7%, 4%, 2%�� ������ �߰��� �����Ѵ�.

//3. ��� ���¿� ���� ������ ������ �����Ѵ�.
//->���°��� �������� �ʱ� �ԱݵǴ� �ݾ׿� ���ؼ��� ���ڸ� ������� �ʴ´�.
//->���°��� �� ������ �Աݰ����� ��ĥ ������ ���ڰ� �߻��ϴ� ������ �����Ѵ�.
//->������ ���������� �߻��ϴ� �Ҽ��� ������ �ݾ��� �����Ѵ�.

//4. Control Class���� ū ��ȭ�� ����� �Ѵ�.

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
		cout << "[������������]" << '\n';
		cout << "1. ���뿹�ݰ���    2. �ſ�ŷڰ���" << '\n';
		cout << "���� : "; cin >> choice;

		int accID, balance, rate; char name[MAX_NAME_LEN];
		switch (choice) {
		case NORMAL_ACCOUNT:
			cout << "[���뿹�ݰ��� ����]" << '\n';
			cout << "����ID : "; cin >> accID;
			cout << "�� �� : "; cin >> name;
			cout << "�Աݾ� : "; cin >> balance;
			cout << "������ : "; cin >> rate;
			account[accCnt++] = new NormalAccount(accID, name, balance, rate);
			break;
		case HIGH_CREDIT_ACCOUNT:
			cout << "[�ſ�ŷڰ��� ����]" << '\n';
			cout << "����ID : "; cin >> accID;
			cout << "�� �� : "; cin >> name;
			cout << "�Աݾ� : "; cin >> balance;
			cout << "������ : "; cin >> rate;
			int credit;
			cout << "�ſ���(1toA, 2toB, 3toC) : "; cin >> credit;
			account[accCnt++] = new HighCreditAccount(accID, name, balance, rate, credit);
			break;
		}

		cout << "���°��� �Ϸ�" << '\n' << '\n';
	}
	void Deposit()
	{
		cout << "[��   ��]" << '\n';
		int accID;
		cout << "���� ID : "; cin >> accID;
		int amount;
		cout << "�Աݾ� : "; cin >> amount;

		for (int i = 0; i < accCnt; i++)
		{
			if (account[i]->getID() == accID)
			{
				account[i]->Deposit(amount);
				cout << "�ԱݿϷ�" << '\n' << '\n';
				return;
			}
		}

		cout << "�߸��� ID �Դϴ�." << '\n' << '\n';
	}
	void Withdraw()
	{
		cout << "[��   ��]" << '\n';
		int accID;
		cout << "���� ID : "; cin >> accID;
		int amount;
		cout << "��ݾ� : "; cin >> amount;

		for (int i = 0; i < accCnt; i++)
		{
			if (account[i]->getID() == accID)
			{
				if (account[i]->getBalance() < amount)
				{
					cout << "�ܾ��� �����մϴ�." << '\n' << '\n';
					return;
				}
				account[i]->Withdraw(amount);
				cout << "��ݿϷ�" << '\n' << '\n';
				return;
			}
		}

		cout << "�߸��� ID �Դϴ�." << '\n' << '\n';
	}
	void ShowAllAccount() const
	{
		cout << "[�������� ��ü ���]" << '\n';
		if (accCnt == 0)
		{
			cout << "������ ���������� �����ϴ�." << '\n' << '\n';
			return;
		}

		for (int i = 0; i < accCnt; i++)
		{
			cout << "���� ID : " << account[i]->getID() << '\n';
			cout << "�� �� : " << account[i]->getName() << '\n';
			cout << "�� �� : " << account[i]->getBalance() << '\n' << '\n';
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
		cout << "1. ���°���" << '\n';
		cout << "2. ��  ��" << '\n';
		cout << "3. ��  ��" << '\n';
		cout << "4. �������� ��ü ���" << '\n';
		cout << "5. ���α׷� ����" << '\n';
		cout << "���� : ";
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