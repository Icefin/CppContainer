//그냥 모든 경우의수를 계산하자. 어차피 최대 8*8이라 아무리 많아도 시간복잡도에서 터지진 않을듯
//GG

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user_divided_len[9];
vector<string> banned_divided_len[9];

//입력된 문자열을 비교하는 함수
//문자열의 길이는 같음이 보장된다
bool comp_user(string user, string ban) {
    int len = user.length();
    bool ret = true;
    for (int i = 0; i < len; i++) {
        if (ban[i] == '*' || user[i] == ban[i]) continue;
        else if (user[i] != ban[i]) {
            ret = false;
            break;
        }
    }
    return ret;
}
//중복되는 경우를 제거하기 위한 펙토리얼 함수
int factorial(int num) {
    if (num == 0 || num == 1) return 1;
    return num * factorial(num - 1);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    //이후에 permutation연산을 위해 user_id를 미리 sort해둔다.
    sort(user_id.begin(), user_id.end());
    //user_id와 banned_id를 길이별로 저장
    for (int i = 0; i < user_id.size(); i++) {
        user_divided_len[user_id[i].length()].push_back(user_id[i]);
    }
    for (int i = 0; i < banned_id.size(); i++) {
        banned_divided_len[banned_id[i].length()].push_back(banned_id[i]);
    }
    //각 길이별 경우의수를 곱하여 answer를 계산
    int answer = 1;
    //길이 1부터 8까지
    for (int i = 1; i <= 8; i++) {
        //만약 해당 길이의 banned_id가 없다면 continue
        if (banned_divided_len[i].size() == 0) continue;

        int temp = 0;
        do {
            bool pos = true;
            for (int j = 0; j < banned_divided_len[i].size(); j++) {
                if (!comp_user(user_divided_len[i][j], banned_divided_len[i][j])) pos = false;
            }
            if (pos) temp++;
        } while (next_permutation(user_divided_len[i].begin(), user_divided_len[i].end()));
        int fact = user_divided_len[i].size() - banned_divided_len[i].size();
        answer *= temp / factorial(fact);
    }

    return answer;
}

int main() {
    int ret = solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "*rodo", "*rodo", "******" });
    cout << ret;
}