//Union - Find연산에 기초하여 구현할 수 있을것 같음
//근데 k값의 범위가 너무 커서 parent 정적 배열로 구현 불가능... 
//Node를 연결하고, mapping하여 Node를 찾아가는 방식으로 구현
//->정적배열로 구현되는 union-find와 다르게 링크된 노드들의 parent 값을 유지하기 힘들다

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

struct roomNode {
    ll rNumber;
    roomNode* next = this;
    roomNode* head = this;
}roomNodes[200001];

unordered_map<ll, roomNode*> um;

int nodeCnt = 0;

roomNode* find_parent(roomNode* rm) {
    if (rm->next == rm) return rm;
    else {
        return rm = find_parent(rm->next);
    }
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        //room_number[i]의 방이 존재하지 않는경우
        if (um.count(room_number[i]) == 0) {
            roomNodes[nodeCnt].rNumber = room_number[i];
            um[room_number[i]] = &roomNodes[nodeCnt];
            //room_number[i] - 1의 방이 존재하면 현재 방과 연결
            if (um.count(room_number[i] - 1)) {
                um[room_number[i] - 1]->next = &roomNodes[nodeCnt];
                um[room_number[i] - 1]->head = &roomNodes[nodeCnt];
            }
            //room_number[i] + 1의 방이 존재하면 현재 방과 연결
            if (um.count(room_number[i] + 1)) {
                roomNode* rm = find_parent(um[room_number[i] + 1]);
                um[room_number[i]]->next = um[room_number[i] + 1];
                um[room_number[i]]->head = rm;
            }
            answer.push_back(room_number[i]);
        }

        //room_number[i]의 방이 존재하는 경우
        else {
            roomNode* rm = find_parent(um[room_number[i]]);
            roomNodes[nodeCnt].rNumber = rm->rNumber + 1;
            um[roomNodes[nodeCnt].rNumber] = &roomNodes[nodeCnt];
            rm->next = &roomNodes[nodeCnt];
            //roomNodes[nodeCnt].rNumber + 1 의 방이 존재하면 rm과 현재 방 모두 연결
            if (um.count(roomNodes[nodeCnt].rNumber + 1)) {
                roomNode* nm = find_parent(um[roomNodes[nodeCnt].rNumber + 1]);
                roomNodes[nodeCnt].next = um[roomNodes[nodeCnt].rNumber + 1];
                roomNodes[nodeCnt].head = nm;
                rm->head = nm;
            }
            else {
                rm->head = &roomNodes[nodeCnt];
            }
            answer.push_back(roomNodes[nodeCnt].rNumber);
        }
        nodeCnt++;
    }
    return answer;
}

int main() {
    vector<ll> ret = solution(10, { 1, 3, 4, 1, 3, 1 });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
}