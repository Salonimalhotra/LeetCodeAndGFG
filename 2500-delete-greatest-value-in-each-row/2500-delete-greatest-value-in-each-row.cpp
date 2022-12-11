class Solution
{
    public:
        int deleteGreatestValue(vector<vector < int>> &grid)
        {
            int rows = grid.size();
            int cols = grid[0].size() - 1;
          
            for (int i = 0; i < rows; i++)
            {
                sort(grid[i].begin(), grid[i].end());
            }
            int totalAns = 0;
            while (cols != -1)
            {
                int maxValue = INT_MIN;
                for (int i = 0; i < rows; i++)
                {
                    maxValue = max(maxValue, grid[i][cols]);
                }
                totalAns += maxValue;
                cols--;
            }
            return totalAns;
        }
};