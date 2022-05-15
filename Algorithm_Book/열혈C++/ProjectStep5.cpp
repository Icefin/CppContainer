//OOP Project Step #5
//Required Function
//Control class�� ����
//Assumptions
//1. ���α׷� ��ü�� ����� ����Ѵ�. ���� ��ɼ� ������ ���� Ŭ�����̴�.
//2. ��Ʈ�� Ŭ������ ���� ���α׷��� ��ü ��ɰ� �帧�� �ľ��� �� �ִ�.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

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
	~Account()
	{
		delete[]name;
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
};

class AccountHandler {
private:
	Account* account[100];
	int accCnt = 0;

private:
	void MakeAccount()
	{
		cout << "[���°���]" << '\n';
		int accID;
		cout << "����ID : "; cin >> accID;
		char name[10];
		cout << "�� �� : "; cin >> name;
		int balance;
		cout << "�Աݾ� : "; cin >> balance;

		account[accCnt++] = new Account(accID, name, balance);
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
		case 1:
			MakeAccount();
			return true;
			break;
		case 2:
			Deposit();
			return true;
			break;
		case 3:
			Withdraw();
			return true;
			break;
		case 4:
			ShowAllAccount();
			return true;
			break;
		case 5:
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