class Solution
{
    public:
        int numberOfSubarrays(vector<int> &nums, int k)
        {
           	// int cnt = 0;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     int cntOdd = 0;
           	//     for (int j = i; j < nums.size(); j++)
           	//     {
           	//         if (nums[j] % 2 != 0)
           	//         {
           	//             cntOdd++;
           	//         }
           	//         if (cntOdd == k)
           	//         {
           	//             cnt++;
           	//         }
           	//     }
           	// }
           	// return cnt;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] % 2 != 0) nums[i] = 1;
                else nums[i] = 0;
            }
           	//             int i = 0;
           	//             int j = 0;
           	//             int cnt = 0;
           	//             int sum = 0;
           	//             while (j < nums.size())
           	//             {
           	//                 sum += nums[j];
           	//                 if (sum < k) j++;

           	//                 else
           	//                 {
           	//                     while (sum == k)
           	//                     {
           	//                         sum -= nums[i];
           	//                         i++;
           	//                         cnt++;
           	//                     }
           	//                     j++;
           	//                 }
           	//             }
           	//             return cnt;
            unordered_map<int, int> mp;
            mp[0] = 1;
            int sum = 0;
            int ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                int required = sum - k;

                ans += mp[required];

                mp[sum]++;
            }
            return ans;
        }
};