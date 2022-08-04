class Solution {
public:
    int solve(vector<int>arr){
        vector<int>dp(arr.size(),-1);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            dp[i]=max(dp[i-1],arr[i] + dp[i-2]);
        }
        return dp[arr.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                arr2.push_back(nums[i]);
            }
            else if(i==nums.size()-1){
                arr1.push_back(nums[i]);
            }
            else{
                 arr2.push_back(nums[i]);
                 arr1.push_back(nums[i]);                
            }
        }
        
        return max(solve(arr1),solve(arr2));        
        
    }
};