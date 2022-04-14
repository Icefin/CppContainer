/*
* problem : JoyStick
* 조이스틱으로 알파벳 이름 완성하기
* 초기에는 A로만 이루어진 이름 -> 목표하는 이름을 만들기 위한 최소 조작횟수 리턴
* 
* 최소 0.01ms / 3.66MB 의 성능
* 최대 0.01ms / 4.35MB 의 성능
*/
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    //결과로 리턴할 변수
    int cnt = 0;
    //조이스틱을 조작해야 하는 index를 저장
    vector<int> idx;
    //name의 첫 문자부터 마지막 문자까지 순회하여
    //각 위치마다 조작횟수를 계산하고, 해당 위치의 index를 idx에 저장한다.
    for (int i = 0; i < name.length(); i++) {
        int move = name[i] - 'A';
        //move가 13을 넘어가면 z부터 돌아오는것이 더 빠르므로 보정해준다.
        if (move > 13) {
            move = 26 - move;
        }
        cnt += move;
        //첫번째 문자는 이동할 필요가 없으므로 저장하지 않음
        //move가 0인경우의 위치에는 반드시 이동할 필요가 없으므로 저장하지 않음
        if (i != 0 && move != 0) 
            idx.push_back(i);
    }
    //idx의 size가 0인경우 : AA....
    if (idx.size() == 0) return cnt;
    //idx의 size가 1인 경우 : 오른쪽으로만 이동하거나 / 왼쪽으로만 이동한다
    else if (idx.size() == 1) {
        cnt += (idx[0] < name.length() - idx[0]) ? idx[0] : name.length() - idx[0];
        return cnt;
    }
    //idx의 size가 2 이상인 경우
    //1) 오른쪽으로만 이동하거나 / 왼쪽으로만 이동하는 경우 중 작은것
    int move_cnt = (idx[idx.size() - 1] < name.length() - idx[0]) ? idx[idx.size() - 1] : name.length() - idx[0];
    //2)오른쪽으로 이동하다 왼쪽으로 이동하거나 / 왼쪽으로 이동하다 오른쪽으로 이동하는 경우 중 작은 것
    for (int i = 0; i < idx.size() - 1; i++){
        int left = idx[i];
        int right = idx[i + 1];
        int temp_cnt = (2 * (name.length() - right) + left < (2 * left) + (name.length() - right)) ? 2 * (name.length() - right) + left : (2 * left) + (name.length() - right);
        move_cnt = move_cnt < temp_cnt ? move_cnt : temp_cnt;
    }
    //최종적으로 움직이는 횟수가 가장 작은것을 cnt에 더해준다.
    cnt += move_cnt;
    return cnt;
}

int main() {
    int answer = solution("JEROEN");
    cout << answer;
    return 0;
}