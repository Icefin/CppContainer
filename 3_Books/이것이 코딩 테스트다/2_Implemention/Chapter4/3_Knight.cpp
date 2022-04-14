#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string position;
//2 1 11 10 8 7 5 4시 순으로 이동방향 검사
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

int main()
{
	cin >> position;

	int cnt = 0;

	int x = (int)position[0] - 'a' + 1;
	int y = (int)position[1] - '0';

	for (int i = 0; i < 8; i++)
	{
		//다음 좌표 계산
		int x_next = x + dx[i];
		int y_next = y + dy[i];

		//다음 위치가 보드를 벗어나면 카운팅 x
		if (x_next < 1 || x_next > 8 || y_next < 1 || y_next > 8) continue;

		cnt++;
	}

	cout << "Possible case is : " << cnt;
}

/*
* 나이트의 움직임을 저장할 dx, dy변수 선언
* 나이트의 움직임은 2시부터 ccw로 이동
* 나이트의 다음 발판 위치가 보드 내부에 있으면 cnt++
* 나이트의 다음 발판 위치가 보드를 벗어나면 continue
*/