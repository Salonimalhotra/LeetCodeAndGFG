class Solution
{
    public:
        int arrangeCoins(int n)
        {

            if (n == 1) return 1;

            int coins = n;
            int rownum = 1;
            while (coins != 0)
            {
                if (coins >= rownum)
                {
                    coins -= rownum;
                    rownum++;
                }
                else break;
            }
            return rownum - 1;
        }
};