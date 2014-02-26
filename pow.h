/*
http://oj.leetcode.com/problems/powx-n/
*/
class Solution {
public:
    double pow(double x, int n) {
        return power_(x, n);
    }
private:
    double power_(double x, int64_t n)
    {
        if(n < 0)
            return 1.0/power_(x, -n);
        if(n == 0)
            return 1.0;
        
        double d = power_(x, n/2);
        if(n%2 == 1)
            return d*d*x;
        else
            return d*d;
    }
};