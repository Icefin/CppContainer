//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "test.h"
//
//using namespace std;
//
////알고리즘에 입력될 int형 변수 선언
//int N, M, K;
////알고리즘에 입력될 배열 선언
//vector<int> v;
//
//int main()
//{
//	//N, M, K를 공백을 기준으로 구분하여 입력 받기
//	cin >> N >> M >> K;
//
//	//N개의 수를 공백을 기준으로 구분하여 입력 받기
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		v.push_back(x);
//	}
//
//	//sort함수를 사용하려면 algorithm헤더 필요
//	//vector의 시작 (v.begin()) ~ 끝(v.end())까지 원소를 오름차순 정렬
//	sort(v.begin(), v.end());
//	//정렬된 vector에서 가장 큰 값
//	int first = v[N - 1];
//	//정렬된 vector에서 두 번째로 큰 값
//	int second = v[N - 2];
//
//	//first가 K번, second가 1번 더해지는 것이 M / (K+1)번 반복됨
//	int cnt = M / (K+1);
//	//만들 수 있는 가장 큰 수는 second가 cnt번, first가 M - cnt번 더해지는 경우 이므로
//	int result = second * cnt + first * (M - cnt);
//	cout << "The result is : " << result << endl;
//
//}

/*
*	//큰 수의 법칙//
* 가장 큰 수를 연속해서 더하는 것이 다른 모든수를 더하는 것보다 큰 경우 이므로 그리디 알고리즘 사용
* N개의 수를 입력받은 후, 입력받은 배열을 정렬하여 가장 큰 수와 그 다음 큰 수를 찾음
* 가장 큰 수를 K번 더한 후 그 다음 큰 수를 1번 더하는 방식으로 결과 계산
*/