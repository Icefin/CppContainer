/*
* Problem : 올바른 괄호 (https://programmers.co.kr/learn/courses/30/lessons/12909)
*'(' 또는 ')' 로만 이루어진 문자열 s가 주어졌을 때,
*문자열 s가 올바른 괄호이면 true를 return 하고, 
*올바르지 않은 괄호이면 false를 return
* 올바른 괄호 : (로 열려서 )로 닫히는 괄호
* 
* stack을 이용하거나 cnt를 이용하거나...
*/

#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    //stack대신 cnt를 이용해서 쌓이는 괄호 표시
    int cnt = 0;
    //문자열의 처음부터 끝까지 순회
    for (int index = 0; index < s.length(); index++)
    {
        //만약 '(' 라면 스택에 push하는 것 처럼 cnt++
        if (s[index] == '(') cnt++;
        else
        {
            //cnt가 0인데 ')'가 온다면 올바르지 않은 괄호
            if (cnt == 0) return false;
            //')'가 왔다면 스택을 pop하는 것 처럼 cnt--
            cnt--;
        }
    }
    //남은 괄호가 없다면 true, 남은 괄호가 있다면 false
    return cnt == 0;
}