//#include <iostream>
//
//using namespace std;
////알고리즘에 입력받을 변수들 미리 정의
//int N;
//
//int main()
//{
//	
//	cin >> N;
//	int cnt = 0;
//	int coinTypes[4] = { 500, 100, 50, 10 };
//
//	for (int i = 0; i < 4; i++)
//	{
//		int coin = coinTypes[i];
//		cnt += N / coin;
//		N %= coin;
//	}
//
//	cout << cnt;
//}

/*
* 모든 화폐들은 다른 화폐들의 배수이므로 그리디 알고리즘 사용 가능
* 가장 큰 화폐 단위부터 사용하여 거스름돈을 반환
*/