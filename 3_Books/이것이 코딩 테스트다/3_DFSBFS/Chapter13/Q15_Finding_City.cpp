#include <iostream>
#include <queue>

using namespace std;
//사용할 변수 초기화
int N = 0, M = 0, K = 0, X = 0;
//거리 정보를 담을 배열
vector<int> graph[300001];
//최단 거리 정보를 담을 배열
//방문하지 않은 도시의 거리는 -1로 설정
vector<int> d(300001, -1);

int main()
{
	//N, M, K, X 입력
	cin >> N >> M >> K >> X;
	//모든 도로 정보 입력
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	//출발 지점의 거리는 0
	d[X] = 0;
	//출발 지점에서 각 도시까지의 거리를 점검하는 문제이므로 BFS를 사용
	queue<int> q;
	q.push(X);
	while (!q.empty())
	{
		//python의 popleft의 기능이 c++에는 없습니다 ㅜ
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];
			//d[] == -1이면 한번도 방문하지 않은 도시 이므로 거리 갱신
			if (d[next] == -1)
			{
				d[next] = d[now] + 1;
				q.push(next);
			}
		}
	}
	//최단 거리가 K인 도시 번호를 오름차순으로 출력
	bool isPossible = false;
	for (int i = 1; i <= N; i++)
	{
		if (d[i] == K)
		{
			cout << i << '/n';
			isPossible = true;
		}
	}
	//최단 거리가 K인 도시가 없을경우 -1 출력
	if (!isPossible) cout << -1;
}