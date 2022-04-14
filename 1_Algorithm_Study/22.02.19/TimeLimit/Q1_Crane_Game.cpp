/*
* problem : 크레인 인형뽑기 (https://programmers.co.kr/learn/courses/30/lessons/64061)
*/

//바구니와 격자 모두 선입후출 구조를 가진다 -> stack을 사용하여 풀이를 구현하자
//board와 moves의 크기 모두 충분히 작으므로 시간복잡도를 고민하지 않고 구현할 수 있다.

//Solving Time : 20min

#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> bucket;
stack<int> machine[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = board[0].size();
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                machine[j].push(board[i][j]);
            }
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        if (machine[moves[i] - 1].empty())
            continue;
        int doll = machine[moves[i] - 1].top();
        machine[moves[i] - 1].pop();

        if (bucket.empty())
            bucket.push(doll);
        else if (bucket.top() == doll) {
            bucket.pop();
            answer += 2;
        }
        else {
            bucket.push(doll);
        }
    }
    return answer;
}