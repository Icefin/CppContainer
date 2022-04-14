//136ms
//N + @ = ((((K')*2 + ?)*2 + ?)*2 + ?...
#include <iostream>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;

	int extra = 0;
	while (true) {
		int curr = N + extra;

		int accum = 1;
		while (curr > 1) {
			if (curr % 2 == 0) {
				curr /= 2;
			}
			else {
				curr /= 2;
				accum++;
			}
		}

		if (accum <= K) break;
		extra++;
	}
	cout << extra;
}