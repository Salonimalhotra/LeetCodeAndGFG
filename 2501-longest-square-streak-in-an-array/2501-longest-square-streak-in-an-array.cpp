class Solution
{
    public:
        int index(vector<int> &nums, int start, int end, int element)
        {
            while (start <= end)
            {
                int mid = (start + (end - start) / 2);
    
                if (((long) nums[mid] *nums[mid]) == element)
                {
                    return mid;
                }
                else if (((long) nums[mid] *nums[mid]) < element)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            return -1;
        }
    int longestSquareStreak(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        int maxAns = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int in = index(nums, 0, i - 1, nums[i]);
            if (in != -1)
            {
                dp[i] = dp[ in ] + 1;
            }
            if (dp[i] != 1)
            {
                maxAns = max(maxAns, dp[i]);
            }
        }
        return maxAns;
    }
};