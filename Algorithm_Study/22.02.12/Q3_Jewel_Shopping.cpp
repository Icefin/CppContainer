/*
* problem : 보석 쇼핑 (https://programmers.co.kr/learn/courses/30/lessons/67258)
* 모든 보석을 하나 이상 포함하는 가장 짧은 구간 찾기
*
* 투포인터 알고리즘 시도
* ->슬라이딩 윈도우 알고리즘 시도
* ->투포인터 사용...
*
* 효율성 테스트 기준
* 최소 2.04ms / 3.95MB의 성능
* 최대 64.65ms / 12MB의 성능
*/

//투포인터 알고리즘을 사용
//s : gems에 있는 모든 보석 종류의 갯수를 구하기 위해 사용
//kinds : 투포인터 범위 내의 보석 종류와 갯수를 구하기 위해 사용

//left~right의 범위에서 모든 보석 종류를 담을 수 있는지 비교
//만약 모든 보석을 담을 수 있다면 해당 범위의 길이가 가장 짧은지 비교 후 answer갱신
//gem를 모두 순회 후 갱신된 answer를 리턴

//set. insert : O(logN)
//map. insert, find, erase : O(logN)
//투포인터 알고리즘 : O(N)
//-> solution의 시간 복잡도 : O(NlogN)정도로 예상

//map,set -> unordered_map으로 자료구조 수정.
//unordered_map의 insert연산은 O(1)이므로 solution의 시간복잡도는 O(N)으로 예상
//->최소 0.95ms, 최대 27.68ms로 속도향상
//-->불필요한 연산 제거 후 최대 19.81ms로 속도향상

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(1);
    answer.push_back(1);
    //gems내의 모든 보석 종류의 갯수를 구하기 위해 s 사용
    unordered_map<string, int> s;
    for (int i = 0; i < gems.size(); i++)
        s[gems[i]]++;
    //gems에 보석의 종류가 1개밖에 없다면 그대로 answer를 리턴
    if (s.size() == 1)
        return answer;
    //투포인터 알고리즘 연산
    //kinds : string 이름의 보석이 int개 만큼 존재
    int left = 0, right = 1;
    unordered_map<string, int> kinds;
    int minDistance = 1e9;
    kinds[gems[0]]++;
    while (right < gems.size()) {
        kinds[gems[right]]++;
        //gems[right]가 gems[left]와 같다면 left의 보석은 제거해도 좋음
        if (gems[right] == gems[left]) {
            kinds[gems[left]]--;
            left++;
        }
        //gems[left]가 gems[left+1]과 같다면 left의 보석은 제거해도 좋음
        while (left < right && gems[left] == gems[left + 1]) {
            kinds[gems[left]]--;
            left++;
        }
        //현재 포인터 범위내 보석의 종류가 전체 보석의 종류와 같다면
        if (kinds.size() == s.size()) {
            //gems[right]가 gems[right - 1]과 같다면 right의 보석은 제거해도 좋음
            /*while (left < right && gems[right] == gems[right - 1]) {
            //    kinds[gems[right]]--;
            //    right--;
            */} // -> 불필요한 연산
            //현재 범위가 minDistance보다 짧다면 answer갱신
            if (right - left < minDistance) {
                minDistance = right - left;
                answer[0] = left + 1;
                answer[1] = right + 1;
            }
            //이후 연산을 지속하기 위해 값을 처리
            kinds[gems[left]]--;
            if (kinds[gems[left]] == 0) {
                kinds.erase(gems[left]);
            }
            left++;
            kinds[gems[right]]--;
            right--;
        }
        right++;
    }
    return answer;
}

int main() {
    vector<int> ret = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
    return 0;
}
