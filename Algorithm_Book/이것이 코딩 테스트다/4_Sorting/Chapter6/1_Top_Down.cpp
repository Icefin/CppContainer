#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> arr_num;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr_num.push_back(x);
	}

	//내림차순으로 정렬
	sort(arr_num.begin(), arr_num.end(), greater<>());

	for (int i = 0; i < n; i++)
		cout << arr_num[i] << ' ';
}
