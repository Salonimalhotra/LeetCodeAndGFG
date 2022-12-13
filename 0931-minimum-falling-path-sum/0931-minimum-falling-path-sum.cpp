class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix[0].size();
          
            vector<vector < int>> dp(matrix.size(), vector<int> (matrix[0].size()));

            for (int i = 0; i < matrix[0].size(); i++)
            {
                dp[rows - 1][i] = matrix[rows - 1][i];
            }

            for (int i =rows - 2; i >= 0; i--)
            {
                for (int j = cols - 1; j >= 0; j--)
                {
                    int first = INT_MAX;
                    int second = INT_MAX;
                    int third = INT_MAX;
                  
                    first = dp[i + 1][j];
                    if (j - 1 >= 0)
                    {
                        second = dp[i + 1][j - 1];
                    }
                    if (j + 1 < cols)
                    {
                        third = dp[i + 1][j + 1];
                    }
                    dp[i][j] = matrix[i][j] + min(min(first, second), third);
                }
            }

            int minAns = INT_MAX;
            for (int j = 0; j < cols; j++)
            {
                minAns = min(minAns, dp[0][j]);
            }
            return minAns;
        }
};