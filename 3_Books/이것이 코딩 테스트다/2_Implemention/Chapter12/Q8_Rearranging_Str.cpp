#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main()
{
	cin >> str;

	sort(str.begin(), str.end());

	//문자가 처음 나오는 위치를 저장할 변수
	int pos = 0;
	//숫자들의 합을 저장할 변수
	int sum = 0;

	for (; pos < str.size(); pos++)
	{
		//문자가 나오기 시작하면 반복문 탈출
		if ((int)str[pos] > 58) break;

		//문자가 나오기 전까지 숫자 합 계산
		sum += (int)str[pos] - '0';
	}
	//sum + 숫자문자를 제외한 문자열 출력 erase : 0~pos까지의 문자 제거
	cout << sum << str.erase(0, pos);
}

/*
* 숫자와 문자가 섞여있을 경우, 정렬 시 숫자가 문자보다 앞으로 정렬됨
*/

/*
string str;
vector<char> result;
int value = 0

int main(void)
{
	cin >> str;

	for(int i = 0; i < str.size(); i++)
	{
		if(isalpha(str[i]))
		{
			result.push_back(str[i]);
		}
		else value += str[i] - '0';
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < result.size(); i++) cout << result[i];
	
	cout << value;
}

*/