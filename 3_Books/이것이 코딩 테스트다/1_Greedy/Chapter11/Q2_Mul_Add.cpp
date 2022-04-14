//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////알고리즘에 입력될 변수 선언
//string str;
//
//int main()
//{
//	cin >> str;
//
//	//결과 반환을 위한 변수 선언
//	int result = str[0] - '0';
//
//	for (int i = 1; i < str.length(); i++)
//	{
//		//배열의 숫자가 0이면 아무 연산을 하지 않음
//		if (str[i] == '0') continue;
//		else if (str[i] == '1') result += 1;
//		else 
//		{
//			//배열의 숫자가 0이 아니라면 result * str[i]
//			result *= str[i] - '0';
//		}
//	}
//	cout << result;
//}

/*
*	//곱하기 혹은 더하기//
* 곱하기 연산이 더하기 연산보다 큰 수를 반환하므로 그리디 알고리즘 사용
* 0을 곱하는 경우를 제외하고 모든 수를 곱하여 결과 출력
* 이 때 str은 char의 배열 이므로 정수형 연산을 위해 ASCII code를 사용
* str[i] 의 ASCII값 - '0' 의 ASCII값 : 해당 숫자의 int값
*/