//84ms

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct state {
	short r;
	short c;
	short time;
	bool isFire;
};

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int R, C;
short map[1002][1002];
queue<state> q;
queue<state> fire_pos;

int bfs() {
	int time = -1; bool isPossible = false;
	while (!q.empty() && !isPossible) {
		short cur_r = q.front().r;
		short cur_c = q.front().c;
		short cur_t = q.front().time;
		bool isFire = q.front().isFire;
		q.pop();

		if (!isFire && map[cur_r][cur_c] == 2) continue;

		for (int i = 0; i < 4; i++) {
			short nr = cur_r + dr[i];
			short nc = cur_c + dc[i];

			if (isFire) {
				if (nr < 1 || nc < 1 || nr > R || nc > C) continue;
				if (map[nr][nc] == 2 || map[nr][nc] == 3) continue;
				map[nr][nc] = 2;
				q.push({ nr, nc, 0, true });
			}
			else {
				if (map[nr][nc] == 1 || map[nr][nc] == 2 || map[nr][nc] == 3) continue;
				if (map[nr][nc] == -1) {
					time = cur_t + 1;
					isPossible = true;
					break;
				}
				map[nr][nc] = 1;
				q.push({ nr, nc, cur_t + 1, false });
			}
		}
	}
	return time;
}

int main() {
	memset(map, -1, sizeof(map));
	cin >> R >> C;
	for (short r = 1; r <= R; r++)
		for (short c = 1; c <= C; c++) {
			char curr;
			cin >> curr;
			if (curr == '#') map[r][c] = 3;			//벽
			else if (curr == '.') map[r][c] = 0;	//빈공간
			else if (curr == 'F') {
				map[r][c] = 2;	//불
				fire_pos.push({ r, c, 0, true });
			}
			else if (curr == 'J') {
				map[r][c] = 1;	//캐릭터
				q.push({ r, c, 0, false });
			}
		}

	while (!fire_pos.empty()) {
		q.push(fire_pos.front());
		fire_pos.pop();
	}

	int answer = bfs();
	if (answer == -1) cout << "IMPOSSIBLE";
	else cout << answer;
}