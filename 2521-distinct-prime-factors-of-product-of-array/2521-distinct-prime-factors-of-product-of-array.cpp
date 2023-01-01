class Solution
{
    public:
        bool getPrimeNumbers(int x)
        {
            if (x <= 1)
            {
                return false;
            }
            for (int i = 2; i < x; i++)
            {
                if (x % i == 0) return false;
            }
            return true;
        }
    void helper(set<int> &prime, int x, set<int> &ans)
    {
        for (int i = 2; i <= x; i++)
        {
            if (prime.find(i) != prime.end() && x % i == 0)
            {
                ans.insert(i);
            }
        }
    }
    int distinctPrimeFactors(vector<int> &nums)
    {
        set<int> n;
        set<int> prime;
        set<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            n.insert(nums[i]);
        }

        for (int i = 2; i <= 1000; i++)
        {
            if (getPrimeNumbers(i))
            {
                prime.insert(i);
            }
        }

        for (auto j: n)
        {
            helper(prime, j, ans);
        }

        return ans.size();
    }
};