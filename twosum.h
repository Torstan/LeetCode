/*
 *http://oj.leetcode.com/problems/two-sum/
 */

#include <algorithm>
class Node
{
public:
    Node(int v=0, int i=0): value(v),id(i){}
    bool operator< (const Node& n) const
    {
        return value < n.value;
    }
    int value;
    int id; //1 based
};


class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int num = (int)numbers.size();
        vector<int> res;
        if(num < 2)
            return res;
            
        vector<Node> arr;
        arr.reserve(num);
        
        for(int i=0;i<num;i++)
        {
            arr.push_back(Node(numbers[i], i));
        }
        std::sort(arr.begin(), arr.end());

        for(int i=0;i<num;i++)
        {
            int s = target - numbers[i];
            vector<Node>::iterator iter = std::lower_bound(arr.begin(), arr.end(), Node(s, 0));
            if(iter != arr.end() && iter->value == s) //found
            {
                if(iter->id == i) //identical element
                {
                    vector<Node>::const_iterator iter2= iter++; //iter pointing to next element 
                    if(iter2 == arr.end() || iter2->value != iter->value)
                        continue;
                }
                int min = i < iter->id ? i : iter->id;
                int max = i > iter->id ? i : iter->id;
                res.push_back(min + 1);
                res.push_back(max + 1);
                return res;
            }
        }
        return res;
    }
};