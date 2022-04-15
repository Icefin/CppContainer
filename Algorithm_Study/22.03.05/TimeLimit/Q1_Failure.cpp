/*
* Problem : 실패율 (https://programmers.co.kr/learn/courses/30/lessons/42889)
*/

//실패율의 정의에 주의하자
//어라 Level 1 치고는 많이 어렵다...?
//차근차근 구현해보자...

//solving time : 30 min

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

float clear[502] = { 0 };

bool comp(pair<double, int> a, pair<double, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    for (int i = 0; i < stages.size(); i++) {
        clear[stages[i]]++;
    }
    int users = clear[N + 1];
    pair<float, int> failure[502] = { {0, 0} };
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