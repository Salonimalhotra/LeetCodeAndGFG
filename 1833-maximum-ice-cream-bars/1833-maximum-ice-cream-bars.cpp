class Solution
{
    public:
        int maxIceCream(vector<int> &costs, int coins)
        {
            sort(costs.begin(), costs.end());
            int ans = 0;
            int i = 0;
            while (i < costs.size())
            {
                if (costs[i] <= coins)
                {
                    coins -= costs[i];
                    ans++;
                    i++;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }
};