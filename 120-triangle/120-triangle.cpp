class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        int cols=triangle[rows-1].size();
        // int **dp=new int*[rows];
        // for(int i=0;i<rows;i++){
        //     dp[i]=new int[cols];
        //     for(int j=0;j<cols;j++){
        //         dp[i][j]=INT_MAX;
        //     }
        // }
        vector<int>prev(cols,0);
        vector<int>curr(cols,0);
        
        
        for(int j=0;j<cols;j++){
            prev[j]=triangle[rows-1][j];
        }
        
        int col=cols-1;
        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<col;j++){
                curr[j]=min(prev[j],prev[j+1]) + triangle[i][j];
            }
            prev=curr;
            col--;
        }
        
        return prev[0];
        
    }
};