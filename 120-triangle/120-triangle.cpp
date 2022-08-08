class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        int cols=triangle[rows-1].size();
        int **dp=new int*[rows];
        for(int i=0;i<rows;i++){
            dp[i]=new int[cols];
            for(int j=0;j<cols;j++){
                dp[i][j]=INT_MAX;
            }
        }
        
        for(int j=0;j<cols;j++){
            dp[rows-1][j]=triangle[rows-1][j];
        }
        
        int col=cols-1;
        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<col;j++){
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]) + triangle[i][j];
            }
            col--;
        }
        
        return dp[0][0];
        
    }
};