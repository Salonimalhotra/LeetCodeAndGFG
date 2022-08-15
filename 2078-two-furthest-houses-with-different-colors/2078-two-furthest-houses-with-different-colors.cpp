class Solution {
public:
    int solve(vector<int>colors,int start,int end,vector<vector<int>>&dp){
        if(start>end){
            return INT_MIN;
        }
        
       
        
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
       if(colors[start]!=colors[end]){
            return dp[start][end]=end-start;
        }
        
        int option1=solve(colors,start+1,end,dp);
        int option2=solve(colors,start,end-1,dp);
        return dp[start][end]= max(option1,option2);        
    }
    int maxDistance(vector<int>& colors) {
        vector<vector<int>>dp(colors.size()+1,vector<int>(colors.size()+1,-1));
        return solve(colors,0,colors.size()-1,dp);
    }
};