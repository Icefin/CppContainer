#include <iostream>
#include <vector>

using namespace std;

int X;
vector<int> dp;

int main()
{
	cin >> X;

	for (int i = 0; i <= X; i++)
	{
		dp.push_back(30001);
	}

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i <= X; i++)
	{
		if (i % 5 == 0)
			dp[i] = min(dp[i], dp[i / 5] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[X];
}
