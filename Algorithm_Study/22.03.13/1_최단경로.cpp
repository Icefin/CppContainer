//1. 단순 연결리스트를 활용한 구현
// 100ms

#include <iostream>
#include <queue>

#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[20001];
int dist[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E, start;
	cin >> V >> E;
	cin >> start;
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	for (int i = 1; i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int n_cost = graph[now][i].second;
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
}

//2. unordered_map을 활용한 구현
//216ms

#include <iostream>
#include <queue>
#include <unordered_map>

#define INF 1e9

using namespace std;

vector<int> graph[20001];
unordered_map<int, int> um_near[20001];
int dist[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int V, E, start;
	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) dist[i] = INF;

	for (int i = 1; i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (um_near[from][to] == 0) {
			graph[from].push_back(to);
			um_near[from][to] = cost;
			continue;
		}
		else if (um_near[from][to] > cost) {
			um_near[from][to] = cost;
		}
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			int n_cost = um_near[now][next];
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
}

//3. sorting을 통해 불필요한 간선 연산 제거
//320ms

#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

vector<vector<pair<int, short>>> graph(20001);
int dist[20001];

bool comp(pair<int, short> a, pair<int, short> b) {
	return a.second < b.second;
}

int main() {
	int V, E, start;
	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) dist[i] = INF;

	for (int i = 1; i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
	}

	for (int i = 1; i <= V; i++) {
		sort(graph[i].begin(), graph[i].end(), comp);
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int n_cost = graph[now][i].second;
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
}

//4. 인접행렬을 사용한 풀이

#include <iostream>
#include <queue>

#define INF 1e9

using namespace std;

short graph[20001][20001];
vector<short> near[20001];
int dist[20001];

int main() {
	short V, E, start;
	cin >> V >> E;
	cin >> start;

	for (int i = 1; i <= V; i++) dist[i] = INF;

	for (int i = 1; i <= E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		if (graph[from][to] == 0) {
			graph[from][to] = cost;
			near[from].push_back(to);
			continue;
		}
		else if (graph[from][to] > cost)
			graph[from][to] = cost;
	}

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		for (int i = 0; i < near[now].size(); i++) {
			int next = near[now][i];
			int n_cost = graph[now][next];
			if (dist[next] > cost + n_cost) {
				dist[next] = cost + n_cost;
				pq.push({ -dist[next], next });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
}