/*
* problem : 받아쓰기 (https://www.acmicpc.net/problem/20542)
* i는 i, j, l과 모두 매칭되며 v는 v, w와 매칭될 때, 받아쓰기 점수를 구하기
*
* 168ms / 90MB 의 성능
*/

//편집거리 알고리즘 (Levensthein Algorithm)의 변형
//편집거리 알고리즘과 거의 유사한 논리구조 + 예외 케이스만 처리
//각 문자열의 길이가 최대 1,000,000이므로 정적할당 dp테이블로 처리 불가능
//vector를 사용하여 동적할당 하는 방법으로 구현
//-> n * m의 dp테이블을 사용하므로 시간복잡도는 O(N*M) ~= O(N^2)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> dp;

int solution(string str1, string str2) {
    //알고리즘을 편하게 구현하기 위해 마진설정
    string ans = "0" + str1;
    string sol = "0" + str2;
    //dp테이블 초기화
    for (int r = 1; r <= n; r++) {
        dp[r][0] = dp[r - 1][0] + 1;
    }
    for (int c = 1; c <= m; c++) {
        dp[0][c] = dp[0][c - 1] + 1;
    }
    //Levensthein Algorithm 수행
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (ans[r] == sol[c] || (ans[r] == 'i' && (sol[c] == 'j' || sol[c] == 'l')) || (ans[r] == 'v' && sol[c] == 'w'))
                dp[r][c] = dp[r - 1][c - 1];
            else {
                dp[r][c] = min(min(dp[r - 1][c], dp[r][c - 1]), dp[r - 1][c - 1]) + 1;
            }
        }
    }

    return dp[n][m];
}

void main() {
    cin >> n >> m;
    dp.resize(n + 1);
    for (int i = 0; i < n + 1; i++)
        dp[i].resize(m + 1);
    string str_ans, str_sol;
    cin >> str_ans; cin >> str_sol;
    int ret = solution(str_ans, str_sol);
    cout << ret;
}