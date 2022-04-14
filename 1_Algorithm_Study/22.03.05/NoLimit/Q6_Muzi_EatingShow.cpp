//10.47ms ~ 34.78ms

#include <string>
#include <vector>
#include <queue>

using namespace std;
//음식 섭취 시간, 음식 번호를 저장. 음식 섭취 시간기준 오름차순 정렬
priority_queue<pair<long long, int>> pq;
//음식 섭취 시간이 남았는지 확인할 배열
bool isOver[200001] = { false };
//음식 섭취 시간이 남은 음식의 갯수
long long leftCnt = 0;

int solution(vector<int> food_times, long long k) {
    leftCnt = food_times.size();
    for (int i = 0; i < food_times.size(); i++) {
        pq.push({ -food_times[i], i + 1 });
    }
    //이전 음식 섭취 시간을 저장
    long long prev = 0;

    while (k >= (-pq.top().first - prev) * leftCnt && !pq.empty()) {
        k -= (-pq.top().first - prev) * leftCnt;
        prev = -pq.top().first;
        isOver[pq.top().second] = true;
        pq.pop();
        leftCnt--;
        while (!pq.empty() && prev == -pq.top().first) {
            isOver[pq.top().second] = true;
            pq.pop();
            leftCnt--;
        }
    }
    //pq가 empty이면 더 이상 섭취할 음식이 없음. return -1
    if (pq.empty()) return -1;

    int remain = k % leftCnt;
    int cnt = 0;
    for (int i = 1; i <= food_times.size(); i++) {
        if (!isOver[i] && cnt == remain) return i;
        else if (!isOver[i]) cnt++;
    }
}