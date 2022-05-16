#include "AccountHandler.h"
#include "BankingCommonDecl.h"

void AccountHandler::MakeAccount()
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
void AccountHandler::Deposit()
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
void AccountHandler::Withdraw()
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
void AccountHandler::ShowAllAccount() const
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
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accCnt; i++)
		delete account[i];
}
void AccountHandler::PrintInfo() const
{
	cout << "-----Menu-----" << '\n';
	cout << "1. ���°���" << '\n';
	cout << "2. ��  ��" << '\n';
	cout << "3. ��  ��" << '\n';
	cout << "4. �������� ��ü ���" << '\n';
	cout << "5. ���α׷� ����" << '\n';
	cout << "���� : ";
}
bool AccountHandler::Process(int cmd)
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