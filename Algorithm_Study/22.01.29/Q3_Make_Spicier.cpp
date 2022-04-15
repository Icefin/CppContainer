/*
* problem : More Spicier
* 모든 음식의 스코빌 지수를 K이상으로 만들기 위해 섞어야 하는 최소 횟수를 리턴
* 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
*
* 효율성테스트
* 최소 19.84ms / 7.91MB 의 성능
* 최대 231.14ms / 41.3MB 의 성능
*/
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int cnt = 0;
    priority_queue<int> pq;
    for (int i = 0; i < scoville.size(); i++) {
        //c++의 우선순위큐는 내림차순 정렬
        pq.push(-scoville[i]);
    }
    //pq에 조합할 음식이 2개이상 남아있으면서
    //가장 낮은 스코빌 지수가 K 미만 이라면
    while (pq.size() > 1 && -pq.top() < K) {
        int scv1 = -pq.top();
        pq.pop();
        int scv2 = -pq.top();
        pq.pop();

        int newScv = scv1 + 2 * scv2;
        pq.push(-newScv);
        cnt++;
    }

    int answer = (-pq.top() < K) ? -1 : cnt;
    return answer;
}

int main() {
    int ret = solution({ 1, 2, 3, 9, 10 ,12 }, 7);
    cout << ret;
    return 0;
}
