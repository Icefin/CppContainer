//0ms

#include <iostream>

using namespace std;
//dp[i] : pw의 i번째 문자까지 해석 가능한 경우의수
//dp[i] = dp[i - 1] + (dp[i - 2])
int dp[5001];

int main() {
	string pw;
	cin >> pw;
	//pw의 0번째에 0이 들어오면 무조건 잘못된 pw이므로 0을 출력
	if (pw[0] == '0') {
		cout << 0;
		return 0;
	}
	
	//pw[0] != 0이면 일단 길이가 1인 pw는 1가지로 해석될 수 있으므로 dp[0] = 1
	dp[0] = 1;
	
	if (pw.length() >= 2) {
		if (pw[1] != '0') dp[1] = dp[0];
		int asci = (pw[0] - '0') * 10 + (pw[1] - '0');
		if (asci <= 26 && asci >= 10) dp[1]++;
	}

	for (int i = 2; i < pw.length(); i++) {
		if (pw[i] != '0') {
			dp[i] = dp[i - 1];
		}

		int asci = (pw[i - 1] - '0') * 10 + (pw[i] - '0');
		if (asci <= 26 && asci >= 10) {
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}

	cout << dp[pw.length() - 1];
}