class Solution
{
    public:
        int minFallingPathSum(vector<vector < int>> &matrix)
        {
            int rows = matrix.size();
            int cols = matrix[0].size();
          
            // vector<vector < int>> dp(matrix.size(), vector<int> (matrix[0].size()));
           vector<int>prev(cols,0);
           vector<int>curr(cols,0);

            for (int i = 0; i <cols; i++)
            {
                prev[i] = matrix[rows - 1][i];
            }

            for (int i =rows - 2; i >= 0; i--)
            {
                for (int j = cols - 1; j >= 0; j--)
                {
                    int first = INT_MAX;
                    int second = INT_MAX;
                    int third = INT_MAX;
                  
                    first = prev[j];
                    if (j - 1 >= 0)
                    {
                        second =prev[j - 1];
                    }
                    if (j + 1 < cols)
                    {
                        third = prev[j + 1];
                    }
                    curr[j] = matrix[i][j] + min(min(first, second), third);
                }
               prev=curr;
               
            }

            int minAns = INT_MAX;
            for (int j = 0; j < cols; j++)
            {
                minAns = min(minAns, prev[j]);
            }
            return minAns;
        }
};