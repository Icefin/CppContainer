//실행시간 0.01ms ~ 15.03ms

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//튜플의 집합을 저장할 정적 배열
vector<int> set[501];
//set배열에 저장되는 집합의 수를 저장할 변수
int _size = 0;

vector<int> solution(string s) {
    vector<int> answer;
    //queue 자료구조를 활용하여 문자열 s를 처리
    queue<int> q;
    string temp = "";
    //문자열 s를 모두 순회하며 집합을 찾아냄
    //queue를 사용. FIFO를 활용하여 집합의 순서를 보장
    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        //쉼표는 숫자 사이의 쉼표만 처리된다.
        else if (s[i] == ',') {
            int num = stoi(temp);
            q.push(num);
            temp = "";
        }
        //괄호가 닫힐때는 하나의 집합이 완성되는 경우
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
            //괄호가 닫힐때 두 칸을 건너뛰어 괄호 사이의 쉼표를 처리
            i++;
        }
        //숫자가 나오는 경우는 temp에 숫자를 더해줌
        else {
            temp += s[i];
        }
    }
    answer.push_back(set[1].front());
    //이전 집합과의 차집합을 구해가며 튜플을 구성
    //i번집합 - i-1번집합 => 튜플의 i번째 원소
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