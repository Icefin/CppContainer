#include <iostream>
#define INF 1e9		//무한대의 거리

using namespace std;

int N, M;
int graph[501][501];

int main()
{
	cin >> N >> M;

	//최단 거리를 모두 무한으로 초기화
	for (int i = 0; i < 501; i++)
	{
		fill(graph[i], graph[i] + 501, INF);
	}
	//자기자신으로 가는 경로는 0으로 초기화
	for (int i = 1; i <= N; i++)
	{
		graph[i][i] = 0;
	}
	//입력에 따라 경로를 추가
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	//플로이드 워셜 알고리즘을 수행하여 최단경로 갱신
	for (int k = 1; k <= N; k++)
	{
		for (int a = 1; a <= N; a++)
		{
			for (int b = 1; b <= N; b++)
			{
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	int ret = 0;
	//각 학생별로 한 명씩 도달 가능한지 체크
	for (int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= N; j++)
		{
			if (graph[i][j] != INF || graph[j][i] != INF)
			{
				cnt += 1;
			}
		}
		//모든 학생에게 도달 가능하면 정확한 순위를 산출 가능함
		if (cnt == N) ret += 1;
	}

	cout << ret;
}