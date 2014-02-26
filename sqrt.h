/*
http://oj.leetcode.com/problems/sqrtx/
*/
#include <stdint.h>

class Solution {
public:
    int sqrt(int x) {
        if(x <= 1)
            return x;
        int64_t low = 1;
        int64_t high = x;
        int64_t mid = low + (high - low)/2;
        while(low <= high)
        {
            int64_t s1 = mid * mid; 
            int64_t s2 = (mid + 1) * (mid + 1);
            if (s1 <= x && x < s2)
            {
                return (int)mid;
            }
            if(s1 > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
            mid = low + (high - low)/2;
        }
        return 0;
    }

};