/*
* problem : 미로 탈출 (https://programmers.co.kr/learn/courses/30/lessons/81304)
*/

//양수 간선의 길찾기 하는거 보니 dijkstra부터 의심... floyd까지는 필요 없을듯
//일반적인 dijkstra는 알고리즘 만으로 O(N^2)를 요구. trap에 따른 처리까지 한다면 시간초과날 가능성이 높다
//pq를 활용한 개선된 dijkstra를 사용하자 => O(NlogN)
//dijkstra를 사용하려면 graph가 완성되어야 할텐데 trap-node, trap-trap에 따라 모든 패턴을 정형화 할 수 없을까?
//=>trap-node는 가능하지만 trap-trap의 경우에 문제가 발생...
//dijkstra 진행 중 graph를 업데이트 하여 최단거리를 찾을 수 있는가???
//=>가능은하다. 그런데 trap끼리 연결되는 경우를 적절히 처리해주어야 한다. => 처리되지 않는경우 길찾기 실패 or 무한루프
//시간이 없으니 생각난 곳 까지 구현...

//Solving Time : 1hour 40min + @...

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

vector<int> trap_info;
int d[1001];
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
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, start });
    d[start] = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int now = pq.top().second;
        bool isTrap = find(trap_info.begin(), trap_info.end(), now) != trap_info.end();
        pq.pop();
        if (d[now] < dist && !isTrap) continue;

        if (isTrap) {
            activate_trap(now);
        }

        for (int i = 1; i <= _size; i++) {
            if (graph[now][i] == INF) continue;
            int cost = dist + graph[now][i];
            if (cost < d[i]) {
                d[i] = cost;
                pq.push({ -cost, i });
            }
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

    trap_info = traps;

    dijkstra(start);

    int answer = d[end];
    return answer;
}