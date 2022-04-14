#include <iostream>
#include <algorithm>
#include <string>

#define MUL_HOUR_CASE 3600		//시에 3이 들어 있는 경우 : 60 * 60 = 3600
#define MUL_MIN_CASE  900		//분에 3이 들어 있는 경우 : 15 * 60 = 900
#define MUL_SEC_CASE  675		//초에 3이 들어 있는 경우 : 45 * 15 = 675

using namespace std;

int N;

int main()
{
	cin >> N;

	int ret = 0;

	//시에 3이 들어있는 경우의 수 0
	if (N < 3)
	{
		ret = (N + 1) * (MUL_MIN_CASE + MUL_SEC_CASE);
	}
	//시에 3이 들어있는 경우의 수 1 (3)
	else if (N < 13)
	{
		ret = N * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE;
	}
	//시에 3이 들어있는 경우의 수 2 (3, 13)
	else if (N < 23)
	{
		ret = (N - 1) * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE * 2;
	}
	//시에 3이 들어있는 경우의 수 3 (3, 13, 23)
	else
	{
		ret = (N - 2) * (MUL_MIN_CASE + MUL_SEC_CASE) + MUL_HOUR_CASE * 3;
	}
	cout << ret;
}

//if 3, 13, 23h : 3600
//else if xh 3 13 23 30~39 43 53m : 60
//else xh xm : 3 13 23 30~39 43 53s