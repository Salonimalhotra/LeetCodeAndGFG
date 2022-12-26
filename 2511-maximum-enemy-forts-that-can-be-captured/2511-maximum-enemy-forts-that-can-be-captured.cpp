class Solution
{
    public:
        int captureForts(vector<int> &forts)
        {
            int ans = 0;
            for (int i = 0; i < forts.size(); i++)
            {
                if (forts[i] == 1)
                {
                   	// first we can check rightways to get out fort
                    int cntZeroes = 0;
                    for (int j = i + 1; j < forts.size(); j++)
                    {
                        if (forts[j] == -1)
                        {
                            ans = max(ans, cntZeroes);
                            break;
                        }
                        else if (forts[j] == 0)
                        {
                            cntZeroes++;
                        }
                        else
                        {
                            break;
                        }
                    }
                   	//second we can check leftways to get out empty fort:- -1 waala
                    cntZeroes = 0;
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (forts[j] == -1)
                        {
                            ans = max(ans, cntZeroes);
                             break;
                        }
                        else if (forts[j] == 0)
                        {
                            cntZeroes++;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
          return ans;
        }
};