/*
problem: https://oj.leetcode.com/problems/find-minimum-in-rotated-sorted-array/
author: Torstan
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int sz = (int)num.size();
        if(sz < 1)
            return -1;
        return binary_search_min(&num[0], 0, sz - 1);
    }   
private:
    int binary_search_min(const int* arr, int low, int high)
    {
        if(arr == NULL || low < 0 || low > high)
            return -1;
        //only one element
        if(low == high)
            return arr[low];
        //only two elements
        if(high == low + 1)
        {
            return arr[low] < arr[high] ? arr[low] : arr[high];
        }
        //>=3 elements
        //sorted
        int mid = (low + high)/2;
        if(arr[low] < arr[mid] && arr[mid] < arr[high])
            return arr[low];

        if(arr[mid] < arr[low])
            return binary_search_min(arr, low + 1, mid); 

        return binary_search_min(arr, mid + 1, high);
    }
};