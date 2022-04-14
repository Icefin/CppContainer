#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Initialize();

int N;
vector<int> storage;
vector<int> dp;

int main()
{
	Initialize();

	for (int i = 2; i < N; i++)
	{
		dp[i] = max(dp[i - 1], dp[i - 2] + storage[i]);
	}

	cout << dp[N - 1];
}

void Initialize()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		storage.push_back(x);
		dp.push_back(0);
	}

	dp[0] = storage[0];
	dp[1] = max(storage[0], storage[1]);
}

/*
* i번째 창고까지 최대치 = max(i-1번째 창고까지 최대치, i-2번째 창고까지 최대치 + i번째 창고의 식량)
* i-1번째 창고까지 최대치 : i번째 창고는 약탈하지 않음.
* i-2번째 창고까지 최대치 : i-1번째 창고는 약탈하지 않고, i번째 창고는 약탈함.
* 
* i-1번째 창고까지 최대치에서, 만약 i-1번째 창고를 털지 않았다면 i번재 창고를 털어도 되지 않나?
* >> 그러한 경우는 i-2번째 창고까지의 최대치 경우에 포함된다.
*/