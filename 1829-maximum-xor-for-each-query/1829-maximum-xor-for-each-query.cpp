class Solution
{
    public:
        vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
        {
            vector<int> ans;
            int n = nums.size();
            vector<int> prefix(nums.size(), 0);
            prefix[0] = nums[0];
            for (int i = 1; i < nums.size(); i++)
            {
                prefix[i] = prefix[i - 1] ^ nums[i];
            }

            for (int i = nums.size() - 1; i >= 0; i--)
            {
                int num = prefix[i];
                int element = 0;
                for (int j = 0; j < maximumBit; j++)
                {
                    int mask = (1 << j);
                    if ((num & mask) == 0) element = element | mask;
                }

                ans.push_back(element);
            }

            return ans;
        }
};