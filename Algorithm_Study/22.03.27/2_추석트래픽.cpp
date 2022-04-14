//#1. Time interval을 이용한 구현
//>>메모리낭비가 너무 심하며 쓸데없는 iteration이 많다
//0.02ms ~ 19.62ms

#include <string>
#include <vector>

using namespace std;

short time_step[86400000];		//time[i] : ims ~ ims + 1 sec time interval

int solution(vector<string> lines) {
	int ret = 0;
	for (int i = 0; i < lines.size(); i++) {
		int h, m, s, ms;
		string temp; int step;
		h = stoi(lines[i].substr(11, 2)) * 60 * 60 * 1000;
		m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
		s = stoi(lines[i].substr(17, 2)) * 1000;
		ms = stoi(lines[i].substr(20, 3));
		int t = h + m + s + ms;

		temp = lines[i].substr(24); temp.pop_back();
		step = (int)(stof(temp) * 1000);

		if (t <= 1000 || t == step || t <= step + 998) {
			for (int k = 0; k <= t; k++) {
				time_step[k]++;
				if (time_step[k] > ret) ret = time_step[k];
			}
		}
		else {
			for (int k = t - step - 998; k <= t; k++) {
				time_step[k]++;
				if (time_step[k] > ret) ret = time_step[k];
			}
		}
	}
	return ret;
}

//#2. pq를 이용한 구현
//1에서 사용하던 문자열 처리는 그대로 사용하고, interval을 계산해주는 알고리즘만 개선
//lines를 뒤에서부터 순회하며, 시작시간을 기준으로 내림차순 정렬하여 정리
//pq.top()의 시작시간이 현재 계산하는 트래픽의 종료시간보다 크다면 해당 트래픽을 현재 interval에서 제외
//0.01ms ~ 0.67ms

#include <string>
#include <queue>
#include <vector>

using namespace std;

priority_queue<pair<int, int>> pq;

int solution(vector<string> lines) {
	int ret = 0;
	for (int i = lines.size() - 1; i >= 0; i--) {
		int h, m, s, ms;
		string temp; int step;
		h = stoi(lines[i].substr(11, 2)) * 60 * 60 * 1000;
		m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
		s = stoi(lines[i].substr(17, 2)) * 1000;
		ms = stoi(lines[i].substr(20, 3));
		int t = h + m + s + ms;

		temp = lines[i].substr(24); temp.pop_back();
		step = (int)(stof(temp) * 1000);

		pq.push({ t - step + 1, t });

		while (!pq.empty() && pq.top().first - 999 > t) {
			pq.pop();
		}

		if (ret < pq.size()) ret = pq.size();
	}
	return ret;
}