//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////입력될 변수를 선언
//int n, k;
//
//int main()
//{
//	//n과 k를 공백을 기준으로 입력받음
//	cin >> n >> k;
//	int cnt = 0;
//
//	//n이 1이 될 때까지
//	while (n > 1)
//	{
//		//n을 k로 나눌 수 있다면
//		if (n % k == 0)
//		{
//			n /= k;
//			cnt++;
//		}
//		//n을 k로 나눌 수 없다면
//		else
//		{
//			n--;
//			cnt++;
//		}
//	}
//
//	cout << "the result is : " << cnt;
//}

/*
*	//1이 될 때까지//
* 나누기 연산은 -1 연산보다 숫자를 작게하므로 그리디 알고리즘 사용
* N을 K로 나눌 수 있다면 나누기 연산을 한 후 count++
* N을 K로 나눌 수 없다면 N-- 후 count++
*/