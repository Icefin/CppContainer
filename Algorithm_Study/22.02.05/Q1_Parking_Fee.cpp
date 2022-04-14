/*
* problem : Parking Fee (https://programmers.co.kr/learn/courses/30/lessons/92341)
* 주차장의 요금표와 입출차 기록이 주어질 때 차량 번호가 작은 차부터 차량별 주차 요금을 계산하여 리턴
*
* 최소 0.03ms / 3.7MB의 성능
* 최대 0.64ms / 4.33MB의 성능
*/
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
//차량 정보를 저장하는 구조체 선언
struct Car {
    int in_Time = 0;
    float duration = 0;
    bool isOut = true;
};
//index의 차량 번호를 가지는 Car배열 ex) 0912번 차량 -> cars[912]
Car cars[10000];

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    //입력 포멧이 일정하므로 stringstream등의 파싱없이 문자열 처리
    //입-출차 여부와 차량 번호를 기준으로 정보를 처리
    for (int i = 0; i < records.size(); i++) {
        string inOut = records[i].substr(11);
        int carNum = stoi(records[i].substr(6, 4));
        //(1)입차의 경우
        if (inOut == "IN") {
            int inTime = (stoi(records[i].substr(0, 2)) * 60) + stoi(records[i].substr(3, 2));
            cars[carNum].in_Time = inTime;
            cars[carNum].isOut = false;
        }
        //(2)출차의 경우
        else if (inOut == "OUT") {
            int outTime = (stoi(records[i].substr(0, 2)) * 60) + stoi(records[i].substr(3, 2));
            cars[carNum].duration += outTime - cars[carNum].in_Time;
            cars[carNum].isOut = true;
        }
    }
    //0000번 차량부터 9999번 차량까지 차량을 주차했던 기록이 있거나
    //출차하지 않은 차량들에 대해서 주차요금 정산
    for (int i = 0; i < 10000; i++) {
        if (cars[i].duration > 0 || !cars[i].isOut) {
            if (!cars[i].isOut) {
                cars[i].duration += 1439 - cars[i].in_Time;
            }
            int fee = 0;
            if (cars[i].duration <= fees[0]) {
                fee = fees[1];
            }
            else if (cars[i].duration > fees[0]) {
                fee = fees[1] + fees[3] * ceil((cars[i].duration - fees[0]) / fees[2]);
            }
            answer.push_back(fee);
        }
    }
    return answer;
}


int main() {
    vector<int> ret = solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT",
        "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }
    return 0;
}