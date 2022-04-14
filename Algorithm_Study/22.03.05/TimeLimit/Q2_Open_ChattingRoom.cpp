/*
* problem : 오픈채팅방 (https://programmers.co.kr/learn/courses/30/lessons/42888)
*/

//userID를 key, 닉네임을 value로 하면 userID에 따라 닉네임 변경 가능
//in, out 순서를 저장하는 자료구조도 하나 필요
//?? level 1 보다 이게 더 쉬운데???

//Solving Time : 15min

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> um_userID;
vector<pair<string, int>> order;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        istringstream st(record[i]);
        string substr;
        vector<string> str;
        while (getline(st, substr, ' ')) str.push_back(substr);

        if (str[0] == "Enter") {
            um_userID[str[1]] = str[2];
            order.push_back({ str[1], 1 });    //1 : in
        }
        else if (str[0] == "Leave") {
            order.push_back({ str[1], 0 });    //0 : out
        }
        else if (str[0] == "Change") {
            um_userID[str[1]] = str[2];
        }
    }

    for (int i = 0; i < order.size(); i++) {
        if (order[i].second == 1) {
            answer.push_back(um_userID[order[i].first] + "님이 들어왔습니다.");
        }
        else if (order[i].second == 0) {
            answer.push_back(um_userID[order[i].first] + "님이 나갔습니다.");
        }
    }

    return answer;
}
