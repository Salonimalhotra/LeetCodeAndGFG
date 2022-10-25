class Solution
{
    public:

        int helper(vector<string> &arr, int index, int mask)
        {
            if (index == arr.size())
            {
                return 0;
            }

            int option1 = helper(arr, index + 1, mask);
            int hash = 0;
            for (int i = 0; i < arr[index].size(); i++)
            {
                int pos = 1 << (arr[index][i] - 'a');
                if (hash & pos)
                {
                    return option1;
                }
                if (mask & pos)
                {
                    return option1;
                }
                hash = hash | pos;
            }

            mask = mask ^ hash;
            int option2 = arr[index].size() + helper(arr, index + 1, mask);
            return max(option1, option2);
        }

    int maxLength(vector<string> &arr)
    {
        int mask = 0;
        return helper(arr, 0, mask);
    }
};