//OOP Project Step #1
//Required Function
//1. 계좌개설 2. 입금 3. 출금 4. 전체고객 잔액조회
//Assumptions
//1. 통장의 계좌번호는 중복되지 아니한다.
//2. 입금 및 출금액은 무조건 0보다 크다.
//3. 고객의 계좌정보는 계좌번호, 고객이름, 고객의 잔액 세 가지만 저장 및 관리한다.
//4. 둘 이상의 고객 정보 저장을 위해서 배열을 사용한다.
//5. 계좌번호는 정수의 형태이다.

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
	cout << "[계좌개설]" << '\n';
	int accID;
	cout << "계좌ID : "; cin >> accID;
	string name;
	cout << "이 름 : "; cin >> name;
	int balance;
	cout << "입금액 : "; cin >> balance;

	account[accCnt++] = { accID, name, balance };
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
		if (account[i].ID == accID)
		{
			account[i].balance += amount;
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
		if (account[i].ID == accID)
		{
			if (account[i].balance < amount)
			{
				cout << "잔액이 부족합니다." << '\n' << '\n';
				return;
			}
			account[i].balance -= amount;
			cout << "출금완료" << '\n' << '\n';
			break;
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
		cout << "계좌 ID : " << account[i].ID << '\n';
		cout << "이 름 : " << account[i].name << '\n';
		cout << "잔 액 : " << account[i].balance << '\n' << '\n';
	}
}