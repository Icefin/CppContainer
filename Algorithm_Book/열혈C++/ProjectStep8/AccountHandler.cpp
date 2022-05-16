#include "AccountHandler.h"
#include "BankingCommonDecl.h"

void AccountHandler::MakeAccount()
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
void AccountHandler::Deposit()
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
void AccountHandler::Withdraw()
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
void AccountHandler::ShowAllAccount() const
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
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accCnt; i++)
		delete account[i];
}
void AccountHandler::PrintInfo() const
{
	cout << "-----Menu-----" << '\n';
	cout << "1. 계좌개설" << '\n';
	cout << "2. 입  금" << '\n';
	cout << "3. 출  금" << '\n';
	cout << "4. 계좌정보 전체 출력" << '\n';
	cout << "5. 프로그램 종료" << '\n';
	cout << "선택 : ";
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