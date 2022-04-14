//0.03ms ~ 128.78ms

//vector대신 queue를 사용해도 시간은 크게 바뀌지 않는다.

#include <string>
#include <queue>
#include <sstream>
#include <unordered_map>

using namespace std;
//userID - 닉네임을 매칭할 해시테이블
unordered_map<string, string> um_userID;
//userID의 in-out을 저장할 배열 1 : in, 0 : out
queue<pair<string, int>> q_order;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        //record의 각 원소를 공백을 기준으로 분할하여 str에 저장
        istringstream st(record[i]);
        string substr;
        vector<string> str;
        while (getline(st, substr, ' ')) str.push_back(substr);
        //각 명령어별로 기능을 수행
        if (str[0] == "Enter") {
            um_userID[str[1]] = str[2];
            q_order.push({ str[1], 1 });    //1 : in
        }
        else if (str[0] == "Leave") {
            q_order.push({ str[1], 0 });    //0 : out
        }
        else if (str[0] == "Change") {
            um_userID[str[1]] = str[2];
        }
    }
    //명령이 실행된 후 order의 앞에서부터 메시지 출력
    while (!q_order.empty()) {
        if (q_order.front().second == 1) {
            answer.push_back(um_userID[q_order.front().first] + "님이 들어왔습니다.");
        }
        else if (q_order.front().second == 0) {
            answer.push_back(um_userID[q_order.front().first] + "님이 나갔습니다.");
        }
        q_order.pop();
    }

    return answer;
}