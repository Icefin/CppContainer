/*
* problem : 튜플 (https://programmers.co.kr/learn/courses/30/lessons/64065)
*/

//문자열로 주어진 입력... 우선 문자열 처리부터 시작해보자.
//문자열을 처리하여 집합을 구한다음, 집합의 크기순서로 새로운 원소를 answer에 삽입하여 리턴
//문자열을 모두 돌더라도 O(N) N = 1,000,000이므로 처리의 시간은 고려하지 않아도 괜찮을 것 같다

//문자열을 처리하여 나오는 집합은 최대 500개이므로 STL의 set_difference (O(N))를 사용하여 처리 가능

//Solving Time : 40min

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> set[501];
int _size = 0;

vector<int> solution(string s) {
    vector<int> answer;
    queue<int> q;
    string temp = "";
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        else if (s[i] == ',') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
        }
        else if (s[i] == '}') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
            int size = q.size();
            if (size > _size) _size = size;
            while (!q.empty()) {
                set[size].push_back(q.front());
                q.pop();
            }
            i++;
        }
        else {
            temp += s[i];
        }
    }
    answer.push_back(set[1].front());
    vector<int> set_diff;
    for (int i = 2; i <= _size; i++) {
        sort(set[i].begin(), set[i].end());
        set_diff.resize(set[i].size());
        set_difference(set[i].begin(), set[i].end(), set[i - 1].begin(), set[i - 1].end(), set_diff.begin());
        answer.push_back(set_diff.front());
        set_diff.clear();
    }
    return answer;
}