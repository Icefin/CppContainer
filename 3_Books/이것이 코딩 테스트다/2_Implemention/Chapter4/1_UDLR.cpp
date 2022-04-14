#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//입력 받을 변수 선언
int _size;
string plan;
//구현 알고리즘에 사용될 변수 선언
//시작지점
int xpos = 1, ypos = 1;
//움직임 방향
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
//움직임 종류
char moveType[4] = { 'L', 'R', 'U', 'D' };

int main()
{
	cin >> _size; 
	//버퍼 제거
	cin.ignore();
	//string 헤더 필요
	getline(cin, plan);
	//공백 제거
	plan.erase(remove(plan.begin(), plan.end(), ' '), plan.end());

	//plan size만큼 반복하며
	for (int i = 0; i < plan.size(); i++)
	{
		//현재 사용될 계획
		char currPlan = plan[i];
		//계획에 따라 가게될 지점
		int x_next, y_next;
		for (int j = 0; j < 4; j++)
		{
			//움직임 종류를 검사
			if (currPlan == moveType[j])
			{
				x_next = xpos + dx[j];
				y_next = ypos + dy[j];
			}
		}
		//다음 지점이 맵을 벗어나면 움직이지 않음
		if (x_next < 1 || x_next > _size || y_next < 1 || y_next > _size) continue;
		//맵을 벗어나지 않으면 현재위치 변경
		xpos = x_next;
		ypos = y_next;
	}

	cout << "Destination coordinate is : " << xpos << " ," << ypos;
}