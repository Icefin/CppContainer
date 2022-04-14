//1. dp를 사용한 구현
// 0ms
//blocklist를 다르게 구현하면 좀 더 효율적으로 할 수 있을것 같다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];
int max_idx = 1;
vector<int> blocklist[101];

struct block {
	int num;
	int area;
	int height;
	int weight;
}blocks[101];

int blockCnt;

bool comp(block a, block b) {
	return a.area < b.area;
}

int main() {
	cin >> blockCnt;
	int area, height, weight;
	for (int i = 1; i <= blockCnt; i++) {
		cin >> area >> height >> weight;
		blocks[i].num = i;
		blocks[i].area = area;
		blocks[i].height = height;
		blocks[i].weight = weight;
	}

	sort(blocks + 1, blocks + blockCnt + 1, comp);
	for (int i = 1; i <= blockCnt; i++) {
		dp[i] = blocks[i].height;
		blocklist[i].push_back(i);
	}

	for (int i = 1; i <= blockCnt; i++) {
		for (int j = 1; j < i; j++) {
			if (blocks[i].weight > blocks[j].weight) {
				if (dp[i] < dp[j] + blocks[i].height) {
					dp[i] = dp[j] + blocks[i].height;
					blocklist[i] = {};
					for (int elem = 0; elem < blocklist[j].size(); elem++) {
						blocklist[i].push_back(blocklist[j][elem]);
					}
					blocklist[i].push_back(i);
				}
			}
		}
		if (dp[i] > dp[max_idx]) max_idx = i;
	}
	cout << blocklist[max_idx].size() << '\n';
	for (int i = 0; i < blocklist[max_idx].size(); i++) {
		cout << blocks[blocklist[max_idx][i]].num << '\n';
	}
}