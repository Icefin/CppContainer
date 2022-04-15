//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
////입력될 변수를 선언
//int N;
//vector<int> adv;
//
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int x;
//		cin >> x;
//		adv.push_back(x);
//	}
//	//vector의 시작 (adv.begin()) ~ 끝(adv.end())까지 원소를 오름차순 정렬
//	sort(adv.begin(), adv.end());
//
//	int num = 0, groupCnt = 0;
//
//	//모든 모험가에 대하여
//	for (int i = 0; i < N; i++)
//	{
//		//그룹에 모험가 1명 추가
//		num++;
//		//그룹에 있는 모험가의 숫자가 현재 모험가의 공포도보다 같거나 높으면
//		if (num >= adv[i])
//		{
//			//그룹 형성
//			groupCnt++;
//			//새로운 그룹 생성을 위해 초기화
//			num = 0;
//		}
//	}
//	cout << groupCnt;
//}

/*
*	//모험가 길드//
* 공포도가 가장 낮은 사람부터 그룹을 형성하는 그리디 알고리즘 사용
* 공포도를 배열로 입력받은 후 sort함수를 사용하여 공포도를 오름차순으로 정렬
* 이 후 공포도가 낮은 순서부터 그룹을 형성하여 그룹이 형성되면 groupCount++
*/