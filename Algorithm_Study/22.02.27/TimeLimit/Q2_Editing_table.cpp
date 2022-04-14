/*
* problem : 표 편집 (https://programmers.co.kr/learn/courses/30/lessons/81303)
*/

//중간에 삽입-삭제 연산이 많이생긴다 -> list 사용하는 문제인가?
//cmd는 위-아래 방향 모두 이동이 가능하다 -> double linked list를 사용하자
//삭제연산 이후 가장 최근 삭제된 노드를 돌아올 수 있게 해야한다 -> stack자료구조를 사용하여 가장 최근 삭제된 노드를 불러오자
//linkedlist를 사용하니 edge case를 조심해서 구현하자

//Solving Time : 40min

#include <string>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

//STL의 list를 사용하지 않고 직접 구현
//memory pooling 사용
struct Node {
    int number;
    Node* next = nullptr;
    Node* prev = nullptr;
    bool isRemoved = false;
}list[1000000];
//커서의 위치를 나타낼 ptr
Node* ptr = nullptr;
//memory pool의 크기를 나타낼 listSize
int listSize = 0;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    //삭제될 노드들을 담을 stack. (removed Node)
    stack<Node*> rmNode;
    //입력에따라 모든 노드를 초기화
    listSize = n;
    for (int i = 0; i < listSize; i++) {
        if (i == 0) {
            list[0].next = &list[1];
            list[0].number = 0;
            continue;
        }
        if (i == listSize - 1) {
            list[listSize - 1].prev = &list[listSize - 2];
            list[listSize - 1].number = listSize - 1;
            continue;
        }

        list[i].next = &list[i + 1];
        list[i].prev = &list[i - 1];
        list[i].number = i;
    }

    ptr = &list[k];

    //cmd 를 순회하며 모든 명령어를 수행
    for (int i = 0; i < cmd.size(); i++) {
        //Up 명령어
        if (cmd[i][0] == 'U') {
            int cnt = stoi(cmd[i].substr(2));
            int iter = 0;
            while (iter < cnt) {
                ptr = ptr->prev;
                iter++;
            }
            continue;
        }
        //Down 명령어
        if (cmd[i][0] == 'D') {
            int cnt = stoi(cmd[i].substr(2));
            int iter = 0;
            while (iter < cnt) {
                ptr = ptr->next;
                iter++;
            }
            continue;
        }
        //Remove 명령어
        if (cmd[i][0] == 'C') {
            ptr->isRemoved = true;
            rmNode.push(ptr);
            if (ptr->next == nullptr) {
                ptr = ptr->prev;
                ptr->next = nullptr;
            }
            else if (ptr->prev == nullptr) {
                ptr = ptr->next;
                ptr->prev = nullptr;
            }
            else {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                ptr = ptr->next;
            }
            continue;
        }
        //Restore 명령어
        if (cmd[i][0] == 'Z') {
            if (rmNode.top()->next == nullptr) {
                rmNode.top()->prev->next = rmNode.top();
            }
            else if (rmNode.top()->prev == nullptr) {
                rmNode.top()->next->prev = rmNode.top();
            }
            else {
                rmNode.top()->next->prev = rmNode.top();
                rmNode.top()->prev->next = rmNode.top();
            }
            rmNode.top()->isRemoved = false;
            rmNode.pop();
            continue;
        }
    }

    //모든 명령이 끝난 후 삭제 여부에 따라 O, X를 삽입
    for (int i = 0; i < n; i++) {
        if (list[i].isRemoved) {
            answer += "X";
        }
        else {
            answer += "O";
        }
    }
    return answer;
}