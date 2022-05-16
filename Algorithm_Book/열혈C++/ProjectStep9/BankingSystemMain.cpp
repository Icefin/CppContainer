#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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