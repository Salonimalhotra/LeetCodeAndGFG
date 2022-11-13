class Solution
{
    public:
        long long int gcd(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }
            return gcd(b, a % b);
        }
    long long int lcm(int a, int b)
    {
        return ((a / gcd(a, b)) *b);
    }
    int subarrayLCM(vector<int> &nums, int m)
    {

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int lm = nums[i];
            if (lm == m) cnt++;
            for (int j = i + 1; j < nums.size(); j++)
            {
                lm = lcm(lm, nums[j]);
                if (lm == m)
                {
                    cnt++;
                }
               	// we are breaking it as currently lcm is greater than m, therefore now it will only increase or remain constant, it cant decrease
                else if (lm > m)
                {
                    break;
                }
            }
        }
        return cnt;
    }
};