//모든 가로, 세로길을 좌표화하여 방문여부 확인
//0.01ms ~ 0.02ms

#include <iostream>
#include <string>

using namespace std;

int y = 10, x = 10;

bool map[21][21];

bool check(int y, int x) {
    if (x < 0 || y < 0 || x > 20 || y > 20) return false;
    return true;
}

pair<int, int> move(char cmd) {
    if (cmd == 'U') {
        return { -1, 0 };
    }
    else if (cmd == 'D') {
        return { 1, 0 };
    }
    else if (cmd == 'R') {
        return { 0, 1 };
    }
    else if (cmd == 'L') {
        return { 0, -1 };
    }
}

int solution(string dirs) {

    pair<int, int> mv = move(dirs[0]);
    y += mv.first, x += mv.second;
    map[y][x] = true;
    char prev = dirs[0];
    int answer = 1;

    for (int i = 1; i < dirs.length(); i++) {
        mv.first = move(prev).first + move(dirs[i]).first;
        mv.second = move(prev).second + move(dirs[i]).second;

        int ny = y + mv.first;
        int nx = x + mv.second;

        if (!check(ny, nx)) continue;

        prev = dirs[i];
        y = ny, x = nx;
        if (!map[y][x]) {
            map[y][x] = true;
            answer++;
        }
    }
    return answer;
}

int main() {
    int ret = solution("UDRLUDRLUDRL");
    cout << ret;
}