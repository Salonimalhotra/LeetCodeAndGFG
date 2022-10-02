class Solution
{
    public:
        int hammingDistance(int x, int y)
        {
            int totalAns;
            for (int k = 0; k < 32; k++)
            {
                int mask = 1 << k;
                if (((mask &x) != 0 && (mask & y ) != 0) || ((mask &x) == 0 && (mask & y) == 0)) continue;
                else totalAns++;
            }
            return totalAns;
        
          }
};