/*
http://oj.leetcode.com/problems/max-points-on-a-line/
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 #include <map>
 using std::map;
 //ax+by=c
 //when c=0, gcd(a, b) = 1, a >= 0 || (a==0 && b>0)
 //otherwise d=gcd(a, b), gcd(d, c) = 1, a >= 0 || (a==0 && b>0)
class Line
{
public:
    Line(int x, int y, int z) : a(x), b(y), c(z) {}
    bool operator< (const Line ln) const
    {
        if((a < ln.a) || (a == ln.a && b < ln.b) || (a == ln.a && b == ln.b && c < ln.c))
            return true;
        else
            return false;
    }
    bool on_line(int x, int y) const
    {
        int64_t s = (int64_t)a * x + (int64_t)b* y - (int64_t)c;
        return s == 0 ? true : false;
    }
    int a;
    int b;
    int c;
};

//suppose both a and b are positive
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int abs_int(int x)
{
    return x>=0 ? x : -x;
}

int sign_int(int x)
{
    return x > 0 ? 1 : (x == 0 ? 0 : -1);
}

 //return -1 if p and q are duplicated
 //otherwise return 0 for success
int compute_line_param(const Point&p, const Point& q, Line& line)
{
    if(p.x == q.x && p.y == q.y)
        return -1;
    
    line.a = line.b = line.c = 0;
    int delta = p.x * q.y - p.y * q.x; //TODO, int64_t
    if(delta == 0)
    {
        int x = p.x;
        int y = p.y;
        if(x == 0 && y == 0 )
        {
            x = q.x;
            y = q.y;
        }
        int d = gcd(abs_int(x), abs_int(y));
        int x0 = x/d;
        int y0 = y/d;
        line.c = 0;
        line.a = abs_int(y0);
        line.b = -1*sign_int(y0)*x0;
        if(line.a == 0)
            line.b = 1;
    }
    else
    {
        int a = q.y - p.y;
        int b = p.x - q.x;
        int c = delta;
        int d = gcd(abs_int(a), abs_int(b));
        d = gcd(d, abs_int(c));
        if(a == 0)
        {
            line.a = 0;
            line.b = abs_int(b/d);
            line.c = sign_int(b/d)*c/d;
        }
        else
        {
            line.a = abs_int(a/d);
            line.b = sign_int(a/d) * b/d;
            line.c = sign_int(a/d) * c/d;
        }
    }
    return 0;
}

class Epoint
{
public:
    Epoint(int xx=0, int yy=0) : x(xx), y(yy) {}
    Epoint(const Epoint& p)
    {
        x = p.x;
        y = p.y;        
    }
    Epoint(const Point& p)
    {
        x = p.x;
        y = p.y;
    }
    bool operator < (const Epoint& p) const
    {
        return (x<p.x || x==p.x && y<p.y )? true : false;
    }
    int x;
    int y;
};
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int num = (int)points.size();
        if(num <= 1)
        {
            return num;
        }
        
        map<Line, int> line_acc;
        vector<Point> pre_points;
        vector<int> count;
        preprocess(points, pre_points, count);
        num = (int)pre_points.size();
        for(int i=0;i<num;i++)
        for(int j=i+1;j<num;j++)
        {
            //find a new line
            const Point& p = pre_points[i];
            const Point& q = pre_points[j];
            Line line(0, 0, 0);
            if(compute_line_param(p, q, line) != 0)
                continue;
             
            if(line_acc.find(line) != line_acc.end()) //statistic before
                continue;
            //stat the number of points on this line    
            int cnt = 0;
            for(int k=0;k<num;k++)
            {
                if(line.on_line(pre_points[k].x, pre_points[k].y))
                    cnt += count[k];
            }
            line_acc[line] = cnt;
        }
        
        int maxn = -1;
        if(!line_acc.empty())
        {
            map<Line, int>::const_iterator iter = line_acc.begin();
            for(;iter!=line_acc.end();iter++)
            {
                if(maxn < iter->second)
                    maxn = iter->second;
            }
        }
        else
        {
            int n = (int)count.size();
            for(int i=0;i<n;i++)
            {
                if(count[i] > maxn)
                    maxn = count[i];
            }
            
        }
        return maxn;
    }
private:
    void preprocess(const vector<Point> &points, vector<Point> &pre_points, vector<int>& count)
    {
        map<Epoint, int> prep;
        int num = (int)points.size();
        for(int i=0;i<num;i++)
        {
            Epoint e(points[i]);
            prep[e]++;
        }
        count.clear();
        pre_points.clear();
        int n = (int)prep.size();
        pre_points.reserve(n);
        count.reserve(n);
        map<Epoint, int>::const_iterator iter = prep.begin();
        for(;iter!=prep.end();iter++)
        {
            pre_points.push_back(Point(iter->first.x, iter->first.y));
            count.push_back(iter->second);
        }
    }
};