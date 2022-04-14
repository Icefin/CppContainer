#include <iostream>

using namespace std;

string str;

int main()
{
	cin >> str;

	float cnt_change = 0;
	char lastLetter = str[0];

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == '0' && lastLetter == '1')
		{
			lastLetter = '0';
			cnt_change++;
		}
		else if (str[i] == '1' && lastLetter == '0')
		{
			lastLetter = '1';
			cnt_change++;
		}
	}

	cout << ceil(cnt_change / 2) << endl;
}

/*
* 연속된 숫자를 모두 한번에 뒤집는것이 최소 시행을 만듦으로 그리디 알고리즘 사용
* 0과 1의 덩어리를 각각 ㅇ, ㅁ라 하면 결국 배열의 형태는 ㅇㅁㅇㅁㅇㅁㅇ...
* ㅇ -> ㅁ && ㅁ -> ㅇ로 변형되는 시점을 count
* 변형되는 모든 시점을 구한 후 count /2 하여 최소 시행 횟수 출력
*/