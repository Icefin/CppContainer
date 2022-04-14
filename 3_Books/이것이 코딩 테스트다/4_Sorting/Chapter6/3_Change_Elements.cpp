#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int N, K;
vector<int> arr_A;
vector<int> arr_B;

//변수 초기화용 함수
void Initialize();

int main()
{
	Initialize();
	//A는 오름차순 정렬
	sort(arr_A.begin(), arr_A.end());
	//B는 내림차순 정렬
	sort(arr_B.begin(), arr_B.end(), greater<>());

	for (int i = 0; i < K; i++)
	{
		if (arr_A[i] > arr_B[i]) break;

		arr_A[i] = arr_B[i];
	}

	//accumulate : arr_A.begin()~ end()까지 원소의 합, 초기값은 0
	//numeric 헤더 필요
	cout << accumulate(arr_A.begin(), arr_A.end(), 0);
}