class Solution
{
    public:
        void helper(int element, int rows, int cols, int x, int y, vector<vector < int>> &matrix, bool &check)
        {
            if (x < 0 || y < 0 || x >= rows || y >= cols)
            {
                return;
            }
            if (matrix[x][y] != element)
            {
                check = false;
                return;
            }

            helper(element, rows, cols, x + 1, y + 1, matrix, check);
            return;
        }
    bool isToeplitzMatrix(vector<vector < int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                bool check = true;
                helper(matrix[i][j], rows, cols, i + 1, j + 1, matrix, check);
                if (check == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};