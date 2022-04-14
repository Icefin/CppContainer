// #5. 테트로미노

#include <iostream>

#define MAX 501

using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

int _N, _M, map[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;

void dfs(int y, int x, int sum, int cnt) {
    if (cnt == 4) {
        ans = max(ans, sum);
        return;
    }

    if (y < 0 || x < 0 || y >= _N || x >= _M || visited[y][x]) return;

    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        dfs(y + dy[i], x + dx[i], sum + map[y][x], cnt + 1);
    }
    visited[y][x] = false;
}

int main(void) {
    cin >> _N >> _M;

    for (int i = 0; i < _N; i++) {
        for (int j = 0; j < _M; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < _N; i++) {
        for (int j = 0; j < _M; j++) {
            dfs(i, j, 0, 0);

            if (j + 2 < _M) {
                int temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
                if (i - 1 >= 0) {
                    ans = max(ans, temp + map[i - 1][j + 1]);
                }
                if (i + 1 < _N) {
                    ans = max(ans, temp + map[i + 1][j + 1]);
                }
            }
            if (i + 2 < _N) {
                int temp = map[i][j] + map[i + 1][j] + map[i + 2][j];
                if (j - 1 >= 0) {
                    ans = max(ans, temp + map[i + 1][j - 1]);
                }
                if (j + 1 < _M) {
                    ans = max(ans, temp + map[i + 1][j + 1]);
                }
            }
        }
    }

    cout << ans;
}