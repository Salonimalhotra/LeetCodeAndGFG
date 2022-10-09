class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>>&dp){
      if(i>j) return 0;
      
      if(dp[i][j]!=-1) return dp[i][j];
      int maxAns=INT_MIN;
      for(int k=i;k<=j;k++){
           int leftans=solve(nums,i,k-1,dp);
           int rightans=solve(nums,k+1,j,dp);
           int val=nums[k] * nums[i-1] * nums[j+1];
           maxAns=max(maxAns,val + leftans + rightans);
      }
      return dp[i][j]=maxAns;
    }
    int maxCoins(vector<int>& nums) {
       int n=nums.size();
      vector<vector<int>>dp(n+2,vector<int>(n+2,-1));      
       nums.push_back(1);
      nums.insert(nums.begin(),1);
      return solve(nums,1,n,dp);
    }
};