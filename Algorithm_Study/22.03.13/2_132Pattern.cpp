//1. 101/102 test cases passed
//Time Limit Exceeded O(N^2)

#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<int> nums) {
	vector<int> min_arr(nums.size());
	min_arr[0] = nums[0];
	for (int i = 1; i < min_arr.size(); i++)
		min_arr[i] = min_arr[i - 1] < nums[i] ? min_arr[i - 1] : nums[i];

	for (int i = nums.size() - 1; i > 0; i--) {
		if (min_arr[i] == nums[i]) continue;

		for (int j = nums.size() - 1; j > i; j--) {
			if (nums[i] > nums[j] && nums[j] > min_arr[i]) return true;
		}
	}
	return false;
}

//2. priority_queue을 사용한 구현 O(NlogN)
//133ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool solution(vector<int> nums) {
	vector<int> min_arr(nums.size());
	priority_queue<int, vector<int>, greater<int>> pq;
	min_arr[0] = nums[0];
	for (int i = 1; i < min_arr.size(); i++)
		min_arr[i] = min_arr[i - 1] < nums[i] ? min_arr[i - 1] : nums[i];

	for (int i = nums.size() - 1; i > 0; i--) {
		while (!pq.empty() && pq.top() <= min_arr[i]) pq.pop();

		if (!pq.empty() && pq.top() < nums[i]) 
			return true;

		pq.push(nums[i]);
	}
	return false;
}

//3. 답안. stack을 사용한 구현 : ????
//=> pq -> st사용. 이게 왜 되는거지?