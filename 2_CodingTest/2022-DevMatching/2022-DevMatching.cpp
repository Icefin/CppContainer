//#1. 프리미엄 유지 문제
//슬라이딩 윈도우 알고리즘으로 해결
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int records[366] = { 0 };


vector<int> solution(vector<string> purchase) {
    vector<int> answer = { 0, 0, 0, 0, 0 };
    for (int i = 0; i < purchase.size(); i++) {
        int month, day, cost;
        month = stoi(purchase[i].substr(5, 2));
        day = stoi(purchase[i].substr(8, 2));
        cost = stoi(purchase[i].substr(11));

        int date = 0;

        for (int i = 1; i < month; i++) {
            date += months[i];
        }
        date += day;
        records[date] = cost;
    }
    int accum = 0;
    for (int i = 1; i <= 30; i++) {
        accum += records[i];
        if (accum < 10000) answer[0]++;
        else if (accum < 20000) answer[1]++;
        else if (accum < 50000) answer[2]++;
        else if (accum < 100000) answer[3]++;
        else if (accum >= 100000) answer[4]++;
    }

    int left = 1, right = 31;
    while (right <= 365) {
        accum -= records[left];
        accum += records[right];
        if (accum < 10000) answer[0]++;
        else if (accum < 20000) answer[1]++;
        else if (accum < 50000) answer[2]++;
        else if (accum < 100000) answer[3]++;
        else if (accum >= 100000) answer[4]++;
        left++;
        right++;
    }

    return answer;
}

//#2. n목 문제
//dfs로 해결
#include <string>
#include <vector>

using namespace std;

int _h, _w, _n;
//right, down, left-down, right-down
int dy[4] = { 0, 1, 1, 1 };
int dx[4] = { 1, 0, -1, 1 };

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= _h || x >= _w) return false;
    return true;
}

int dfs(int dir, vector<vector<int>> board) {
    int ret = 0;
    for (int r = 0; r < _h; r++) {
        for (int c = 0; c < _w; c++) {
            if (board[r][c] == 0) continue;
            board[r][c] = 0;
            int cnt = 1;
            int ny = r + dy[dir];
            int nx = c + dx[dir];
            while (check(ny, nx) && board[ny][nx] == 1) {
                board[ny][nx] = 0;
                ny += dy[dir];
                nx += dx[dir];
                cnt++;
            }
            if (cnt == _n) ret++;
        }
    }
    return ret;
}

int solution(int h, int w, int n, vector<string> board) {
    int answer = 0;
    _h = board.size(); _w = board[0].size(); _n = n;
    vector<vector<int>> _board(1000);
    for (int r = 0; r < _h; r++) {
        for (int c = 0; c < _w; c++) {
            if (board[r][c] == '1') _board[r].push_back(1);
            else if (board[r][c] == '0') _board[r].push_back(0);
        }
    }

    for (int dir = 0; dir < 4; dir++) {
        answer += dfs(dir, _board);
    }

    return answer;
}

//#3. 큐브회전 문제
//뭐임;;
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> ans = { {1, 1, 2, 2}, {1, 1, 2, 2}, {2, 2, 1, 1}, {2, 2, 1, 1} };
int _cnt = 10;

bool check(vector<vector<int>> temp) {
    bool ret = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (temp[i][j] != ans[i][j]) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

void rotate(int pos, char rc, int dir, vector<vector<int>>& grid) {
    if (rc == 'r') {
        if (dir == 0) {
            int first = grid[pos][0];
            for (int i = 0; i < 3; i++) {
                grid[pos][i] = grid[pos][i + 1];
            }
            grid[pos][3] = first;
            return;
        }
        else if (dir == 1) {
            int first = grid[pos][3];
            for (int i = 3; i > 0; i--) {
                grid[pos][i] = grid[pos][i - 1];
            }
            grid[pos][0] = first;
            return;
        }
    }
    else if (rc == 'c') {
        if (dir == 0) {
            int first = grid[0][pos];
            for (int i = 0; i < 3; i++) {
                grid[i][pos] = grid[i + 1][pos];
            }
            grid[3][pos] = first;
            return;
        }
        else if (dir == 1) {
            int first = grid[3][pos];
            for (int i = 3; i > 0; i--) {
                grid[i][pos] = grid[i - 1][pos];
            }
            grid[0][pos] = first;
            return;
        }
    }
}

void dfs(vector<vector<int>>& grid, int cnt) {
    if (check(grid)) {
        if (cnt < _cnt) _cnt = cnt;
        return;
    }
}

int solution(vector<vector<int>> grid) {
    dfs(grid, 0);
    return _cnt;
}
