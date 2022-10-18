class Solution
{
    public:
        int orangesRotting(vector<vector < int>> &grid)
        {
            int timer = 0;
            queue<pair<int, int>> q;
            int rows = grid.size();
            int cols = grid[0].size();
            vector<vector < bool>> visited(rows, vector<bool> (cols, false));
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (grid[i][j] == 2)
                    {
                        q.push(make_pair(i, j));
                        visited[i][j] = true;
                    }
                }
            }

            while (q.size() != 0)
            {
                int s = q.size();
                bool check=false;
                while (s--)
                {
                    pair<int, int> top = q.front();
                    q.pop();

                    int dir[4][2] = {
		{ 0,
                            -1 },
                        { 0,
                            1 },
                        { 1,
                            0 },
                        { -1,
                            0 }
                    };
                    for (int i = 0; i < 4; i++)
                    {
                        int x = top.first + dir[i][0];
                        int y = top.second + dir[i][1];
                        if (x >= 0 && y >= 0 && x < rows && y < cols && visited[x][y] != true && grid[x][y] == 1)
                        {
                            check=true;
                            q.push(make_pair(x, y));
                            grid[x][y] = 2;
                            visited[x][y] = true;
                        }
                    }
                }
                if(check==true)timer++;
            }

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        return -1;
                    }
                }
            }
            return timer;
        }
};