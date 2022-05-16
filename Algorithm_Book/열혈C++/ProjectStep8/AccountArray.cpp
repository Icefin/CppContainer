#include "AccountArray.h"

AccountArray::AccountArray(int size)
	: arrCnt(size)
{
	account = new ACCOUNT_PTR[size];
}
AccountArray::~AccountArray()
{
	delete[] account;
}
ACCOUNT_PTR& AccountArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrCnt)
	{
		cout << "Array index out of bound exception!" << '\n';
		exit(1);
	}
	return account[idx];
}
ACCOUNT_PTR AccountArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrCnt)
	{
		cout << "Array index out of bound exception!" << '\n';
		exit(1);
	}
	return account[idx];
}
int AccountArray::GetArrCnt() const
{
	return arrCnt;
}