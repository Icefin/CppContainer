/*
* problem : 징검다리 건너기 (https://programmers.co.kr/learn/courses/30/lessons/64062)
*/

//stones배열의 크기 : 200,000, 원소값의 최대 : 200,000,000 -> 단순구현으로 효율성 통과 절대 불가능할것
//문제에서 원하는것 : 연속된 k개의 원소에서 구해지는 최댓값들 중 가장 작은 값
//슬라이딩 윈도우 알고리즘을 잘 응용하면 O(N...)쯤에 구할 수 있지 않을까?
//효율성 잡아보려다 시간 많이 날림...

//Solving Time : 1h 40min
//정확성 64.1, 효율성 25.6 -> 89.7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int range_max = *max_element(stones.begin(), stones.begin() + k);
    int range_max_idx = max_element(stones.begin(), stones.begin() + k) - stones.begin();
    int left = 0, right = k - 1;
    int ret = range_max;
    int next_max = 0, next_max_idx = 0;
    while (right < stones.size()) {
        if (stones[right] >= range_max) {
            range_max = stones[right];
            range_max_idx = right;
            next_max = 0, next_max_idx = 0;
        }
        else if (stones[right] >= next_max) {
            next_max = stones[right];
            next_max_idx = right;
        }
        if (left > range_max_idx) {
            range_max = *max_element(stones.begin() + left, stones.begin() + next_max_idx);
            range_max_idx = max_element(stones.begin() + left, stones.begin() + next_max_idx) - (stones.begin() + left);
            range_max_idx = next_max < range_max ? range_max_idx : next_max_idx;
            range_max = next_max < range_max ? range_max : next_max;
            next_max = 0, next_max_idx = 0;
        }
        if (ret > range_max) ret = range_max;
        left++; right++;
    }
    return ret;
}
