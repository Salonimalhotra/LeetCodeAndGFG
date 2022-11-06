class Solution
{
    public:
        int numSubarrayBoundedMax(vector<int> &nums, int left, int right)
        {
           	//             int numsAns = 0;

           	//             for (int i = 0; i < nums.size(); i++)
           	//             {

           	//                 int maxElement = INT_MIN;
           	//                 for (int j = i; j < nums.size(); j++)
           	//                 {
           	//                     maxElement = max(maxElement, nums[j]);
           	//                     if (maxElement >= left && maxElement <= right)
           	//                     {
           	//                         cout << maxElement << endl;
           	//                         numsAns++;
           	//                     }
           	//                 }
           	//             }
           	//             return numsAns;
            int n = nums.size();
            int ans = 0;
            int l = 0;
            int r = 0;
            int window = 0;
            while (r < n)
            {
                if (nums[r] >= left && nums[r] <= right)
                {
                    window = r - l + 1;
                }
                else if (nums[r] > right)
                {
                    window = 0;
                    l = r + 1;
                }

                ans += window;	// since whatever previously valid windows were present, we can add this to each of those windows
                r += 1;
            }
            return ans;
        }
};