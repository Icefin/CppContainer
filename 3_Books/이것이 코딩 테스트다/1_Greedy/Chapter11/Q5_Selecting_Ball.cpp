#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> mass;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		mass.push_back(x);
	}

	int cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (mass[i] != mass[j])
				cnt++;
		}
	}

	cout << cnt;
}

/*
int n, m;
// 1부터 10까지의 무게를 담을 수 있는 배열
int arr[11];

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}

	int result = 0;

	// 1부터 m까지의 각 무게에 대하여 처리
	for (int i = 1; i <= m; i++) {
		n -= arr[i]; // 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수) 제외
		result += arr[i] * n; // B가 선택하는 경우의 수와 곱해주기
	}

	cout << result << '\n';
}
*/