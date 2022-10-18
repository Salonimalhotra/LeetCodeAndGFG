class Solution
{
    public:
        void dfs(vector<vector < char>> &board, vector< vector< bool>> &visited, int r, int c)
        {
            if (r < 0 || c < 0 || r >= board.size() || c>=board[0].size())
            {
                return;
            }
            if (visited[r][c] == true)
            {
                return;
            }
            if (board[r][c] == 'X')
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
                dfs(board, visited, r + dir[i][0], c + dir[i][1]);
            }
            return;
        }
    void solve(vector<vector < char>> &board)
    {
        vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1))
                {
                    if (visited[i][j] == false)
                    {
                        dfs(board, visited, i, j);
                    }
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O' && visited[i][j]==false) {
                   board[i][j]='X';
                }
            }
        }
      return;
    }
};