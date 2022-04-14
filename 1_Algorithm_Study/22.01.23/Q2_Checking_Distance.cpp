/*
* Problem : 거리두기 확인하기
* 각 대기실 별로 모든 응시자가 맨해튼 거리 2 초과로 위치하는지 검사
* 5개의 5x5구조 대기실
* vector<vector<string>> -> vector<string> : 각 대기실 구조 (P : 응시자, O : 빈 테이블, X : 파티션)
*
* 하나의 대기실에 대한 알고리즘을 짜고, 나머지 대기실은 테스트케이스로 돌리기
* 
* >>최소 0.02ms, 3.66MB의 성능
* >>최대 0.02ms, 4.34MB의 성능
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<string> room;
int graph[5][5];	//빈 테이블 = 0, 응시자 : 1, 파티션 = 2
queue<pair<int, int>> pos;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main()
{
	//하나의 대기실에 대한 정보 입력
	for (int i = 0; i < 5; i++)
	{
		string temp;
		cin >> temp;
		room.push_back(temp);
	}
	//문자열로 주어진 정보를 다루기 쉽도록 정수형태로 변환
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
		{
			if (room[i][j] == 'O')
				graph[i][j] = 0;
			//해당 칸에 사람이 있다면
			else if (room[i][j] == 'P')
			{
				graph[i][j] = 1;
				pos.push({ i, j });		//사람의 위치 저장
			}
			else
				graph[i][j] = 2;
		}
	//BFS 알고리즘 수행
	while (!pos.empty())
	{
		pair<int, int> person = pos.front();
		pos.pop();
		//사람간의 맨허튼 거리가 2 초과이어야 하므로
		//각 사람마다 한 칸씩은 띄워져 있어야 한다.
		for (int i = 0; i < 4; i++)
		{
			int nx = person.first + dx[i];
			int ny = person.second + dy[i];
			//맵을 벗어나지 않는 경우에만
			if (0 <= nx && 0 <= ny && nx < 5 && ny < 5)
			{
				//옆칸에 사람이 있는경우
				if (graph[nx][ny] == 1)
				{
					//0을 반환하고 종료
					cout << 0;
					return 0;
				}
				//옆칸이 파티션이라면 탐색을 지속
				else if (graph[nx][ny] == 2) continue;
				else
					//옆칸이 빈칸이라면 다음사람 조사를 위해 1 삽입
					graph[nx][ny] = 1;
			}
		}
	}
	//검색을 모두 마친다면 1을 반환
	cout << 1;
	return 0;
}

//프로그래머스 제출용 코드
//#include <string>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//void Initialize(vector<string> part);
//
//int graph[5][5];
//queue<pair<int, int>> pos;
//
//int dx[] = { -1, 0, 1, 0 };
//int dy[] = { 0, 1, 0, -1 };
//
//vector<int> solution(vector<vector<string>> places) {
//	vector<int> answer;
//
//	for (int i = 0; i < 5; i++)
//	{
//		Initialize(places[i]);
//		bool isPossible = true;
//		while (!pos.empty() && isPossible)
//		{
//			pair<int, int> person = pos.front();
//			pos.pop();
//
//			for (int i = 0; i < 4; i++)
//			{
//				int nx = person.first + dx[i];
//				int ny = person.second + dy[i];
//
//				if (0 <= nx && 0 <= ny && nx < 5 && ny < 5)
//				{
//					if (graph[nx][ny] == 1)
//					{
//						isPossible = false;
//						break;
//					}
//					else if (graph[nx][ny] == 2) continue;
//					else
//						graph[nx][ny] = 1;
//				}
//			}
//		}
//		if (isPossible) answer.push_back(1);
//		else
//			answer.push_back(0);
//	}
//	return answer;
//}
//
////각 테스트케이스에 대비해 정보를 초기화하는 함수
//void Initialize(vector<string> part)
//{
//	pos = queue<pair<int, int>>();
//	for (int i = 0; i < 5; i++)
//		for (int j = 0; j < 5; j++)
//		{
//			if (part[i][j] == 'O')
//				graph[i][j] = 0;
//			else if (part[i][j] == 'P')
//			{
//				graph[i][j] = 1;
//				pos.push({ i, j });
//			}
//			else
//				graph[i][j] = 2;
//		}
//}