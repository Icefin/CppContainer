#include <iostream>

using namespace std;

string N;

int main()
{
	cin >> N;
	int length = N.size();
	int left_score = 0, right_score = 0;

	for (int i = 0; i < length / 2; i++)
		left_score += N[i];

	for (int i = length / 2; i < length; i++)
		right_score += N[i];

	if (left_score == right_score)
		cout << "LUCKY";
	else
		cout << "READY";
}

/*
* 원래 값이 중요한 문제였다면 sth_score += N[i] - '0'으로 작성되었을 것.
* 그러나 left_score == right_score 여부가 중요한 문제 이므로
* 그냥 ASCII값 그대로 덧셈 진행
*/