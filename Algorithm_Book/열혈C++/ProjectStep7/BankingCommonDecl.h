#pragma once
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NAME_LEN = 10;
const int MAX_ACCOUNT_NUM = 100;

enum { MAKE = 1, DEPOSIT, WITHDRAW, SHOWALL, EXIT };
enum { CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 2 };
enum { NORMAL_ACCOUNT = 1, HIGH_CREDIT_ACCOUNT };