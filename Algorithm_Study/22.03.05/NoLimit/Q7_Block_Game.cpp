//이렇게 안된다.
//윗줄부터 검사한다 해서 모든 블럭을 깰 수 있는게 아님.
//0 0 0 0 1
//0 0 2 2 1
//0 0 2 1 1
//0 0 2 0 0

#include <string>
#include <vector>

using namespace std;

bool col_usable[50];

vector<int> findBlock(vector<vector<int>>& board, int r, int c) {
    int curr = board[r][c];
    vector<int> ret;
    ret.push_back(c);
    if ((r + 2 < board.size() && c - 1 >= 0) && board[r + 2][c - 1] == curr) {
        ret.push_back(c - 1);
    }
    else if ((r + 2 < board.size() && c + 1 < board.size()) && board[r + 2][c + 1] == curr) {
        ret.push_back(c + 1);
    }
    else if ((r + 1 < board.size() && c - 2 >= 0) && board[r + 1][c - 2] == curr) {
        ret.push_back(c - 1);
        ret.push_back(c - 2);
    }
    else if ((r + 1 < board.size() && c + 2 < board.size()) && board[r + 1][c + 2] == curr) {
        ret.push_back(c + 1);
        ret.push_back(c + 2);
    }
    else if ((r + 1 < board.size() && c + 1 < board.size() && c - 1 >= 0) && board[r + 1][c - 1] == curr) {
        ret.push_back(c - 1);
        ret.push_back(c + 1);
    }
    return ret;
}

void removeBlock(vector<vector<int>>& board, int r, int c) {
    int curr = board[r][c];
    if ((r + 2 < board.size() && c - 1 >= 0) && board[r + 2][c - 1] == curr) {
        board[r][c] = 0;
        board[r + 1][c] = 0;
        board[r + 2][c] = 0;
        board[r + 2][c - 1] = 0;
    }
    else if ((r + 2 < board.size() && c + 1 < board.size()) && board[r + 2][c + 1] == curr) {
        board[r][c] = 0;
        board[r + 1][c] = 0;
        board[r + 2][c] = 0;
        board[r + 2][c + 1] = 0;
    }
    else if ((r + 1 < board.size() && c - 2 >= 0) && board[r + 1][c - 2] == curr) {
        board[r][c] = 0;
        board[r + 1][c] = 0;
        board[r + 1][c - 1] = 0;
        board[r + 1][c - 2] = 0;
    }
    else if ((r + 1 < board.size() && c + 2 < board.size()) && board[r + 1][c + 2] == curr) {
        board[r][c] = 0;
        board[r + 1][c] = 0;
        board[r + 1][c + 1] = 0;
        board[r + 1][c + 2] = 0;
    }
    else if ((r + 1 < board.size() && c + 1 < board.size() && c - 1 >= 0) && board[r + 1][c - 1] == curr) {
        board[r][c] = 0;
        board[r + 1][c] = 0;
        board[r + 1][c - 1] = 0;
        board[r + 1][c + 1] = 0;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++)
        col_usable[i] = true;

    for (int r = 0; r < board.size(); r++) {
        for (int c = 0; c < board.size(); c++) {
            if (board[r][c] == 0 || !col_usable[c]) continue;

            int curr = board[r][c];

            if (c + 1 < board.size() && board[r][c + 1] == curr) {
                col_usable[c] = false;
                col_usable[c + 1] = false;
                if (c + 2 < board.size() && board[r][c + 2] == curr)
                    col_usable[c + 2] = false;
                continue;
            }

            if (r + 2 < board.size() && c + 1 < board.size() && board[r + 2][c] == curr && board[r + 1][c + 1] == curr) {
                col_usable[c] = false;
                col_usable[c + 1] = false;
                continue;
            }
            if (r + 2 < board.size() && c - 1 >= 0 && board[r + 2][c] == curr && board[r + 1][c - 1] == curr) {
                col_usable[c] = false;
                col_usable[c - 1] = false;
                continue;
            }

            vector<int> xpos = findBlock(board, r, c);
            bool pos = true;
            for (int i = 0; i < xpos.size(); i++)
                if (!col_usable[xpos[i]]) pos = false;

            if (pos) {
                removeBlock(board, r, c);
                answer++;
            }
            else if (!pos) {
                for (int i = 0; i < xpos.size(); i++)
                    col_usable[xpos[i]] = false;
            }

        }
    }
    return answer;
}