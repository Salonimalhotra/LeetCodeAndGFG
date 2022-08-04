class Solution {
public:
    int helperDP(vector<vector<char>>&matrix,int &maxi){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
       for(int i=n-1;i>=0;i--){
           for(int j=m-1;j>=0;j--){
               if(matrix[i][j]=='1'){
                   dp[i][j]=1 + min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                   maxi=max(maxi,dp[i][j]);
               }
               else{
                   dp[i][j]=0;
               }
           }
       }
        return dp[0][0];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
         int maxi=0;
         int smallAns=helperDP(matrix,maxi);
        return maxi * maxi;
    }
};