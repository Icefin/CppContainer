//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////입력될 변수 선언
//int n, m;
//
//int main()
//{
//	//결과 반환에 사용될 변수 선언
//	int result;
//	//n 과 m을 공백을 기준으로 구분하여 입력받음
//	cin >> n >> m;
//
//	//0 ~ n-1번째 행까지
//	for (int i = 0; i < n; i++)
//	{
//		//입력될 최댓값이 10000이므로 min_value를 10000으로 설정
//		int min_value = 10001;
//		for (int j = 0; j < m; j++)
//		{
//			int x;
//			cin >> x;
//			//현재까지 min_value와 새로 입력된 x를 비교하여 작은 값을 min_value에 저장
//			min_value = min(min_value, x);
//		}
//
//		//해당 행에서 찾아진 min_value와 result를 비교하여 큰 값을 result에 저장
//		result = max(min_value, result);
//	}
//
//	cout << result;
//}

/*
*	//숫자 카드 게임//
* 각 행에서 가장 작은 수를 이용하여 비교하는 경우이므로 그리디 알고리즘 사용
* 각 행에서 입력받을 때 가장 작은 수를 계산하고, 현재까지 입력된 가장 작은 수와 비교하여 계산
*/