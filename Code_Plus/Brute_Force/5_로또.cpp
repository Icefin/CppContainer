// #1. ·Î¶Ç

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	while (true) {
		int k;
		vector<int> num;
		cin >> k;

		if (k == 0) break;

		vector<int> comb;
		for (int i = 0; i < 6; i++) comb.push_back(1);
		for (int i = 0; i < k - 6; i++) comb.push_back(0);

		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			num.push_back(temp);
		}

		do {
			for (int i = 0; i < k; i++) {
				if (comb[i] == 1) {
					cout << num[i] << ' ';
				}
			}
			cout << '\n';
		} while (prev_permutation(comb.begin(), comb.end()));
		cout << '\n';
	}
}