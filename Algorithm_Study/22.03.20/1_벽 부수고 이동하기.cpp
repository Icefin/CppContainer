//100ms

#include <iostream>
#include <cstring>
#include <queue>

#define MAXM 1001

using namespace std;

struct state {
	short y;
	short x;
	bool isBreak;
};

short map[MAXM][MAXM];
int dist[MAXM][MAXM][2];

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int _N, _M;

void bfs() {
	queue<state> q;
	q.push({ 1, 1, false });
	dist[1][1][0] = 1;

	while (!q.empty()) {
		state curr = q.front();
		q.pop();

		if (curr.y == _N && curr.x == _M) return;

		for (int dir = 0; dir < 4; dir++) {
			int ny = curr.y + dy[dir];
			int nx = curr.x + dx[dir];
			bool nBreak = curr.isBreak;

			if (ny < 1 || nx < 1 || ny > _N || nx > _M) continue;
			if (dist[ny][nx][nBreak] != -1) continue;

			if (map[ny][nx] == 0) {
				dist[ny][nx][nBreak] = dist[curr.y][curr.x][curr.isBreak] + 1;
				q.push({ ny, nx, nBreak });
			}
			else if (map[ny][nx] == 1 && !curr.isBreak) {
				dist[ny][nx][true] = dist[curr.y][curr.x][curr.isBreak] + 1;
				q.push({ ny, nx, true });
			}
		}
	}
}

int main() {
	memset(dist, -1, sizeof(dist));
	cin >> _N >> _M;

	for (int i = 1; i <= _N; i++) {
		string temp;
		cin >> temp;
		for (int j = 1; j <= _M; j++) {
			if (temp[j - 1] == '1') map[i][j] = 1;
			else map[i][j] = 0;
		}
	}

	bfs();

	if (dist[_N][_M][false] == -1 && dist[_N][_M][true] == -1) cout << -1;
	else if (dist[_N][_M][false] == -1 && dist[_N][_M][true] != -1) cout << dist[_N][_M][true];
	else if (dist[_N][_M][false] != -1 && dist[_N][_M][true] == -1) cout << dist[_N][_M][false];
	else {
		int ret = min(dist[_N][_M][false], dist[_N][_M][true]);
		cout << ret;
	}
}