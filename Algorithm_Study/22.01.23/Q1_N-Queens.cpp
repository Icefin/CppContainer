/*
* Problem : N-Queens
* 체스판의 가로/세로 길이 n이 매개변수로 주어질 때
* n개의 퀸이 서로 공격가능하지 않도록 배치하는 경우의 수 (1<= n <= 12)
*
* 한 줄에 둘 이상의 퀸은 존재할 수 없음.
* BackTracking 알고리즘의 대표격 문제!!
* 
* >>최소 0.01ms, 3.67MB의 성능
* >>최대 281.47ms, 4.27MB의 성능
*/
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void dfs(int i);

int n;
int column[13];	//i번째 행의 column[i]번째 열에 퀸이 존재
int ret = 0;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		column[1] = i;
		dfs(2);
	}

	cout << ret;
}

void dfs(int i)
{
	//끝까지 탐색이 된다면 ret을 1 증가시키고 종료
	if (i > n)
	{
		ret++;
		return;
	}
	else
	{
		//i행 j열 검사
		for (int j = 1; j <= n; j++)
		{
			bool flag = true;
			//k행 column[k]열에 대해서
			for (int k = 1; k <= i - 1; k++)
			{
				pair<int, int> prev_Post = { k, column[k] };	//이전 퀸의 위치
				if (j == column[k] || (abs(k - i) == abs(column[k] - j)))	//이전 퀸과 같은 열에 있거나 || 대각선에 위치한다면
				{
					flag = false;											//플래그변수를 false로
					break;
				}
			}
			//이전 퀸들의 공격범위를 모두 벗어난다면
			if (flag)
			{
				column[i] = j;					//i행 j열에 퀸을 위치
				dfs(i + 1);						//i+1행으로 검사 진행
			}
		}
	}
}

//프로그래머스 제출용 코드
//#include <cmath>
//#include <vector>
//
//using namespace std;
//
//void dfs(int i, int n);
//int column[13];
//int ret = 0;
//
//int solution(int n) {
//	for (int i = 1; i <= n; i++)
//	{
//		column[1] = i;
//		dfs(2, n);
//	}
//	return ret;
//}
//
//void dfs(int i, int n)
//{
//	if (i > n)
//	{
//		ret++;
//		return;
//	}
//	else
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			bool flag = true;
//			for (int k = 1; k <= i - 1; k++)
//			{
//				pair<int, int> prev_Post = { k, column[k] };
//				if (j == column[k] || (abs(k - i) == abs(column[k] - j)))
//					flag = false;
//			}
//			if (flag)
//			{
//				column[i] = j;
//				dfs(i + 1, n);
//			}
//		}
//	}
//}