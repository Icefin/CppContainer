// #1. 부등호
//작은수, 큰 수 부터 사용
//next_permutation, prev_permutation을 사용하여 순열조합을 이용

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int> arr, vector<char> sign) {
	for (int i = 0; i < sign.size(); i++) {
		if (sign[i] == '<' && arr[i] > arr[i + 1])
			return false;
		if (sign[i] == '>' && arr[i] < arr[i + 1])
			return false;
	}
	return true;
}

int main() {
	int k;
	cin >> k;
	vector<char> sign;
	for (int i = 0; i < k; i++) {
		char temp;
		cin >> temp;
		sign.push_back(temp);
	}

	vector<int> _max;
	vector<int> _min;
	for (int i = 0; i <= k; i++) {
		_max.push_back(9 - i);
		_min.push_back(i);
	}

	do {
		if (check(_max, sign)) break;
	} while (prev_permutation(_max.begin(), _max.end()));

	do {
		if (check(_min, sign)) break;
	} while (next_permutation(_min.begin(), _min.end()));

	for (int i = 0; i < _max.size(); i++) {
		cout << _max[i];
	}
	cout << '\n';
	for (int i = 0; i < _min.size(); i++) {
		cout << _min[i];
	}
}