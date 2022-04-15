/*
* problem : 뉴스 클러스터링 (https://programmers.co.kr/learn/courses/30/lessons/17677)
* 자카드 유사도 J(A, B) = (A^B)/(AuB)
* 입력으로 들어온 두 문자열을 두 글자씩 끊어 다중집합의 원소로 변환 후
* 자카드 유사도를 출력. 대소문자의 차이는 무시하며 영문으로 된 글자 쌍만 유효하게 계산한다.
*
* 최소 0.01ms / 3.66MB의 성능
* 최대 1.62ms / 4.34MB의 성능
*/

//두 문자열의 길이가 최대 1000이므로 단순비교로 충분히 계산 가능
//make_set : 문자열을 집합으로 분해. 대문자는 소문자로 변환하며 알파벳 이외의 문자가 포함되면 버린다.
//intersecion : 두 집합의 교집합을 구하는 함수
//->intersection의 연산으로 인해 최악의 경우 O(N^2)으로 예상

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> make_set(string str) {
    vector<string> ret;
    for (int i = 0; i < str.size() - 1; i++) {
        string temp = "";
        //첫번째 문자가 대문자이면 소문자로 변환, 소문자 이외의 문자이면 포함x
        if (isupper(str[i]))
            temp += tolower(str[i]);
        else if (str[i] <= 122 && str[i] >= 97) {
            temp += str[i];
        }
        //두번째 문자가 대문자이면 소문자로 변환, 소문자 이외의 문자이면 포함x
        if (isupper(str[i + 1]))
            temp += tolower(str[i + 1]);
        else if (str[i + 1] <= 122 && str[i + 1] >= 97) {
            temp += str[i + 1];
        }
        //temp의 길이가 2가 되지 않으면 집합에 포함하지 않음
        if (temp.length() == 2) {
            ret.push_back(temp);
        }
    }
    return ret;
}

vector<string> intersection(vector<string> set1, vector<string> set2) {
    vector<string> ret;
    int len = 0;
    bool isCounted[1000] = { false };
    //두 집합 중 크기가 작은 집합의 원소로 비교
    //isCounted배열을 사용하여 크기가 큰 배열에서 비교가 되었는지 검사
    if (set1.size() > set2.size()) {
        for (int i = 0; i < set2.size(); i++) {
            for (int j = 0; j < set1.size(); j++) {
                if (set2[i] == set1[j] && !isCounted[j]) {
                    ret.push_back(set2[i]);
                    isCounted[j] = true;
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < set1.size(); i++) {
            for (int j = 0; j < set2.size(); j++) {
                if (set1[i] == set2[j] && !isCounted[j]) {
                    ret.push_back(set1[i]);
                    isCounted[j] = true;
                    break;
                }
            }
        }
    }
    return ret;
}

int solution(string str1, string str2) {
    vector<string> set1 = make_set(str1);
    vector<string> set2 = make_set(str2);

    vector<string> set_inter = intersection(set1, set2);

    int len_inter = set_inter.size();
    int len_union = set1.size() + set2.size() - len_inter;

    //합집합이 0이면 유사도는 1
    if (len_union == 0) return 65536;
    else return (65536 * len_inter) / len_union;
}

void main() {
    int ret = solution("FRANCE", "french");
    cout << ret;
}