class Solution {
public:
    int countSubsetSum(vector<int>& nums, int subsetSum){
        int n =nums.size();
        int ** dp=new int*[nums.size()+1];
        for(int i=0;i<=nums.size();i++){
            dp[i]=new int[subsetSum+1];
        }
        
       for(int i=0;i<=nums.size();i++){
            dp[i][0]=1;
        }
        for(int j=1;j<=subsetSum;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=subsetSum;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][subsetSum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        if(target>totalSum){
            return 0;
        }
        int subset_Sum=(totalSum+target)/2;
        if(subset_Sum<0 ||(totalSum+target)%2!=0){
           return 0;
        }
        int ans=countSubsetSum(nums,subset_Sum);
        return ans;
    }
};