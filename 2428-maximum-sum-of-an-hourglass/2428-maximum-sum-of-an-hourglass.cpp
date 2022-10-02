class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
      int maxAns=INT_MIN;
      
      int rows=grid.size();
      int cols=grid[0].size();
       
     for(int i=0;i<rows-2;i++){
       for(int j=0;j<cols-2;j++){
          int sum=grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i+1][j+1] +grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
          maxAns=max(maxAns,sum);
       }
     }
        return maxAns;
    }
};