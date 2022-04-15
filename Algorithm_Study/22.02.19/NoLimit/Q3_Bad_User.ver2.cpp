//그냥 모든 경우의수를 계산하자. 어차피 최대 8*8이라 아무리 많아도 시간복잡도에서 터지진 않을듯
//GG

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool comp(string user, string ban) {
    if (user.length() != ban.length()) return false;
    int len = user.length();
    bool ret = true;
    for (int i = 0; i < len; i++) {
        if (user[i] == ban[i] || ban[i] == '*') continue;
        ret = false;
        break;
    }
    return ret;
}

int factorial(int num) {
    if (num == 0 || num == 1) return 1;
    return num * factorial(num - 1);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    sort(user_id.begin(), user_id.end());
    do {
        bool isPossible = true;
        for (int i = 0; i < banned_id.size(); i++) {
            if (!comp(user_id[i], banned_id[i])) {
                isPossible = false;
                break;
            }
        }
        if (isPossible) answer++;
    } while (next_permutation(user_id.begin(), user_id.end()));

    answer /= factorial(user_id.size() - banned_id.size());

    unordered_map<string, int> elem;

    for (int i = 0; i < banned_id.size(); i++) {
        elem[banned_id[i]]++;
    }
    unordered_map<string, int>::iterator iter;
    for (iter = elem.begin(); iter != elem.end(); iter++) {
        answer /= factorial(iter->second);
    }

    return answer;
}

int main() {
    int ret = solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******", "******" });
    cout << ret;
}