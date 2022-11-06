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
            int i = 0;
            int j = 0;
            int ans = 0;
            int window = 0;
            while (j < nums.size())
            {

                if (nums[j] >= left && nums[j] <= right)
                {
                    window = j - i + 1;
                }
                else if (nums[j] > right)
                {
                    window = 0;
                    i = j + 1;
                }
                j++;
                ans += window;
            }
          return ans;
        }
};