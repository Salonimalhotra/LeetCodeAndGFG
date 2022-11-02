class Solution
{
    public:
        int helper(vector<vector < int>> &grid, int row, int col, int x, int y)
        {
            if (x > row)
            {
                return y;
            }
            if (grid[x][y] == 1)
            {
                int nextCol = y + 1;
                if (nextCol <= col && grid[x][y] == grid[x][nextCol])
                {
                    return helper(grid, row, col, x + 1, nextCol);
                }
                else
                {
                    return -1;
                }
            }

            if (grid[x][y] == -1)
            {
                int prevCol = y - 1;
                if (prevCol >= 0 && grid[x][y] == grid[x][prevCol])
                {
                    return helper(grid, row, col, x + 1, prevCol);
                }
                else
                {
                    return -1;
                }
            }
            return -1;
        }
    vector<int> findBall(vector<vector < int>> &grid)
    {
        vector<int> ans;
        int row = grid.size();
        int col = grid[0].size();
        for (int j = 0; j < col; j++)
        {
            int smallans = helper(grid, row - 1, col - 1, 0, j);
            ans.push_back(smallans);
        }
        return ans;
    }
};