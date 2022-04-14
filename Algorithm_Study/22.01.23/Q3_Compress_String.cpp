/*
* Problem : 문자열 압축
* : 반복되는 문자열을 압축하여 나타낼 수 있는 문자열의 최소길이 구하기
* 문자열 s의 길이는 1이상 1000이하 -> 완전 탐색의 경우에도 10000번 미만의 탐색
*
* >>최소 0.01ms, 3.68MB의 성능
* >>최대 0.65ms, 4.28MB의 성능
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;

int main()
{
	cin >> s;
	//문자열의 최대 길이인 s.length()로 구하고자 하는 최소길이 초기화
	int min_len = s.length();
	//압축할 문자열의 길이는 1부터 s.length()/2 까지
	//s.length()/2를 넘어가면 압축하는 의미가 없어짐
	for (int i = 1; i <= s.length() / 2; i++) {
		//현재 문자열 저장
		string prev_str = s.substr(0, i);
		//현재 문자열이 몇번 반복되는지 저장
		int cnt = 1;
		//현재까지 압축된 문자열의 길이
		int curr_len = 0;
		//문자를 i개씩 건너뛰며 압축 시작
		for (int j = i; j <= s.length(); j += i) {
			//만약 현재위치 j에서 i만큼 건너뛴 위치가 문자열의 길이를 넘어간다면
			if (j + i > s.length())
			{
				//문자열이 한번 이상 압축되었다면
				if (cnt > 1) {
					int n = 0;
					//압축된 횟수에 따라 더해지는 숫자 계산
					//2~9번 : 1, 10~99번 : 2, 100~1000번 : 3
					while (cnt > 0) {
						n++;
						cnt /= 10;
					}
					//압축될 문자열 길이 + 숫자 길이를 더해줌
					curr_len += i + n;
				}
				//문자열이 압축되지 않았다면 압축될 문자열 길이만 더해줌
				else curr_len += i;
				break;
			}
			//문자열 압축이 가능하다면
			else if (prev_str == s.substr(j, i)) {
				cnt++;
				continue;
			}
			//문자열 압축이 불가능하다면
			else {
				if (cnt > 1) {
					int n = 0;
					while (cnt > 0) {
						n++;
						cnt /= 10;
					}
					curr_len += i + n;
				}
				else curr_len += i;

				prev_str = s.substr(j, i);
				cnt = 1;
			}
		}
		//문자열 압축 후 남은 문자열은 그대로 더해줌
		int remain = s.length() % i;
		curr_len += remain;
		//최소 길이 갱신
		min_len = min(min_len, curr_len);
	}
	cout << min_len;
}