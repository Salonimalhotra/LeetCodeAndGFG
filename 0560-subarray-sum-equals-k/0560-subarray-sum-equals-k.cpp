class Solution
{
    public:
        int subarraySum(vector<int> &nums, int k)
        {
            int cnt = 0;
            unordered_map<int, int> mp;
            int prefixsum = 0;
            mp[0] = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                prefixsum += nums[i];
                if (mp.find(prefixsum - k) != mp.end())
                {
                    cnt += mp[prefixsum - k];
                }
                mp[prefixsum]++;
            }
          return cnt;
        }
};