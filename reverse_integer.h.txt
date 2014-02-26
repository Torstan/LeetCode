/*
http://oj.leetcode.com/problems/reverse-integer/
*/
#include <stdint.h>
#include <limits.h>
class Solution {
public:
    int reverse(int x) {
        int64_t y;
        reverse(x, y);
        return (int)y;
    }
    void reverse(int64_t x, int64_t& y)
    {
        int sign = x >= 0 ? 1 : -1;
        if(x < 0)
            x = -x;
        y = 0;
        while(x > 0)
        {
            int last = x%10;
            x = x/10;
            y = y*10 + last;
        }
        y *= sign;
    }
};