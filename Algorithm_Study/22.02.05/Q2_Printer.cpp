/*
* problem : Printer (https://programmers.co.kr/learn/courses/30/lessons/42587)
* 문서가 요청된 순서대로 인쇄하되, 중요도가 높은 문서부터 출력되도록 프린트 함
* 이 때 location의 문서는 몇 번째 출력되는지 리턴
*
* 효율성테스트
* 최소 0.01ms / 3.66MB 의 성능
* 최대 0.02ms / 4.34MB 의 성능
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    //프린터의 출력 순서를 나타낼 queue
    queue<pair<int, int>> q;
    //우선순위를 저장할 priority queue
    priority_queue<int> pq;
    //입력받을 priorities를 이용하여 q와 pq를 초기화
    for (int i = 0; i < priorities.size(); i++) {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }
    //출력 순서를 리턴
    int cnt = 1;
    while (true) {
        //queue맨 앞 원소의 우선순위가 전체 우선순위보다 낮다면 
        //맨 앞 원소를 빼서 맨 뒤로 보내는 작업
        if (q.front().first < pq.top()) {
            pair<int, int> elem = q.front();
            q.pop();
            q.push(elem);
            continue;
        }
        //queue맨 앞 원소의 우선순위가 전체 우선순위에서 제일 높다면
        //현재 원소의 원래 index가 location과 같은지 검사
        //만약 location과 같은 값이라면 반복문 탈출
        pair<int, int> temp = q.front();
        if (temp.second == location) {
            break;
        }
        //location과 같은 값이 아니라면 해당 원소를 queue에서 제거
        //이후 priority queue에서도 우선순위를 제거해 준다.
        q.pop();
        pq.pop();
        cnt++;
    }
    return cnt;
}

int main() {
    int ret = solution({ 2, 1, 3, 2 }, 2);
    cout << ret;
    return 0;
}
