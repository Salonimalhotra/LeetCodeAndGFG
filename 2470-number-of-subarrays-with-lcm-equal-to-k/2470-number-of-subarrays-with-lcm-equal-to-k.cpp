class Solution
{
    public:
        int subarrayLCM(vector<int> &nums, int m)
        {
           	// int cnt = 0;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     for (int j = i; j < nums.size(); j++)
           	//     {
           	//         int minNum = INT_MAX;
           	//         for (int k = i; k <= j; k++)
           	//         {
           	//             minNum = min(minNum, nums[k]);
           	//         }
           	//         int lcm = 1;
           	//         for (int t = 1; t <= minNum; t++)
           	//         {
           	//             bool check = true;
           	//             for (int k = i; k <= j; k++)
           	//             {
           	//                 if (nums[k] % t != 0)
           	//                 {
           	//                     check = false;
           	//                     break;
           	//                 }
           	//             }
           	//             if (check == true)
           	//             {
           	//                 lcm = t;
           	//             }
           	//         }
           	//         if (lcm == m) cnt++;
           	//     }
           	// }
           	// return cnt;
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                int lm = nums[i];
                if(lm==m) cnt++;
                for (int j = i+1; j < nums.size(); j++)
                {
                    lm = lcm(lm, nums[j]);
                    if (lm == m)
                    {
                        cnt++;
                    }
                    else if (lm > m)
                    {
                        break;
                    }
                }
            }
          return cnt;
        }
};