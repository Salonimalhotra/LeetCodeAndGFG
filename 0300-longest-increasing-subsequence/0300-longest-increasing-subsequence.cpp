class Solution
{
    public:
        int helper(vector<int> &nums, int curr, int prev, vector<vector< int>> &dp)
        {
            if (curr == nums.size())
            {
                return 0;
            }
            if (dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

            int option1 = 0;
            int option2 = 0;

           	//not take waala case
            option2 = helper(nums, curr + 1, prev, dp);

            if (prev == -1 || nums[curr] > nums[prev])
            {
               	// take waala case can only happen when there is no element in the sequence or the curr element is smaller then the element at previous index
                option1 = 1 + helper(nums, curr + 1, curr,dp);
            }

            return dp[curr][prev + 1] = max(option1, option2);
        }
    int lengthOfLIS(vector<int> &nums)
    {

        vector<vector < int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        return helper(nums, 0, -1, dp);
    }
};