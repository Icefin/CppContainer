// #2. 부분수열의 합

#include <iostream>
#include <vector>

using namespace std;

int _N, _S;
int answer;
vector<int> arr;

void dfs(int idx, int sum) {
	if (idx == _N && sum == _S) {
		answer++;
		return;
	}
	else if (idx == _N && sum != _S)
		return;

	dfs(idx + 1, sum);
	dfs(idx + 1, sum + arr[idx]);
}

int main() {
	cin >> _N >> _S;
	for (int i = 0; i < _N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	dfs(0, 0);

	if (_S == 0) answer--;

	cout << answer;
}