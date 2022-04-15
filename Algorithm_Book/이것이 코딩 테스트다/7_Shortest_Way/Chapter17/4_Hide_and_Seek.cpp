#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
int d[20001];
vector<int> graph[20001];

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		//양방향 그래프 연결
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//최단거리 테이블 초기화
	for (int i = 0; i <= N; i++)
		d[i] = INF;
	//다익스트라 알고리즘을 사용하기 위한 준비
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });		//dist, number
	d[1] = 0;				//시작지점의 거리는 0
	//다익스트라 알고리즘 수행
	while (!pq.empty())
	{
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (d[now] < dist) continue;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int cost = dist + 1;
			if (cost < d[graph[now][i]])
			{
				d[graph[now][i]] = cost;
				pq.push({ -cost, graph[now][i] });
			}
		}
	}

	//다익스트라 알고리즘을 통해 구해진 거리를 이용하여
	//숨을 헛간 번호, 최대 거리, 같은 거리의 헛간 개수 계산
	int maxNode = 0;
	int maxDist = 0;
	vector<int> result;

	for (int i = 1; i <= N; i++)
	{
		if (maxDist < d[i])
		{
			maxNode = i;
			maxDist = d[i];
			result.clear();
			result.push_back(maxNode);
		}

		else if (maxDist == d[i])
			result.push_back(i);
	}

	cout << maxNode << ' ' << maxDist << ' ' << result.size();
}