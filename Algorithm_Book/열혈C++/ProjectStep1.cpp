//OOP Project Step #1
//Required Function
//1. ���°��� 2. �Ա� 3. ��� 4. ��ü�� �ܾ���ȸ
//Assumptions
//1. ������ ���¹�ȣ�� �ߺ����� �ƴ��Ѵ�.
//2. �Ա� �� ��ݾ��� ������ 0���� ũ��.
//3. ���� ���������� ���¹�ȣ, ���̸�, ���� �ܾ� �� ������ ���� �� �����Ѵ�.
//4. �� �̻��� �� ���� ������ ���ؼ� �迭�� ����Ѵ�.
//5. ���¹�ȣ�� ������ �����̴�.

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

struct Account {
	int ID = 0;
	string name = "";
	int balance = 0;
} account[100];

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
	string name;
	cout << "�� �� : "; cin >> name;
	int balance;
	cout << "�Աݾ� : "; cin >> balance;

	account[accCnt++] = { accID, name, balance };
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
		if (account[i].ID == accID)
		{
			account[i].balance += amount;
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
		if (account[i].ID == accID)
		{
			if (account[i].balance < amount)
			{
				cout << "�ܾ��� �����մϴ�." << '\n' << '\n';
				return;
			}
			account[i].balance -= amount;
			cout << "��ݿϷ�" << '\n' << '\n';
			break;
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
		cout << "���� ID : " << account[i].ID << '\n';
		cout << "�� �� : " << account[i].name << '\n';
		cout << "�� �� : " << account[i].balance << '\n' << '\n';
	}
}