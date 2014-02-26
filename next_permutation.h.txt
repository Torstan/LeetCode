/*
http://oj.leetcode.com/problems/next-permutation/
*/
#include <algorithm>

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = (int)num.size();
        if(n <= 1)
            return ;
        
        int i = 0, j = 0, max = -100000;
        for(j=n-1;j>=0;j--)
        {
            if(max > num[j])
                break;
            max = num[j];
        }
        if(j < 0)
        {
            std::sort(num.begin(), num.end());
            return;
        }

        int min = 100000, mini = 0;
        for(int i=n-1;i>j;i--)
        {
            if(num[i] > num[j])
            {
                if(num[i] < min)
                {
                    min = num[i];
                    mini = i;
                }
            }
        }
        std::swap(num[mini], num[j]);
        std::sort(num.begin()+j+1, num.end()); 
    }
};