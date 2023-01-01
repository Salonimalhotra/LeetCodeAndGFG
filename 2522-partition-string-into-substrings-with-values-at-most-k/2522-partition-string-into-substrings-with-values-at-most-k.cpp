class Solution
{
    public:
        int minimumPartition(string s, int k)
        {
           
            int j = 0;
            int minPartitions = 0;
            long int currValue = 0;
            while (j < s.size())
            {
                if (currValue *10 + (s[j] - '0') <= k)
                {
                    currValue = currValue *10 + (s[j] - '0');
                    
                }
                else
                {
                    minPartitions++;
                    currValue = s[j] - '0';
                    if (currValue > k) return -1;
                   
                }
              j++;
            }
            minPartitions++;
            return minPartitions;
        }
};