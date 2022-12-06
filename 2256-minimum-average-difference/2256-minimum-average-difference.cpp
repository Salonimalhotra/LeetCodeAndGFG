class Solution
{
    public:
        int minimumAverageDifference(vector<int> &nums)
        {
            long long sumFromEnd = 0;
            for (auto i: nums)
            {
                sumFromEnd += i;
            }

            long long sumFromStart = 0;
            int diff=INT_MAX;
            int index=-1;
            for (int i = 0; i < nums.size(); i++)
            {
                sumFromStart += nums[i];
                sumFromEnd -= nums[i];
                long x1 = sumFromStart / (i + 1);
                long x2 = 0;
                if (i != nums.size() - 1)
                {
                    x2 = sumFromEnd / (nums.size() - i - 1);
                }
                if (abs(x1 - x2) < diff){
                  diff=abs(x1-x2);
                  index=i;
                }
            }
          return index;
        }
};