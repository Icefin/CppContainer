#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> house;

int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	//이진 탐색을 사용하기 위해 오름차순 정렬
	sort(house.begin(), house.end());

	//가능한 가장 긴 거리와 짧은 거리를 계산
	int low = 1;
	int high = house[N - 1] - house[0];
	//결과를 저장할 변수
	int minDistance = 0;
	//가능한 거리 사이에서 이진탐색
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int num_Router = 1;
		//처음 설치되는 장소는 무조건 첫번째 집
		int router_Install = house[0];

		for (int i = 1; i < N; i++)
		{
			//차례로 순회하며 거리가 mid보다 커지면
			if (house[i] - router_Install >= mid)
			{
				//해당 장소에 공유기를 설치
				router_Install = house[i];
				num_Router += 1;
			}
		}
		//설치된 공유기의 수가 C보다 커지면
		if (num_Router >= C)
		{
			//공유기간의 거리의 최솟값은 mid보다 클 수 있으므로
			low = mid + 1;
			//현재 도출된 최적의 결과를 저장
			minDistance = mid;
		}
		else
		{
			//설치된 공유기의 수가 C보다 작다면 공유기간의 거리의 최솟값은 mid보다 클 수 없으므로
			high = mid - 1;
		}
	}

	cout << minDistance;
}

//max(minDistance)