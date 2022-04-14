//링크된 노드들에 공통된 값을 유지하는것은 매우 어렵다...
//링크된 노드들에 parent값을 유지하지 않으면 모든 노드를 순회하는것은 불가피하다
//결국 모든 노드들을 순회하지 않고 빠르게 head를 찾는것이 관건인듯
//입력 -> 끝의 방을 mapping하여 찾아가는 식으로 해보는건 어떨까

//실행시간 144.19ms / 227.61ms

#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

unordered_map<ll, ll> selected_room;        //실제 배정된 방들
unordered_map<ll, ll> assigned_room;        //입력된 방, 최근에 배정된 방

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        //room_number[i]의 방이 이미 배정되어 있다면
        //연결된 방들 중 최종적인 head를 찾아내어 방을 배정
        if (selected_room[room_number[i]] == 1) {
            vector<ll> candidates;          /*이전 알고리즘들과 속도 차이를 내는 부분*/
            candidates.push_back(room_number[i]);
            ll temp = assigned_room[room_number[i]] + 1;
            candidates.push_back(temp);

            while (selected_room[temp] != 0) {  /*연결된 모든 노드들을 검사하지 않고, tail -> head로 점프 가능!*/
                temp = assigned_room[temp] + 1;
                candidates.push_back(temp);
            }

            selected_room[temp]++;
            for (int i = 0; i < candidates.size(); i++) {
                assigned_room[candidates[i]] = temp;    /*이후 검색된 모든 tail의 head를 temp로 업데이트*/
            }
            answer.push_back(temp);
        }
        //room_number[i]의 방이 배정되어있지 않다면
        else {
            //room_number[i]의 방을 배정하고, room_number[i]의 head는 room_number[i]로 초기화
            selected_room[room_number[i]]++;
            assigned_room[room_number[i]] = room_number[i];
            answer.push_back(room_number[i]);
        }
    }
    return answer;
}

int main() {
    vector<ll> ret = solution(10, { 1, 1, 2, 2, 3, 3, 4, 4 });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}