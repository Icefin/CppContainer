#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int T, N;
int graph[125][125], d[125][125];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	cin >> T;
	vector<int> ret;
	//테스트 케이스 횟수만큼 반복
	for (int cnt = 0; cnt < T; cnt++)
	{
		cin >> N;
		//맵 정보 입력
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> graph[i][j];
		//최단 거리를 모두 무한으로 초기화
		for (int i = 0; i < N; i++)
			fill(d[i], d[i] + 125, INF);
		//시작 위치 지정
		int x = 0, y = 0;
		//다익스트라 알고리즘을 사용하기 위해 우선순위 큐 사용
		//(-거리, {위치값 x, y})
		priority_queue < pair<int, pair<int, int>>> pq;
		pq.push({ -graph[x][y], {0, 0} });
		d[x][y] = graph[x][y];

		while (!pq.empty())
		{
			int dist = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			//처리된 적이 있는 지점이라면 무시
			if (d[x][y] < dist) continue;
			//인접한 노드들을 확인
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				//맵의 범위를 벗어나는 경우 무시
				if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				int cost = dist + graph[nx][ny];
				if (cost < d[nx][ny])
				{
					d[nx][ny] = cost;
					pq.push({ -cost, {nx, ny} });
				}
			}
		}

		ret.push_back(d[N - 1][N - 1]);
	}

	//결과 출력
	for (int i = 0; i < T; i++)
	{
		cout << ret[i] << '\n';
	}
}