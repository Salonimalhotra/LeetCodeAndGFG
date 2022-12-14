#include <vector>

class Solution
{
    public:

        int tab(vector<int> nums)
        {
            vector<int> dp(nums.size() + 2, 0);
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
            }
            return dp[0];
        }
    int helper(vector<int> nums, int index, vector<int> &dp)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int option1 = nums[index] + helper(nums, index + 2, dp);
        int option2 = helper(nums, index + 1, dp);
        return dp[index] = max(option1, option2);
    }
    int rob(vector<int> &nums)
    {
       	//         if(nums.size()<=0){
       	//             return 0;
       	//         }
       	//         else if(nums.size()==1){
       	//             return nums[0];
       	//         }
       	//         int prev2=0;
       	//         int prev1=nums[0];
       	//         for(int i=1;i < nums.size();i++){
       	//             int incl=prev2 + nums[i];
       	//             int excl=prev1;
       	//             int ans=max(incl,excl);

       	//             prev2=prev1;
       	//             prev1=ans;
       	//         }
       	//         return prev1;
        // vector<int> dp(nums.size() + 2, -1);
        // return helper(nums, 0, dp);
        return tab(nums);
    }
};