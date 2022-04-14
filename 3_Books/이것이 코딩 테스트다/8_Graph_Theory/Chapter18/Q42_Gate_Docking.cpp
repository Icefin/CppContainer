#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
//집합 연산에 필요한 함수
int findRoot(int num);
void unionRoot(int num1, int num2);

int G, P;
int root[100001];

int main()
{
	cin >> G;
	cin >> P;
	//루트를 자기 자신으로 초기화
	for (int i = 1; i <= G; i++)
		root[i] = i;
	//비행기는 가능한 게이트번호가 높은 게이트에 도킹
	//게이트 그래프의 루트가 0이되면 더 이상 도킹이 불가능하므로 break
	int ret = 0;
	for (int i = 0; i < P; i++)
	{
		int p_gate;
		cin >> p_gate;
		int r_gate = findRoot(p_gate);
		if (r_gate == 0) break;
		unionRoot(r_gate, r_gate - 1);
		ret++;
	}
	cout << ret;
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