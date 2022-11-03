class Solution
{
    public:
        bool cmp(vector<int> &v1, vector<int> &v2)
        {
            if (v1[0] < v2[0])
            {
                return true;
            }
            else if (v1[0] == v2[0])
            {
                if (v1[1] < v2[1])
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    int removeCoveredIntervals(vector<vector < int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int first = intervals[0][0];
        int second = intervals[0][1];
        int cnt = 1;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][1] <= second)
            {
                continue;
            }
            else if (intervals[i][1] > second)
            {
                if (first == intervals[i][0])
                {
                    second = intervals[i][1];
                    continue;
                }
                first = intervals[i][0];
                second = intervals[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};