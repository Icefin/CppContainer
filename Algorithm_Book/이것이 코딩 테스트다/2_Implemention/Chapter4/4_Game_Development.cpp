#include <iostream>

using namespace std;

//사용될 함수 정의
void Initialize();
void Turn_Left();

//입력될 변수 정의
int size_y, size_x;
int charactor[3];		//0 : y좌표, 1 : x좌표, 2 : 방향 
int map[50][50];

//사용될 변수 정의
int visited[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };	//북쪽방향부터 ccw

int main()
{
	//변수 초기화
	Initialize();
	//알고리즘 결과를 저장할 변수
	int cnt_ret = 1;
	//알고리즘에 사용될 변수
	int cnt_turn = 0;

	while (1)
	{
		//왼쪽으로 회전
		Turn_Left();
		cnt_turn++;
		//다음 위치 후보 계산
		int next_y = charactor[0] + dy[charactor[2]];
		int next_x = charactor[1] + dx[charactor[2]];
		//갈 수 있는 지형 && 방문하지 않은 지형이면
		if (map[next_y][next_x] != 1 && visited[next_y][next_x] == 0)
		{
			//방문 기록
			visited[next_y][next_x] = 1;
			//캐릭터 이동
			charactor[0] = next_y;
			charactor[1] = next_x;
			//방문 카운트++
			cnt_ret++;
			//회전 횟수 초기화
			cnt_turn = 0;
			continue;
		}

		//한 바퀴를 모두 돌았다면
		if (cnt_turn == 4)
		{
			//뒤로 가는 경우
			int next_y = charactor[0] - dy[charactor[2]];
			int next_x = charactor[0] - dx[charactor[2]];
			//뒤쪽 방향이 갈 수 있는 지형이라면
			if (map[next_y][next_x] != 1)
			{
				//캐릭터 이동
				charactor[0] = next_y;
				charactor[1] = next_x;
				//회전 횟수 초기화
				cnt_turn = 0;
			}
			else break;
		}
	}
	cout << cnt_ret;
}

void Initialize()
{
	cin >> size_y >> size_x;

	for (int i = 0; i < 3; i++)
	{
		int char_info;
		cin >> char_info;
		charactor[i] = char_info;
	}

	for (int y = 0; y < size_y; y++)
		for (int x = 0; x < size_x; x++)
		{
			int tile_info;
			cin >> tile_info;
			map[y][x] = tile_info;
		}

	visited[charactor[0]][charactor[1]] = 1;
}

void Turn_Left()
{
	charactor[2] += 1;
	if (charactor[2] == 4) charactor[2] = 0;
}

/*
* 현재 위치에서 현재 방향을 기준으로 왼쪽 방향부터 ccw로 이동방향 결정
* 더 이상 움직일 수 없을때까지 방문한 칸의 수 출력
*/