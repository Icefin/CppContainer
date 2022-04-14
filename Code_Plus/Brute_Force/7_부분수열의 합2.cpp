// #3. 부분수열의 합2

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int _N, _S;
int answer;
vector<int> arr;
priority_queue<int, vector<int>, greater<int>> pq;

void dfs(int idx, int sum) {
	if (idx == _N) {
		pq.push(sum);
		return;
	}

	dfs(idx + 1, sum);
	dfs(idx + 1, sum + arr[idx]);
}

int main() {
	cin >> _N;
	for (int i = 0; i < _N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	dfs(0, 0);

	if (pq.top() > 1) cout << 1;

	int prev = pq.top();
	while (!pq.empty()) {
		if (pq.top() - prev > 1) {
			cout << prev + 1;
			return 0;
		}
		else {
			prev = pq.top();
			pq.pop();
		}
	}
	cout << prev + 1;
}