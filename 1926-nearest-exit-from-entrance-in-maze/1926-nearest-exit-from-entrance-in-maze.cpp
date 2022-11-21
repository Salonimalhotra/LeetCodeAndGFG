class Solution
{
    public:
        bool border(vector<vector < char>> &maze, int row, int col)
        {
            if ((row == 0) || (row == maze.size() - 1))
            {
                return true;
            }
            if ((col == 0) || (col == maze[0].size() - 1))
            {
                return true;
            }
            return false;
        }
    int nearestExit(vector<vector < char>> &maze, vector< int > &entrance)
    {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector < bool>> vis(m, vector<bool> (n, false));
        queue<pair<pair<int, int>, int>> q;
        q.push(make_pair(make_pair(entrance[0], entrance[1]), 0));
        vis[entrance[0]][entrance[1]] = true;
        while (q.size() != 0)
        {
            pair<pair<int, int>, int> top = q.front();
            q.pop();
            int x = top.first.first;
            int y = top.first.second;
            int steps = top.second;

            if (border(maze, x, y) == true && !(x == entrance[0] && y == entrance[1]))
            {
                return steps;
            }
            if(maze[x][y]=='+'){
              vis[x][y]=true;
              continue;
            }
           	// right down up left
            int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
          
            for (int i = 0; i < 4; i++)
            {
                int xi = x + dir[i][0];
                int yi = y + dir[i][1];
                if (xi < 0 || yi < 0 || xi >= m || yi >= n || vis[xi][yi] == true || maze[xi][yi] == '+')
                {
                    continue;
                }

                vis[xi][yi] = true;
                q.push(make_pair(make_pair(xi, yi), steps + 1));
            }
        }
        return -1;
    }
};