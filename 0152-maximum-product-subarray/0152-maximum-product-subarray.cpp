class Solution
{
    public:
        int maxProduct(vector<int> &nums)
        {
           	//Brute force Approach-O(n^2)
           	// int maxP = INT_MIN;
           	// for (int i = 0; i < nums.size(); i++)
           	// {
           	//     int p = 1;
           	//     for (int j = i; j < nums.size(); j++)
           	//     {
           	//         p *= nums[j];
           	//         maxP = max(maxP, p);
           	//     }
           	// }
           	// return maxP;

           	// greedy Approach:-
            int maxP = INT_MIN;
            int p = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                p *= nums[i];
                maxP = max(maxP, p);
                if (p == 0) p = 1;
            }

            p = 1;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                p *= nums[i];
                maxP = max(maxP, p);
                if (p == 0) p = 1;
            }
          return maxP;
        }
};