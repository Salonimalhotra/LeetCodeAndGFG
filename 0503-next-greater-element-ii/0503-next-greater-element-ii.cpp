class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            vector<int> ans;
            int n=nums.size();
            for (int i = 0; i < nums.size(); i++)
            {
                int j = (i + 1) % n;
                int check=-1;
                while (j != i)
                {
                    if (nums[j] > nums[i])
                    {
                        check=nums[j];
                        break;
                    }
                    else {
                      j=(j+1)%n;
                    }
                }
              ans.push_back(check);
            }
          return ans;
        }
};