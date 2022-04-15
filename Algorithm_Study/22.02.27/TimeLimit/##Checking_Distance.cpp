/*
* Problem : 거리두기 확인하기 (https://programmers.co.kr/learn/courses/30/lessons/81302)
*/

// 시간이 애매하게 남으니 풀었던 문제나 다시 풀어볼까
// 지난번에 구상해둔 아이디어를 토대로 문제 풀이 진행
// 한번 풀었던 문제라 어렵지않게 구현하는듯

//solving time : 15 min

#include <string>
#include <queue>

using namespace std;

int graph[5][5];        //0 : 빈공간, 1 : 파티션, 2 : 응시자

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int tc = 0; tc < 5; tc++) {
        queue<pair<int, int>> pos;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (places[tc][i][j] == 'O') graph[i][j] = 0;
                else if (places[tc][i][j] == 'X') graph[i][j] = 1;
                else {
                    graph[i][j] = 2;
                    pos.push({ i, j });
                }
            }
        }
        int ret = 1;
        while (!pos.empty() && ret == 1) {
            int x = pos.front().first;
            int y = pos.front().second;
            pos.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx < 0 || ny < 0 || nx > 4 || ny > 4) continue;

                if (graph[nx][ny] == 0) {
                    graph[nx][ny] = 2;
                    continue;
                }
                else if (graph[nx][ny] == 1)
                    continue;
                else {
                    ret = 0;
                    break;
                }
            }
        }
        answer.push_back(ret);
    }
    return answer;
}