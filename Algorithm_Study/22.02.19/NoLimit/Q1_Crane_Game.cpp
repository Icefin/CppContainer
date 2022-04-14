//실행시간 0.01ms ~ 0.02ms

#include <string>
#include <vector>
#include <stack>

using namespace std;

//바구니와 정사각 격자를 표현할 stack 자료구조
stack<int> bucket;
stack<int> machine[30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //입력된 board를 따라 machine을 초기화
    int size = board[0].size();
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] != 0) {
                machine[j].push(board[i][j]);
            }
        }
    }
    //입력된 move를 따라 인형뽑기를 수행
    for (int i = 0; i < moves.size(); i++) {
        //해당 칸에 인형이 없다면 아무일도 하지 않는다.
        if (machine[moves[i] - 1].empty())
            continue;
        //해당 칸에 인형이 있다면 해당 인형을 선택한다.
        int doll = machine[moves[i] - 1].top();
        machine[moves[i] - 1].pop();
        //바구니가 비어있거나 선택된 인형이 바구니 맨 위의 인형과 같지 않다면 push
        //선택된 인형이 바구니 맨 위의 인형과 같은 인형이라면 두 인형을 터트리고 answer에 +2
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