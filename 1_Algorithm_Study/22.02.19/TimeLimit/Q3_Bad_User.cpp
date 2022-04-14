/*
* problem : 불량 사용자 (https://programmers.co.kr/learn/courses/30/lessons/64064)
*/

//아니 카카오 문자열 처리하는거 왜이리 좋아함...
//user_id와 banned_id의 크기와 아이디 길이가 그렇게 길지 않으므로 구현만 잘 하면 통과할듯?
//user_id와 banned_id를 길이별로 나눈다음 비교하여 각 케이스에서 나온 결과값을 곱해주는 형식으로 구현
//길이별로 나눈 케이스에서 각 아이디를 어떻게 비교해야 할까...?

//Solving Time : ...

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> user_divided_len[9];
vector<string> banned_divided_len[9];

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

using namespace std;

int solution(vector<string> user_id, vector<string> banned_id) {
    for (int i = 0; i < user_id.size(); i++) {
        user_divided_len[user_id[i].length()].push_back(user_id[i]);
    }
    for (int i = 0; i < banned_id.size(); i++) {
        banned_divided_len[banned_id[i].length()].push_back(banned_id[i]);
    }
    int answer = 1;

    
    return answer;
}