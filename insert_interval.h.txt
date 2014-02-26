/*
http://oj.leetcode.com/problems/insert-interval/
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

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int n = (int)intervals.size();

        int ids = lower_bound(intervals, newInterval.start);
        int ide = lower_bound(intervals, newInterval.end);
        vector<Interval> res;
        if(ids < 0 && ide < 0)
        {
            res.reserve(n+1);
            res.push_back(newInterval);
            for(int i=0;i<n;i++)
                res.push_back(intervals[i]);
        }
        else
        {
            Interval inv = newInterval;
            for(int i=0; i < ids;i++)
                res.push_back(intervals[i]);
            if(ids < 0)
                ids = 0;
            int merged = 0, i;
            for(i=ids;i<=ide;i++)
            {
                merged = merge_interval(intervals[i], inv);
                if(merged == 0)
                {
                    res.push_back(intervals[i]);
                }
            }
            merged = 0;
            if(ide + 1 < n)
                merged = merge_interval(intervals[ide + 1], inv);
                
            res.push_back(inv); 
            
            if(!merged && ide + 1 < n)
                res.push_back(intervals[ide + 1]);
                
            for(i=ide+2; i<n;i++)
                res.push_back(intervals[i]);
        }
        return res;
    }
private:
    //retuval < 0 || interval[retuval].end < e || (interval[retuval].start <= e && interval[retuval].end >= e)
    int lower_bound(const vector<Interval> &intervals, int e)
    {
        int low = 0;
        int high = (int)intervals.size() - 1;
        while(low <= high)
        {
            int mid = (high + low)/2;
            if(intervals[mid].start <= e && e <= intervals[mid].end)
                return mid;
            else if(intervals[mid].start > e)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;
    }
    //merge intv1 to intv2
    //return 1 for merged, 0 for not
    int merge_interval(const Interval& intv1, Interval& intv2)
    {
        const int& a = intv1.start;
        const int& b = intv1.end;
        int& c = intv2.start;
        int& d = intv2.end;
        if(d < a)
        {
            return 0;
        }
        else if(d == a)
        {
            d = b;
            return 1;
        }
        else if(a >= c && a <= d && b >= d)
        {
            d = b;
            return 1;
        }
        else if(a >= c && b <= d)
        {
            return 1;
        }
        else if(a <= c && d <= b)
        {
            c = a;
            d = b;
            return 1;
        }
        else if(c >= a && c <= b && b <= d)
        {
            c = a;
            return 1;
        }
        else if(b == c)
        {
            c = a;
            return 1;
        }
        else //b < c 
            return 0;
    }
};