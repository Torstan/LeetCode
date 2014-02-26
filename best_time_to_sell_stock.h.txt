/*
http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/
#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    int n = (int)prices.size();
    if(n <= 1)
        return 0;
        
    vector<int> profit(n-1, 0);
    for(int i=1;i<n;i++)
        profit[i-1] = prices[i] - prices[i-1];
    
    int max_profit = 0;
    int prev = 0;
    for(int i=0;i<n-1;i++)
    {
        int prof = prev > 0 ? profit[i] + prev : profit[i];
        prev = prof;
        if(max_profit < prof)
        {
            max_profit = prof;
        }
    }
    return max_profit;
    }
};

