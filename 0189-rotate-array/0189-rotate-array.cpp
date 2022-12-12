class Solution
{
    public:
        void rotate(vector<int> &nums, int k)
        {
            vector<int> helper(nums.size(), 0);
            for (int i = 0; i < nums.size(); i++)
            {
                helper[(i + k) % nums.size()] = nums[i];
            }
            nums = helper;
            return;
        }
};