//원래 구현하던 방식으로는 최악의 경우 O(N^2)을 피할수가 없다!
//max_element연산을 없애고 단순 윈도우 슬라이딩 알고리즘으로 구현이 된다면 O(N)
//->범위내의 최댓값을 계속 찾는것이 어려움. next_max로 보정한다 해도 숫자가 내림차순으로 정렬되는 경우 모든값을 알고 있어야함
//O(NlogN) -> 최악의 경우 약 166만이므로 적절한 방법일듯
//->이진탐색을 사용할 수 있는 문제인가???
//이진탐색을 적용하려면, 탐색을 진행할 값은 정렬되어 있거나, 최대 최소값을 알거나...
//stones의 최대, 최소값으로 구현한다면?

//실행시간 2.50ms / 3.55ms

//https://www.acmicpc.net/problem/2110

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 1;
    //stones의 최댓값을 탐색
    int stones_max = *max_element(stones.begin(), stones.end());
    int right = stones_max; int left = 1;
    //stones의 max, min으로 이진탐색
    while (left <= right) {
        bool pos = true;
        int mid = (right + left) / 2;
        int cnt = 0;
        //연속해서 k개 이상의 stone이 mid이하라면 건너뛸 수 없다.
        for (int i = 0; i < stones.size(); i++) {
            if (stones[i] < mid) cnt++;
            else if (stones[i] >= mid) cnt = 0;

            if (cnt >= k) {
                pos = false;
                break;
            }
        }
        //현재 mid값으로 가능하다면 answer을 mid로 갱신, 이진탐색을 진행
        if (pos) {
            answer = mid;
            left = mid + 1;
        }
        //현재 mid값으로 불가능하다면 바로 이진탐색을 진행
        else right = mid - 1;
    }
    return answer;
}