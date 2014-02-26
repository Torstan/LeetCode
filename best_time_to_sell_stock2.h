/*
http://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = (int)prices.size();
        if(n <= 1)
            return 0;
        int s = 0;
        for(int i=1;i<n;i++)
        {
            if(prices[i] > prices[i-1])
                s += prices[i] - prices[i-1];
        }
        return s;
    }
};