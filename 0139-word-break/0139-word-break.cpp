class Solution
{
    public:
        int helper(string s, unordered_map<string, int> &mp, int i, int j, vector<vector< int>> &dp)
        {
            if (i > j) return false;

            if (mp.find(s.substr(i, j - i + 1)) != mp.end())
            {
                return true;
            }

            if (dp[i][j] != -1) return dp[i][j];

            for (int k = i; k <= j - 1; k++)
            {
                int leftans;
                if (dp[i][k] != -1) leftans = dp[i][k];
                else
                {
                    leftans = helper(s, mp, i, k, dp);
                }
              
                int rightans;
                if (dp[k + 1][j] != -1) rightans = dp[k + 1][j];
                else
                {
                    rightans = helper(s, mp, k + 1, j, dp);
                }

                if (leftans == 1 && rightans == 1) return dp[i][j] = 1;
            }
            return dp[i][j] = 0;
        }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        
        unordered_map<string, int> mp;
        for (auto i: wordDict)
        {
            mp[i]++;
        }
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return helper(s, mp, 0, s.size() - 1, dp);
    }
};