#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
//집합 연산에 필요한 함수
int findRoot(int num);
void unionRoot(int num1, int num2);
//입력될 변수들
int N, M;
int root[501];

int main()
{
	cin >> N >> M;
	//루트를 자기 자신으로 초기화
	for (int i = 1; i <= N; i++)
		root[i] = i;
	//입력받으며 루트를 최신화
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
				unionRoot(i + 1, j + 1);
		}
	}
	//여행 계획 입력
	vector<int> plan;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		plan.push_back(temp);
	}
	//여행 계획 속 도시들의 루트가 동일하지 않다면 연결 되어있지않음
	bool ret = true;
	for (int i = 1; i < M; i++)
	{
		if (findRoot(plan[0]) != findRoot(plan[i]))
			ret = false;
	}

	if (ret) cout << "YES";
	else cout << "NO";
}

int findRoot(int num)
{
	if (num == root[num]) return num;
	return root[num] = findRoot(root[num]);
}

void unionRoot(int num1, int num2)
{
	num1 = findRoot(num1);
	num2 = findRoot(num2);
	if (num1 < num2) root[num2] = num1;
	else root[num1] = num2;
}