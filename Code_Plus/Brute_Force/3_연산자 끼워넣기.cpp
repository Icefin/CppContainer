// #3. 연산자 끼워넣기
//dfs...
//재귀를 사용하기 전에 기저조건과 global변수를 잘 설정하자

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int operands[11];
int operators[4];
int _max = -100000001;
int _min = 100000001;
int _N;

void dfs(int ret, int idx) {
	if (idx == _N) {
		if (ret > _max) {
			_max = ret;
		}
		if (ret < _min) {
			_min = ret;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			if (i == 0) {
				dfs(ret + operands[idx], idx + 1);
			}
			else if (i == 1) {
				dfs(ret - operands[idx], idx + 1);
			}
			else if (i == 2) {
				dfs(ret * operands[idx], idx + 1);
			}
			else if (i == 3) {
				dfs(ret / operands[idx], idx + 1);
			}
			operators[i]++;
		}
	}
	return;
}

int main() {
	cin >> _N;
	for (int i = 0; i < _N; i++) {
		cin >> operands[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}
	dfs(operands[0], 1);
	cout << _max << '\n' << _min;
}