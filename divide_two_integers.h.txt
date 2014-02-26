/*
http://oj.leetcode.com/problems/divide-two-integers/
*/
#include <limites.h>
#include <stdint.h>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return INT_MAX;
          
        int64_t res = 0, rem = 0; 
        divide_positive(dividend >= 0 ? dividend : negative(dividend), divisor > 0 ? divisor : negative(divisor), res, rem);
        if((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0))
            return (int)res;
        else
            return (int)negative(res);
    }
    
    int divide_positive(int64_t dividend, int64_t divisor, int64_t& res, int64_t& rem)
    {
        if(dividend == 0)
        {
            res = 0;
            rem = 0;
            return 0;
        }
        int64_t rs = 0, rm = 0;
        divide_positive(dividend>>1, divisor, rs, rm);
        res = rs + rs;
        rem = rm + rm;
        if(dividend & 0x1)
        {
            rem += 1;
        }
        if(rem >= divisor)
        {
            rem -= divisor;
            res += 1;
        }
        return 0;
    }
    
    int64_t negative(int64_t n)
    {
        return 0-n;
    }
};