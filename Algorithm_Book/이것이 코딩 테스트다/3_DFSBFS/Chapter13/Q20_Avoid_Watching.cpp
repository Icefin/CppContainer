#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
char graph[6][6];
vector<pair<int, int>> teachers;	//선생님의 위치를 저장
vector<pair<int, int>> spaces;		//빈공간의 위치를 저장

bool watch(int x, int y, int direction);	//상하좌우로 감시하는 함수	true : 학생발견
bool process();								//감시 후 처리를 하는 함수	true : 발견된 경우가 존재

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp;
			cin >> temp;
			graph[i][j] = temp;

			if (temp == 'T') teachers.push_back({ i, j });	//선생님이 있는 경우 해당 위치를 저장
			if (temp == 'X') spaces.push_back({ i, j });	//빈공간이 있는 경우 해당 위치를 저장
		}
	}

	bool isPossible = false;
	
	//spaces.size()크기의 배열에서 3개의 원소를 뽑은 조합
	//spaces.size()크기의 bool 배열을 생성 후 3개의 원소를 true로 초기화 나머지는 false
	//이후에 next_permutation을 이용해 순열을 생성하여 조합을 생성
	vector<bool> binary(spaces.size());		//spaces.size()크기의 bool배열 생성
	fill(binary.end() - 3, binary.end(), true);		//bool배열의 마지막 세 원소를 true로 초기화
	do
	{
		//장애물 생성
		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				graph[x][y] = 'O';
			}
		}
		//생성된 장애물로 모든 선생의 감시를 피할 수 있는지 검사
		if (!process())
		{
			isPossible = true;
			break;
		}
		//생성된 장애물 제거
		for (int i = 0; i < spaces.size(); i++)
		{
			if (binary[i])
			{
				int x = spaces[i].first;
				int y = spaces[i].second;
				graph[x][y] = 'X';
			}
		}
	} while (next_permutation(binary.begin(), binary.end()));

	if (isPossible) cout << "YES";
	else cout << "NO";
}

bool watch(int x, int y, int direction)
{
	if (direction == 0)
	{
		while (y >= 0)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			y -= 1;
		}
	}
	if (direction == 1)
	{
		while (y <= N)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			y += 1;
		}
	}
	if (direction == 2)
	{
		while (x >= 0)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			x -= 1;
		}
	}
	if (direction == 3)
	{
		while (x <= N)
		{
			if (graph[x][y] == 'S') return true;
			if (graph[x][y] == 'O') return false;
			x += 1;
		}
	}
}
bool process()
{
	for (int i = 0; i < teachers.size(); i++)
	{
		int x = teachers[i].first;
		int y = teachers[i].second;
		for (int i = 0; i < 4; i++)
		{
			if (watch(x, y, i)) return true;
		}
	}

	return false;
}