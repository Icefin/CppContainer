#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Binary_Search(vector<int> arr, int component, int start, int end);

int N, M;
vector<int> dduck;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		dduck.push_back(x);
	}

	sort(dduck.begin(), dduck.end());		//sorting 필요없음

	int ret = Binary_Search(dduck, M, 0, arr[N-1]);

	cout << ret;

}


int Binary_Search(vector<int> arr, int target, int start, int end)
{
	if (start == end) return start;

	int mid = (start + end)/ 2;
	int temp_length = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)
			temp_length += arr[i] - mid;
	}

	if (temp_length == target) return mid;
	else if (temp_length > target)
		return Binary_Search(arr, target, mid + 1, end);
	else
		return Binary_Search(arr, target, start, mid - 1);
}