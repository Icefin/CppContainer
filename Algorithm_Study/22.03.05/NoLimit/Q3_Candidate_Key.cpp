//0.01ms ~ 1.20ms

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> attribute[8];
vector<int> counted;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    //attribute의 갯수
    int att_Cnt = relation[0].size();
    //relation의 갯수
    int rel_Cnt = relation.size();
    //각 attribute별로 분류하여 저장
    for (int i = 0; i < relation.size(); i++) {
        for (int j = 0; j < relation[0].size(); j++) {
            attribute[j].push_back(relation[i][j]);
        }
    }
    //combination을 사용하여 후보키 판별
    for (int i = 1; i <= att_Cnt; i++) {
        //combination을 만들 comb배열
        vector<int> comb = {};
        for (int cnt = 0; cnt < i; cnt++) comb.push_back(1);
        for (int cnt = 0; cnt < att_Cnt - i; cnt++) comb.push_back(0);

        do {
            //유일성을 검사할 배열과 집합, cnt
            vector<string> singular(rel_Cnt);
            set<string> s_singular;
            int cnt = 0;
            //조합에 속한 attribute로 새로운 key값을 만듦
            //이 때 사용된 attribute의 번호는 최소성 검사를 위해 cnt에 비트로 저장
            for (int j = 0; j < att_Cnt; j++) {
                if (comb[j] == 1) {
                    for (int k = 0; k < rel_Cnt; k++) {
                        singular[k] += attribute[j][k];
                    }
                    cnt += (1 << j);
                }
            }
            //만들어진 key값을 set에 넣어 유일성 검사
            for (int j = 0; j < rel_Cnt; j++) s_singular.insert(singular[j]);
            //cnt값을 이용하여 최소성 검사
            bool isCounted = false;
            for (int i = 0; i < counted.size(); i++) {
                if ((cnt & counted[i]) == counted[i]) {
                    isCounted = true;
                    break;
                }
            }
            //유일성과 최소성을 모두 통과하면 answer++
            if (s_singular.size() == rel_Cnt && !isCounted) {
                answer++;
                counted.push_back(cnt);
            }
        } while (prev_permutation(comb.begin(), comb.end()));
    }

    return answer;
}