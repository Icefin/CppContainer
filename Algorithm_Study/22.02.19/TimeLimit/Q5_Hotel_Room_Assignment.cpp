/*
* problem : 호텔 방 배정 (https://programmers.co.kr/learn/courses/30/lessons/64063)
*/

//long long 으로 처리하는것 보니 array나 vector로 방 번호를 비교하는 식으로는 절대 구현 못하겠다
//room_number가 200,000이하이므로 단순구현으로는 통과하지 못함.
//하지만 시간없으니 대충 해싱해서 정합성만 맞춰야지

//Solving Time : 10min
//정확성 78.8, 효율성 0 -> 78.8

#include <string>
#include <vector>
#include <unordered_map>

typedef long long ll;

using namespace std;

unordered_map<ll, int> um;

vector <ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        while (um[room_number[i]] != 0) {
            room_number[i]++;
        }
        um[room_number[i]]++;
        answer.push_back(room_number[i]);
    }
    return answer;
}