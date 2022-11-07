class Solution
{
    public:
        void helper(vector<vector < int>> &grid, vector< vector< bool>> &visited, int i, int j, int &cnt)
        {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
            {
                return;
            }
            if (visited[i][j] == true || grid[i][j] == 0)
            {
                return;
            }

            cnt++;
            visited[i][j] = true;

            int dir[4][2] = {
		{ 0,
                    1 },
                { 0,
                    -1 },
                { 1,
                    0 },
                { -1,
                    0 }
            };
            for (int k = 0; k < 4; k++)
            {
                int xi = i + dir[k][0];
                int yi = j + dir[k][1];
                helper(grid, visited, xi, yi, cnt);
            }
            return;
        }
    int maxAreaOfIsland(vector<vector < int>> &grid)
    {
        int maxAns = 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector < bool>> visited(r, vector<bool> (c, false));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if (grid[i][j] == 1 && visited[i][j] == false)
                {
                    int cnt = 0;
                    helper(grid,visited,i,j,cnt);
                    maxAns=max(maxAns,cnt);
                }
            }
        }
      return maxAns;
    }
};