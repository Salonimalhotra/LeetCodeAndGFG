class Solution
{
    public:
        int dp[601][101][101];
    int helper(int index, vector<string> &strs, int m, int n)
    {
        if (index == strs.size() || (m == 0 && n == 0))
        {
            return 0;
        }

        if (dp[index][m][n] != -1) return dp[index][m][n];

        int cntZeroes = 0;
        int cntOnes = 0;

        for (int i = 0; i < strs[index].size(); i++)
        {
            if (strs[index][i] == '0') cntZeroes++;
            else cntOnes++;
        }

        if (cntZeroes <= m && cntOnes <= n)
        {
            int option1 = 1 + helper(index + 1, strs, m - cntZeroes, n - cntOnes);
            int option2 = helper(index + 1, strs, m, n);
            return dp[index][m][n] = max(option1, option2);
        }
        else
        {
            return dp[index][m][n] = helper(index + 1, strs, m, n);
        }
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        return helper(0, strs, m, n);
    }
};