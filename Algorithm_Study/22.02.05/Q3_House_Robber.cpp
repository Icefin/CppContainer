/*
* problem : House Robber
* 원형으로 위치한 집들을 방문할 때, 가장 많은 돈을 획득할 수 있는 방법
* 이 때 인접한 두 집을 동시에 방문할 수는 없다.
*
* 효율성테스트
* Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
* Memory Usage: 7.8 MB, less than 57.45% of C++ online submissions for House Robber II.
* 
* memset을 사용하여 배열 초기화 하는것이 for문을 돌리는 것 보다 효율적
*/
#include <iostream>
#include <vector>

using namespace std;

int dp[100];

int solution(vector<int> nums) {
    if (nums.size() <= 3) {
        if (nums.size() == 1) return nums[0];
        else if (nums.size() == 2) return max(nums[0], nums[1]);
        else {
            return max(max(nums[0], nums[1]), nums[2]);
        }
    }

    //1)첫번째 집을 포함해서 방문하는 경우 -> 마지막집은 방문할 수 없음
    memset(dp, -1, sizeof(dp));
    dp[0] = nums[0];
    dp[1] = nums[1];
    dp[2] = max(nums[0] + nums[2], nums[1]);
    for (int i = 3; i < nums.size() - 1; i++) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + nums[i]), dp[i - 3] + nums[i]);
    }
    int ret1 = dp[nums.size() - 2];
    //2)첫번째 집을 미포함하여 방문하는 경우 -> 마지막집을 방문할 수 있음
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = nums[1];
    dp[2] = nums[2];
    for (int i = 3; i < nums.size(); i++) {
        dp[i] = max(max(dp[i - 1], dp[i - 2] + nums[i]), dp[i - 3] + nums[i]);
    }
    int ret2 = dp[nums.size() - 1];

    return max(ret1, ret2);
}


int main() {
    int ret = solution({ 1, 3, 1 });
    cout << ret;
    return 0;
}