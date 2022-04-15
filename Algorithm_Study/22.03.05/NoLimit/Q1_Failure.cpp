// 0.01ms ~ 1.05ms

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//각 stage당 클리어한 사용자수를 저장
float clear[502] = { 0 };
//실패율 정렬시 이용
//실패율이 같으면 스테이지 번호기준 오름차순
bool comp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    //stages정보로 각 stage당 클리어한 사용자수를 저장
    for (int i = 0; i < stages.size(); i++) {
        clear[stages[i]]++;
    }
    //N스테이지부터 클리어한 사용자수를 누적한다.
    int users = clear[N + 1];
    //각 스테이지당 실패율을 저장.
    //실패율이 같으면 스테이지 번호를 사용해야 하므로 pair로 쌍을 만들어줌
    pair<float, int> failure[502] = { {0, 0} };
    //N스테이지부터 계산하며 사용자수 누적
    for (int i = N; i > 0; i--) {
        users += clear[i];
        if (users == 0) {
            failure[i] = { 0, i };
            continue;
        }
        failure[i] = { clear[i] / users, i };
    }

    sort(failure + 1, failure + N + 1, comp);

    for (int i = 1; i <= N; i++) {
        answer.push_back(failure[i].second);
    }

    return answer;
}