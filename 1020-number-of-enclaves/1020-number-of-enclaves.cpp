class Solution
{
    public:
        void dfs(vector<vector < int>> &grid, vector< vector< bool>> &visited, int r, int c)
        {
            if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            {
                return;
            }
            if (visited[r][c] == true)
            {
                return;
            }
            if (grid[r][c] == 0)
            {
                return;
            }
            visited[r][c] = true;
            int dir[4][2] = {
		{ 0,
                    -1 },
                { 0,
                    1 },
                { -1,
                    0 },
                { 1,
                    0 }
            };

            for (int i = 0; i < 4; i++)
            {
                dfs(grid, visited, r + dir[i][0], c + dir[i][1]);
            }
            return;
        }
    int numEnclaves(vector<vector < int>> &grid)
    {
        vector<vector < bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && (i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1))
                {
                    if (visited[i][j] == false)
                    {
                        dfs(grid, visited, i, j);
                    }
                }
            }
        }
        int cntEnclaves = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    cntEnclaves++;
                }
            }
        }
        return cntEnclaves;
    }
};