#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Initialize();
bool Binary_Search(vector<int> arr, int component, int start, int end);

int N;
vector<int> serialNum;
int M;
vector<int> partNum;


int main()
{
	Initialize();

	sort(serialNum.begin(), serialNum.end());

	for (int i = 0; i < M; i++)
	{
		bool isExist = Binary_Search(serialNum, partNum[i], 0, N - 1);
		if (isExist)
			cout << "YES ";
		else
			cout << "NO ";
	}
}

void Initialize()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		serialNum.push_back(x);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		partNum.push_back(x);
	}
}

bool Binary_Search(vector<int> arr, int component, int start, int end)
{
	if (start > end) return false;

	int mid = (start + end) / 2;

	if (arr[mid] == component) return true;
	else if (arr[mid] > component)
		return Binary_Search(arr, component, start, mid - 1);
	else
		return Binary_Search(arr, component, mid + 1, end);
}