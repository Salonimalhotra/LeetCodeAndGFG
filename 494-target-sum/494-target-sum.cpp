class Solution {
public:
    int helper(vector<int>&nums,int target,int n){
        if(n==0){
            if(target==0){
                return 1;
            }
            return 0;
        }
        
        // we cant consider an option for target==0 as we did in sum problem becoz here we have to consider all elements ,we cant pick a sequence from it.
        int option1=helper(nums,target-nums[n-1],n-1);
        int option2=helper(nums,target+nums[n-1],n-1);
        
        return option1+option2;
        
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
      return helper(nums,target,nums.size());
        
    }
};