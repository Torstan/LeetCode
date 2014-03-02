/*
problem: http://oj.leetcode.com/problems/container-with-most-water/
*/

#include <stack>
using std::stack;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        int left = 0;
        int right = (int)height.size() - 1;
        while(left < right)
        {
            max_area = std::max(max_area, (right - left) * std::min(height[left], height[right]));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};