// #4. 스타트와링크

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, status[21][21];
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> status[i][j];
		}
	}

	vector<int> comb = {};
	for (int i = 0; i < N / 2; i++)
		comb.push_back(0);
	for (int i = 0; i < N / 2; i++)
		comb.push_back(1);

	int answer = 1e9;

	do {
		vector<int> start; int startScore = 0;
		vector<int> link; int linkScore = 0;
		for (int i = 0; i < comb.size(); i++) {
			if (comb[i] == 0) start.push_back(i + 1);
			else if (comb[i] == 1) link.push_back(i + 1);
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				startScore += status[start[i]][start[j]];
				linkScore += status[link[i]][link[j]];
			}
		}

		int curr = abs(startScore - linkScore);
		if (answer > curr) answer = curr;

	} while (next_permutation(comb.begin(), comb.end()));

	cout << answer;
}