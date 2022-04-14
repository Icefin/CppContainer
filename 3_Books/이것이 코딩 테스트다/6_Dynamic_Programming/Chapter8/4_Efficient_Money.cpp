#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> coins;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		coins.push_back(temp);
	}

	vector<int> dp(M + 1, 10001);

	dp[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = coins[i]; j <= M; j++)
		{
			if (dp[j - coins[i]] != 10001)
				dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[M] == 10001) cout << -1;
	else cout << dp[M];
}