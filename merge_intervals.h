/*
http://oj.leetcode.com/problems/merge-intervals/
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class LessThan
{
public:
    bool operator()(const Interval& i1, const Interval& i2)
    {
        return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);
    }
};
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        int n = (int)intervals.size();
        if(n <= 0)
            return res;
        std::sort(intervals.begin(), intervals.end(), LessThan());
        Interval mr = intervals[0];
        for(int i=1;i<n;i++)
        {
            if(mr.end < intervals[i].start)
            {
                res.push_back(mr);
                mr = intervals[i];
            }
            else if(mr.end >= intervals[i].end)
            {
                
            }
            else
            {
                mr.end = intervals[i].end;
            }
        }
        res.push_back(mr);
        return res;
    }
};