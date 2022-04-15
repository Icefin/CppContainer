//trap이 발동된 상태로 다른 노드를 검사하여 문제 발생
//=>현재 노드까지 지나온 모든 trap을 저장, 발동 -> 노드 확인이 끝난 후 trap을 다시 발동
//같은 trap은 두 번 까지만 밟는다.
//=>visited배열로 방문 횟수 저장
//이래도 통과 못함... -> trap뿐 아니라 일반 노드까지 두 번 방문할 수 있음;; main의 반례...

//정확성 94.9 / 100

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<int> trap_info;
int d[1001];
int visited[1001];
int _size;
int graph[1001][1001];
//trap발동 함수
void activate_trap(int num) {
    for (int i = 1; i <= _size; i++) {
        swap(graph[num][i], graph[i][num]);
    }
}
//priority_queue를 활용한 dijkstra
void dijkstra(int start) {
    priority_queue<pair<int, pair<int, vector<int>>>> pq;
    pq.push({ 0, {start, {}} });
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second.first;
        vector<int> trapped = pq.top().second.second;
        bool isTrap = find(trap_info.begin(), trap_info.end(), now) != trap_info.end();
        pq.pop();

        if (d[now] < dist && !isTrap) continue;

        if (isTrap) trapped.push_back(now);
        for (int i = 0; i < trapped.size(); i++) {
            activate_trap(trapped[i]);
        }

        for (int i = 1; i <= _size; i++) {
            if (graph[now][i] == INF) continue;
            bool isNext_Trap = find(trap_info.begin(), trap_info.end(), i) != trap_info.end();
            int cost = dist + graph[now][i];
            if (cost < d[i] || isNext_Trap && visited[i] < 2) {
                d[i] = cost;
                pq.push({ -cost, {i, trapped } });
                visited[i]++;
            }
        }

        for (int i = 0; i < trapped.size(); i++) {
            activate_trap(trapped[i]);
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    _size = n;
    //roads입력을 받기 전 graph 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }
    //dijkstra를 사용하기 위해 distance배열 초기화
    for (int i = 1; i <= n; i++) d[i] = INF;
    //roads 입력에 따른 graph초기화
    for (int i = 0; i < roads.size(); i++) {
        int from, to, cost;
        from = roads[i][0]; to = roads[i][1]; cost = roads[i][2];
        if (graph[from][to] > cost) {
            graph[from][to] = cost;
        }
    }
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    trap_info = traps;

    dijkstra(start);

    int answer = d[end];
    return answer;
}

int main() {
    int ret = solution(4, 1, 4, { {1, 2, 1}, {2, 3, 1}, {3, 2, 1}, {3, 4, 1} }, { 3 });
    cout << ret;
}