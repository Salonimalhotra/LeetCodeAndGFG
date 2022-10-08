class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            pair<int, int> ans;
            ans.first = INT_MAX;
            ans.second = INT_MIN;
            for (int i = 0; i < nums.size() - 2; i++)
            {
                int j = i + 1;
                int k = nums.size() - 1;
                int x = target - nums[i];
                while (j < k)
                {
                    if (nums[j] + nums[k] == x)
                    {
                        return nums[i] + nums[j] + nums[k];
                    }
                    else if (nums[j] + nums[k] < x)
                    {
                        if (abs(target - (nums[i] + nums[j] + nums[k])) < ans.first)
                        {
                            ans.first = abs(target - (nums[i] + nums[j] + nums[k])); ans.second = nums[i] + nums[j] + nums[k];
                            }
                            j++;
                        }
                        else if (nums[j] + nums[k] > x)
                        {
                            if (abs(target - (nums[i] + nums[j] + nums[k])) < ans.first)
                            {
                                ans.first = abs(target - (nums[i] + nums[j] + nums[k])); ans.second = nums[i] + nums[j] + nums[k];
                                }
                                k--;
                            }
                        }
                    }
                                                return ans.second;
                }
            };