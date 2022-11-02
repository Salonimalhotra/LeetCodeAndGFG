class Solution
{
    public:
        int maxOperations(vector<int> &nums, int k)
        {
            unordered_map<int, int> mp;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                mp[nums[i]]++;
                if (nums[i] == (k - nums[i]))
                {
                    if (mp[nums[i]] >= 2)
                    {
                        cnt++;
                        mp[k - nums[i]]--;
                        mp[nums[i]]--;
                    }
                }
                else if (mp.find(k - nums[i]) != mp.end() && mp[k - nums[i]] > 0)
                {
                    cnt++;
                    mp[k - nums[i]]--;
                    mp[nums[i]]--;
                }
            }
            return cnt++;
        }
};