/*
* problem : 숫자 문자열과 영단어 (https://programmers.co.kr/learn/courses/30/lessons/81301)
*/

//출력 정수의 길이는 최대 10자리
//각 자리별로 영단어롤 검사해주면 끝나는 문제인듯
//단순하게 풀어도 충분한 문제이므로 최적화를 생각하지 말고 단순 구현으로 해결하자
//처음에 한글자씩 비교하고, 같은 글자가 나오면 추가 케이스 분류를 생각하였으나
//생각해보니 두 글자씩 비교하면 추가 케이스 분류를 하지 않아도 된다!

//Solving Time : 10min

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string original_number;
    for (int i = 0; i < s.length(); i++) {
        //s[i]가 숫자인 경우
        if (s[i] >= 48 && s[i] <= 57) {
            original_number += s[i];
            continue;
        }

        if (s.substr(i, 2) == "ze") {
            original_number += '0';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "on") {
            original_number += '1';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "tw") {
            original_number += '2';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "th") {
            original_number += '3';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "fo") {
            original_number += '4';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "fi") {
            original_number += '5';
            i += 3;
            continue;
        }
        if (s.substr(i, 2) == "si") {
            original_number += '6';
            i += 2;
            continue;
        }
        if (s.substr(i, 2) == "se") {
            original_number += '7';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "ei") {
            original_number += '8';
            i += 4;
            continue;
        }
        if (s.substr(i, 2) == "ni") {
            original_number += '9';
            i += 3;
            continue;
        }
    }
    answer = stoi(original_number);
    return answer;
}