class Solution
{
    public:
        int maximumDifference(vector<int> &nums)
        {
           	//O(N^2) Approach:-
            int maxdiff = -1;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[j] > nums[i])
                    {
                        maxdiff = max(maxdiff, nums[j] - nums[i]);
                    }
                }
            }
            return maxdiff;

           	//O(N)- Approach
           	//   int minElement=nums[0];
           	//   int diff=-1;
           	//   for(int i=1;i < nums.size();i++){
           	//     if(nums[i]>minElement && nums[i]-minElement>diff){
           	//       diff=nums[i]-minElement;
           	//     }
           	//     if(nums[i] < minElement){
           	//       minElement=nums[i];
           	//     }
           	//   }
           	// return diff;
        }
};