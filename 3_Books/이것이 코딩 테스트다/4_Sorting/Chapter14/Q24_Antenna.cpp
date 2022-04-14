#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> house;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		house.push_back(x);
	}

	sort(house.begin(), house.end());

	cout << house[(N - 1) / 2];
}
