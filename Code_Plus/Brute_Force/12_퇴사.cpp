// #1. Επ»η

#include <iostream>

using namespace std;

int ans = 0, n = 0;
int t[15];
int p[15];

void dfs(int day, int sum) {
	if (day == n) {
		ans = max(ans, sum);
		return;
	}
	if (day > n) return;

	dfs(day + 1, sum);
	dfs(day + t[day], sum + p[day]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int day, pay;
		cin >> day >> pay;
		t[i] = day; p[i] = pay;
	}

	dfs(0, 0);

	cout << ans;
}