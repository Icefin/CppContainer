//OOP Project Step #3 & #4
//Required Function
//���� ���縦 ��Ģ���� ���� �����ڸ� �߰��Ѵ�.
//const������ �߰��Ͽ� �ڵ��� �������� ���δ�.
//Assumptions

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void PrintInfo() {
	cout << "-----Menu-----" << '\n';
	cout << "1. ���°���" << '\n';
	cout << "2. ��  ��" << '\n';
	cout << "3. ��  ��" << '\n';
	cout << "4. �������� ��ü ���" << '\n';
	cout << "5. ���α׷� ����" << '\n';
	cout << "���� : ";
}

void MakeAccount();
void Deposit();
void Withdraw();
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
	Account(Account& acc)
		:accID(acc.accID), balance(acc.balance)
	{
		this->name = new char[strlen(acc.name) + 1];
		strcpy(this->name, acc.name);
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
			Deposit();
			break;
		case 3:
			Withdraw();
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

void ShowAllAccount()
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