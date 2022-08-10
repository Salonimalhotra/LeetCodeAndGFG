class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
          vector<int>dp(nums.size(),1);
        int maxlen=1;
        for(int i=1;i<nums.size();i++){
                if(nums[i]>nums[i-1] && dp[i] <dp[i-1]+1){
                    dp[i]=dp[i-1]+1;
                    maxlen=max(dp[i],maxlen);
                }
            
        }
     return maxlen;
    }
};