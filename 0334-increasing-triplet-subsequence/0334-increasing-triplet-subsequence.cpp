class Solution
{
    public:
        bool increasingTriplet(vector<int> &nums)
        {

           	//one more approach:-

            vector<int> lis;
            for (int i = 0; i < nums.size(); i++)
            {
                if (lis.size() == 0 || nums[i] > lis[lis.size() - 1]) lis.push_back(nums[i]);
                else
                {
                    int ind = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
                    lis[ind] = nums[i];
                }
            }
            if (lis.size() >= 3) return true;
            else return false;
           	//            	//Brute force
           	//             for (int i = 0; i < nums.size() - 2; i++)
           	//             {
           	//                 for (int j = i + 1; j < nums.size() - 1; j++)
           	//                 {
           	//                     for (int k = j + 1; k < nums.size(); k++)
           	//                     {
           	//                         if (nums[j] > nums[i] && nums[k] > nums[j])
           	//                         {
           	//                             return true;
           	//                         }
           	//                     }
           	//                 }
           	//             }
           	//             return false;

           	//            	//Using the concept of LIS 
           	//             int n = nums.size();
           	//             vector<int> dp(n, 1);
           	//             for (int i = 1; i < n; i++)
           	//             {
           	//                 for (int j = i - 1; j >= 0; j--)
           	//                 {
           	//                     if (nums[i] < nums[j] && dp[j] + 1 > dp[i])
           	//                     {
           	//                         dp[i] = dp[j] + 1;
           	//                     }
           	//                 }
           	//                 if(dp[i]==3) return true;
           	//             }
        }
};