class Solution
{
    public:
        int helper(vector<int> a1, vector<int> b1)
        {
            int x = a1[1] - b1[1];
            int y = a1[0] - b1[0];
            return x *x + y * y;
        }
    int numberOfBoomerangs(vector<vector < int>> &points)
    {
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = 0; j < points.size(); j++)
            {
                if (j != i)
                {
                    int dis = helper(points[i], points[j]);
                    mp[dis]++;
                }
            }
            for (auto it: mp)
            {
                cnt += (it.second) *(it.second - 1);
            }

            mp.clear();
        }

        return cnt;
    }
};