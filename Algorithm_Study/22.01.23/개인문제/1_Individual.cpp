/*
* Problem : Best Time to Buy and Sell Stock (https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
* i번째 날의 주식 금액 prices[]가 주어질 때,
* 매수 금액과 매도 금액 차이의 최댓값을 반환하는 함수
* 매수는 매도보다 먼저 이루어져야 함
* 
* 1. 단순 탐색 O(n^2)
* for(int i = 0...) {for(for j = i+1...) //}
* 
* 2. 최소금액, 최대차액 추적 O(n)
*/

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        //최소금액과 최대차액을 추적할 변수 선언
        int minPrice = 1e4;
        int maxProfit = 0;
        //prices의 모든 금액을 순회
        for (int i = 0; i < prices.size(); i++)
        {
            //현재 금액이 최소 금액보다 작으면 최소금액 갱신
            if (prices[i] < minPrice)
                minPrice = prices[i];
            //현재 금액과 최소 금액의 차액이 최대차액보다 크다면 최대차액 갱신
            else if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};